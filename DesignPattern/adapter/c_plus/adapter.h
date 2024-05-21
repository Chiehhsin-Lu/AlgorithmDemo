#pragma once
#include "adaptee.h"

class DESP_AdaTarget {
public:
	DESP_AdaTarget() = default;
	virtual void requst(int* val) {};
	virtual ~DESP_AdaTarget() = default;
};

class DESP_Adapter : public DESP_AdaTarget {
public:
	DESP_Adaptee* adaptee;
	DESP_Adapter() = default;
	DESP_Adapter(DESP_Adaptee* adapteePtr) : adaptee(adapteePtr) {};
	void requst(int *val);
};