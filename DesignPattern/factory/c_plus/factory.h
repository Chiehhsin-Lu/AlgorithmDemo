#pragma once

#include <string>

#include "product.h"

// factory
class DESP_FacCreatorProduct {
public:
	DESP_FacCreatorProduct() = default;
	virtual DESP_FacProduct* creat(std::string  name) { return NULL; };
	virtual ~DESP_FacCreatorProduct() = default;
};

class DESP_FacCreatorProductA : public DESP_FacCreatorProduct {
public:
	DESP_FacCreatorProductA() = default;
	DESP_FacProduct* creat(std::string  name);
};

class DESP_FacCreatorProductB : public DESP_FacCreatorProduct {
public:
	DESP_FacCreatorProductB() = default;
	DESP_FacProduct* creat(std::string  name);
};

class DESP_FacCreatorProductC : public DESP_FacCreatorProduct {
public:
	DESP_FacCreatorProductC() = default;
	DESP_FacProduct* creat(std::string  name);
};


// function
class DESP_FactoryFunc {
public:
	DESP_FacCreatorProduct* factory;
	DESP_FactoryFunc() = default;
	DESP_FactoryFunc(DESP_FacCreatorProduct* func_factory) : factory(func_factory) {};
	void function(std::string  name);
};