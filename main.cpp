extern "C" {
#include <stdlib.h>
#include <stdio.h>
}

#include "sub_floders.h"

#define C_SWITCH 1u
#define C_PLUS__SWITCH 1u

static void Test_Distance(void);
static void Test_Observe(void);
static void Test_Factory(void);
static void Test_AbsFactory(void);

int main()
{
	printf("Hellod Word!\n");

	Test_Distance();
	Test_Observe();
	Test_Factory();
	Test_AbsFactory();

	system("pause");
	return 0;
}

/***** 内部函数 *****/
static void Test_Distance(void)
{
	int ret_size = 0;
	int** ret = levelOrder(NULL, &ret_size, NULL);
	Dsitance dis;
	dis.testSumAbsoluteDifferences();
}

static void Test_Observe(void)
{
#if C_SWITCH == 1
	DESP_ObserverMain();
#endif

#if C_PLUS__SWITCH == 1
	DESP_ObsObserver obs;
	obs.Function();
#endif
}

static void Test_Factory(void)
{
#if C_SWITCH == 1
	DESP_FactoryMain();
#endif

#if C_PLUS__SWITCH == 1
	std::string  name1 = "product1";
	DESP_FacCreatorProductA proA;
	DESP_FactoryFunc facFunc1(&proA);

	facFunc1.function(name1);

	std::string  name2 = "product2";
	DESP_FacCreatorProductB proB;
	DESP_FactoryFunc facFunc2(&proB);

	facFunc2.function(name2);

	std::string  name3 = "product3";
	DESP_FacCreatorProductC proC;
	DESP_FactoryFunc facFunc3(&proC);

	facFunc3.function(name3);

	std::string  name4 = "product4";
	facFunc3.function(name4);
#endif
}

static void Test_AbsFactory(void)
{
#if C_SWITCH == 1
	DESP_AbsFactoryMain();
#endif

#if C_PLUS__SWITCH == 1
	std::string  name1 = "product1";
	DESP_AbsFacCreatorProductA proA;
	DESP_AbsFactoryFunc facFunc1(&proA);

	facFunc1.function(name1, 1);

	std::string  name2 = "product2";
	DESP_AbsFacCreatorProductB proB;
	DESP_AbsFactoryFunc facFunc2(&proB);

	facFunc2.function(name2, 2);

	std::string  name3 = "product3";
	DESP_AbsFacCreatorProductC proC;
	DESP_AbsFactoryFunc facFunc3(&proC);

	facFunc3.function(name3, 3);

	std::string  name4 = "product4";
	facFunc3.function(name4, 4);
#endif
}