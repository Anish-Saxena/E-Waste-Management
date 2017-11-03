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

		static double totalewaste, plastics[2], preciousmetal[2], metal[2], nonmetal[2], glassnceramics[2];	 //var[0] for percentage, var[1] for total, of given substance

		static int headphonenumber[2], printernumber[2], joysticknumber[2], scannernumber[2], webcamnumber[2], smartwatchnumber[2]; //var[0] for Owned, var[1] for Disposed	

		static int laptopshared[2], mobileshared[2], tabletshared[2], pcshared[2];	 //var[0] for sharing of Owned, var[1] for sharing of Disposed

		static int totalgadgets[2], totalperipherals[2], totalshared[2]; //var[0] for total of owned, var[1] for total of Disposed		
	};


	class HelperFunctions
	{
	public:
		static void WhatLevel(char);

	};


	struct Process
	{
		static char type;
		static int stage;
		static string information;
		static double economicfactor;
		static double environmentalfactor;
		static double inputfactor;
	};



	class BestProcess
	{
	public:
		static void DefineProcess();
		static void Metals();
		static void NonMetals();
	};


	class Display
	{
	public:
		static void GeneralResults();
		static void ComponentBreakup();
		static void PreProcessing();
		static void GeneralProcessing();
		static void MetalProcessing();
		static void NonMetalProcessing();
	};

}