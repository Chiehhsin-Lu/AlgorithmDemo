#pragma once

typedef enum {
	PRODUCT_A,
	PRODUCT_B,
	PRODUCT_C,

	PRODUCT_TYPE,
}FacProductType;

typedef struct {
	FacProductType type;
	char* name;
	void(*processFunc)(void);
} FacProduct;

void DESP_FacProductAProcess(void);
void DESP_FacProductBProcess(void);
void DESP_FacProductCProcess(void);