#pragma once

#include <string>

class DESP_ObsObserver {
public:
	DESP_ObsObserver() = default;
	DESP_ObsObserver(std::string obs_name) : name(obs_name) {};
	std::string GetName() const;
	void Function(void);
	virtual unsigned char Update(unsigned char state) { printf("***\n");  return state; };
	virtual ~DESP_ObsObserver() = default;
private:
	std::string name;
};

class DESP_ObsObserver1 : public DESP_ObsObserver {
public:
	DESP_ObsObserver1() = default;
	DESP_ObsObserver1(std::string obs_name) : DESP_ObsObserver(obs_name) {};
	unsigned char Update(unsigned char state);
};

class DESP_ObsObserver2 : public DESP_ObsObserver {
public:
	DESP_ObsObserver2() = default;
	DESP_ObsObserver2(std::string obs_name) : DESP_ObsObserver(obs_name) {};
	unsigned char Update(unsigned char state);
};

bool operator==(const DESP_ObsObserver &lhs, const DESP_ObsObserver& rhs);
bool operator!=(const DESP_ObsObserver& lhs, const DESP_ObsObserver& rhs);