#pragma once
typedef struct {
	void(*process)(int *val);
} DESP_Adaptee;

DESP_Adaptee* DESP_GetAdaptee(void);