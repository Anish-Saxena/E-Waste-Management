#include<iostream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<dos.h>
#include "MyForm.h"
#include "ManageData.h"
#include "Analyze.h"
#include"Screens.h"
#include<string>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace ManageData;
using namespace Analyze;

namespace Welcome
{
	void Welcomescreen()
	{
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
	}

	int Choice(int c)
	{
		cout << setw(50) << "What would you like to do?" << endl << endl << endl;
		cout << "1. Take survey of user(s)" << endl << endl << endl;
		cout << "2. Analyze currently present data and see the results" << endl << endl << endl;
		cin >> c;
		return c;
	}

	void RunForm()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Project1::MyForm form;
		Application::Run(%form);
	}

}