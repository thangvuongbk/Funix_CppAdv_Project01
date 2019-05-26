#include "Employee.h"


Employee::Employee()
{
	m_EmployeeID = "uic00949";
	m_EmployeeFullName = "Vuong Van Thang";
	m_Birthday = "02/06/1991";
	m_Email = "thangvuongbk@gmail.com";
	m_PhoneNumber = "0989465759";
	m_Address = "Bong Sao, P5, Q8, HCM";
}


Employee::~Employee()
{
}


void Employee::enterEmployeeInfo()
{
	std::cin.ignore();
	std::cout << "\nEmployee ID: ";
	std::getline(std::cin, m_EmployeeID); // 7 characters only

	std::cout << "\nEmployee Name: ";
	std::getline(std::cin, m_EmployeeFullName); // 30 characters only

	std::cout << "\nEmployee Birthday : ";
	std::getline(std::cin, m_Birthday); // 6 characters only

	std::cout << "\nEmployee Email: ";
	std::getline(std::cin, m_Email); // 50 characters only

	std::cout << "\nEmployee Phone: ";
	std::getline(std::cin, m_PhoneNumber); // 10 characters only

	std::cout << "\nEmployee Address: ";
	std::getline(std::cin, m_Address); // 100 characters only
}

void Employee::printEmployeeInfo()
{
	std::cout.left;
	std::cout << std::left << std::setw(15) << m_EmployeeID << std::setw(20) << m_EmployeeFullName << std::setw(12) << m_Birthday << std::setw(30) << m_Email
		<< std::setw(15) << m_PhoneNumber << std::setw(25) << m_Address;
}

std::string Employee::getEmployeeName()
{

	return m_EmployeeFullName;
}