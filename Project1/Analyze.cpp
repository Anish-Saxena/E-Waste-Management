#include"Analyze.h"
#include "ManageData.h"
#include <stdexcept>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include<string.h>

using namespace std;
using namespace ManageData;

void PrintWidth(const char* t, double x)
{
	cout<<  t << "\t\t" << x <<" kg"<< endl;
}

namespace Analyze
{
	//Testing phase (7th Oct 2017), say the given data values are obtained after ManageData functions act on user surveys, 
	//assigning hard coded values for testing purposes to the variables to showcase Analyze functions. Values represent 
	//about 15 laptops, 25 mobile phones-tablets and 5-10 computers worth of E-waste

	//All data is in kg

	double GlobalData::gold = 0.0194, GlobalData::aluminum = 7.452, GlobalData::carbon = 0.945, GlobalData::copper = 2.541, GlobalData::electrolyte = 1.512, 
	GlobalData::glass = 10.11, GlobalData::lead = 0.051, GlobalData::lithium = 0.255, GlobalData::magnesium = 17.8, GlobalData::mercury = 0.0068, GlobalData::ceramics=5.435,
	GlobalData::nickel = 0.0291, GlobalData::plastics = 8.11, GlobalData::silicon = 0.41, GlobalData::silver = 0.175, GlobalData::steel = 1.04;

	int GlobalData::surveytakers = 21, GlobalData::laptopnumber = 16, GlobalData::mobilenumber = 24, GlobalData::pcnumber = 7, GlobalData::tabletnumber=7;
	
	int GlobalData::laptopshared = 3, GlobalData::mobileshared = 2, GlobalData::tabletshared = 4, GlobalData::pcshared = 5;
	int GlobalData::totalshared = GlobalData::laptopshared + GlobalData::mobileshared + GlobalData::pcshared + GlobalData::tabletshared;

	void BestProcess::Metals()
	{
		;
	}
	void Display::GeneralResults()
	{
		cout << "The survey was taken by " << GlobalData::surveytakers << " users." << endl << endl;
		Sleep(1000);
		cout << "The total number of electronic gadgets shared are: " << GlobalData::totalshared << endl << endl;
		Sleep(1000);
		cout << "The number of Laptops shared is: " << GlobalData::laptopshared << endl << endl;
		Sleep(1000);
		cout << "The number of Tablets shared is: " << GlobalData::tabletnumber << endl << endl;
		Sleep(1000);
		cout << "The number of Personal computers shared is: " << GlobalData::pcshared << endl << endl;
		Sleep(1000);
		cout << "The number of Mobile Phones shared is: " << GlobalData::mobileshared << endl << endl;
		Sleep(1000);
		cout << "The average number of various electronic equipments owned per person are:" << endl << endl;
		Sleep(1000);
		//Now, I've assumed that each electronic item marked as shared is on average shared b/w 2 persons
		cout << "Laptops: " << std::setprecision(2) << ((float)GlobalData::laptopnumber / (GlobalData::surveytakers+GlobalData::laptopshared)) << endl << endl;
		Sleep(1000);
		cout << "Tablets: " << std::setprecision(2) << ((float)GlobalData::tabletnumber / (GlobalData::surveytakers+GlobalData::tabletshared)) << endl << endl;
		Sleep(1000);
		cout << "Personal Computers: " << std::setprecision(2) << ((float)GlobalData::pcnumber / (GlobalData::surveytakers+GlobalData::pcshared)) << endl << endl;
		Sleep(1000);
		cout << "Mobile Phones: " << std::setprecision(2) << ((float)GlobalData::mobilenumber / (GlobalData::surveytakers+GlobalData::mobileshared)) << endl << endl;				
		Sleep(1000);
		cout << "Let us now see how much of each substance, be it metal, glass, ceramics, etc., is approximately present (in total) in this E-waste:" << endl << endl;
		Sleep(1000);
		cout << "Press any key to continue to the next screen" << endl;
		_getch();
		ComponentBreakup();
	}
	void Display::ComponentBreakup()
	{
		system("CLS");
		cout << "The amount of each substance in kg is as follows: " << endl << endl;
		Sleep(1000);
		cout << "Trace elements by their amount in E-waste:" << endl << endl;
		Sleep(1000);
		PrintWidth("Gold", GlobalData::gold);		
		PrintWidth("Mercury", GlobalData::mercury);
		PrintWidth("Lead", GlobalData::lead);
		PrintWidth("Nickel", GlobalData::nickel);
		Sleep(1000);
		cout << endl << "Fairly abundant elements by their amount in E-waste:" << endl << endl;
		PrintWidth("Silver", GlobalData::silver);
		PrintWidth("Silicon", GlobalData::silicon);
		PrintWidth("Carbon", GlobalData::carbon);
		PrintWidth("Lithium", GlobalData::lithium);
		Sleep(1000);
		cout << endl << "Very Abundant elements by their amount in E-waste: " << endl << endl;
		PrintWidth("Steel", GlobalData::steel);
		PrintWidth("Plastics", GlobalData::plastics);
		PrintWidth("Ceramics", GlobalData::ceramics);
		PrintWidth("Aluminum", GlobalData::aluminum);
		PrintWidth("Copper", GlobalData::copper);
		PrintWidth("Electrolyte", GlobalData::electrolyte);
		PrintWidth("Magnesium", GlobalData::magnesium);
		PrintWidth("Glass", GlobalData::glass);
	}
}