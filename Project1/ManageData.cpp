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

	//Array index to substance mapping:
	//0 is gold, 1 is mercury, 2 is copper, 3 is plastics, 4 is ceramics,5 is steel, 6 is lithium, 7 is lead, 8 is carbon, 
	//9 is glass, 10 is silver, 11 is nickel, 12 is aluminum, 13 is magnesium, 14 is electrolyte, 15 is silicon

	//Gadgets:

	//FOR LAPTOP DATA:	
	const double LaptopData::LD[16] = { 0.000775 ,0.000297,0.0786, 0.225 ,0.155,0.035,0.007,0.001524,0.025,0.332,0.0055,0.001024,0.215,0.525,0.055,0.01 };

	//FOR MOBILE DATA:	
	const double MobileData::MD[16] = { 0.000210 ,0.0001 ,0.0153 ,0.025,0.021,0.010,0.003 ,0.00005,0.005,0.072 ,0.0012 ,0.0002,0.035,0.015,0.0001 ,0.005 };
	
	//FOR PC DATA:
	const double PCData::PCD[16] = { 0.001075 ,0.001412 ,0.1234 ,0.735 ,0.214 ,0.053,0.013 ,0.002425,0.040,0.361,0.0067,0.001218,0.331,0.617,0.075,0.012 };

	//FOR TABLET DATA:
	const double TabletData::TD[16] = { 0.000215 ,0.0001 ,0.0214,0.067 ,0.041 ,0.010,0.004 ,0.00025,0.005,0.091,0.0015,0.00029,0.040,0.065,0.0001,0.006 };

	//Peripherals:

	//FOR HEADPHONE DATA:	
	const double HeadphoneData::HD[16] = { 0.0001 ,0,0.012 ,0.075,0.005 ,0.015 ,0,0.000005 ,0.004 ,0.004 ,0.0062,0.00003,0.060,0.040,0, 0.002 };

	//FOR SCANNER DATA:
	const double ScannerData::SD[16] = { 0.000575 ,0.00355,0.080 ,0.275 ,0.125,0.02,0, 0.003256,0.005 ,0.340,0.0032,0.0002,0.110,0.265,0,0.004 };

	//FOR PRINTER DATA:
	const double PrinterData::PD[16] = { 0.000575 ,0.00355 ,0.080,0.320 ,0.150 ,0.04 ,0,0.003256,0.045 ,0.280,0.0067,0.0002,0.210, 0.170 ,0,0.004 };

	//FOR JOYSTICK DATA:
	const double JoystickData::JD[16] = { 0.0001 ,0,0.01 ,0.065 ,0.015 ,0.01 ,0.002 ,0.000005 ,0.005 ,0.01,0.0045,0.00002,0.048,0.045,0, 0.003 };

	//FOR WEBCAM DATA:
	const double WebcamData::WD[16] = { 0.000150 ,0,0.012,0.030,0.012,0.005,0,0,0, 0.020 ,0.0015 ,0,0.040 ,0.01 ,0,0.001 };

	//FOR SMARTWATCH DATA:
	const double SmartwatchData::SWD[16] = { 0.000210 ,0.0001,0.0153,0.040,0.005,0.005,0.002,0.00004 ,0.004 ,0.02 ,0.001,0.0001 ,0.005,0.01,0.0001 ,0.004 };

	//DataManip
	void DataManip::ChecknSum() //primitive version for testing
	{
		ifstream f;
		f.open("TestUsersNew.csv", ios::in);
		string s;
		char a;
		int x, i;
		getline(f, s, '\n');
		getline(f, s, '\n');
		while (!f.eof())
		{
			GlobalData::surveytakers++;
			getline(f, s, ';');
			f >> x;
			f >> a;
			getline(f, s, ';');			
			for (i = 0; i < 2; i++)
			{
				f >> x;
				GlobalData::mobilenumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::laptopnumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::tabletnumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::pcnumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::mobileshared[i] += x;
				f >> a;
				f >> x;
				GlobalData::laptopshared[i] += x;
				f >> a;
				f >> x;
				GlobalData::tabletshared[i] += x;
				f >> a;
				f >> x;
				GlobalData::pcshared[i] += x;
				f >> a;
				f >> x;
				GlobalData::headphonenumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::printernumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::joysticknumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::scannernumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::webcamnumber[i] += x;
				f >> a;
				f >> x;
				GlobalData::smartwatchnumber[i] += x;
				f >> a;									
			}					
		}	
		for (i = 0; i < 2; i++)
		{
			GlobalData::totalshared[i] = GlobalData::mobileshared[i] + GlobalData::laptopshared[i] + GlobalData::tabletshared[i] + GlobalData::pcshared[i];
			GlobalData::totalgadgets[i] = GlobalData::mobilenumber[i] + GlobalData::laptopnumber[i] + GlobalData::tabletnumber[i] + GlobalData::pcnumber[i];
			GlobalData::totalperipherals[i] = GlobalData::headphonenumber[i] + GlobalData::scannernumber[i] + GlobalData::printernumber[i] +
												GlobalData::smartwatchnumber[i] + GlobalData::joysticknumber[i] + GlobalData::webcamnumber[i];
		}
	}
	void DataManip::AggregateSum()
	{
		int i;
		for (i = 0; i < 16; i++)
		{
			GlobalData::GD[i] = LaptopData::LD[i] * GlobalData::laptopnumber[1] + MobileData::MD[i] * GlobalData::mobilenumber[1] +
				TabletData::TD[i] * GlobalData::tabletnumber[1] + PCData::PCD[i] * GlobalData::pcnumber[1] + HeadphoneData::HD[i] * GlobalData::headphonenumber[1] +
				ScannerData::SD[i] * GlobalData::scannernumber[1] + PrinterData::PD[i] * GlobalData::printernumber[1] + JoystickData::JD[i] * GlobalData::joysticknumber[1] +
				WebcamData::WD[i] * GlobalData::webcamnumber[1] + SmartwatchData::SWD[i] * GlobalData::smartwatchnumber[1];

			GlobalData::totalewaste += GlobalData::GD[i];
		}

		GlobalData::metal[1] = GlobalData::GD[0] + GlobalData::GD[1] + GlobalData::GD[2] + GlobalData::GD[5] + GlobalData::GD[6] + GlobalData::GD[7] +
			GlobalData::GD[10] + GlobalData::GD[11] + GlobalData::GD[12] + GlobalData::GD[13];
		GlobalData::nonmetal[1] = GlobalData::GD[3] + GlobalData::GD[4] + GlobalData::GD[8] + GlobalData::GD[9] + GlobalData::GD[14] + GlobalData::GD[15];
		GlobalData::glassnceramics[1] = GlobalData::GD[4] + GlobalData::GD[9] + GlobalData::GD[15];
		GlobalData::preciousmetal[1] = GlobalData::GD[0] + GlobalData::GD[10];		
		GlobalData::plastics[1] = GlobalData::GD[3];

		GlobalData::metal[0] = GlobalData::metal[1] * 100 / GlobalData::totalewaste;
		GlobalData::nonmetal[0] = GlobalData::nonmetal[1] * 100 / GlobalData::totalewaste;
		GlobalData::preciousmetal[0] = GlobalData::preciousmetal[1] * 100 / GlobalData::totalewaste;
		GlobalData::glassnceramics[0] = GlobalData::glassnceramics[1] * 100 / GlobalData::totalewaste;
		GlobalData::plastics[0] = GlobalData::plastics[1] * 100 / GlobalData::totalewaste;
	}
}