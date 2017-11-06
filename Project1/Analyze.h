#pragma once
#include<string>

using namespace std;

namespace Analyze
{
	//This class stores aggregate data values for whole survey
	class GlobalData
	{
	public:
		static double GD[16];

		static int surveytakers, laptopnumber[2], mobilenumber[2], tabletnumber[2], pcnumber[2]; //var[0] for Owned, var[1] for Disposed

		static int headphonenumber[2], printernumber[2], joysticknumber[2], scannernumber[2], webcamnumber[2], smartwatchnumber[2]; //var[0] for Owned, var[1] for Disposed	

		static int laptopshared[2], mobileshared[2], tabletshared[2], pcshared[2];	 //var[0] for sharing of Owned, var[1] for sharing of Disposed

		static int totalgadgets[2], totalperipherals[2], totalshared[2]; //var[0] for total of owned, var[1] for total of Disposed	

		static double totalewaste, plastics[2], metal[2], nonmetal[2], glassnceramics[2];	 //var[0] for percentage, var[1] for total, of given substance

		static double basemetal[2], preciousmetal[2], hazardousmetal[2];					//var[0] for percentage, var[1] for total, of given substance

		static int citmanualovveride;

		static void SettingFactor(int);

	};


	class HelperFunctions
	{
	public:
		static void WhatLevel(char);
		static void OtherTypeInfo(struct Process);
		static void ConvertperCycle();
		static int GetInit(struct Process, double, double);
		static int GetOverrideCit(struct Process, int);
		static double PointCalc(struct Process, double , double , double, char , int, int, int, double x[][4], int);
		static int Maxpoints(double a[]);
	};

	class BestProcess
	{
	public:		
		static void Metals(int level);
		static void NonMetals();		
	};

	//Defining the structure which'll provide skeleton for all process formats
	struct Process
	{
		string information;			//general info about the process

		double cost;				//cost of running the process (in Rs.)		
		double efficiency;			//efficiency in processing the specific e-waste type from one form to another (in fraction)
		double maxefficiency;		//the max efficiency achievable through the given process
		double economicfactors[2];	//var[0] for returns to scale (input->input*2 then output?) and var[1] for economies of scale (cost->cost*2 then output?)
									//var[0] relates variable scale of process with constant efficiency and var[1] relates variable efficiency of process with constant scale
		double amountinput[2];		//var[0] for specific substance type's amount, var[1] for amount of all of E-waste (in kg)
		int category;				//0 for metals and 1 for nonmetals
		double carbonfootprint[2];	//var[0] for footprint of the process, var[1] for mining the product instad of recycling it in kgs of CO2 equivalents
		char type;					//type of e-waste treated by the given process
									//types: B is for base metals, P is for precious metals, H is for hazardous heavy metals
		int stagefrom;				//what stage the given process works from in case of specific e-waste
		int stageto;					//what stage the given process takes the specific e-waste to

										//stages: for metals: 1->Purification or Leaching, 2->Extraction or recovery, 3->Refining

		struct OT					//if incase the process treats other types as well
		{
			char typeof;
			int stagefrom;
			int stageto;
		}othertypes;

		Process()
		{
			information = "NA";
			cost = 0;			
			efficiency = 0;
			maxefficiency = 0;
			economicfactors[0] = 0;
			economicfactors[1] = 0;
			amountinput[0] = 0;
			amountinput[1] = 0;
			carbonfootprint[0] = 0;
			carbonfootprint[1] = 0;
			type = 'Z';
			stagefrom = -5;
			stageto = -4;
			othertypes.stagefrom = -10;
			othertypes.stageto = -5;
			othertypes.typeof = 'Z';
		}
	};
	
	class Display
	{
	public:
		static void GeneralResults();
		static void ComponentBreakup(int *flag);
		static void PreProcessing();
		static void GeneralProcessing();
		static void Processing();
	};

}