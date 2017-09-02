#include<iostream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<dos.h>
using namespace std;
void NewForm();       //function to feed data from users through forms
void Segregate();     //function to sgregate form data about e-waste into categories of e-waste
void DisplayInfo();   //function to display analysed data to users
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
		//call function for form based feed
	}
	case 2:
	{
		//call analysis functions, display results, etc
	}
	} 
	_getch();
	return 0;
}