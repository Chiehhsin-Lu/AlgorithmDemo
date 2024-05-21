#include "adapter_c.h"

#include "malloc.h"
#include "common.h"
#include "adaptee_c.h"

typedef struct {
	void (*request)(void *obj, int* val);
}DESP_AdpTarget;

typedef struct DESP_Adapter {
	DESP_Adaptee *adaptee;
	DESP_AdpTarget target;
}DESP_Adapter;

static DESP_Adapter* DESP_GetAdapter(DESP_Adaptee* adaptee);
static void DESP_AdaTargetRequest(void* obj, int* val);

void DESP_AdapterFunction(void)
{
	DESP_Adaptee* adaptee = DESP_GetAdaptee();
	if (adaptee == NULL) {
		return;
	}

	DESP_Adapter* adapter = DESP_GetAdapter(adaptee);
	if (adapter == NULL) {
		return;
	}

	int val = 1;
	adapter->target.request(adapter, &val);

	free(adapter);
	free(adaptee);
}

static DESP_Adapter* DESP_GetAdapter(DESP_Adaptee* adaptee)
{
	DESP_Adapter* adapter = (DESP_Adapter*)malloc(sizeof(DESP_Adapter));
	if (adapter == NULL) {
		return NULL;
	}
	adapter->adaptee = adaptee;
	adapter->target.request = DESP_AdaTargetRequest;
}

static void DESP_AdaTargetRequest(void *obj, int *val)
{
	DESP_Adapter* adapter = (DESP_Adapter*)obj;
	adapter->adaptee->process(val);
	*val *= 2;
	printf("Adapter requst:%d\n", *val);
}