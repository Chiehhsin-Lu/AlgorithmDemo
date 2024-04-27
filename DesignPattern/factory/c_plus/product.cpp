#include "product.h"

void DESP_FacProductA::Process(void)
{
	printf("type is product a, name is %s\n", this->name.c_str());
}

void DESP_FacProductB::Process(void)
{
	printf("type is product b, name is %s\n", this->name.c_str());
}

void DESP_FacProductC::Process(void)
{
	printf("product c, name is %s\n", this->name.c_str());
}