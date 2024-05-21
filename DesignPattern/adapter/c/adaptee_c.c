#include "adaptee_c.h"

#include "malloc.h"
#include "common.h"

static void DESP_AdapteeProcess(int *val);

DESP_Adaptee* DESP_GetAdaptee(void)
{
	DESP_Adaptee* adap = (DESP_Adaptee*)malloc(sizeof(DESP_Adaptee));
	if (adap == NULL) {
		return NULL;
	}
	adap->process = DESP_AdapteeProcess;
	return adap;
}

static void DESP_AdapteeProcess(int *val)
{
	*val += 1;
	printf("Adaptee process :%d\n", *val);
}