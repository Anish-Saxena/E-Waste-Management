#include<iostream>
#include<conio.h>
#include<windows.h>
#include"Screens.h"
#include"ManageData.h"
#include"Analyze.h"

using namespace std;
using namespace System;
using namespace Welcome;
using namespace ManageData;
using namespace Analyze;

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
	}/*
	DataManip::ChecknSum();
	cout << endl << GlobalData::tabletnumber[0];
	_getche();*/
	system("CLS");
	cout << "Press any key to exit" << endl;
	_getch();
	return 0;
}