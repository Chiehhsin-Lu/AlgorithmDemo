#pragma once

typedef struct {
	char* name;
	void (*update)(unsigned char state);
} Observer;

void DESP_ObserverMain(void);