#include "subject.h"

#include "common.h"

void DESP_ObsSubject::Attach(DESP_ObsObserver *obs) {
	this->obsList.push_back(obs);
	printf("Observer %s is attached!\n", obs->GetName().c_str());
}

void DESP_ObsSubject::Detach(DESP_ObsObserver *obs) {
	auto it = this->obsList.begin();
	while (it != this->obsList.end()) {
		if (*it == obs) {
			it = this->obsList.erase(it);
			printf("Observer %s is detach!\n", obs->GetName().c_str());
		} else {
			it++;
		}
	}
}

void DESP_ObsSubject::Function(void) {
	printf("process subject\n");
	for (auto i = 0; i < 10; i++) {
		this->Notify(i);
	}
}

void DESP_ObsSubject::Notify(unsigned char state) {
	auto it = this->obsList.begin();
	while (it != this->obsList.end()) {
		(*it)->Update(this->GetState(state));
		it++;
	}
}

unsigned char DESP_ObsSubject::GetState(unsigned char state)
{
	return state * 10;
}