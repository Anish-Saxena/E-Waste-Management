#include<iostream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<dos.h>
#include "MyForm.h"
#include "ManageData.h"
#include "Analyze.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace ManageData;
using namespace Analyze;

int main()
{
	//Welcome Screen
	system("color 31");
	cout << setw(45) << "Welcome!" << endl << endl << endl;
	Sleep(1000);
	cout << setw(55) << "ESC101 Advanced Track Project" << endl << endl << endl;
	Sleep(1000);
	cout << setw(53) << "E-Waste Management System" << endl << endl << endl;
	Sleep(1000);
	cout.width(6);
	cout << setw(80) << "By Anish Saxena" << endl;
	Sleep(1000);
	cout << setw(80) << "Roll no. 170118" << endl;
	Sleep(1000);
	cout << setw(80) << "Y17 Chemical Engineering" << endl << endl << endl;
	Sleep(1000);
	cout << "Press any key to continue" << endl;
	_getch();
	system("CLS");
	int choice;
	cout << setw(50) << "What would you like to do?" << endl << endl << endl;
	cout << "1. Take survey of user(s)" << endl << endl << endl;
	cout << "2. Analyse currently present data" << endl << endl << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		Project1::MyForm form;
		Application::Run(%form);
	}
	case 2:
	{
		//call analysis functions, display results, etc	
		cout << endl << endl;
		Display::GeneralResults();
	}
	} 
	_getch();
	return 0;
}