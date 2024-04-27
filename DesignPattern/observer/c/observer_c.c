#include "observer_c.h"

#include "common.h"
#include "subject_c.h"

static unsigned char UpdateConcreteObs1(unsigned char state);
static unsigned char UpdateConcreteObs2(unsigned char state);

static Observer g_observerList[] = {
	{ .name = "Obs1", .update = UpdateConcreteObs1 },
	{ .name = "Obs2", .update = UpdateConcreteObs2 },
};

void DESP_ObserverMain(void)
{
	printf("observer c\n");
	DESP_Attach(&g_observerList[0]);
	DESP_Attach(&g_observerList[1]);

	DESP_ObsSubject();

	DSEP_Detach(&g_observerList[0]);
	DESP_ObsSubject();
}

static unsigned char UpdateConcreteObs1(unsigned char state)
{
	printf("***%d\n", state);
	return E_OK;
}

static unsigned char UpdateConcreteObs2(unsigned char state)
{
	printf("???%d\n", state);
	return E_OK;
}