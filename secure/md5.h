#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>

#define GROUP_LEN_BYTE 64u
#define DATA_LEN_SIZE_BYTE 8u
#define GET_PADDING_LEN (GROUP_LEN_BYTE - DATA_LEN_SIZE_BYTE)

class Md5Processer {
public:
    uint32_t finalDataLen;
    uint32_t paddingBuffSize;
    std::string getMd5Hash(const std::string originalData);
private:
    constexpr static uint32_t initial_state[4] = { 0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476 };
    uint32_t state[4] = { initial_state[0], initial_state[1], initial_state[2], initial_state[3] };
    uint32_t count[2] = { 0 };
    std::unique_ptr<uint8_t[]> getPaddingBuff(const std::string originalData, uint32_t len);
    void processSubBuff(uint8_t* buff, uint32_t size);
    void encodeBuff(uint8_t* output, uint32_t* input, uint32_t len);

    long executeNonlinear(long a, long b, long c, long d, long m, long s, long k, long (Md5Processer::* func)(long, long, long));
    long F(long x, long y, long z) { return (x & y) | (~x & z); }
    long G(long x, long y, long z) { return (x & z) | (y & ~z); }
    long H(long x, long y, long z) { return (x ^ y ^ z); }
    long I(long x, long y, long z) { return (y ^ (x | ~z)); }
};