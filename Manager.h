#pragma once
#include "Employee.h"

class Manager : public Employee
{
private:
	std::string m_ManagerPosition;

public:
	Manager();
	~Manager();

	void enterManagerInfo();
	std::string getManagerPosition();
};

