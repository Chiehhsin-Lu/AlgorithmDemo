#include "adaptee.h"

#include "common.h"

void DESP_Adaptee::process(int *val)
{
	*val += 1;
	printf("Adaptee process: %d\n", *val);
}