#pragma once

#include <list>

#include "observer.h"

class DESP_ObsSubject {
public:
	DESP_ObsSubject() = default;
	void Attach(DESP_ObsObserver *obs);
	void Detach(DESP_ObsObserver *obs);
	void Function(void);
protected:
	void Notify(unsigned char state);
	unsigned char GetState(unsigned char state);
private:
	std::list< DESP_ObsObserver*> obsList;
};