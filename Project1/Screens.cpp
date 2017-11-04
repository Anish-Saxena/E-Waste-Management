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
		cout << "3. Settings (Advanced)" << endl << endl << endl;
		cin >> c;
		return c;
	}

	void RunForm()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Project1::MyForm form;
		Application::Run(%form);
		cout << endl << endl;
		system("Pause");
		DataManip::ChecknSum();
		DataManip::AggregateSum();
		cout << endl << endl << "Would you like to now go to analysis and display section? Press 1 for yes" << endl << endl;
		int x;
		cin >> x;
		if (x == 1)	AnalysisnDisplay();
		_getche();
	}

	void AnalysisnDisplay()
	{
		int option;		
		Sleep(100);
		system("CLS");
		cout << "What would you like to see?" << endl << endl;
		cout << "1. The General results from the survey regarding quantity of E-waste generated" << endl << endl;
		cout << "2. The substance wise breakup of E-waste generated" << endl << endl;
		cout << "3. Display how the E-waste should be processed prior to dedicated treatment of each substance/ group of substances" << endl << endl;
		cout << "4. Display the best processes required to treat the given E-waste" << endl << endl;
		//more options to follow
		cin >> option;
		int u = option, flag=1;
		for (; option >0; option++)
		{
			u = option;
			if (option >= 3 && flag != 0)	HelperFunctions::ConvertperCycle();
			switch (option)
			{
			case 1:
			{
				system("CLS");
				Display::GeneralResults();
				cout << endl << endl << "Would you like to continue to \"Subtance wise breakup of E-waste generated\" or exit? Enter 1 to continue and 0 to exit" << endl << endl;
				cin >> u;
				if (u < 1)	option = -1;
				Sleep(100);
				break;
			}
			case 2:
			{
				system("CLS");
				Display::ComponentBreakup(&flag);
				cout << endl << endl << "Would you like to continue to \"Pre-processing of E-waste generated\" or exit? Enter 1 to continue and 0 to exit" << endl << endl;
				cin >> u;
				if (u < 1)	option = -1;
				Sleep(100);
				break;
			}
			case 3:
			{
				system("CLS");
				Display::PreProcessing();
				cout << endl << endl << "Would you like to continue to \"Processing of E-waste generated\" or exit? Enter 1 to continue and 0 to exit" << endl << endl;
				cin >> u;
				if (u < 1)	option = -1;
				Sleep(100);
				break;
			}
			case 4:
			{
				system("CLS");
				Display::GeneralProcessing();
				_getche();
				option = -1;
				break;
			}
			}
		}
	}

	void Settings()
	{
		int inuser;
		cout << "Note: the settings are runtime and hence temporary, so that one can evaluate various scenarios without affecting actual data. Still, be careful." << endl << endl;
		cout << "Do you want to extrapolate current data by taking current survey users as a modal class for the whole targetted population and multiplying them with a factor of your choice?" << endl<<endl;
		cout << "Press 1 for yes" << endl;
		cin >> inuser;
		cout << endl << "Enter the integral factor you want to multiply the current data with:\t";
		cin >> inuser;
		GlobalData::SettingFactor(inuser);
		Sleep(1000);
		cout << "Done!" << endl << endl;
		cout << "Press any key to move on to analysis and display" << endl;
		_getche();
		AnalysisnDisplay();
	}

}