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
#include<math.h>

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

	double GlobalData::preciousmetal[2] = { 0,0 }, GlobalData::metal[2] = { 0,0 }, GlobalData::nonmetal[2] = { 0,0 }, GlobalData::glassnceramics[2] = { 0,0 },
		 GlobalData::plastics[2] = { 0,0 }, GlobalData::basemetal[2] = { 0,0 }, GlobalData::hazardousmetal[2] = { 0,0 };

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


	void Display::ComponentBreakup(int *flag)
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
		printf("%.4lf kg of Base Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::basemetal[1], (GlobalData::basemetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Hazardous Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::hazardousmetal[1], (GlobalData::hazardousmetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Non Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::nonmetal[1], (GlobalData::nonmetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Glass and ceramics, that is, %.2lf%c of total E-waste\n\n", GlobalData::glassnceramics[1], (GlobalData::glassnceramics[0]), 37);	Sleep(100);
		printf("%.4lf kg of Plastics, that is, %.2lf%c of total E-waste\n\n", GlobalData::plastics[1], (GlobalData::plastics[0]), 37);	Sleep(100);
		cout << "Press any key to continue." << endl;
		_getche();
		system("CLS");
		printf("Now, %d users dump %.4lf kg of E-Waste every two years, or about %.4lf kg of E-waste on average every 4 day, since 4 days is the normal cycle of treating",GlobalData::surveytakers,GlobalData::totalewaste,GlobalData::totalewaste/182.5);
		printf(" batch of E-waste in a regular treatment plant.\n\n");
		cout << "Obviously, the plant works on a cycle basis of approximately 4 days each, to conduct all the processes involved for all substances present.";
		cout << " Given the plant gets a steady stream of regularly collected E-waste, it will run for about 360 cycles in our survey period of 2 years." << endl;
		HelperFunctions::ConvertperCycle();
		*flag = 0;
		cout << "Hence, the amount of E-waste produced in the given survey per cycle is as follows:\n\n";
		printf("\n%.4lf kg of total E-waste has been produced collectively in this survey per cycle", GlobalData::totalewaste);
		cout << endl << endl << "The E-Waste contains: " << endl << endl;
		printf("%.4lf kg of Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::metal[1], (GlobalData::metal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Precious Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::preciousmetal[1], (GlobalData::preciousmetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Base Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::basemetal[1], (GlobalData::basemetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Hazardous Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::hazardousmetal[1], (GlobalData::hazardousmetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Non Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::nonmetal[1], (GlobalData::nonmetal[0]), 37);	Sleep(100);
		printf("%.4lf kg of Glass and ceramics, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::glassnceramics[1], (GlobalData::glassnceramics[0]), 37);	Sleep(100);
		printf("%.4lf kg of Plastics, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::plastics[1], (GlobalData::plastics[0]), 37);	Sleep(100);
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
		for (i = 0; i < 10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Mechanical Processing\t------>\tSeperation of wirings metals and plastics" << endl;
		for (i = 0; i < 10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Vibrating Screen" << endl;
		for (i = 0; i < 10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Magnetic Seperation\t------>\tSeperation of Ferrous metals" << endl;
		for (i = 0; i < 10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Eddy current seperation\t------>\tSeperation of Non-Ferrous metals" << endl;
		for (i = 0; i < 10; ++i)
		{
			cout << "\t" << (char)0xB3;
			cout << '\n';
		}
		cout << "\t\\/\n";
		cout << "Density Seperation\t------>\tSeperation of Plastics" << endl;
		for (i = 0; i < 10; ++i)
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
		char MNPRGBH[] = { 'M','N','P','R','G','B','H' };
		int i = 0;
		while (i < 7)
		{
			HelperFunctions::WhatLevel(MNPRGBH[i]);	Sleep(1000);
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
		//Start with precious metals
		double samount, tamount, typecost, type, stage, init, cit;
		samount = GlobalData::preciousmetal[1];
		tamount = GlobalData::totalewaste;
		typecost = TypeCost::preciousm;
		type = 'P';
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
		Sleep(1000);
		cout << " The preprocessing of E-waste is not always required for pyrometallurgical routes.";
		cout << " However for hydrometallurgical routes, preprocessing is required to separate metal fractions from other fractions.";
		cout << " This will enhance the efficiency of each step associated with hydrometallurgical routes.";
		cout << " Each route has advantages and disadvantages and this project will try to select the best combinations of both routes to both reduce costs";
		cout << " and have minimum carbon footprint as well, so as to create as much efficient design as possible." << endl << endl;
		Sleep(1000);
		cout << "Before delving into the in-depth analysis, some of the parameters must be specified by the administrator who is is calling for this analysis";
		cout << " as per the economic and environmental situation of the locality the survey was taken in. These parameters will be fundamental to determining";
		cout << "The best way to manage the E-waste at hand." << endl << endl;
		Sleep(1000);
		cout << "It is assumed that the cost of running the E-waste management plant would be born by the locality (through addition in maintainance costs or taxes) ";
		cout<<"and hence, it is advised to carefully read the approximate costs";
		cout << " associated with various plant sizes as per the E-waste amount, and select what level of economic liberty this software can take when assessing your case." << endl << endl;
		cout << "Small plants:\n\nFor total E-waste upto about 200kg per day, from about 25,000 users typically (per year), carries an economic cost of about Rs. 30,00,000 per annum for 10 years\n\n";
		cout << "The residents will pay about that cost Rs. 650 per month.";
		cout << endl << endl;
		cout << "Medium sized plants";
		//^LOOK AT IT
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



			if (GlobalData::glassnceramics[0] >= 30)
				cout << "HIGH: ";
			else if (GlobalData::glassnceramics[0] < 30 && GlobalData::glassnceramics[0] >= 25)
				cout << "NORMAL: ";
			else
				cout << "LOW: ";
			cout << std::fixed << std::setprecision(2) << GlobalData::glassnceramics[0] << "% detected" << endl << endl;
			break;
		}
		case 'B':
		{
			cout << "Base Metals comprise Copper, Steel, Lithium, Aluminum and Magnesium. The threshold for Base Metal presence level presence level by weight percentage are as follows:" << endl << endl;
			cout << "1. High : if level is >=50%" << endl;
			cout << "1. Normal : if level is <50% and >=45%" << endl;
			cout << "1. Low : if level is <45%" << endl;
			cout << "The level of Metals in the given survey is:\n\n";



			if (GlobalData::basemetal[0] >= 50)
				cout << "HIGH: ";
			else if (GlobalData::basemetal[0] < 50 && GlobalData::basemetal[0] >= 45)
				cout << "NORMAL: ";
			else
				cout << "LOW: ";
			cout << std::fixed << std::setprecision(2) << GlobalData::basemetal[0] << "% detected" << endl << endl;
			break;
		}
		case 'H':
		{
			cout << "Hazardous Metals comprise Mercury, Lead and Nickel. The threshold for Hazardous Metal presence level presence level by weight percentage are as follows:" << endl << endl;
			cout << "1. High : if level is >=0.25%" << endl;
			cout << "1. Normal : if level is <0.25% and >=0.05%" << endl;
			cout << "1. Low : if level is <0.05%" << endl;
			cout << "The level of Metals in the given survey is:\n\n";



			if (GlobalData::hazardousmetal[0] >= 0.25)
				cout << "HIGH: ";
			else if (GlobalData::hazardousmetal[0] < 0.25 && GlobalData::hazardousmetal[0] >= 0.05)
				cout << "NORMAL: ";
			else
				cout << "LOW: ";
			cout << std::fixed << std::setprecision(2) << GlobalData::hazardousmetal[0] << "% detected" << endl << endl;
			break;
		}
		}
	}


	void HelperFunctions::ConvertperCycle()
	{
		GlobalData::metal[1] = GlobalData::metal[1] / 180.0;
		GlobalData::nonmetal[1] = GlobalData::nonmetal[1] / 180.0;
		GlobalData::glassnceramics[1] = GlobalData::glassnceramics[1] / 180.0;
		GlobalData::plastics[1] = GlobalData::plastics[1] / 180.0;
		GlobalData::basemetal[1] = GlobalData::basemetal[1] / 180.0;
		GlobalData::preciousmetal[1] = GlobalData::preciousmetal[1] / 180.0;
		GlobalData::hazardousmetal[1] = GlobalData::hazardousmetal[1] / 180.0;
		GlobalData::totalewaste = GlobalData::totalewaste / 180.0;
	}

	
	void HelperFunctions::PointCalc(struct Process s, double tamount, double samount, double typecost, char type, int stage, int init, int cit /*normalize*/)	//start init nd cit from 0
	{
		double economicpoints, environmentalpoints, relativeprocesspoints;		//Remember to normalize the points
		
		double ce = (s.efficiency*(1 + init*s.economicfactors[0])) / (init + 1);
		ce = ce*(1 + cit*s.economicfactors[1]) / (cit + 1);
		double cc;
		if (init >=19)
			cc = s.cost*(1 + cit)*(1 + init / 10.0);
		else if (init > 5 && init < 19)
			cc = s.cost*(1 + cit)*(1 + init*0.1537 - init*init*0.0034);
		else
			cc = s.cost*(1 + cit)*(1 + init / 6.67);

		if (ce > s.maxefficiency||cc>s.maxcost)
		{
			economicpoints = -1;
			environmentalpoints = -1;
			relativeprocesspoints = -1;
			return;		//edit this as per return type
		}

		double sidetreatment, sideamount;
		switch (s.othertypes.typeof)
		{
		case 'B':
		{
			sidetreatment = 50;
			sideamount = GlobalData::basemetal[1];
			break;
		}
		case 'P':
		{
			sidetreatment = 200;
			sideamount = GlobalData::preciousmetal[1];
			break;
		}
		case 'H':
		{
			sidetreatment = 200;
			sideamount = GlobalData::hazardousmetal[1];
			break;
		}
		default: sidetreatment = 0;
		}

		economicpoints = (pow(ce, 3)*samount*typecost) / cc;
		environmentalpoints = ce*s.carbonfootprint[1] * samount / s.carbonfootprint[0] + (samount / tamount);	
		relativeprocesspoints = sidetreatment*sideamount*(pow(s.othertypes.stageto, 2) - pow(s.othertypes.stagefrom, 2));
		double totalpoints = economicpoints + environmentalpoints + relativeprocesspoints;
	}

	
	void BestProcess::DefineProcess()
	{
		//Now defining processes for metals
		Process Metals[7];

		//Process 0: Ion Exchange, for Base metals, to get them from Extraction to refining phase, also makes Precious metals go from leaching to extraction

		Metals[0].information = "Ion Exchange process, Hydrometallurgy, more info soon.";
		Metals[0].category = 0;
		Metals[0].type = 'B';
		Metals[0].cost = 175000;
		Metals[0].maxcost = 1200000;
		Metals[0].efficiency = 0.92;
		Metals[0].maxefficiency = 0.99;
		Metals[0].economicfactors[0] = 1.05;
		Metals[0].economicfactors[1] = 1.05;
		Metals[0].amountinput[0] = 100;
		Metals[0].amountinput[1] = 400;
		Metals[0].carbonfootprint[0] = 55000;
		Metals[0].carbonfootprint[1] = 80000;		
		Metals[0].stagefrom = 2;
		Metals[0].stageto = 3;
		Metals[0].othertypes.stagefrom = 2;
		Metals[0].othertypes.stageto = 3;
		Metals[0].othertypes.typeof = 'P';

		//Process 1: Adsorption, for Precious metals, to get them from extraction to refining phase, doesn't act on other types of E-waste

		Metals[1].information = "Adsorption process, Hydrometallury, more info soon.";
		Metals[1].category = 0;
		Metals[1].type = 'P';		
		Metals[1].cost = 125000;
		Metals[1].maxcost = 900000;
		Metals[1].efficiency = 0.97;
		Metals[1].maxefficiency = 0.99;
		Metals[1].economicfactors[0] = 0.98;
		Metals[1].economicfactors[1] = 1.05;
		Metals[1].amountinput[0] = 1.2;
		Metals[1].amountinput[1] = 200;
		Metals[1].carbonfootprint[0] = 2500;
		Metals[1].carbonfootprint[1] = 15000;		
		Metals[1].stagefrom = 2;
		Metals[1].stageto = 3;
		Metals[1].othertypes.stagefrom = -1;
		Metals[1].othertypes.stageto = -1;
		Metals[1].othertypes.typeof = 'Z';

		//Process 2: Vat Leaching, for Precious metals, to get them from leaching to extraction phase, also makes base metals go from leaching to extraction

		Metals[2].information = "Vat Leaching, Hydrometallurgy, more info soon.";
		Metals[2].type = 'P';
		Metals[2].category = 0;
		Metals[2].cost = 75000;
		Metals[2].maxcost = 600000;
		Metals[2].efficiency = 0.85;
		Metals[2].maxefficiency = 0.90;
		Metals[2].economicfactors[0] = 0.95;
		Metals[2].economicfactors[1] = 0.8;
		Metals[2].amountinput[0] = 1.5;
		Metals[2].amountinput[1] = 200;
		Metals[2].carbonfootprint[0] = 1500;
		Metals[2].carbonfootprint[1] = 13000;
		Metals[2].stagefrom = 1;
		Metals[2].stageto = 2;
		Metals[2].othertypes.stagefrom = 1;
		Metals[2].othertypes.stageto = 2;
		Metals[2].othertypes.typeof = 'B';

		//Process 3: Caustic Leaching, for Precious metals, to get them from leaching to extraction phase, doesn't act on other types of E-waste

		Metals[3].information = "Caustic Leaching, Hydrometallurgy, more info soon.";
		Metals[3].type = 'P';
		Metals[3].category = 0;
		Metals[3].cost = 60000;
		Metals[3].maxcost = 420000;
		Metals[3].efficiency = 0.80;
		Metals[3].maxefficiency = 0.90;
		Metals[3].economicfactors[0] = 0.90;
		Metals[3].economicfactors[1] = 0.50;
		Metals[3].amountinput[0] = 1.0;
		Metals[3].amountinput[1] = 100;
		Metals[3].carbonfootprint[0] = 2000;
		Metals[3].carbonfootprint[1] = 5500;
		Metals[3].stagefrom = 1;
		Metals[3].stageto = 2;
		Metals[3].othertypes.stagefrom = -1;
		Metals[3].othertypes.stageto = -1;
		Metals[3].othertypes.typeof = 'Z';

		//Process 4: Autoclave leaching, for precious metals, to get them from leaching to extraction phase, also makes hazardous metals go from leaching to extraction

		Metals[4].information = "Autoclave leaching, Hydrometallurgy, more info soon.";
		Metals[4].type = 'P';
		Metals[4].category = 0;
		Metals[4].cost = 200000;
		Metals[4].maxcost = 1000000;
		Metals[4].efficiency = 0.95;
		Metals[4].maxefficiency = 0.999;
		Metals[4].economicfactors[0] = 1.005;
		Metals[4].economicfactors[1] = 1.005;
		Metals[4].amountinput[0] = 1.0;
		Metals[4].amountinput[1] = 100;
		Metals[4].carbonfootprint[0] = 4000;
		Metals[4].carbonfootprint[1] = 13000;
		Metals[4].stagefrom = 1;
		Metals[4].stageto = 2;
		Metals[4].othertypes.stagefrom = 1;
		Metals[4].othertypes.stageto = 2;
		Metals[4].othertypes.typeof = 'H';

		//Process 5: Shaft Furnace calcination, for base metals, to get them from Purification to recovery, also makes hazardous metals go from purifcation to recovery

		Metals[5].information = "Shaft furnace calcination, pyrometallurgy, more info soon.";
		Metals[5].type = 'B';
		Metals[5].category = 0;
		Metals[5].cost = 100000;
		Metals[5].maxcost = 500000;
		Metals[5].efficiency = 0.97;
		Metals[5].maxefficiency = 0.9999;
		Metals[5].economicfactors[0] = 1.05;
		Metals[5].economicfactors[1] = 1;
		Metals[5].amountinput[0] = 75;
		Metals[5].amountinput[1] = 150;
		Metals[5].carbonfootprint[0] = 25000;
		Metals[5].carbonfootprint[1] = 65000;
		Metals[5].stagefrom = 1;
		Metals[5].stageto = 2;
		Metals[5].othertypes.stagefrom = 1;
		Metals[5].othertypes.stageto = 2;
		Metals[5].othertypes.typeof = 'H';

		//Process 6: Shaft Furnace calcination, for base metals, to get them from Purification to recovery, also makes hazardous metals go from purifcation to recovery

		Metals[6].information = "Fluidized bed reactor, pyrometallurgy, more info soon.";
		Metals[6].type = 'B';
		Metals[6].category = 0;
		Metals[6].cost = 160000;
		Metals[6].maxcost = 760000;
		Metals[6].efficiency = 0.975;
		Metals[6].maxefficiency = 0.9999;
		Metals[6].economicfactors[0] = 1.01;
		Metals[6].economicfactors[1] = 1.01;
		Metals[6].amountinput[0] = 80;
		Metals[6].amountinput[1] = 175;
		Metals[6].carbonfootprint[0] = 40000;
		Metals[6].carbonfootprint[1] = 50000;
		Metals[6].stagefrom = 1;
		Metals[6].stageto = 2;
		Metals[6].othertypes.stagefrom = 1;
		Metals[6].othertypes.stageto = 2;
		Metals[6].othertypes.typeof = 'H';
	}


	void GlobalData::SettingFactor(int factor)
	{
		GlobalData::surveytakers = GlobalData::surveytakers*factor;
		int i;
		for (i = 0; i < 2; i++)
		{
			 
			GlobalData::mobilenumber[i] *=factor;
			 
			 
			GlobalData::laptopnumber[i] *= factor;
			 
			 
			GlobalData::tabletnumber[i] *=factor;
			 
			 
			GlobalData::pcnumber[i] *=factor;
			 
			 
			GlobalData::mobileshared[i] *=factor;
			 
			 
			GlobalData::laptopshared[i] *=factor;
			 
			 
			GlobalData::tabletshared[i] *=factor;
			 
			 
			GlobalData::pcshared[i] *=factor;
			 
			 
			GlobalData::headphonenumber[i] *=factor;
			 
			 
			GlobalData::printernumber[i] *=factor;
			 
			 
			GlobalData::joysticknumber[i] *=factor;
			 
			 
			GlobalData::scannernumber[i] *=factor;
			 
			 
			GlobalData::webcamnumber[i] *=factor;
			 
			 
			GlobalData::smartwatchnumber[i] *=factor;
			 
		}

		for (i = 0; i < 2; i++)
		{
			GlobalData::totalshared[i] = GlobalData::mobileshared[i] + GlobalData::laptopshared[i] + GlobalData::tabletshared[i] + GlobalData::pcshared[i];
			GlobalData::totalgadgets[i] = GlobalData::mobilenumber[i] + GlobalData::laptopnumber[i] + GlobalData::tabletnumber[i] + GlobalData::pcnumber[i];
			GlobalData::totalperipherals[i] = GlobalData::headphonenumber[i] + GlobalData::scannernumber[i] + GlobalData::printernumber[i] +
				GlobalData::smartwatchnumber[i] + GlobalData::joysticknumber[i] + GlobalData::webcamnumber[i];
		}
		GlobalData::totalewaste = 0;
		DataManip::AggregateSum();
	}
}