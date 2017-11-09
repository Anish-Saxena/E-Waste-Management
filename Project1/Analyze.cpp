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
		GlobalData::plastics[2] = { 0,0 }, GlobalData::basemetal[2] = { 0,0 }, GlobalData::hazardousmetal[2] = { 0,0 }, GlobalData::carbon[2] = { 0,0 };

	double GlobalData::totalewaste = 0;

	int GlobalData::citmanualovveride = 20;

	void GlobalData::SettingFactor(int factor)
	{
		GlobalData::surveytakers = GlobalData::surveytakers*factor;
		int i;
		for (i = 0; i < 2; i++)
		{

			GlobalData::mobilenumber[i] *= factor;


			GlobalData::laptopnumber[i] *= factor;


			GlobalData::tabletnumber[i] *= factor;


			GlobalData::pcnumber[i] *= factor;


			GlobalData::mobileshared[i] *= factor;


			GlobalData::laptopshared[i] *= factor;


			GlobalData::tabletshared[i] *= factor;


			GlobalData::pcshared[i] *= factor;


			GlobalData::headphonenumber[i] *= factor;


			GlobalData::printernumber[i] *= factor;


			GlobalData::joysticknumber[i] *= factor;


			GlobalData::scannernumber[i] *= factor;


			GlobalData::webcamnumber[i] *= factor;


			GlobalData::smartwatchnumber[i] *= factor;

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


	void Display::GeneralResults()
	{
		string ord[2] = { "Owned","Disposed" }, ltpm[4] = { "Laptops","Tablets","Personal Computers","Mobile Phones" };
		int i, gi = 0;
		cout << "The survey was taken by " << GlobalData::surveytakers << " users." << endl << endl;
		cout << "_____________________________________________" << endl;
		for (i = 0; i < 2; i++)
		{
			/*Sleep(1000);*/
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " are " << GlobalData::laptopnumber[i] << endl << endl; ++gi;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " are " << GlobalData::tabletnumber[i] << endl << endl; ++gi;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " are " << GlobalData::pcnumber[i] << endl << endl; ++gi;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " are " << GlobalData::mobilenumber[i] << endl << endl; ++gi;	/*Sleep(100);*/
			/*Sleep(1000);*/ gi = 0;
			cout << "_____________________________________________" << endl;
			cout << "The total number of " << ord[i] << " electronic gadgets are: " << GlobalData::totalgadgets[i] << endl << endl;
			cout << "_____________________________________________" << endl;
			/*Sleep(1000);*/
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " shared are " << GlobalData::laptopshared[i] << endl << endl; ++gi;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " shared are " << GlobalData::tabletshared[i] << endl << endl; ++gi;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " shared are " << GlobalData::pcshared[i] << endl << endl; ++gi;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " " << ltpm[gi] << " shared are " << GlobalData::mobileshared[i] << endl << endl; ++gi;	/*Sleep(100);*/
			/*Sleep(1000);*/ gi = 0;
			cout << "_____________________________________________" << endl;
			cout << "The total number of " << ord[i] << " electronic gadgets shared are: " << GlobalData::totalshared[i] << endl << endl;
			cout << "_____________________________________________" << endl;
			/*Sleep(1000);*/
			cout << "The average number of various electronic equipments " << ord[i] << " per person are:" << endl << endl;
			cout << "_____________________________________________" << endl;
			/*Sleep(1000);*/
			//I've assumed that each electronic item marked as shared is on average shared b/w 2 persons
			cout << ltpm[gi] << ": " << std::setprecision(2) << ((float)GlobalData::laptopnumber[i] / (GlobalData::surveytakers + GlobalData::laptopshared[i])) << endl << endl; ++gi;	/*Sleep(100);*/
			cout << ltpm[gi] << ": " << std::setprecision(2) << ((float)GlobalData::tabletnumber[i] / (GlobalData::surveytakers + GlobalData::tabletshared[i])) << endl << endl; ++gi;	/*Sleep(100);*/
			cout << ltpm[gi] << ": " << std::setprecision(2) << ((float)GlobalData::pcnumber[i] / (GlobalData::surveytakers + GlobalData::pcshared[i])) << endl << endl; ++gi;	/*Sleep(100);*/
			cout << ltpm[gi] << ": " << std::setprecision(2) << ((float)GlobalData::mobilenumber[i] / (GlobalData::surveytakers + GlobalData::mobileshared[i])) << endl << endl; ++gi;	/*Sleep(100);*/
			/*Sleep(1000);*/ gi = 0;
			cout << "_____________________________________________" << endl;
			cout << "The number of " << ord[i] << " Headphones are " << GlobalData::headphonenumber[i] << endl << endl;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " Scanners are " << GlobalData::scannernumber[i] << endl << endl;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " Prineter are " << GlobalData::printernumber[i] << endl << endl;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " Joysticks are " << GlobalData::joysticknumber[i] << endl << endl;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " Webcams are " << GlobalData::webcamnumber[i] << endl << endl;	/*Sleep(100);*/
			cout << "The number of " << ord[i] << " Smartwatches are " << GlobalData::smartwatchnumber[i] << endl << endl;	/*Sleep(100);*/
			/*Sleep(1000);*/
			cout << "_____________________________________________" << endl;
			cout << "The total number of " << ord[i] << " peripherals are: " << GlobalData::totalperipherals[i] << endl << endl;
			cout << "_____________________________________________" << endl;

		}
		/*Sleep(1000);*/

	}


	void Display::ComponentBreakup(int *flag)
	{
		cout << "Let us now see how much of each substance, be it metal, glass, ceramics, etc., is approximately present (in total) in this E-waste:" << endl << endl;
		cout << "The amount of each substance in kg is as follows: " << endl << endl;
		cout << "Elements by their amount in E-waste:" << endl << endl;

		string substance[16] = { "Gold","Mercury","Copper","Plastics","Ceramics","Steel","Lithium","Lead","Carbon","Glass","Silver","Nickel","Aluminum","Magnesium","Electrolyte","Silicon" };

		int i;
		/*Sleep(1000);*/
		for (i = 0; i < 16; i++)
		{
			/*Sleep(100);*/
			printf("%-30s%6.3lf\tkg\n", substance[i].c_str(), GlobalData::GD[i]);

		}
		printf("\n%.4lf kg of total E-waste has been produced collectively in this survey", GlobalData::totalewaste);
		cout << endl << endl << "The E-Waste contains: " << endl << endl;
		printf("%.4lf kg of Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::metal[1], (GlobalData::metal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Precious Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::preciousmetal[1], (GlobalData::preciousmetal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Base Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::basemetal[1], (GlobalData::basemetal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Hazardous Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::hazardousmetal[1], (GlobalData::hazardousmetal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Non Metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::nonmetal[1], (GlobalData::nonmetal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Glass and ceramics, that is, %.2lf%c of total E-waste\n\n", GlobalData::glassnceramics[1], (GlobalData::glassnceramics[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Plastics, that is, %.2lf%c of total E-waste\n\n", GlobalData::plastics[1], (GlobalData::plastics[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Carbon-like non-metals, that is, %.2lf%c of total E-waste\n\n", GlobalData::carbon[1], (GlobalData::carbon[0]), 37);	/*Sleep(100);*/
		cout << "Press any key to continue." << endl;
		_getche();
		system("CLS");
		printf("Now, %d users dump %.4lf kg of E-Waste every two years, or about %.4lf kg of E-waste on average every 4 day, since 4 days is the normal cycle of treating",GlobalData::surveytakers,GlobalData::totalewaste,GlobalData::totalewaste/182.5);
		printf(" batch of E-waste in a regular treatment plant.\n\n");
		cout << "Obviously, the plant works on a cycle basis of approximately 4 days each, to conduct all the processes involved for all substances present.";
		cout << " Given the plant gets a steady stream of regularly collected E-waste, it will run for about 360 cycles in our survey period of 2 years." << endl;
		HelperFunctions::ConvertperCycle();
		HelperFunctions::Limits();
		*flag = 0;
		cout << "Hence, the amount of E-waste produced in the given survey per cycle is as follows:\n\n";
		printf("\n%.4lf kg of total E-waste has been produced collectively in this survey per cycle", GlobalData::totalewaste);
		cout << endl << endl << "The E-Waste contains: " << endl << endl;
		printf("%.4lf kg of Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::metal[1], (GlobalData::metal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Precious Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::preciousmetal[1], (GlobalData::preciousmetal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Base Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::basemetal[1], (GlobalData::basemetal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Hazardous Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::hazardousmetal[1], (GlobalData::hazardousmetal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Non Metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::nonmetal[1], (GlobalData::nonmetal[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Glass and ceramics, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::glassnceramics[1], (GlobalData::glassnceramics[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Plastics, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::plastics[1], (GlobalData::plastics[0]), 37);	/*Sleep(100);*/
		printf("%.4lf kg of Carbon-like non-metals, that is, %.2lf%c of total E-waste per cycle\n\n", GlobalData::carbon[1], (GlobalData::carbon[0]), 37);	/*Sleep(100);*/
	}


	void Display::PreProcessing()
	{
		cout << "Preprocessing of e-waste is one of the most important steps in the E-waste treatment chain." << endl << endl;
		/*Sleep(1000);*/
		cout << " The non-usable components are dismantled at the collection facilities prior to sending to the treatment plant.";
		cout << " Mechanical processing is an integrated part of this stage where E-waste scrap is shredded into pieces using hammer mills.";
		cout << " Metals and non-metals are separated during this stage using techniques similar to that used in the";
		cout << "	mineral dressing, e.g., screening, magnetic, eddy current and density separation techniques" << endl << endl;
		/*Sleep(1000);*/
		cout << "Since this project aims to manage the E-waste from the time it is collected, the first crucial step, Preprocessing, has been illustrated. It involves the following steps:" << endl << endl;
		/*Sleep(1000);*/
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
		cout << endl << endl;	/*Sleep(1000);*/
		cout << "Let's now analyze the contents of given E-waste:\n\n";
		cout << "Checking the level of various substances in given E-waste:\n\n";
		char MNPRGBH[] = { 'M','N','P','R','G','B','H' };
		int i = 0;
		while (i < 7)
		{
			HelperFunctions::WhatLevel(MNPRGBH[i]);	/*Sleep(1000);*/
			i++;
		}
		cout << "Knowing about presence levels of various substance, it's time to move on to determine best of course of action for specific type of substances, keeping in mind the 3 conditions." << endl;
		cout << "\nPress any key to move on the specific processing section.\n\n";
		_getche();
		/*Sleep(100);*/
		system("CLS");
		Display::Processing();		
	}


	void BestProcess::Metals(int level)
	{
		system("CLS");
		cout << "Please wait, analysing";
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//Now defining processes for metals

		Process Metals[21];
		//Process 0: Ion Exchange, for Base metals, to get them from Extraction to refining phase, also makes Precious metals go from leaching to extraction
		Metals[0].information = "Ion Exchange process, Hydrometallurgy, more info soon.";
		Metals[0].category = 0;
		Metals[0].type = 'B';
		Metals[0].cost = 750000;		
		Metals[0].efficiency = 0.92;
		Metals[0].maxefficiency = 0.99;
		Metals[0].economicfactors[0] = 1.05;
		Metals[0].economicfactors[1] = 1.05;
		Metals[0].amountinput[0] = 100;
		Metals[0].amountinput[1] = 250;
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
		Metals[1].cost = 500000;		
		Metals[1].efficiency = 0.97;
		Metals[1].maxefficiency = 0.99;
		Metals[1].economicfactors[0] = 0.98;
		Metals[1].economicfactors[1] = 1.05;
		Metals[1].amountinput[0] = 1.5;
		Metals[1].amountinput[1] = 250;
		Metals[1].carbonfootprint[0] = 25000;
		Metals[1].carbonfootprint[1] = 65000;
		Metals[1].stagefrom = 2;
		Metals[1].stageto = 3;
		Metals[1].othertypes.stagefrom = -1;
		Metals[1].othertypes.stageto = -1;
		Metals[1].othertypes.typeof = 'Z';

		//Process 2: Vat Leaching, for Precious metals, to get them from leaching to extraction phase, also makes base metals go from leaching to extraction

		Metals[2].information = "Vat Leaching, Hydrometallurgy, more info soon.";
		Metals[2].type = 'P';
		Metals[2].category = 0;
		Metals[2].cost = 320000;		
		Metals[2].efficiency = 0.85;
		Metals[2].maxefficiency = 0.90;
		Metals[2].economicfactors[0] = 0.95;
		Metals[2].economicfactors[1] = 1.05;
		Metals[2].amountinput[0] = 1.2;
		Metals[2].amountinput[1] = 200;
		Metals[2].carbonfootprint[0] = 35000;
		Metals[2].carbonfootprint[1] = 60000;
		Metals[2].stagefrom = 1;
		Metals[2].stageto = 2;
		Metals[2].othertypes.stagefrom = 1;
		Metals[2].othertypes.stageto = 2;
		Metals[2].othertypes.typeof = 'B';

		//Process 3: Caustic Leaching, for Precious metals, to get them from leaching to extraction phase, doesn't act on other types of E-waste

		Metals[3].information = "Caustic Leaching, Hydrometallurgy, more info soon.";
		Metals[3].type = 'P';
		Metals[3].category = 0;
		Metals[3].cost = 270000;		
		Metals[3].efficiency = 0.80;
		Metals[3].maxefficiency = 0.90;
		Metals[3].economicfactors[0] = 0.90;
		Metals[3].economicfactors[1] = 1;
		Metals[3].amountinput[0] = 1.0;
		Metals[3].amountinput[1] = 100;
		Metals[3].carbonfootprint[0] = 30000;
		Metals[3].carbonfootprint[1] = 60000;
		Metals[3].stagefrom = 1;
		Metals[3].stageto = 2;
		Metals[3].othertypes.stagefrom = -1;
		Metals[3].othertypes.stageto = -1;
		Metals[3].othertypes.typeof = 'Z';

		//Process 4: Autoclave leaching, for precious metals, to get them from leaching to extraction phase, also makes hazardous metals go from leaching to extraction

		Metals[4].information = "Autoclave leaching, Hydrometallurgy, more info soon.";
		Metals[4].type = 'P';
		Metals[4].category = 0;
		Metals[4].cost = 975000;		
		Metals[4].efficiency = 0.95;
		Metals[4].maxefficiency = 0.999;
		Metals[4].economicfactors[0] = 0.99;
		Metals[4].economicfactors[1] = 1.05;
		Metals[4].amountinput[0] = 1.5;
		Metals[4].amountinput[1] = 250;
		Metals[4].carbonfootprint[0] = 40000;
		Metals[4].carbonfootprint[1] = 65000;
		Metals[4].stagefrom = 1;
		Metals[4].stageto = 2;
		Metals[4].othertypes.stagefrom = 1;
		Metals[4].othertypes.stageto = 2;
		Metals[4].othertypes.typeof = 'H';

		//Process 5: Shaft Furnace calcination, for base metals, to get them from Purification to recovery, also makes hazardous metals go from purifcation to recovery

		Metals[5].information = "Shaft furnace calcination, pyrometallurgy, more info soon.";
		Metals[5].type = 'B';
		Metals[5].category = 0;
		Metals[5].cost = 500000;		
		Metals[5].efficiency = 0.97;
		Metals[5].maxefficiency = 0.9999;
		Metals[5].economicfactors[0] = 1.05;
		Metals[5].economicfactors[1] = 1;
		Metals[5].amountinput[0] = 120;
		Metals[5].amountinput[1] = 300;
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
		Metals[6].cost = 620000;		
		Metals[6].efficiency = 0.975;
		Metals[6].maxefficiency = 0.9999;
		Metals[6].economicfactors[0] = 1.1;
		Metals[6].economicfactors[1] = 1.01;
		Metals[6].amountinput[0] = 150;
		Metals[6].amountinput[1] = 375;
		Metals[6].carbonfootprint[0] = 40000;
		Metals[6].carbonfootprint[1] = 50000;
		Metals[6].stagefrom = 1;
		Metals[6].stageto = 2;
		Metals[6].othertypes.stagefrom = 1;
		Metals[6].othertypes.stageto = 2;
		Metals[6].othertypes.typeof = 'H';

		//Process 7: Pyrolytic Extraction: for base metals, to get them from Purification to recovery, also makes hazardous metals go from purification to recovery

		Metals[7].information = "Pyrolytic Extraction, pyrometallurgy, more info soon.";
		Metals[7].type = 'B';
		Metals[7].category = 0;
		Metals[7].cost = 580000;
		Metals[7].efficiency = 0.95;
		Metals[7].maxefficiency = 0.99;
		Metals[7].economicfactors[0] = 1.1;
		Metals[7].economicfactors[1] = 1.005;
		Metals[7].amountinput[0] = 100;
		Metals[7].amountinput[1] = 250;
		Metals[7].carbonfootprint[0] = 45000;
		Metals[7].carbonfootprint[1] = 50000;
		Metals[7].stagefrom = 1;
		Metals[7].stageto = 2;
		Metals[7].othertypes.stagefrom = 1;
		Metals[7].othertypes.stageto = 2;
		Metals[7].othertypes.typeof = 'H';

		//Process 8: Parke's Process, for hazardous metals, to get them from Purification to recovery, also makes precious metals go from purification and recovery

		Metals[8].information = "Parke's Process, pyrometallurgy, more info soon.";
		Metals[8].type = 'H';
		Metals[8].category = 0;
		Metals[8].cost = 450000;
		Metals[8].efficiency = 0.97;
		Metals[8].maxefficiency = 0.9999;
		Metals[8].economicfactors[0] = 1.05;
		Metals[8].economicfactors[1] = 1.06;
		Metals[8].amountinput[0] = 0.5;
		Metals[8].amountinput[1] = 250;
		Metals[8].carbonfootprint[0] = 60000;
		Metals[8].carbonfootprint[1] = 80000;
		Metals[8].stagefrom = 1;
		Metals[8].stageto = 2;
		Metals[8].othertypes.stagefrom = 1;
		Metals[8].othertypes.stageto = 2;
		Metals[8].othertypes.typeof = 'P';

		//Process 9: Distillation process: for hazardous metals, to get them from Purification to recovery, doesn't act on other types of e-waste

		Metals[9].information = "Distillation process, hydrometallurgy, more info soon.";
		Metals[9].type = 'H';
		Metals[9].category = 0;
		Metals[9].cost = 400000;
		Metals[9].efficiency = 0.92;
		Metals[9].maxefficiency = 0.97;
		Metals[9].economicfactors[0] = 1.01;
		Metals[9].economicfactors[1] = 1.029;
		Metals[9].amountinput[0] = 0.6;
		Metals[9].amountinput[1] = 225;
		Metals[9].carbonfootprint[0] = 50000;
		Metals[9].carbonfootprint[1] = 75000;
		Metals[9].stagefrom = 1;
		Metals[9].stageto = 2;
		Metals[9].othertypes.stagefrom = -1;
		Metals[9].othertypes.stageto = -1;
		Metals[9].othertypes.typeof = 'Z';

		//Process 10: Extractive Roasting: for hazardous metals, to get them from Purification to recovery, also makes base metals go from purification to recovery

		Metals[10].information = "Extractive Roasting, pyrometallurgy, more info soon.";
		Metals[10].type = 'H';
		Metals[10].category = 0;
		Metals[10].cost = 600000;
		Metals[10].efficiency = 0.75;
		Metals[10].maxefficiency = 0.95;
		Metals[10].economicfactors[0] = 0.99;
		Metals[10].economicfactors[1] = 1.042;
		Metals[10].amountinput[0] = 0.5;
		Metals[10].amountinput[1] = 240;
		Metals[10].carbonfootprint[0] = 60000;
		Metals[10].carbonfootprint[1] = 80000;
		Metals[10].stagefrom = 1;
		Metals[10].stageto = 2;
		Metals[10].othertypes.stagefrom = 1;
		Metals[10].othertypes.stageto = 2;
		Metals[10].othertypes.typeof = 'B';

		//Process 11: Mertill-Crowe Process: for precious metals, to get them from Recovery to refining, doesn't act on other types of E-waste

		Metals[11].information = "Merill-Crowe Process, hydrometallurgy, more info soon.";
		Metals[11].type = 'P';
		Metals[11].category = 0;
		Metals[11].cost = 400000;
		Metals[11].efficiency = 0.82;
		Metals[11].maxefficiency = 0.96;
		Metals[11].economicfactors[0] = 1.03;
		Metals[11].economicfactors[1] = 1.057;
		Metals[11].amountinput[0] = 1.5;
		Metals[11].amountinput[1] = 250;
		Metals[11].carbonfootprint[0] = 35000;
		Metals[11].carbonfootprint[1] = 60000;
		Metals[11].stagefrom = 2;
		Metals[11].stageto = 3;
		Metals[11].othertypes.stagefrom = -1;
		Metals[11].othertypes.stageto = -1;
		Metals[11].othertypes.typeof = 'Z';

		//Process 12: Park and Fray Process, for precious metals, to get them from recovery to refining, doesn't act on other types of E-waste

		Metals[12].information = "Park and Fray Process, hydrometallurgy, more info soon.";
		Metals[12].type = 'P';
		Metals[12].category = 0;
		Metals[12].cost = 350000;
		Metals[12].efficiency = 0.97;
		Metals[12].maxefficiency = 0.9999;
		Metals[12].economicfactors[0] = 1.2;
		Metals[12].economicfactors[1] = 1.08;
		Metals[12].amountinput[0] = 1.5;
		Metals[12].amountinput[1] = 250;
		Metals[12].carbonfootprint[0] = 40000;
		Metals[12].carbonfootprint[1] = 60000;
		Metals[12].stagefrom = 2;
		Metals[12].stageto = 3;
		Metals[12].othertypes.stagefrom = -1;
		Metals[12].othertypes.stageto = -1;
		Metals[12].othertypes.typeof = 'Z';
		
		//Process 13: Kogan Process, for base metals, to get them from recovery to refining, also makes hazardous metals go from recovery to refining

		Metals[13].information = "Kogan Process, hydrometallurgy, more info soon.";
		Metals[13].type = 'B';
		Metals[13].category = 0;
		Metals[13].cost = 750000;
		Metals[13].efficiency = 0.85;
		Metals[13].maxefficiency = 0.99;
		Metals[13].economicfactors[0] = 1.01;
		Metals[13].economicfactors[1] = 1.2;
		Metals[13].amountinput[0] = 150;
		Metals[13].amountinput[1] = 375;
		Metals[13].carbonfootprint[0] = 35000;
		Metals[13].carbonfootprint[1] = 80000;
		Metals[13].stagefrom = 2;
		Metals[13].stageto = 3;
		Metals[13].othertypes.stagefrom = 2;
		Metals[13].othertypes.stageto = 3;
		Metals[13].othertypes.typeof = 'H';
		
		//Process 14: Unicore Process, for base metals, to get them from recovery to refining, also makes precious metals go from recovery to refining

		Metals[14].information = "Unicore Process, pyrometallurgy, more info soon.";
		Metals[14].type = 'B';
		Metals[14].category = 0;
		Metals[14].cost = 600000;
		Metals[14].efficiency = 0.95;
		Metals[14].maxefficiency = 0.99;
		Metals[14].economicfactors[0] = 1.001;
		Metals[14].economicfactors[1] = 1.08;
		Metals[14].amountinput[0] = 150;
		Metals[14].amountinput[1] = 375;
		Metals[14].carbonfootprint[0] = 35000;
		Metals[14].carbonfootprint[1] = 80000;
		Metals[14].stagefrom = 2;
		Metals[14].stageto = 3;
		Metals[14].othertypes.stagefrom = 2;
		Metals[14].othertypes.stageto = 3;
		Metals[14].othertypes.typeof = 'P';

		//Process 15: Ronnskar Smetler process: for hazardous metals, to get them from recovery to refining, also makes precious metals go from recovery to refining

		Metals[15].information = "Ronnskar Smelter Process, pyrometallugry, more info soon.";
		Metals[15].type = 'H';
		Metals[15].category = 0;
		Metals[15].cost = 700000;
		Metals[15].efficiency = 0.97;
		Metals[15].maxefficiency = 0.99;
		Metals[15].economicfactors[0] = 1.04;
		Metals[15].economicfactors[1] = 1.08;
		Metals[15].amountinput[0] = 0.25;
		Metals[15].amountinput[1] = 400;
		Metals[15].carbonfootprint[0] = 45000;
		Metals[15].carbonfootprint[1] = 65000;
		Metals[15].stagefrom = 2;
		Metals[15].stageto = 3;
		Metals[15].othertypes.stagefrom = 2;
		Metals[15].othertypes.stageto = 3;
		Metals[15].othertypes.typeof = 'P';

		//Process 16: Outotec Process, for hazardous metals, to get them from recovery to refining, doesn't act on other types of E-waste

		Metals[16].information = "Outotec Process, pyrometallurgy, more info soon.";
		Metals[16].type = 'H';
		Metals[16].category = 0;
		Metals[16].cost = 450000;
		Metals[16].efficiency = 0.90;
		Metals[16].maxefficiency = 0.97;
		Metals[16].economicfactors[0] = 1.01;
		Metals[16].economicfactors[1] = 1.02;
		Metals[16].amountinput[0] = 0.5;
		Metals[16].amountinput[1] = 250;
		Metals[16].carbonfootprint[0] = 55000;
		Metals[16].carbonfootprint[1] = 90000;
		Metals[16].stagefrom = 2;
		Metals[16].stageto = 3;
		Metals[16].othertypes.stagefrom = -1;
		Metals[16].othertypes.stageto = -1;
		Metals[16].othertypes.typeof = 'Z';

		//Process 17: Mecucci and Scott Process, for hazardous metals, to get them from recovery to refining, doesn't act on other types of E-waste

		Metals[17].information = "Mecucci and Scott Process, hydrometallurgy, more info soon.";
		Metals[17].type = 'H';
		Metals[17].category = 0;
		Metals[17].cost =  350000;
		Metals[17].efficiency = 0.90;
		Metals[17].maxefficiency = 0.95;
		Metals[17].economicfactors[0] = 0.94;
		Metals[17].economicfactors[1] = 1.012;
		Metals[17].amountinput[0] = 0.45;
		Metals[17].amountinput[1] = 350;
		Metals[17].carbonfootprint[0] = 45000;
		Metals[17].carbonfootprint[1] = 60000;
		Metals[17].stagefrom = 2;
		Metals[17].stageto = 3;
		Metals[17].othertypes.stagefrom = -1;
		Metals[17].othertypes.stageto = -1;
		Metals[17].othertypes.typeof = 'Z';

		//Process 18: Electrorefining process: for precious metals, to get them from refining phase to done!, also makes hazardous metals go from refining to done!

		Metals[18].information = "Electrorefining Process, electrometallurgy, more info soon.";
		Metals[18].type = 'P';
		Metals[18].category = 0;
		Metals[18].cost = 900000;
		Metals[18].efficiency = 0.98;
		Metals[18].maxefficiency = 0.99999;
		Metals[18].economicfactors[0] = 1.01;
		Metals[18].economicfactors[1] = 1.006;
		Metals[18].amountinput[0] = 1.4;
		Metals[18].amountinput[1] = 400;
		Metals[18].carbonfootprint[0] = 40000;
		Metals[18].carbonfootprint[1] = 100000;
		Metals[18].stagefrom = 3;
		Metals[18].stageto = 4;
		Metals[18].othertypes.stagefrom = 3;
		Metals[18].othertypes.stageto = 4;
		Metals[18].othertypes.typeof = 'H';

		//Process 19: Noranda process: for precious metals, to get them from refining phase to done1, also makes hazardous metals go from refining to done!

		Metals[19].information = "Noranda Process, pyrometallurgy, more info soon.";
		Metals[19].type = 'P';
		Metals[19].category = 0;
		Metals[19].cost = 800000;
		Metals[19].efficiency = 0.94;
		Metals[19].maxefficiency = 0.99;
		Metals[19].economicfactors[0] = 1.01;
		Metals[19].economicfactors[1] = 1.09;
		Metals[19].amountinput[0] = 1.8;
		Metals[19].amountinput[1] = 240;
		Metals[19].carbonfootprint[0] = 45000;
		Metals[19].carbonfootprint[1] = 90000;
		Metals[19].stagefrom = 3;
		Metals[19].stageto = 4;
		Metals[19].othertypes.stagefrom = 3;
		Metals[19].othertypes.stageto = 4;
		Metals[19].othertypes.typeof = 'H';

		//Process 20: Veit Process: for base metals, to get them from refining to done!, doesn't act onother types of E-waste

		Metals[20].information = "Veit Process, hydrometallurgy, more info soon.";
		Metals[20].type = 'B';
		Metals[20].category = 0;
		Metals[20].cost = 400000;
		Metals[20].efficiency = 0.92;
		Metals[20].maxefficiency = 0.98;
		Metals[20].economicfactors[0] = 1.01;
		Metals[20].economicfactors[1] = 1.08;
		Metals[20].amountinput[0] = 150;
		Metals[20].amountinput[1] = 400;
		Metals[20].carbonfootprint[0] = 55000;
		Metals[20].carbonfootprint[1] = 75000;
		Metals[20].stagefrom = 3;
		Metals[20].stageto = 4;
		Metals[20].othertypes.stagefrom = -1;
		Metals[20].othertypes.stageto = -1;
		Metals[20].othertypes.typeof = 'Z';

		//Refining of hazardous metals is done along with their recovery, software will take care of that


		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//Analysis part

		double samount, tamount, typecost;
		int init, tempcit, cit, i;
								
		double pointsp1[3], pointsp2[3],pointsp3[3],pointsb1[3],pointsb2[3],pointsb3[3],pointsh1[3],pointsh2[3],pointsh3[3];
		int whatip1[3], whatip2[3], whatip3[3], whatib1[3], whatib2[3], whatib3[3], whatih1[3], whatih2[3], whatih3[3];
		int p1 = 0, p2 = 0, p3 = 0, b1 = 0, b2 = 0, b3 = 0, h1 = 0, h2 = 0, h3 = 0;
		double store[21][4] = { 0 };
		for (i = 0; i < 3; i++)
		{
			pointsb1[i] = 0;	pointsb2[i] = 0;	pointsb3[i] = 0;
			pointsp1[i] = 0;	pointsp2[i] = 0;	pointsp3[i] = 0;
			pointsh1[i] = 0;	pointsh2[i] = 0;	pointsh3[i] = 0;

			whatib1[i] = -1;	whatib2[i] = -1;	whatib3[i] = -1;
			whatip1[i] = -1;	whatip2[i] = -1;	whatip3[i] = -1;
			whatih1[i] = -1;	whatih2[i] = -1;	whatih3[i] = -1;

		}
		tamount = GlobalData::totalewaste;

		for (i = 0; i < 21; i++)
		{
			if (i % 3 == 0 || i == 20)	cout << ".";
			if (Metals[i].category != 0)	continue;
			switch(Metals[i].type)
			{
			case 'P':
			{
				samount = GlobalData::preciousmetal[1];
				typecost = TypeCost::preciousm;

				init = HelperFunctions::GetInit(Metals[i], samount, tamount);
				tempcit = HelperFunctions::GetOverrideCit(Metals[i], init);

				switch (level)
				{
				case 1:
				{
					cit = tempcit;
					break;
				}
				case 2:
				{
					cit = tempcit / 2;		
					break;
				}
				case 3:
				{
					cit = 0;
					break;
				}
				}

				switch (Metals[i].stagefrom)
				{
				case 1:
				{

					pointsp1[p1] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'P', 1, init, cit, store, i);
					whatip1[p1] = i;		
					p1++;
					break;
				}
				case 2:
				{

					pointsp2[p2] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'P', 2, init, cit, store, i);
					whatip2[p2] = i;
					p2++;

					break;
				}
				case 3:
				{

					pointsp3[p3] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'P', 3, init, cit, store, i);
					whatip3[p3] = i;
					p3++;
					break;
				}
				}

				break;
			}
			case 'H':
			{
				samount = GlobalData::hazardousmetal[1];
				typecost = TypeCost::hazardousm;

				init = HelperFunctions::GetInit(Metals[i], samount, tamount);
				tempcit = HelperFunctions::GetOverrideCit(Metals[i], init);

				switch (level)
				{
				case 1:
				{
					cit = tempcit;
					break;
				}
				case 2:
				{
					cit = tempcit / 2;
					break;
				}
				case 3:
				{
					cit = 0;
					break;
				}
				}
				switch (Metals[i].stagefrom)
				{
				case 1:
				{
					pointsh1[h1] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'H', 1, init, cit, store, i);
					whatih1[h1] = i;
					h1++;
					break;
				}
				case 2:
				{
					pointsh2[h2] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'H', 2, init, cit, store, i);
					whatih2[h2] = i;
					h2++;
					break;
				}
				case 3:
				{
					pointsh3[h3] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'H', 3, init, cit, store, i);
					whatih3[h3] = i;
					h3++;
					break;
				}
				}
				break;
			}
			case 'B':
			{
				samount = GlobalData::basemetal[1];
				typecost = TypeCost::basem;

				init = HelperFunctions::GetInit(Metals[i], samount, tamount);
				tempcit = HelperFunctions::GetOverrideCit(Metals[i], init);

				switch (level)
				{
				case 1:
				{
					cit = tempcit;
					break;
				}
				case 2:
				{
					cit = tempcit / 2;
					break;
				}
				case 3:
				{
					cit = 0;
					break;
				}
				}
				switch (Metals[i].stagefrom)
				{
				case 1:
				{
					pointsb1[b1] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'B', 1, init, cit, store, i);
					whatib1[b1] = i;
					b1++;
					break;
				}
				case 2:
				{
					pointsb2[b2] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'B', 2, init, cit, store, i);
					whatib2[b2] = i;
					b2++;
					break;
				}
				case 3:
				{
					pointsb3[b3] = HelperFunctions::PointCalc(Metals[i], tamount, samount, typecost, 'B', 3, init, cit, store, i);
					whatib3[b3] = i;
					b3++;
					break;
				}
				}

				break;
			}
			}
		}

		int maxip1, maxip2, maxip3, maxih1, maxih2, maxih3, maxib1, maxib2, maxib3;
		maxip1 = HelperFunctions::Maxpoints(pointsp1);
		maxip2 = HelperFunctions::Maxpoints(pointsp2);
		maxip3 = HelperFunctions::Maxpoints(pointsp3);
		maxih1 = HelperFunctions::Maxpoints(pointsh1);
		maxih2 = HelperFunctions::Maxpoints(pointsh2);
		maxih3 = HelperFunctions::Maxpoints(pointsh3);
		maxib1 = HelperFunctions::Maxpoints(pointsb1);
		maxib2 = HelperFunctions::Maxpoints(pointsb2);
		maxib3 = HelperFunctions::Maxpoints(pointsb3);

		int processip1, processip2, processip3, processih1, processih2, processih3, processib1, processib2, processib3;
		processip1 = whatip1[maxip1];
		processip2 = whatip2[maxip2];
		processip3 = whatip3[maxip3];
		processih1 = whatih1[maxih1];
		processih2 = whatih2[maxih2];
		processih3 = whatih3[maxih3];
		processib1 = whatib1[maxib1];
		processib2 = whatib2[maxib2];
		processib3 = whatib3[maxib3];
						
		cout << endl << endl;
		/*Sleep(1000);*/
		cout << "Done!\n\n";	/*Sleep(100);*/
		cout << "METAL PROCESSING can be broken down into three 3 stages:\n\n";
		cout << "1. Purification or Leaching or preprocessed substances\n2. Recovery or Isolation of metal of interest\n3. Refining of metal to get best yields\n\n";
		/*Sleep(1000);*/
		cout << "Also, the metals can be divied into, as before:\n\n1. Precious metals\n2. Base metals\n3. Hazardous heavy metals\n\n";
		/*Sleep(1000);*/
		cout << "After analysis, the software has come up with the following plan to treat metals in E-waste:\n\n";
		cout << "Press any key to view the plan.";
		_getche();
		system("CLS");
		cout << "STAGE 1: PURIFICATION OR LEACHING\n\nSuggested routes are as follows:\n\n";
		cout << "FOR PRECIOUS METALS:\n\n";
		cout << Metals[processip1].information;
		cout << endl << endl;
		double ce = store[processip1][0];
		double cc = store[processip1][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce,37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n",Metals[processip1].carbonfootprint[0]*(1+store[processip1][2])/(1+store[processip1][3]/2.0));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processip1].carbonfootprint[1] * (1 + store[processip1][2]));
		HelperFunctions::OtherTypeInfo(Metals[processip1]);
		cout << "\n\nFOR BASE METALS:\n\n";
		cout << Metals[processib1].information;
		cout << endl << endl;
		ce = store[processib1][0];
		cc = store[processib1][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce,37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n", Metals[processib1].carbonfootprint[0] * (1 + store[processib1][2]));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processib1].carbonfootprint[1] * (1 + store[processib1][2]) / (1 + store[processib1][3] / 2.0));
		HelperFunctions::OtherTypeInfo(Metals[processib1]);		
		cout << "\n\nFOR HAZARDOUS METALS:\n\n";
		cout << Metals[processih1].information;
		cout << endl << endl;
		ce = store[processih1][0];
		cc = store[processih1][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce,37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n", Metals[processih1].carbonfootprint[0] * (1 + store[processih1][2]));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processih1].carbonfootprint[1] * (1 + store[processih1][2]) / (1 + store[processih1][3] / 2.0));
		HelperFunctions::OtherTypeInfo(Metals[processih1]);
		cout << endl << endl;

		cout << "Press any key to continue to stage 2.";
		_getche();
		system("CLS");
		cout << "STAGE 2: EXTRACTION (ISOLATION) OR RECOVERY:\n\nSuggested routes are as follows:\n\n";
		cout << "FOR PRECIOUS METALS:\n\n";
		cout << Metals[processip2].information;
		cout << endl << endl;
		ce = store[processip2][0];
		cc = store[processip2][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce, 37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n", Metals[processip2].carbonfootprint[0] * (1 + store[processip2][2]));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processip2].carbonfootprint[1] * (1 + store[processip2][2]) / (1 + store[processip2][3] / 2.0));
		HelperFunctions::OtherTypeInfo(Metals[processip2]);
		cout << "\n\nFOR BASE METALS:\n\n";
		cout << Metals[processib2].information;
		cout << endl << endl;
		ce = store[processib2][0];
		cc = store[processib2][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce, 37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n", Metals[processib2].carbonfootprint[0] * (1 + store[processib2][2]));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processib2].carbonfootprint[1] * (1 + store[processib2][2]) / (1 + store[processib2][3] / 2.0));
		HelperFunctions::OtherTypeInfo(Metals[processib2]);
		cout << "\n\nFOR HAZARDOUS METALS:\n\n";
		cout << Metals[processih2].information;
		cout << endl << endl;
		ce = store[processih2][0];
		cc = store[processih2][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce, 37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n", Metals[processih2].carbonfootprint[0] * (1 + store[processih2][2]));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processih2].carbonfootprint[1] * (1 + store[processih2][2]) / (1 + store[processih2][3] / 2.0));
		HelperFunctions::OtherTypeInfo(Metals[processih2]);
		cout << endl << endl;


		cout << "Press any key to continue to stage 3.";
		_getche();
		system("CLS");
		cout << "STAGE 1: REFINING:\n\nSuggested routes are as follows:\n\n";
		cout << "FOR PRECIOUS METALS:\n\n";
		cout << Metals[processip3].information;
		cout << endl << endl;
		ce = store[processip3][0];
		cc = store[processip3][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce, 37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n", Metals[processip3].carbonfootprint[0] * (1 + store[processip3][2]));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processip3].carbonfootprint[1] * (1 + store[processip3][2]) / (1 + store[processip3][3] / 2.0));
		HelperFunctions::OtherTypeInfo(Metals[processip3]);
		cout << "\n\nFOR BASE METALS:\n\n";
		cout << Metals[processib3].information;
		cout << endl << endl;
		ce = store[processib3][0];
		cc = store[processib3][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce, 37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n", Metals[processib3].carbonfootprint[0] * (1 + store[processib3][2]));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processib3].carbonfootprint[1] * (1 + store[processib3][2]) / (1 + store[processib3][3] / 2.0));
		HelperFunctions::OtherTypeInfo(Metals[processib3]);
		cout << "\n\nFOR HAZARDOUS METALS:\n\n";
		cout << "The Hazardous metals are refined along with precious metals:\n\n";
		cout << Metals[processip3].information;
		cout << endl << endl;
		ce = store[processip3][0];
		cc = store[processip3][1];
		printf("The current efficiency of this process is: %3.2lf%c\n", ce, 37);
		printf("The current cost per two years of this process is: Rs. %.2lf\n", cc);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n", Metals[processip3].carbonfootprint[0] * (1 + store[processip3][2]));
		printf("The Carbon footprint of conducting this process while mining the ore is: %10.2lf kg equivalents of CO2\n", Metals[processip3].carbonfootprint[1] * (1 + store[processip3][2]) / (1 + store[processip3][3] / 2.0));
		HelperFunctions::OtherTypeInfo(Metals[processip3]);

		double cf = Metals[processip3].carbonfootprint[1] * (1 + store[processip3][2]) / (1 + store[processip3][3] / 2.0)*1.5
			+ Metals[processip2].carbonfootprint[1] * (1 + store[processip2][2]) / (1 + store[processip2][3] / 2.0)
			+ Metals[processip1].carbonfootprint[1] * (1 + store[processip1][2]) / (1 + store[processip1][3] / 2.0)
			+ Metals[processib3].carbonfootprint[1] * (1 + store[processib3][2]) / (1 + store[processib3][3] / 2.0)
			+ Metals[processib2].carbonfootprint[1] * (1 + store[processib2][2]) / (1 + store[processib2][3] / 2.0)
			+ Metals[processib1].carbonfootprint[1] * (1 + store[processib1][2]) / (1 + store[processib1][3] / 2.0)
			+ Metals[processih2].carbonfootprint[1] * (1 + store[processih2][2]) / (1 + store[processih2][3] / 2.0)
			+ Metals[processih1].carbonfootprint[1] * (1 + store[processih1][2]) / (1 + store[processih1][3] / 2.0);

		cout << "Press any key to continue to view the non-metal analysis.\n\n";
		_getche();
		system("CLS");
		BestProcess::NonMetals(cf);


		cout << "Press any key to continue to view the analysis summary.\n\n";
		_getche();
		system("CLS");
		cout << "ANALYSIS SUMMARY:\n\n\n";
		double ocost = store[processip1][1] + store[processip2][1] + store[processip3][1] + store[processib1][1] + store[processib2][1] + store[processib3][1] +
			store[processih1][1] + store[processih2][1]+ 400000 + (GlobalData::glassnceramics[1] / 25) * 120000;
		printf("Total costs per cycle of 2 years are:\tRs. %.0lf\n\n", ocost);
		printf("Average cost per resident per year is:\tRs. %.0lf\n\n", ocost / (2 * GlobalData::surveytakers));		
		cf += cf / 15;
		printf("Total Equivalent Kgs of CO2 emitted per 2 years is: %.0lf kg\n\n", cf);
		printf("This treatment process with current logistics is capable of handling %.0lf kg of E-waste per cycle of 4 days.\n\n", GlobalData::totalewaste);
	}


	void BestProcess::NonMetals(double cf)
	{
		cout << "NON METAL PROCESSING:\n\n\n";
		cout << "1.GLASS AND CERAMICS:\n\nGlass is recycled in a fairly straightforward manner.";
		cout << " The process of recycling glass essentially involves crushing it to bits, melting it and remoulding it per needs.\n\n";
		double cfg, ocost;
		ocost = 400000 + (GlobalData::glassnceramics[1] / 25) * 120000;
		cfg = cf / 15;
		printf("The cost of the process for given parametes is: Rs. %.0lf\n\n",ocost);
		printf("The Carbon footprint of this process is: %10.2lf kg equivalents of CO2\n\n", cfg);
	}


	void Display::Processing()
	{
		int level;
		cout << "The metal fractions separated from e-waste during preprocessing can be further processed using";
		cout << " hydrometallurgical, pyrometallurgical, electrometallurgical, biometallurgical processes, and their";
		cout << " combinations. The hydrometallurgical and pyrometallurgical processes are the major routes for";
		cout << " processing of E-waste. These routes may be followed by electrometallurgical/electrochemical processes";
		cout << " (for example electrorefining or electrowinning) for selected metal separation and recovery.";
		cout << " Currently, there are only limited laboratory studies for e-waste processing through biometallurgical routes,";
		cout << " e.g., bioleaching of metals from e-waste. Nevertheless, this route has a potential for further development.";
		cout << " This project focusses on efficient treatment of E-waste using hydrometallurgical, electrometallurgical and pyrometallurgical processes." << endl << endl;
		/*Sleep(1000);*/
		cout << " The preprocessing of E-waste is not always required for pyrometallurgical routes.";
		cout << " However for hydrometallurgical routes, preprocessing is required to separate metal fractions from other fractions.";
		cout << " This will enhance the efficiency of each step associated with hydrometallurgical routes.";
		cout << " Each route has advantages and disadvantages and this project will try to select the best combinations of both routes to both reduce costs";
		cout << " and have minimum carbon footprint as well, so as to create as much efficient design as possible." << endl << endl;
		cout << "It should also be noted that metal processing techniques basically determine the non metal processes as metals are of high economic value.";
		cout << "Most of the economic benefits of E-waste come from metals, while environmental benefits are about equal from both components of E-waste.\n\n";
		/*Sleep(1000);*/
		cout << "Before delving into the in-depth analysis, some of the parameters must be specified by the administrator who is is calling for this analysis";
		cout << " as per the economic and environmental situation of the locality the survey was taken in. These parameters will be fundamental to determining";
		cout << " the best way to manage the E-waste at hand." << endl << endl;
		/*Sleep(1000);*/
		cout << "Press any key to continue." << endl << endl;	_getche();	system("CLS");
		cout << "It is assumed that the cost of opening up and running the E-waste management plant would be born by the locality (through addition in maintainance costs or taxes) ";
		cout<<"and hence, it is advised to carefully read the approximate costs";
		cout << " associated with various plant sizes as per the E-waste amount, and select what level of economic liberty this software can take when assessing your case.";
		cout << "Note that the cost of opening up of plant will be amortized through the 10 years to get a uniform cost" << endl << endl;
		cout << "Small plants:\n\nFor total E-waste of about 200 kg per cycle, from about 15,000 users typically (per 2 years), carries an economic cost of about Rs. 36,00,000 per annum for 10 years\n\n";
		cout << "Each resident will pay about that cost Rs. 650 per annum.";
		cout << endl << endl;
		/*Sleep(100);*/
		cout << "Medium sized plants:\n\nFor total E-waste of about 3,500 kg per cycle, from about 2,40,000 users typically (per 2 years), carries an economic cost of about Rs. 5,40,00,000 per annum for 10 years\n\n";
		cout << "Each Resident will pay about Rs. 250 per annum";
		cout << endl << endl;
		/*Sleep(100);*/
		cout << "Large sized plants:\n\n For total E-waste of about 25,000 kg per cycle, from about 15,00,000 users typically (per two years), carries an economic cost of about Rs. 40,00,000 per annum for 10 years\n\n";
		cout << "Each Resident will pay about Rs. 250 per annum";
		cout << endl << endl;
		/*Sleep(100);*/
		cout << "Please note that these are approximate values only, exact values will be determined during subsequent steps.\n\n";
		cout<<"So what kind of economic liberty do you want to give to this software ? " << endl << endl;
		/*Sleep(100);*/
		cout << "1. Complete economic liberty: \n\nImplies high priority for environment. The software will focus on improving efficiency and assume it has almost unlimited economic resources, subject to only development constraints themselves. ";
		cout << "This will certainly produce most efficient solutions. Carbon footprint would be least. But keep in mind that the cost can increase significantly, at times even more than 10 times the original!";
		cout << endl << endl << endl;
		/*Sleep(100);*/
		cout << "2. Constrained economic liberty:\n\nImplies moderate priority for environment. The software will make sure the costs do not sky rocket while efficiency is also maintained. It will provide a well-balanced solution. Recommended in most cases.";
		cout << endl << endl << endl;
		/*Sleep(100);*/
		cout << "3. No economic liberty:\n\nImplies low prioirty for environment. The software will try to make sure all the E-waste is treated, without worrying much about the efficiency. The cost will clearly be least, but bear in mind ";
		cout << "this method will never provide most eco-friendly solutions. Carbon footprint would be on the higher side.To be used only when budget is tight.";
		cout << endl << endl<<endl;
		cout << "What is your choice?\t";
		cin >> level;
		//Call best process functions.
		if (level < 1 || level>3)
		{
			cout << "\n\nInvalid level detected! Setting level as 2 by default.";
			level = 2;
		}
		/*Sleep(100);*/		
		BestProcess::Metals(level);
	}

		
	double HelperFunctions::PointCalc(struct Process s, double tamount, double samount, double typecost, char type, int stage, int init, int cit, double store[][4], int it /*normalize*/)	//start init and cit from 0
	{
		double economicpoints, environmentalpoints, relativeprocesspoints;		//Remember to normalize the points

		double ce = (s.efficiency*(1 + init + 0.01*init*s.economicfactors[0])) / (init + 1);
		ce = ce*(1 + cit*s.economicfactors[1]) / (cit + 1);
		double cc;
		if (init > 80)
			cc = s.cost*(1 + cit)*(1 + init / 2.61);
		else if (init >=19)
			cc = s.cost*(1 + cit)*(1 + init / 5.42);
		else if (init > 5 && init < 19)
			cc = s.cost*(1 + cit)*(1 + init*0.2916 - init*init*0.00694);
		else
			cc = s.cost*(1 + cit)*(1 + init / 4);

		store[it][0] = ce;
		store[it][1] = cc;
		store[it][2] = init;
		store[it][3] = cit;

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
		default: 
		{
			sideamount = 1;
			sidetreatment = 1;
		}
		}

		economicpoints = (ce*ce*ce*samount*typecost)*100000 / cc;
		while (economicpoints > 100||economicpoints<10)
		{
			if (economicpoints > 100)	economicpoints /= 10.0;
			if (economicpoints < 10)		economicpoints *= 10.0;
		}
		environmentalpoints = ce*s.carbonfootprint[1] * samount*(1+0.5*cit) / (s.carbonfootprint[0]*(1+init)) + (samount / tamount);	
		while (environmentalpoints > 100 || environmentalpoints<10)
		{
			if (environmentalpoints > 100)	environmentalpoints /= 10.0;
			if (environmentalpoints < 10)		environmentalpoints *= 10.0;
		}

		relativeprocesspoints = sidetreatment*sideamount*(1+pow(s.othertypes.stageto, 2) - pow(s.othertypes.stagefrom, 2));
		while (relativeprocesspoints > 100 || relativeprocesspoints<10)
		{
			if (relativeprocesspoints > 100)	relativeprocesspoints /= 10.0;
			if (relativeprocesspoints < 10)		relativeprocesspoints *= 10.0;
		}
		
		double totalpoints = economicpoints+environmentalpoints+relativeprocesspoints;
		while (totalpoints > 100 || totalpoints<10)
		{
			if (totalpoints > 100)	totalpoints /= 10.0;
			if (totalpoints < 10)		totalpoints *= 10.0;
		}
		return totalpoints;
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
		GlobalData::metal[1] = GlobalData::metal[1] / 182.5;
		GlobalData::nonmetal[1] = GlobalData::nonmetal[1] / 182.5;
		GlobalData::glassnceramics[1] = GlobalData::glassnceramics[1] / 182.5;
		GlobalData::plastics[1] = GlobalData::plastics[1] / 182.5;
		GlobalData::basemetal[1] = GlobalData::basemetal[1] / 182.5;
		GlobalData::carbon[1] = GlobalData::carbon[1] / 182.5;
		GlobalData::preciousmetal[1] = GlobalData::preciousmetal[1] / 182.5;
		GlobalData::hazardousmetal[1] = GlobalData::hazardousmetal[1] / 182.5;
		GlobalData::totalewaste = GlobalData::totalewaste / 182.5;
	}


	int HelperFunctions::GetInit(struct Process p, double samount, double tamount)
	{
		int init = 0;
		double psamount, ptamount;
		psamount = p.amountinput[0];
		ptamount = p.amountinput[1];
		while (samount > psamount || tamount > ptamount)
		{
			init++;
			psamount = p.amountinput[0] *(init + 1);
			ptamount = p.amountinput[1] *(init + 1);			
		}
		return init;
	}


	int HelperFunctions::GetOverrideCit(struct Process p, int init)
	{
		int cit = 0;

		if (p.economicfactors[1] == 1)	return cit;

		double ce=p.efficiency;
		while (p.maxefficiency >= ce && cit <= GlobalData::citmanualovveride)		//20 times the original cost is an automatic override to limit program from going actually at unlimited resources
		{			
			cit++;
			ce = (p.efficiency*(1 + init + 0.01*init*p.economicfactors[0])) / (init + 1);
			ce = ce*(1 + cit*p.economicfactors[1]) / (cit + 1);			
		}
		return (cit - 1);
	}

	int HelperFunctions::Maxpoints(double a[])
	{
		int i;
		double max = a[0];
		int whati = 0;
		for (i = 1; i < 3; i++)
		{
			if (max < a[i])
			{
				max = a[i];
				whati = i;
			}
		}
		return whati;
	}
	
	void HelperFunctions::OtherTypeInfo(struct Process p)
	{
		switch (p.othertypes.typeof)
		{
		case 'B':
		{
			cout << "The given process also helps in treatment of base metals, specifically, it contributes in taking them from stage " << p.othertypes.stagefrom << " to stage " << p.othertypes.stageto << endl;
			break;
		}
		case 'H':
		{
			cout << "The given process also helps in treatment of hazardous metals, specifically, it contributes in taking them from stage " << p.othertypes.stagefrom << " to stage " << p.othertypes.stageto << endl;
			break;
		}
		case 'P':
		{
			cout << "The given process also helps in treatment of precious metals, specifically, it contributes in taking them from stage " << p.othertypes.stagefrom << " to stage " << p.othertypes.stageto << endl;
			break;
		}
		default: 
		{
			cout << endl;
			break;
		}
		}
	}

	void HelperFunctions::Limits()
	{
		if (GlobalData::surveytakers > 5000000 || GlobalData::totalewaste > 100000)
		{
			system("CLS");
			cout << "ERROR:\n\n";
			cout << "The current set of data (either users are more than 50,00,000 or total E-waste per 4 day cycle is more than 1,00,000 kg) is too high for proper analysis.\n\n";
			cout << "Even the biggest E-waste plants on the planet right now will struggle to combat such amounts of e-waste, it is highly recommended to set up multiple plants in this scenario.\n\n";
			cout << "For now, you might want to decrease the multiplication factor of your representative data from Settings, if that's what you've done.\n\n";
			cout << "Press any key to exit the software.\n\n";
			_getche();
			exit(0);
		}
		else return;
	}

}