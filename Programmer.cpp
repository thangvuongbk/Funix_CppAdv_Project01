#include "Programmer.h"



Programmer::Programmer() : m_ProgBasicSalary{20000000}, m_ProRegularHour{40}
{
}


Programmer::~Programmer()
{
}

void Programmer::enterEmployeeInfo()
{
	//std::cin.ignore();
	Employee::enterEmployeeInfo();
	
	std::cout << "\nBasic programmer salary: ";
	std::cin >> m_ProgBasicSalary;

	std::cout << "\nRegular hour for programmer: ";
	std::cin >> m_ProRegularHour;

}

void Programmer::printEmployeeInfo()
{
	std::cout.left;
	Employee::printEmployeeInfo();	
	std::cout << std::left << std::setw(15) << m_ProgBasicSalary << std::setw(15) << m_ProRegularHour << std::endl;
}

int Programmer::getProgBasicSalary()
{
	return m_ProgBasicSalary;
}

int Programmer::getProgRegularHour()
{
	return m_ProRegularHour;
}
