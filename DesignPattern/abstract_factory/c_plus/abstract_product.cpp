#include "abstract_product.h"

void DESP_AbsFacProductA1::Process(void)
{
	printf("type is product a, name is %s\n", this->name.c_str());
}
void DESP_AbsFacProductA2::Method(void)
{
	printf("type is product a, number is %d\n", this->number);
}

void DESP_AbsFacProductB1::Process(void)
{
	printf("type is product b, name is %s\n", this->name.c_str());
}
void DESP_AbsFacProductB2::Method(void)
{
	printf("type is product b, number is %d\n", this->number);
}

void DESP_AbsFacProductC1::Process(void)
{
	printf("product c, name is %s\n", this->name.c_str());
}
void DESP_AbsFacProductC2::Method(void)
{
	printf("product c, number is %d\n", this->number);
}