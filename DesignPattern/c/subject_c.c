#include "subject_c.h"

#include <string.h>

#define MAX_OSB_NUM 10u
typedef struct {
	bool hasAtt;
	Observer obs;
} ObsSubjectMgt;
static ObsSubjectMgt g_obsSubjectList[MAX_OSB_NUM] = { false, { NULL, NULL }};

static bool FindIdleListIndex(unsigned char* index);
static bool FindObsListIndex(Observer* obs, unsigned char* index);
static void NotifyObs(unsigned char value);
static unsigned char DESP_GetState(unsigned char state);

void DESP_ObsSubject(void)
{
	for (unsigned char i = 0; i < 10; i++) {
		NotifyObs(DESP_GetState(i));
	}
}

unsigned char DESP_Attach(Observer *obs)
{
	unsigned char index = MAX_OSB_NUM;
	if (!FindIdleListIndex(&index)) {
		return E_NOT_OK;
	}
	if (memcpy_s(&g_obsSubjectList[index].obs, sizeof(g_obsSubjectList[index].obs), obs, sizeof(Observer)) != 0) {
		return E_NOT_OK;
	}
	printf("Attach %s\n", obs->name);
	g_obsSubjectList[index].hasAtt = true;
	return E_OK;
}

unsigned char DSEP_Detach(Observer* obs)
{
	unsigned char index = MAX_OSB_NUM;
	if (!FindObsListIndex(obs, &index)) {
		return E_NOT_OK;
	}
	memset(&g_obsSubjectList[index], 0, sizeof(g_obsSubjectList[index]));
	printf("Detach %s\n", obs->name);
	return E_OK;
}

/***** ÄÚ²¿º¯Êý *****/

static bool FindIdleListIndex(unsigned char *index)
{
	for (unsigned int i = 0; i < (sizeof(g_obsSubjectList) / sizeof(g_obsSubjectList[0])); i++) {
		if (!g_obsSubjectList[i].hasAtt) {
			*index = i;
			return true;
		}
	}
	return false;
}

static bool FindObsListIndex(Observer* obs, unsigned char* index)
{
	for (unsigned int i = 0; i < (sizeof(g_obsSubjectList) / sizeof(g_obsSubjectList[0])); i++) {
		if (g_obsSubjectList[i].obs.name == obs->name) {
			*index = i;
			return true;
		}
	}
	return false;
}

static void NotifyObs(unsigned char value)
{
	for (unsigned int i = 0; i < (sizeof(g_obsSubjectList) / sizeof(g_obsSubjectList[0])); i++) {
		if ((g_obsSubjectList[i].hasAtt) && (g_obsSubjectList[i].obs.update != NULL)) {
			g_obsSubjectList[i].obs.update(value);
		}
	}
}

static unsigned char DESP_GetState(unsigned char state)
{
	return state * 10;
}