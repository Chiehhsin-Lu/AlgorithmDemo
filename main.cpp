extern "C" {
#include <stdlib.h>
#include <stdio.h>
#include "levelOrder.h"

#include "observer_c.h"
}
#include "distance.h"
#include "observer.h"

#define C_SWITCH 1u
#define C_PLUS__SWITCH 1u

static void Test_Distance(void);
static void Test_Observe(void);

int main()
{
	printf("Hellod Word!\n");

	Test_Observe();

	system("pause");
	return 0;
}

/***** ÄÚ²¿º¯Êý *****/
static void Test_Distance(void)
{
	int ret_size = 0;
	int** ret = levelOrder(NULL, &ret_size, NULL);
	Dsitance dis;
	dis.testSumAbsoluteDifferences();
}

static  void Test_Observe(void)
{
#if C_SWITCH == 1
	DESP_ObserverMain();
#endif

#if C_PLUS__SWITCH == 1
	DESP_ObsObserver obs;
	obs.Function();
#endif
}