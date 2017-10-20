#include "ManageData.h"
#include"Analyze.h"
#include <stdexcept>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<string>
#include<Windows.h>

using namespace std;
using namespace Analyze;

namespace ManageData
{
	//All data is in kg

	
	//FOR LAPTOP DATA:
	const double LaptopData::gold = 0.000775, LaptopData::mercury = 0.000297, LaptopData::copper = 0.078591, LaptopData::plastics = 0.225, LaptopData::ceramics = 0.155,
	LaptopData::steel = 0.035, LaptopData::lithium = 0.007, LaptopData::lead = 0.001524, LaptopData::carbon = 0.025, LaptopData::glass = 0.332, LaptopData::silver = 0.0055,
	LaptopData::nickel = 0.001024, LaptopData::aluminum = 0.215, LaptopData::magnesium = 0.525, LaptopData::electrolyte = 0.055, LaptopData::silicon= 0.01;

	//FOR MOBILE DATA:
	
	//FOR PC DATA:

	//FOR TABLET DATA:
	

	//DataManip
	void DataManip::ChecknSum() //primitive version for testing
	{
		ifstream f;
		f.open("TestUsersNew.csv", ios::in);
		string s;
		char a;
		int x;		
		getline(f, s, '\n');
		getline(f, s, '\n');
		while (!f.eof())
		{
			getline(f, s, ';');
			f >> x;
			f >> a;
			getline(f, s, ';');
			f >> x;			
			GlobalData::mobilenumber += x;
			f >> a;
			f >> x;			
			GlobalData::laptopnumber += x;
			getline(f, s, '\n');			
		}
		cout << GlobalData::mobilenumber << endl << GlobalData::laptopnumber;
	}
}