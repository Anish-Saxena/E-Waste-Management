#pragma once

namespace Analyze
{
	//This class stores aggregate data values for whole survey
	class GlobalData
	{
	public:
		static double GD[16];

		static int surveytakers, laptopnumber[2], mobilenumber[2], tabletnumber[2], pcnumber[2]; //var[0] for Owned, var[1] for Disposed

		static double totalewaste[2], preciousmetal[2], metal[2], nonmetal[2], glassnceramics[2];	 //var[0] for total of owned, var[1] for total of Disposed

		static int headphonenumber[2], printernumber[2], joysticknumber[2], scannernumber[2], webcamnumber[2], smartwatchnumber[2]; //var[0] for Owned, var[1] for Disposed	

		static int laptopshared[2], mobileshared[2], tabletshared[2], pcshared[2];	 //var[0] for sharing of Owned, var[1] for sharing of Disposed

		static int totalgadgets[2], totalperipherals[2], totalshared[2]; //var[0] for total of owned, var[1] for total of Disposed		
	};
	class BestProcess
	{
	public:
		static void Metals();
	};
	class Display
	{
	public:
		static void GeneralResults();		
		static void ComponentBreakup();
		static void PreProcessing();
		static void ProcessingMetals();
	};
	
}