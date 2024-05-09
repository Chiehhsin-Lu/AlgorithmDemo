#pragma once
#pragma once

#include <string>

#include "abstract_product.h"

// factory
class DESP_AbsFacCreatorProduct {
public:
	DESP_AbsFacCreatorProduct() = default;
	virtual DESP_AbsFacProduct1* creat1(std::string  name) { return NULL; };
	virtual DESP_AbsFacProduct2* creat2(int  number) { return NULL; };
	virtual ~DESP_AbsFacCreatorProduct() = default;
};

class DESP_AbsFacCreatorProductA : public DESP_AbsFacCreatorProduct {
public:
	DESP_AbsFacCreatorProductA() = default;
	DESP_AbsFacProduct1* creat1(std::string  name);
	DESP_AbsFacProduct2* creat2(int  number);
};

class DESP_AbsFacCreatorProductB : public DESP_AbsFacCreatorProduct {
public:
	DESP_AbsFacCreatorProductB() = default;
	DESP_AbsFacProduct1* creat1(std::string  name);
	DESP_AbsFacProduct2* creat2(int  number);
};

class DESP_AbsFacCreatorProductC : public DESP_AbsFacCreatorProduct {
public:
	DESP_AbsFacCreatorProductC() = default;
	DESP_AbsFacProduct1* creat1(std::string  name);
	DESP_AbsFacProduct2* creat2(int  number);
};


// function
class DESP_AbsFactoryFunc {
public:
	DESP_AbsFacCreatorProduct* factory;
	DESP_AbsFactoryFunc() = default;
	DESP_AbsFactoryFunc(DESP_AbsFacCreatorProduct* func_factory) : factory(func_factory) {};
	void function(std::string  name, int number);
};