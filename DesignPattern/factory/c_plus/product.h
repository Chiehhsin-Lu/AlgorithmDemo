#pragma once

#include <string>

class DESP_FacProduct {
public:
	DESP_FacProduct() = default;
	DESP_FacProduct(std::string pro_name) : name(pro_name) {};
	virtual void Process(void) {};
	virtual ~DESP_FacProduct() = default;
	std::string name;
};

class DESP_FacProductA : public DESP_FacProduct {
public:
	DESP_FacProductA() = default;
	DESP_FacProductA(std::string pro_name) : DESP_FacProduct(pro_name) {};
	void Process(void);
};

class DESP_FacProductB : public DESP_FacProduct {
public:
	DESP_FacProductB() = default;
	DESP_FacProductB(std::string pro_name) : DESP_FacProduct(pro_name) {};
	void Process(void);
};

class DESP_FacProductC : public DESP_FacProduct {
public:
	DESP_FacProductC() = default;
	DESP_FacProductC(std::string pro_name) : DESP_FacProduct(pro_name) {};
	void Process(void);
};