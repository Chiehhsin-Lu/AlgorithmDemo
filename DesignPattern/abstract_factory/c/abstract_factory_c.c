#include "abstract_factory_c.h"

#include "malloc.h"
#include "common.h"
#include "abstract_product_c.h"

typedef struct {
	AbsFacProductType type;
	AbsFacProduct1* (*creatFactoryFunc1)(void);
	AbsFacProduct2* (*creatFactoryFunc2)(void);
} FacProductTable;

static void DESP_FactoryFunc(AbsFacProductType type);
static AbsFacProduct1* DESP_FacCreatorProductA1(void);
static AbsFacProduct1* DESP_FacCreatorProductB1(void);
static AbsFacProduct1* DESP_FacCreatorProductC1(void);
static AbsFacProduct2* DESP_FacCreatorProductA2(void);
static AbsFacProduct2* DESP_FacCreatorProductB2(void);
static AbsFacProduct2* DESP_FacCreatorProductC2(void);

static FacProductTable g_facProTable[ABS_PRODUCT_TYPE] = {
	{.type = ABS_PRODUCT_A, .creatFactoryFunc1 = DESP_FacCreatorProductA1,	.creatFactoryFunc2 = DESP_FacCreatorProductA2 },
	{.type = ABS_PRODUCT_B, .creatFactoryFunc1 = DESP_FacCreatorProductB1,	.creatFactoryFunc2 = DESP_FacCreatorProductB2 },
	{.type = ABS_PRODUCT_C, .creatFactoryFunc1 = DESP_FacCreatorProductC1,	.creatFactoryFunc2 = DESP_FacCreatorProductC2 },
};


void DESP_AbsFactoryMain(void)
{
	DESP_FactoryFunc(ABS_PRODUCT_A);

	DESP_FactoryFunc(ABS_PRODUCT_B);

	DESP_FactoryFunc(ABS_PRODUCT_C);
}

static void DESP_FactoryFunc(AbsFacProductType type)
{
	if (type >= ABS_PRODUCT_TYPE) {
		return;
	}
	AbsFacProduct1* pro1 = g_facProTable[type].creatFactoryFunc1();
	if (pro1 == NULL) {
		printf("Creat product1 failed!\n");
		return;
	}
	printf("Creat product1 %s success!\n", pro1->name);
	pro1->processFunc(pro1->name);

	AbsFacProduct2* pro2 = g_facProTable[type].creatFactoryFunc2();
	if (pro2 == NULL) {
		printf("Creat product2 failed!\n");
		return;
	}
	printf("Creat product2 %d success!\n", pro2->number);
	pro2->methodFunc(pro2->number);
	free(pro1);
	free(pro2);
}

static AbsFacProduct1* DESP_FacCreatorProductA1(void)
{
	AbsFacProduct1* pro = (AbsFacProduct1*)malloc(sizeof(AbsFacProduct1));
	if (pro == NULL) {
		return pro;
	}
	pro->name = "ProductA";
	pro->type = ABS_PRODUCT_A;
	pro->processFunc = DESP_AbsFacProductAProcess;
	return pro;
}

static AbsFacProduct1* DESP_FacCreatorProductB1(void)
{
	AbsFacProduct1* pro = (AbsFacProduct1*)malloc(sizeof(AbsFacProduct1));
	if (pro == NULL) {
		return pro;
	}
	pro->name = "ProductB";
	pro->type = ABS_PRODUCT_B;
	pro->processFunc = DESP_AbsFacProductBProcess;
	return pro;
}

static AbsFacProduct1* DESP_FacCreatorProductC1(void)
{
	AbsFacProduct1* pro = (AbsFacProduct1*)malloc(sizeof(AbsFacProduct1));
	if (pro == NULL) {
		return pro;
	}
	pro->name = "ProductC";
	pro->type = ABS_PRODUCT_C;
	pro->processFunc = DESP_AbsFacProductCProcess;
	return pro;
}

static AbsFacProduct2* DESP_FacCreatorProductA2(void)
{
	AbsFacProduct2* pro = (AbsFacProduct2*)malloc(sizeof(AbsFacProduct2));
	if (pro == NULL) {
		return pro;
	}
	pro->number = 1;
	pro->type = ABS_PRODUCT_A;
	pro->methodFunc = DESP_AbsFacProductAMethod;
	return pro;
}

static AbsFacProduct2* DESP_FacCreatorProductB2(void)
{
	AbsFacProduct2* pro = (AbsFacProduct2*)malloc(sizeof(AbsFacProduct2));
	if (pro == NULL) {
		return pro;
	}
	pro->number = 2;
	pro->type = ABS_PRODUCT_B;
	pro->methodFunc = DESP_AbsFacProductBMethod;
	return pro;
}

static AbsFacProduct2* DESP_FacCreatorProductC2(void)
{
	AbsFacProduct2* pro = (AbsFacProduct2*)malloc(sizeof(AbsFacProduct2));
	if (pro == NULL) {
		return pro;
	}
	pro->number = 3;
	pro->type = ABS_PRODUCT_C;
	pro->methodFunc = DESP_AbsFacProductCMethod;
	return pro;
}