#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>

#include "Employee.h"
#include "Programmer.h"
#include "Manager.h"
#include "Employer.h"

///
///
///
int theFirstScreen()
{
	int m_menuOption = -1;	
	std::cout << "Please select the below option" << std::endl;

	do
	{
		std::cout << "\n1-Nhap thong tin nhan vien.";
		std::cout << "\n2-Xem thong tin toan bo nhan vien.";
		std::cout << "\n3-Xem thong tin tong luong nhan vien.";
		std::cout << "\n0-Thoat.";

		std::cout << "\nLua chon cua ban la: ";
		std::cin >> m_menuOption;

	} while (m_menuOption < 0 || m_menuOption > 3);
	
	return m_menuOption;
}

///
///
///
int theSecondScreen()
{
	int m_menuOption = -1;
	do
	{
		std::cout << "\n 1-Nhap thong tin manager.";
		std::cout << "\n 2-Nhap thong tin programmer.";
		std::cout << "\n 3-Nhap thong tin employer.";
		std::cout << "\n 0-Thoat.";

		std::cout << "\nLua chon cua ban la: ";
		std::cin >> m_menuOption;

	} while (m_menuOption < 0 || m_menuOption > 3);
	
	return m_menuOption;
}

/// Create an programmer
void createAProgrammer(Programmer *programmer, int& iProEmployeeNumber)
{	
	
	std::ofstream ofsProOutfile;

	//ofsProOutfile.open("Programmer.dat", std::ios::binary | std::ios::app);
	//// in case the file is not able to open
	//if (!ofsProOutfile)
	//{
	//	std::cout << "\nThe file is not able to open, Press Enter to back the main menu" << std::endl;
	//	return;
	//}
	//// Input the programmer information
	//programmer.enterEmployeeInfo();
	//
	//// Write this info to the file
	//ofsProOutfile.write(reinterpret_cast<char*>(&programmer), sizeof(Programmer));
	//ofsProOutfile.close();

	if (programmer == nullptr)
	{
		std::cout << "\nSomething wrong, please restart the application";
		return;
	}	
	//
	if (iProEmployeeNumber >= 1)
	{
		Programmer* proTemp = new Programmer[iProEmployeeNumber];

		for (int i = 0; i < iProEmployeeNumber; i++)
		{
			proTemp[i] = programmer[i];
		}
		programmer = nullptr;
		if (iProEmployeeNumber == 1)
		{
			delete programmer;
		}
		else delete[] programmer;
				
		//
		programmer = new Programmer[iProEmployeeNumber + 1];
		programmer[iProEmployeeNumber].enterEmployeeInfo();
		//
		for (int i = 0; i < iProEmployeeNumber; i++)
		{
			programmer[i] = proTemp[i];
		}
		delete[] proTemp;
	}
	else
	{
		programmer = new Programmer;
		programmer[iProEmployeeNumber].enterEmployeeInfo();		
	}	
	//
	++iProEmployeeNumber;


	//=====================
	std::cout << "-----------------------------------------------------------------------------";
	std::cout << "\nThe employee: '" << programmer[iProEmployeeNumber - 1].getEmployeeName() << "' created successfully\n";
	std::cout << "\nPress Enter to back the Main menu";
}

/// output the Programmer
void printProgrammer(Programmer* programmer, int iProEmployeeNumber)
{
	if (programmer == nullptr)
	{
		std::cout << "\nNo any Programmer information available";
		return;
	}
	for (int iProgrammerNumber = 0; iProgrammerNumber < iProEmployeeNumber - 1; iProgrammerNumber++)
	{
		programmer[iProgrammerNumber].printEmployeeInfo();
	}
	

	//std::ifstream ifsProInputfile;
	//ifsProInputfile.open("Programmer.dat", std::ios::binary);
	//// in case the file is not able to open
	//if (!ifsProInputfile)
	//{
	//	std::cout << "\nThe file is not able to open, Press Enter to back the main menu" << std::endl;
	//	return;
	//}
	//// Print it out
	//while (ifsProInputfile.read(reinterpret_cast<char*>(&programmer), sizeof(Programmer)))
	//{
	//	programmer.printEmployeeInfo();
	//}
	//ifsProInputfile.close();	
}


//======================================================================

void printAllEmployeeOut(Programmer* programmer, int iProEmployeeNumber)
{
	system("cls");
	std::cout << "\nBAO PHONG COMPANY EMPLOYEE INFORMATION\\n\n";
	std::cout.left;
	std::cout << "\nProgammer List:\n";
	std::cout << std::left << std::setw(15) << "Employee ID | " << std::setw(20) << "Employee Name | " << std::setw(12) << "Birthday | " << std::setw(30)
		<< "Email | " << std::setw(15) << "Phone | " << std::setw(25) << "Address |" << std::setw(15)
		<< "Basic Salary | " << std::setw(15) << "Regular Hour | "  << std::endl;

	
	
	printProgrammer(programmer, iProEmployeeNumber);
	std::cout << "\nPress Enter to back the Main menu";
}

//=======================================================================

int main()
{
	/*
	The below code is to the dimension of windown in case the default one is not coverred all the text
	*/
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 2000, 400, TRUE); // 1000 width, 400 height

	int m_MenuOption = -1;
	
	int iProEmployeeNumber = 0;
	Programmer* proEmployee = new Programmer;
	
	//Manager magEmployee;
	//Employer emplEmployee;

	//Employee *empEmployeeProgrammer = proEmployee;
		
	do
	{
		system("cls");
		std::cout << "======== Chuong Trinh Quan Ly Nhan Vien ========" << std::endl;
		m_MenuOption = theFirstScreen();

		switch (m_MenuOption)
		{
		// 1 - Nhap thong tin nhan vien
		case 1:
				m_MenuOption = theSecondScreen();
					switch (m_MenuOption)
					{
						// 1-Nhap thong tin manager
					case 1:
						//magEmployee.enterManagerInfo();
					
						break;
					// 2-Nhap thong tin programmer
					case 2:
						//proEmployee = new Programmer[iProEmployeeNumber];
						createAProgrammer(proEmployee, iProEmployeeNumber);
						break;
					// 3-Nhap thong tin employer.
					case 3:
						//emplEmployee.enterEmployerInfo();
						break;

					// 0-Thoat.
					case 0:

						break;

					default: std::cout << "\a";
						
					}
				break;

		// 2 - Xem thong tin toan bo nhan vien.
		case 2:
			printAllEmployeeOut(proEmployee, iProEmployeeNumber);
			break;

		// 3-Xem thong tin tong luong nhan vien.
		case 3:

			break;
		
		//0-Thoat.
		case 0:
	
			break;

		default:  std::cout << "\a";				
		}
		std::cin.ignore();
		std::cin.get();
	} while (m_MenuOption != 0);

//	delete empEmployeeProgrammer;
	//system("pause");
	return 0;


}