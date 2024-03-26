#include "observer.h"

#include "common.h"
#include "subject.h"

bool operator==(const DESP_ObsObserver &lhs, const DESP_ObsObserver &rhs) {
	if (lhs.GetName() != rhs.GetName()) {
		return false;
	}
	return true;
}

bool operator!=(const DESP_ObsObserver &lhs, const DESP_ObsObserver &rhs) {
	return !(lhs == rhs);
}

std::string DESP_ObsObserver::GetName() const {
	return this->name;
}

void DESP_ObsObserver::Function(void)
{
	printf("observer c++\n");
	DESP_ObsSubject sub;
	DESP_ObsObserver1 obs1("obs1");
	DESP_ObsObserver2 obs2("obs2");
	sub.Attach(&obs1);
	sub.Attach(&obs2);
	sub.Function();

	sub.Detach(&obs1);
	sub.Function();
}

unsigned char DESP_ObsObserver1::Update(unsigned char state)
{
	printf("***%d\n", state);
	return E_OK;
}

unsigned char DESP_ObsObserver2::Update(unsigned char state)
{
	printf("???%d\n", state);
	return E_OK;
}