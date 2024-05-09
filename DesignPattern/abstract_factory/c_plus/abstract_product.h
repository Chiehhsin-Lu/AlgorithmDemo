#pragma once
#include <string>

class DESP_AbsFacProduct1 {
public:
	DESP_AbsFacProduct1() = default;
	DESP_AbsFacProduct1(std::string pro_name) : name(pro_name) {};
	virtual void Process(void) {};
	virtual ~DESP_AbsFacProduct1() = default;
	std::string name;
};

class DESP_AbsFacProduct2 {
public:
	DESP_AbsFacProduct2() = default;
	DESP_AbsFacProduct2(int pro_num) : number(pro_num) {};
	virtual void Method(void) {};
	virtual ~DESP_AbsFacProduct2() = default;
	int number;
};

class DESP_AbsFacProductA1 : public DESP_AbsFacProduct1 {
public:
	DESP_AbsFacProductA1() = default;
	DESP_AbsFacProductA1(std::string pro_name) : DESP_AbsFacProduct1(pro_name) {};
	void Process(void);
};
class DESP_AbsFacProductA2 : public DESP_AbsFacProduct2 {
public:
	DESP_AbsFacProductA2() = default;
	DESP_AbsFacProductA2(int pro_num) : DESP_AbsFacProduct2(pro_num) {};
	void Method(void);
};

class DESP_AbsFacProductB1 : public DESP_AbsFacProduct1 {
public:
	DESP_AbsFacProductB1() = default;
	DESP_AbsFacProductB1(std::string pro_name) : DESP_AbsFacProduct1(pro_name) {};
	void Process(void);
};
class DESP_AbsFacProductB2 : public DESP_AbsFacProduct2 {
public:
	DESP_AbsFacProductB2() = default;
	DESP_AbsFacProductB2(int pro_num) : DESP_AbsFacProduct2(pro_num) {};
	void Method(void);
};

class DESP_AbsFacProductC1 : public DESP_AbsFacProduct1 {
public:
	DESP_AbsFacProductC1() = default;
	DESP_AbsFacProductC1(std::string pro_name) : DESP_AbsFacProduct1(pro_name) {};
	void Process(void);
};
class DESP_AbsFacProductC2 : public DESP_AbsFacProduct2 {
public:
	DESP_AbsFacProductC2() = default;
	DESP_AbsFacProductC2(int pro_num) : DESP_AbsFacProduct2(pro_num) {};
	void Method(void);
};