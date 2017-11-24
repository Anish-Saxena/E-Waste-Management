#pragma once
#include<string>
#include"Processes.h"

using namespace std;
using namespace Processes;

namespace Analyze
{
	//This class stores aggregate data values for whole survey
	class GlobalData
	{
	public:
		static double GD[16];

		static int surveytakers, laptopnumber[2], mobilenumber[2], tabletnumber[2], pcnumber[2];	 //var[0] for Owned, var[1] for Disposed

		static int headphonenumber[2], printernumber[2], joysticknumber[2], scannernumber[2], webcamnumber[2], smartwatchnumber[2]; //var[0] for Owned, var[1] for Disposed	

		static int laptopshared[2], mobileshared[2], tabletshared[2], pcshared[2];					 //var[0] for sharing of Owned, var[1] for sharing of Disposed

		static int totalgadgets[2], totalperipherals[2], totalshared[2];							//var[0] for total of owned, var[1] for total of Disposed	

		static double totalewaste, plastics[2], metal[2], nonmetal[2], glassnceramics[2];			//var[0] for percentage, var[1] for total, of given substance

		static double basemetal[2], preciousmetal[2], hazardousmetal[2], carbon[2];					//var[0] for percentage, var[1] for total, of given substance

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
		static double* PointCalc(struct Process, double , double , double, char , int, int, int, double x[][4], int);
		static int Maxpoints(double a[]);
		static void Limits();
	};


	class BestProcess
	{
	public:		
		static void Metals(int level);
		static void NonMetals(double);		
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