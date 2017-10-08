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
using namespace Welcome;

int main()
{
	//Welcome Screen
	system("color 31");
	Welcomescreen();
	int choice = Choice(choice);
	switch (choice)
	{
	case 1:
	{
		RunForm();
	}
	case 2:
	{
		//call analysis functions, display results, etc
		int option;
		Sleep(100);
		system("CLS");
		cout << "What would you like to see?" << endl << endl;
		cout << "1. The General results from the survey regarding quantity of E-waste generated" << endl << endl;
		cout << "2. The substance wise breakup of E-waste generated" << endl << endl;
		cout << "3. Display how the E-waste should be processed prior to dedicated treatment of each substance/ group of substances" << endl << endl;
		//more options to follow
		cin >> option;
		int increment;
		for (; option > 0;(option>0?option+=increment:0))
		{
			switch (option)
			{
			case 1:
			{
				system("CLS");
				Display::GeneralResults();
				cout << endl << endl << "Would you like to continue to \"Subtance wise breakup of E-waste generated\" or exit? Enter 1 to continue and 0 to exit" << endl << endl;
				cin >> increment;
				Sleep(100);
				break;
			}
			case 2:
			{
				system("CLS");
				Display::ComponentBreakup();
				cout << endl << endl << "Would you like to continue to \"Pre-processing of E-waste generated\" or exit? Enter 1 to continue and 0 to exit" << endl << endl;
				cin >> increment;
				Sleep(100);
				break;
			}
			case 3:
			{
				system("CLS");
				Display::PreProcessing();
				option = 0;
				_getche();
				break;
			}
			}
		}

	}
	}
	system("CLS");
	cout << "Press any key to exit" << endl;
	_getch();
	return 0;
}