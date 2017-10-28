#include<iostream>
#include<conio.h>
#include<windows.h>
#include"Screens.h"
#include"ManageData.h"

using namespace std;
using namespace System;
using namespace Welcome;

int main()
{
	//Welcome Screen
	system("color B2");
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
	}
	system("CLS");
	cout << "Press any key to exit" << endl;
	_getch();
	return 0;
}