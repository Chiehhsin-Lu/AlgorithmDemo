#pragma once

typedef enum {
	ABS_PRODUCT_A,
	ABS_PRODUCT_B,
	ABS_PRODUCT_C,

	ABS_PRODUCT_TYPE,
}AbsFacProductType;

typedef struct {
	AbsFacProductType type;
	char* name;
	void(*processFunc)(void);
} AbsFacProduct1;

typedef struct {
	AbsFacProductType type;
	int number;
	void(*methodFunc)(void);
} AbsFacProduct2;

void DESP_AbsFacProductAProcess(char* name);
void DESP_AbsFacProductAMethod(int number);
void DESP_AbsFacProductBProcess(char* name);
void DESP_AbsFacProductBMethod(int number);
void DESP_AbsFacProductCProcess(char* name);
void DESP_AbsFacProductCMethod(int number);