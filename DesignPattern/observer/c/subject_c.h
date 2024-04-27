#pragma once
#include "common.h"

#include "observer_c.h"

void DESP_ObsSubject(void);
unsigned char DESP_Attach(Observer* obs);
unsigned char DSEP_Detach(Observer* obs);