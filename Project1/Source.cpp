#include<iostream>
#include<conio.h>
#include<windows.h>
#include"Screens.h"
#include"ManageData.h"

using namespace std;
using namespace System;
using namespace Welcome;
using namespace ManageData;

int main()
{
	//Welcome Screen
	system("color F0");
	//Welcomescreen();
	int choice = Choice(choice);
	if (choice != 1)
	{
		DataManip::ChecknSum();
		DataManip::AggregateSum();
	}
	switch (choice)
	{
	case 1:
	{
		//Display survey form
		RunForm();		
		break;
	}
	case 2:
	{
		//call analysis functions, display results, etc
		AnalysisnDisplay();
		break;
	}
	case 3:
	{
		Settings();
		break;
	}
	}
	system("CLS");
	cout << "Press any key to exit" << endl;
	_getch();
	return 0;
}