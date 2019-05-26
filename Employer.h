#pragma once
#include "Employee.h"

class Employer : public Employee
{
public:
	Employer();
	~Employer();

	void enterEmployerInfo();
};

