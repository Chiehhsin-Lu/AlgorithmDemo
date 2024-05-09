#include "abstract_factory.h"

#include"abstract_product.h"

void DESP_AbsFactoryFunc::function(std::string name, int number)
{
	DESP_AbsFacProduct1* product1 = this->factory->creat1(name);
	product1->Process();

	DESP_AbsFacProduct2* product2 = this->factory->creat2(number);
	product2->Method();

	delete product1;
	delete product2;
}

// factory
DESP_AbsFacProduct1* DESP_AbsFacCreatorProductA::creat1(std::string name)
{
	DESP_AbsFacProduct1* pro = new DESP_AbsFacProductA1(name);
	return pro;
}
DESP_AbsFacProduct2* DESP_AbsFacCreatorProductA::creat2(int number)
{
	DESP_AbsFacProduct2* pro = new DESP_AbsFacProductA2(number);
	return pro;
}

DESP_AbsFacProduct1* DESP_AbsFacCreatorProductB::creat1(std::string name)
{
	DESP_AbsFacProduct1* pro = new DESP_AbsFacProductB1(name);
	return pro;
}
DESP_AbsFacProduct2* DESP_AbsFacCreatorProductB::creat2(int number)
{
	DESP_AbsFacProduct2* pro = new DESP_AbsFacProductB2(number);
	return pro;
}

DESP_AbsFacProduct1* DESP_AbsFacCreatorProductC::creat1(std::string name)
{
	DESP_AbsFacProduct1* pro = new DESP_AbsFacProductC1(name);
	return pro;
}
DESP_AbsFacProduct2* DESP_AbsFacCreatorProductC::creat2(int number)
{
	DESP_AbsFacProduct2* pro = new DESP_AbsFacProductC2(number);
	return pro;
}