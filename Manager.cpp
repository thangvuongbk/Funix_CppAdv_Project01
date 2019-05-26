#include "Manager.h"

Manager::Manager()
{
}


Manager::~Manager()
{
}

void Manager::enterManagerInfo()
{
	//std::cin.ignore();
	// Call the enterEmployeeInfo() first
	Employee::enterEmployeeInfo();
	
	std::cout << "\nPlease enter the Manager Postion: ";
	std::getline(std::cin, m_ManagerPosition);
}

std::string Manager::getManagerPosition()
{
	return m_ManagerPosition;
}
