#pragma once
#include "Employee.h"

class Programmer : public Employee
{
private:
	unsigned int m_ProgBasicSalary;
	unsigned int m_ProRegularHour;

public:
	Programmer();
	~Programmer();

	virtual void enterEmployeeInfo() override;
	virtual void printEmployeeInfo() override;

	int getProgBasicSalary();
	int getProgRegularHour();
};

