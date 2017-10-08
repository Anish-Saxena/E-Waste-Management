#include"Analyze.h"
#include "ManageData.h"
#include <stdexcept>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>
#include<string.h>
#include<string>

using namespace std;
using namespace ManageData;

void PrintWidth(const char* t, double x)
{	
	cout << t << "\t\t" << x << " kg" << endl;
}

namespace Analyze
{
	//Testing phase (7th Oct 2017), say the given data values are obtained after ManageData functions act on user surveys, 
	//assigning hard coded values for testing purposes to the variables to showcase Analyze functions. Values represent 
	//about 15 laptops, 25 mobile phones-tablets and 5-10 computers worth of E-waste

	//test csv file format: name,age,address, mobiles disposed, laptops disposed, tablets disposed, pcs disposed, are mobiles shared?, are laptops shared?,are tablets shared?,are pcs shared? 
	
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
		
	}
	void Display::ComponentBreakup()
	{
		cout << "Let us now see how much of each substance, be it metal, glass, ceramics, etc., is approximately present (in total) in this E-waste:" << endl << endl;
		Sleep(1000);
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
	void Display::PreProcessing()
	{
		cout << "Preprocessing of e-waste is one of the most important steps in the E-waste treatment chain." << endl << endl;
		Sleep(1000);
		cout << " The non-usable components are dismantled at the collection facilities prior to sending to the treatment plant.";
		cout << " Mechanical processing is an integrated part of this stage where E-waste scrap is shredded into pieces using hammer mills.";
		cout << " Metals and non-metals are separated during this stage using techniques similar to that used in the";
		cout<<"	mineral dressing, e.g., screening, magnetic, eddy current and density separation techniques" << endl << endl;
		Sleep(1000);
		cout << "Since this project aims to manage the E-waste from the time it is collected, the first crucial step, Preprocessing, has been illustrated. It involves the following steps:" << endl << endl;
		Sleep(1000);
		cout << "Sorting and Dismantling\t------>\tSeperation of Re-usable parts" << endl;
		cout << "\t|\n\t|\n\t|\n\t\\/" << endl;
		cout << "Mechanical Processing\t------>\tSeperation of wirings metals and plastics"<<endl;
		cout << "\t|\n\t|\n\t|\n\t\\/" << endl;
		cout << "Vibrating Screen" << endl;
		cout << "\t|\n\t|\n\t|\n\t\\/" << endl;
		cout << "Magnetic Seperation\t------>\tSeperation of Ferrous metals" << endl;
		cout << "\t|\n\t|\n\t|\n\t\\/" << endl;
		cout << "Eddy current seperation\t------>\tSeperation of Non-Ferrous metals" << endl;
		cout << "\t|\n\t|\n\t|\n\t\\/" << endl;
		cout << "Density Seperation\t------>\tSeperation of Plastics" << endl;
		cout << "\t|\n\t|\n\t|\n\t\\/" << endl;
		cout << "Disposalt\t------>\tLandfills" << endl;
	}
	void Display::ProcessingMetals()
	{
		cout<<"The metal fractions separated from e-waste during preprocessing can be further processed using";
		cout << " hydrometallurgical, pyrometallurgical, electrometallurgical, biometallurgical processes, and their";
		cout << " combinations. The hydrometallurgical and pyrometallurgical processes are the major routes for";
		cout << "processing of e-waste. These routes may be followed by electrometallurgical/electrochemical processes";
		cout << "(for example electrorefining or electrowinning) for selected metal separation and recovery.";
		cout << "";
		cout << "";

	}
}