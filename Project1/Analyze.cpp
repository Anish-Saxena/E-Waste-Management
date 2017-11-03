#include"Analyze.h"
#include "ManageData.h"
#include <stdexcept>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<string>
#include<stdio.h>

using namespace std;
using namespace ManageData;

namespace Analyze
{
	//All data is in kg	

	double GlobalData::GD[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	int GlobalData::surveytakers = 0, GlobalData::mobilenumber[2] = { 0,0 }, GlobalData::laptopnumber[2] = { 0,0 }, GlobalData::tabletnumber[2] = { 0,0 }, GlobalData::pcnumber[2] = { 0,0 };

	int GlobalData::headphonenumber[2] = { 0,0 }, GlobalData::printernumber[2] = { 0,0 }, GlobalData::joysticknumber[2] = { 0,0 },
		GlobalData::scannernumber[2] = { 0,0 }, GlobalData::webcamnumber[2] = { 0,0 }, GlobalData::smartwatchnumber[2] = { 0,0 };

	int GlobalData::totalshared[2] = { 0,0 }, GlobalData::totalgadgets[2] = { 0,0 }, GlobalData::totalperipherals[2] = { 0,0 },
		GlobalData::mobileshared[2] = { 0,0 }, GlobalData::laptopshared[2] = { 0,0 }, GlobalData::tabletshared[2] = { 0,0 }, GlobalData::pcshared[2] = { 0,0 };

	double GlobalData::preciousmetal[2] = { 0,0 }, GlobalData::metal[2] = { 0,0 }, GlobalData::nonmetal[2] = { 0,0 }, GlobalData::glassnceramics[2] = { 0,0 }, GlobalData::plastics[2] = { 0,0 };

	double GlobalData::totalewaste = 0;



	void Display::GeneralResults()
	{
		string ord[2] = { "Owned","Disposed" }, ltpm[4] = { "Laptops","Tablets","Personal Computers","Mobile Phones" };
		int i, gi = 0;
		cout << "The survey was taken by " << GlobalData::surveytakers << " users." << endl << endl;
		cout << "_____________________________________________" << endl;
		for (i = 0; i < 2; i++)
		{
			Sleep(1000);
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " are " << GlobalData::laptopnumber[i] << endl << endl; ++gi;	Sleep(100);
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " are " << GlobalData::tabletnumber[i] << endl << endl; ++gi;	Sleep(100);
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " are " << GlobalData::pcnumber[i] << endl << endl; ++gi;	Sleep(100);
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " are " << GlobalData::mobilenumber[i] << endl << endl; ++gi;	Sleep(100);
			Sleep(1000); gi = 0;
			cout << "_____________________________________________" << endl;
			cout << "The total number of " << ord[i] << " electronic gadgets are: " << GlobalData::totalgadgets[i] << endl << endl;
			cout << "_____________________________________________" << endl;
			Sleep(1000);
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " shared are " << GlobalData::laptopshared[i] << endl << endl; ++gi;	Sleep(100);
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " shared are " << GlobalData::tabletshared[i] << endl << endl; ++gi;	Sleep(100);
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " shared are " << GlobalData::pcshared[i] << endl << endl; ++gi;	Sleep(100);
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " shared are " << GlobalData::mobileshared[i] << endl << endl; ++gi;	Sleep(100);
			Sleep(1000); gi = 0;
			cout << "_____________________________________________" << endl;
			cout << "The total number of " << ord[i] << " electronic gadgets shared are: " << GlobalData::totalshared[i] << endl << endl;
			cout << "_____________________________________________" << endl;
			Sleep(1000);
			cout << "The average number of various electronic equipments " << ord[i] << " per person are:" << endl << endl;
			cout << "_____________________________________________" << endl;
			Sleep(1000);
			//I've assumed that each electronic item marked as shared is on average shared b/w 2 persons
			cout << ltpm[gi] << ": " << std::setprecision(2) << ((float)GlobalData::laptopnumber[i] / (GlobalData::surveytakers + GlobalData::laptopshared[i])) << endl << endl; ++gi;	Sleep(100);
			cout << ltpm[gi] << ": " << std::setprecision(2) << ((float)GlobalData::tabletnumber[i] / (GlobalData::surveytakers + GlobalData::tabletshared[i])) << endl << endl; ++gi;	Sleep(100);
			cout << ltpm[gi] << ": " << std::setprecision(2) << ((float)GlobalData::pcnumber[i] / (GlobalData::surveytakers + GlobalData::pcshared[i])) << endl << endl; ++gi;	Sleep(100);
			cout << ltpm[gi] << ": " << std::setprecision(2) << ((float)GlobalData::mobilenumber[i] / (GlobalData::surveytakers + GlobalData::mobileshared[i])) << endl << endl; ++gi;	Sleep(100);
			Sleep(1000); gi = 0;
			cout << "_____________________________________________" << endl;
			cout << "The number of " << ord[i] << " Headphones are " << GlobalData::headphonenumber[i] << endl << endl;	Sleep(100);
			cout << "The number of " << ord[i] << " Scanners are " << GlobalData::scannernumber[i] << endl << endl;	Sleep(100);
			cout << "The number of " << ord[i] << " Prineter are " << GlobalData::printernumber[i] << endl << endl;	Sleep(100);
			cout << "The number of " << ord[i] << " Joysticks are " << GlobalData::joysticknumber[i] << endl << endl;	Sleep(100);
			cout << "The number of " << ord[i] << " Webcams are " << GlobalData::webcamnumber[i] << endl << endl;	Sleep(100);
			cout << "The number of " << ord[i] << " Smartwatches are " << GlobalData::smartwatchnumber[i] << endl << endl;	Sleep(100);
			Sleep(1000);
			cout << "_____________________________________________" << endl;
			cout << "The total number of " << ord[i] << " peripherals are: " << GlobalData::totalperipherals[i] << endl << endl;
			cout << "_____________________________________________" << endl;

		}
		Sleep(1000);

	}


	void Display::ComponentBreakup()
	{
		cout << "Let us now see how much of each substance, be it metal, glass, ceramics, etc., is approximately present (in total) in this E-waste:" << endl << endl;
		cout << "The amount of each substance in kg is as follows: " << endl << endl;
		cout << "Elements by their amount in E-waste:" << endl << endl;

		string substance[16] = { "Gold","Mercury","Copper","Plastics","Ceramics","Steel","Lithium","Lead","Carbon","Glass","Silver","Nickel","Aluminum","Magnesium","Electrolyte","Silicon" };

		int i;
		Sleep(1000);
		for (i = 0; i < 16; i++)
		{
			Sleep(100);
			printf("%-30s%.6lf\tkg\n", substance[i].c_str(), GlobalData::GD[i]);

		}
		printf("\n%.4lf kg of total E-waste has been produced collectively in this survey", GlobalData::totalewaste);
		cout << endl << endl << "The E-Waste contains: " << endl << endl;
		printf("%.4lf kg of Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::metal[1], (GlobalData::metal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Precious Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::preciousmetal[1], (GlobalData::preciousmetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Non Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::nonmetal[1], (GlobalData::nonmetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Glass and ceramics, that is, %.2lf%c of total E-waste\n\n", GlobalData::glassnceramics[1], (GlobalData::glassnceramics[0]), 37);	Sleep(100);

		printf("%.4lf kg of Plastics, that is, %.2lf%c of total E-waste\n\n", GlobalData::plastics[1], (GlobalData::plastics[0]), 37);	Sleep(100);
	}


	void Display::PreProcessing()
	{
		cout << "Preprocessing of e-waste is one of the most important steps in the E-waste treatment chain." << endl << endl;
		Sleep(1000);
		cout << " The non-usable components are dismantled at the collection facilities prior to sending to the treatment plant.";
		cout << " Mechanical processing is an integrated part of this stage where E-waste scrap is shredded into pieces using hammer mills.";
		cout << " Metals and non-metals are separated during this stage using techniques similar to that used in the";
		cout << "	mineral dressing, e.g., screening, magnetic, eddy current and density separation techniques" << endl << endl;
		Sleep(1000);
		cout << "Since this project aims to manage the E-waste from the time it is collected, the first crucial step, Preprocessing, has been illustrated. It involves the following steps:" << endl << endl;
		Sleep(1000);
		cout << "Sorting and Dismantling\t------>\tSeperation of Re-usable parts" << endl;
		int i;
		for (i = 0; i<10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Mechanical Processing\t------>\tSeperation of wirings metals and plastics" << endl;
		for (i = 0; i<10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Vibrating Screen" << endl;
		for (i = 0; i<10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Magnetic Seperation\t------>\tSeperation of Ferrous metals" << endl;
		for (i = 0; i<10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Eddy current seperation\t------>\tSeperation of Non-Ferrous metals" << endl;
		for (i = 0; i<10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Density Seperation\t------>\tSeperation of Plastics" << endl;
		for (i = 0; i<10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Disposalt\t------>\tLandfills" << endl;
	}


	void Display::GeneralProcessing()
	{
		cout << "This software will try to project solutions based on 3 major conditions:\n\n1. Inputs Provided\n2. Economic factors\n3. Environmental factors";
		cout << endl << endl;	Sleep(1000);
		cout << "Let's now analyze the contents of given E-waste:\n\n";
		cout << "Checking the level of various substances in given E-waste:\n\n";
		char MNPRG[] = { 'M','N','P','R','G' };
		int i = 0;
		while (i < 5)
		{
			HelperFunctions::WhatLevel(MNPRG[i]);	Sleep(1000);
			i++;
		}
		cout << "Knowing about presence levels of various substance, it's time to move on to determine best of course of action for specific type of substances, keeping in mind the 3 conditions." << endl;
		cout << "Hence, for what type of materials would you like to see the best processes?" << endl << endl;
		cout << "1. Metals\n2. Non Metals" << endl << endl;
		cin >> i;
		system("CLS");
		if (i == 1)	Display::MetalProcessing();
		else if (i == 2)	Display::NonMetalProcessing();
	}

	void BestProcess::Metals()
	{
		;
	}


	void BestProcess::NonMetals()
	{
		;
	}


	void Display::MetalProcessing()
	{

		cout << "The metal fractions separated from e-waste during preprocessing can be further processed using";
		cout << " hydrometallurgical, pyrometallurgical, electrometallurgical, biometallurgical processes, and their";
		cout << " combinations. The hydrometallurgical and pyrometallurgical processes are the major routes for";
		cout << " processing of E-waste. These routes may be followed by electrometallurgical/electrochemical processes";
		cout << " (for example electrorefining or electrowinning) for selected metal separation and recovery.";
		cout << " Currently, there are only limited laboratory studies for e-waste processing through biometallurgical routes,";
		cout << " e.g., bioleaching of metals from e-waste. Nevertheless, this route has a potential for further development.";
		cout << " This project focusses on efficient treatment of E-waste using hydrometallurgical and pyrometallurgical processes." << endl << endl;

		cout << " The preprocessing of E-waste is not always required for pyrometallurgical routes.";
		cout << " However for hydrometallurgical routes, preprocessing is required to separate metal fractions from other fractions.";
		cout << " This will enhance the efficiency of each step associated with hydrometallurgical routes.";
		cout << " Each route has advantages and disadvantages and this project will try to select the best combinations of both routes to both reduce costs";
		cout << " and have minimum carbon footprint as well, so as to create as much efficient design as possible." << endl << endl;
	}


	void Display::NonMetalProcessing()
	{
		;
	}


	void HelperFunctions::WhatLevel(char i)
	{
		switch (i)
		{
		case 'R':
		{
			cout << "Precious metals comprise Gold and Silver. The threshold for precious metal presence level by weight percentage are as follows:" << endl << endl;
			cout << "1. High : if level is >=1%" << endl;
			cout << "1. Normal : if level is <1% and >=0.4%" << endl;
			cout << "1. Low : if level is <0.4%" << endl;
			cout << "The level of Precious metals in the given survey is:\n\n";

			if (GlobalData::preciousmetal[0] >= 1)
				cout << "HIGH: ";
			else if (GlobalData::preciousmetal[0] < 1 && GlobalData::preciousmetal[0] >= 0.4)
				cout << "NORMAL: ";
			else
				cout << "LOW: ";
			cout << std::fixed << std::setprecision(2) << GlobalData::preciousmetal[0] << "% detected" << endl << endl;
			break;
		}
		case 'M':
		{
			cout << "Metals comprise Gold, Mercury, Copper, Steel, Lithium, Lead, Silver, Nickel, Aluminum and Magnesium. The threshold for metal presence level by weight percentage are as follows:" << endl << endl;
			cout << "1. High : if level is >=55%" << endl;
			cout << "1. Normal : if level is <55% and >=45%" << endl;
			cout << "1. Low : if level is <45%" << endl;
			cout << "The level of Metals in the given survey is:\n\n";


			if (GlobalData::metal[0] >= 55)
				cout << "HIGH: ";
			else if (GlobalData::metal[0] < 55 && GlobalData::metal[0] >= 45)
				cout << "NORMAL: ";
			else
				cout << "LOW: ";
			cout << std::fixed << std::setprecision(2) << GlobalData::metal[0] << "% detected" << endl << endl;
			break;
		}
		case 'N':
		{
			cout << "Non Metals comprise Plastics, Ceramics, Carbon, Glass, Electrolytes and Silicon. The threshold for non metal presence level by weight percentage are as follows:" << endl << endl;
			cout << "1. High : if level is >=50%" << endl;
			cout << "1. Normal : if level is <50% and >=40%" << endl;
			cout << "1. Low : if level is <40%" << endl;
			cout << "The level of Metals in the given survey is:\n\n";

			if (GlobalData::nonmetal[0] >= 50)
				cout << "HIGH: ";
			else if (GlobalData::nonmetal[0] < 50 && GlobalData::nonmetal[0] >= 40)
				cout << "NORMAL: ";
			else
				cout << "LOW: ";
			cout << std::fixed << std::setprecision(2) << GlobalData::nonmetal[0] << "% detected" << endl << endl;
			break;
		}
		case 'P':
		{
			cout << "The threshold for plastics presence level by weight percentage are as follows:" << endl << endl;
			cout << "1. High : if level is >=20%" << endl;
			cout << "1. Normal : if level is <20% and >=12%" << endl;
			cout << "1. Low : if level is <12%" << endl;
			cout << "The level of Metals in the given survey is:\n\n";

			if (GlobalData::plastics[0] >= 20)
				cout << "HIGH: ";
			else if (GlobalData::plastics[0] < 20 && GlobalData::plastics[0] >= 12)
				cout << "NORMAL: ";
			else
				cout << "LOW: ";
			cout << std::fixed << std::setprecision(2) << GlobalData::plastics[0] << "% detected" << endl << endl;
			break;
		}
		case 'G':
		{
			cout << "Glass and Ceramics comprise Ceramics, Glass and Silicon. The threshold for Glass and Ceramics presence level presence level by weight percentage are as follows:" << endl << endl;
			cout << "1. High : if level is >=30%" << endl;
			cout << "1. Normal : if level is <30% and >=25%" << endl;
			cout << "1. Low : if level is <25%" << endl;
			cout << "The level of Metals in the given survey is:\n\n";



			if (GlobalData::metal[0] >= 55)
				cout << "HIGH: ";
			else if (GlobalData::metal[0] < 55 && GlobalData::metal[0] >= 45)
				cout << "NORMAL: ";
			else
				cout << "LOW: ";
			cout << std::fixed << std::setprecision(2) << GlobalData::metal[0] << "% detected" << endl << endl;
			break;
		}

		}
	}

	void BestProcess::DefineProcess()
	{
		;
	}

}