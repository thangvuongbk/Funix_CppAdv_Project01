#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Employee
{
	std::string m_EmployeeID;
	std::string m_EmployeeFullName;
	std::string m_Birthday;
	std::string m_Email;
	std::string m_PhoneNumber;
	std::string m_Address;

public:
	Employee();
	~Employee();

	virtual void enterEmployeeInfo();
	virtual void printEmployeeInfo();
	// Missing the get/set function
	std::string getEmployeeName();
};


