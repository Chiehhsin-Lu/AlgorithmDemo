#include "adapter.h"

#include "common.h"

void DESP_Adapter::requst(int *val) {
	if (this->adaptee == nullptr) {
		return;
	}
	this->adaptee->process(val);
	*val *= 2;
	printf("Adapter requst: %d\n", *val);
}