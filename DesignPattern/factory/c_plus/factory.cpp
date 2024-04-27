#include "factory.h"

#include "product.h"

void DESP_FactoryFunc::function(std::string name)
{
	DESP_FacProduct* product = this->factory->creat(name);
	product->Process();
}

// factory
DESP_FacProduct* DESP_FacCreatorProductA::creat(std::string  name)
{
	DESP_FacProduct* pro = new DESP_FacProductA(name);
	return pro;
}

DESP_FacProduct* DESP_FacCreatorProductB::creat(std::string  name)
{
	DESP_FacProduct* pro = new DESP_FacProductB(name);
	return pro;
}

DESP_FacProduct* DESP_FacCreatorProductC::creat(std::string  name)
{
	DESP_FacProduct* pro = new DESP_FacProductC(name);
	return pro;
}