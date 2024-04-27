#include "factory_c.h"

#include "malloc.h"
#include "common.h"
#include "product_c.h"

typedef struct {
	FacProductType type;
	FacProduct* (*creatFactoryFunc)(void);
} FacProductTable;

void DESP_FactoryFunc(FacProductType type);
FacProduct* DESP_FacCreatorProductA(void);
FacProduct* DESP_FacCreatorProductB(void);
FacProduct* DESP_FacCreatorProductC(void);

static FacProductTable g_facProTable[PRODUCT_TYPE] = {
	{ .type = PRODUCT_A, .creatFactoryFunc = DESP_FacCreatorProductA },
	{ .type = PRODUCT_B, .creatFactoryFunc = DESP_FacCreatorProductB },
	{ .type = PRODUCT_C, .creatFactoryFunc = DESP_FacCreatorProductC },
};


void DESP_FactoryMain(void)
{
	DESP_FactoryFunc(PRODUCT_A);

	DESP_FactoryFunc(PRODUCT_B);

	DESP_FactoryFunc(PRODUCT_C);
}

void DESP_FactoryFunc(FacProductType type)
{
	if (type >= PRODUCT_TYPE) {
		return;
	}
	FacProduct*  pro = g_facProTable[type].creatFactoryFunc();
	if (pro == NULL) {
		printf("Creat product failed!\n");
		return;
	}
	printf("Creat product %s success!\n", pro->name);
	pro->processFunc();

	free(pro);
}

FacProduct* DESP_FacCreatorProductA(void)
{
	FacProduct* pro = (FacProduct*)malloc(sizeof(FacProduct));
	if (pro == NULL) {
		return pro;
	}
	pro->name = "ProductA";
	pro->type = PRODUCT_A;
	pro->processFunc = DESP_FacProductAProcess;
	return pro;
}

FacProduct* DESP_FacCreatorProductB(void)
{
	FacProduct* pro = (FacProduct*)malloc(sizeof(FacProduct));
	if (pro == NULL) {
		return pro;
	}
	pro->name = "ProductB";
	pro->type = PRODUCT_B;
	pro->processFunc = DESP_FacProductBProcess;
	return pro;
}

FacProduct* DESP_FacCreatorProductC(void)
{
	FacProduct* pro = (FacProduct*)malloc(sizeof(FacProduct));
	if (pro == NULL) {
		return pro;
	}
	pro->name = "ProductC";
	pro->type = PRODUCT_C;
	pro->processFunc = DESP_FacProductCProcess;
	return pro;
}