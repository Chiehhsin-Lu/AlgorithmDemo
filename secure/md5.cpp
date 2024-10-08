#include "md5.h"

const uint32_t k[GROUP_LEN_BYTE] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 ,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a ,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c ,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 ,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 ,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 ,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 ,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 ,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 ,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

const uint32_t s[GROUP_LEN_BYTE] = {
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

constexpr uint32_t rotate_right(uint32_t x, uint32_t n) {
    return (x << n) | (x >> (32 - n));
}

std::string hexArrayToString(const std::vector<uint8_t>& hexArray) {
    std::ostringstream hexStream;
    hexStream << std::hex << std::setw(2) << std::setfill('0');

    for (char byte : hexArray) {
        hexStream << static_cast<int>(static_cast<unsigned char>(byte));
    }

    return hexStream.str();
}

std::unique_ptr<uint8_t[]> Md5Processer::getPaddingBuff(const std::string originalData, uint32_t len) {
    this->finalDataLen = len % GROUP_LEN_BYTE;
    int paddingLen = (this->finalDataLen < GET_PADDING_LEN) ? (GET_PADDING_LEN - this->finalDataLen) :
        (GROUP_LEN_BYTE - this->finalDataLen + GET_PADDING_LEN);
    this->paddingBuffSize = paddingLen + 8;

    this->count[0] = (uint32_t)len << 3;
    if (this->count[0] < (uint32_t)(len << 3)) {
        this->count[1]++;
    }
    this->count[1] += ((uint32_t)len >> 29);

    uint8_t lenBitBuff[8] = { 0 };
    this->encodeBuff(lenBitBuff, this->count, 8);

    try {
        std::unique_ptr<uint8_t[]> paddingBuff(new uint8_t[this->paddingBuffSize]);
        std::memset(paddingBuff.get(), 0, this->paddingBuffSize);
        paddingBuff[0] = 0x80;

        std::memcpy(&paddingBuff[paddingLen], lenBitBuff, sizeof(lenBitBuff));

        return paddingBuff;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return nullptr;
    }
}

void Md5Processer::encodeBuff(uint8_t* output,uint32_t* input, uint32_t len)
{
    uint32_t i = 0, j = 0;
    while (j < len) {
        output[j] = input[i] & 0xFF;
        output[j + 1] = (input[i] >> 8) & 0xFF;
        output[j + 2] = (input[i] >> 16) & 0xFF;
        output[j + 3] = (input[i] >> 24) & 0xFF;
        i++;
        j += 4;
    }
}

long Md5Processer::executeNonlinear(long a, long b, long c, long d, long m, long s, long k, long (Md5Processer::*func)(long, long, long))
{
    a += (this->*func)(b, c, d) + m + k;
    a = rotate_right(a, s);
    a += b;
    return a;
}

void Md5Processer::processSubBuff(uint8_t *buff, uint32_t size) {
    uint32_t m32[16] = { 0 };
    for (uint32_t i = 0; i < size; i+= 4) {
        m32[i / 4] = buff[i] | (buff[i + 1] << 8) | (buff[i + 2] << 16) | (buff[i + 3] << 24);
    }
    long a = this->state[0];
    long b = this->state[1];
    long c = this->state[2];
    long d = this->state[3];
    // round 1
    a = this->executeNonlinear(a, b, c, d, m32[0], s[0], k[0], &Md5Processer::F);
    d = this->executeNonlinear(d, a, b, c, m32[1], s[1], k[1], &Md5Processer::F);
    c = this->executeNonlinear(c, d, a, b, m32[2], s[2], k[2], &Md5Processer::F);
    b = this->executeNonlinear(b, c, d, a, m32[3], s[3], k[3], &Md5Processer::F);

    a = this->executeNonlinear(a, b, c, d, m32[4], s[4], k[4], &Md5Processer::F);
    d = this->executeNonlinear(d, a, b, c, m32[5], s[5], k[5], &Md5Processer::F);
    c = this->executeNonlinear(c, d, a, b, m32[6], s[6], k[6], &Md5Processer::F);
    b = this->executeNonlinear(b, c, d, a, m32[7], s[7], k[7], &Md5Processer::F);

    a = this->executeNonlinear(a, b, c, d, m32[8], s[8], k[8], &Md5Processer::F);
    d = this->executeNonlinear(d, a, b, c, m32[9], s[9], k[9], &Md5Processer::F);
    c = this->executeNonlinear(c, d, a, b, m32[10], s[10], k[10], &Md5Processer::F);
    b = this->executeNonlinear(b, c, d, a, m32[11], s[11], k[11], &Md5Processer::F);

    a = this->executeNonlinear(a, b, c, d, m32[12], s[12], k[12], &Md5Processer::F);
    d = this->executeNonlinear(d, a, b, c, m32[13], s[13], k[13], &Md5Processer::F);
    c = this->executeNonlinear(c, d, a, b, m32[14], s[14], k[14], &Md5Processer::F);
    b = this->executeNonlinear(b, c, d, a, m32[15], s[15], k[15], &Md5Processer::F);

    // round 2
    a = this->executeNonlinear(a, b, c, d, m32[1], s[16], k[16], &Md5Processer::G);
    d = this->executeNonlinear(d, a, b, c, m32[6], s[17], k[17], &Md5Processer::G);
    c = this->executeNonlinear(c, d, a, b, m32[11], s[18], k[18], &Md5Processer::G);
    b = this->executeNonlinear(b, c, d, a, m32[0], s[19], k[19], &Md5Processer::G);

    a = this->executeNonlinear(a, b, c, d, m32[5], s[20], k[20], &Md5Processer::G);
    d = this->executeNonlinear(d, a, b, c, m32[10], s[21], k[21], &Md5Processer::G);
    c = this->executeNonlinear(c, d, a, b, m32[15], s[22], k[22], &Md5Processer::G);
    b = this->executeNonlinear(b, c, d, a, m32[4], s[23], k[23], &Md5Processer::G);

    a = this->executeNonlinear(a, b, c, d, m32[9], s[24], k[24], &Md5Processer::G);
    d = this->executeNonlinear(d, a, b, c, m32[14], s[25], k[25], &Md5Processer::G);
    c = this->executeNonlinear(c, d, a, b, m32[3], s[26], k[26], &Md5Processer::G);
    b = this->executeNonlinear(b, c, d, a, m32[8], s[27], k[27], &Md5Processer::G);

    a = this->executeNonlinear(a, b, c, d, m32[13], s[28], k[28], &Md5Processer::G);
    d = this->executeNonlinear(d, a, b, c, m32[2], s[29], k[29], &Md5Processer::G);
    c = this->executeNonlinear(c, d, a, b, m32[7], s[30], k[30], &Md5Processer::G);
    b = this->executeNonlinear(b, c, d, a, m32[12], s[31], k[31], &Md5Processer::G);

    // round 3
    a = this->executeNonlinear(a, b, c, d, m32[5], s[32], k[32], &Md5Processer::H);
    d = this->executeNonlinear(d, a, b, c, m32[8], s[33], k[33], &Md5Processer::H);
    c = this->executeNonlinear(c, d, a, b, m32[11], s[34], k[34], &Md5Processer::H);
    b = this->executeNonlinear(b, c, d, a, m32[14], s[35], k[35], &Md5Processer::H);

    a = this->executeNonlinear(a, b, c, d, m32[1], s[36], k[36], &Md5Processer::H);
    d = this->executeNonlinear(d, a, b, c, m32[4], s[37], k[37], &Md5Processer::H);
    c = this->executeNonlinear(c, d, a, b, m32[7], s[38], k[38], &Md5Processer::H);
    b = this->executeNonlinear(b, c, d, a, m32[10], s[39], k[39], &Md5Processer::H);

    a = this->executeNonlinear(a, b, c, d, m32[13], s[40], k[40], &Md5Processer::H);
    d = this->executeNonlinear(d, a, b, c, m32[0], s[41], k[41], &Md5Processer::H);
    c = this->executeNonlinear(c, d, a, b, m32[3], s[42], k[42], &Md5Processer::H);
    b = this->executeNonlinear(b, c, d, a, m32[6], s[43], k[43], &Md5Processer::H);

    a = this->executeNonlinear(a, b, c, d, m32[9], s[44], k[44], &Md5Processer::H);
    d = this->executeNonlinear(d, a, b, c, m32[12], s[45], k[45], &Md5Processer::H);
    c = this->executeNonlinear(c, d, a, b, m32[15], s[46], k[46], &Md5Processer::H);
    b = this->executeNonlinear(b, c, d, a, m32[2], s[47], k[47], &Md5Processer::H);

    // round 4
    a = this->executeNonlinear(a, b, c, d, m32[0], s[48], k[48], &Md5Processer::I);
    d = this->executeNonlinear(d, a, b, c, m32[7], s[49], k[49], &Md5Processer::I);
    c = this->executeNonlinear(c, d, a, b, m32[14], s[50], k[50], &Md5Processer::I);
    b = this->executeNonlinear(b, c, d, a, m32[5], s[51], k[51], &Md5Processer::I);

    a = this->executeNonlinear(a, b, c, d, m32[12], s[52], k[52], &Md5Processer::I);
    d = this->executeNonlinear(d, a, b, c, m32[3], s[53], k[53], &Md5Processer::I);
    c = this->executeNonlinear(c, d, a, b, m32[10], s[54], k[54], &Md5Processer::I);
    b = this->executeNonlinear(b, c, d, a, m32[1], s[55], k[55], &Md5Processer::I);

    a = this->executeNonlinear(a, b, c, d, m32[8], s[56], k[56], &Md5Processer::I);
    d = this->executeNonlinear(d, a, b, c, m32[15], s[57], k[57], &Md5Processer::I);
    c = this->executeNonlinear(c, d, a, b, m32[6], s[58], k[58], &Md5Processer::I);
    b = this->executeNonlinear(b, c, d, a, m32[13], s[59], k[59], &Md5Processer::I);

    a = this->executeNonlinear(a, b, c, d, m32[4], s[60], k[60], &Md5Processer::I);
    d = this->executeNonlinear(d, a, b, c, m32[11], s[61], k[61], &Md5Processer::I);
    c = this->executeNonlinear(c, d, a, b, m32[2], s[62], k[62], &Md5Processer::I);
    b = this->executeNonlinear(b, c, d, a, m32[9], s[63], k[63], &Md5Processer::I);

    this->state[0] += a;
    this->state[1] += b;
    this->state[2] += c;
    this->state[3] += d;
}

std::string Md5Processer::getMd5Hash(const std::string originalData)
{
    uint32_t len = originalData.length();
    auto paddingBuff = this->getPaddingBuff(originalData, len);
    if (!paddingBuff) {
        return "";
    }
    uint8_t subBuff[GROUP_LEN_BYTE] = { 0 };
    for (uint32_t i = 0; i < len; i += GROUP_LEN_BYTE) {
        if ((i + GROUP_LEN_BYTE) > len) {
            break;
        }
        std::memcpy(subBuff, &originalData[i], GROUP_LEN_BYTE);
        this->processSubBuff(subBuff, sizeof(subBuff));
        std::memset(subBuff, 0, sizeof(subBuff));
    }

    std::memcpy(subBuff, &originalData[len - this->finalDataLen], this->finalDataLen);
    std::memcpy(&subBuff[this->finalDataLen], paddingBuff.get(), this->paddingBuffSize);
    this->processSubBuff(subBuff, sizeof(subBuff));

    uint8_t md5Buff[16] = { 0 };
    this->encodeBuff(md5Buff, this->state, sizeof(md5Buff));
    std::vector<uint8_t> md5Vector(std::begin(md5Buff), std::end(md5Buff));
    std::string md5Str = hexArrayToString(md5Vector);

    return md5Str;
}