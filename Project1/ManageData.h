#pragma once


namespace ManageData
{
	//These are constant data storing classes

	//Array index to substance mapping:
	//0 is gold, 1 is mercury, 2 is copper, 3 is plastics, 4 is ceramics,5 is steel, 6 is lithium, 7 is lead, 8 is carbon, 
	//9 is glass, 10 is silver, 11 is nickel, 12 is aluminum, 13 is magnesium, 14 is electrolyte, 15 is silicon

	//Class for Gadgets		
	class LaptopData
	{
	public:
		static const double LD[16];
	};
	class MobileData
	{
	public:
		static const double MD[16];
	};
	class TabletData
	{
	public:
		static const double TD[16];
	};
	class PCData
	{
	public:
		static const double PCD[16];
	};
	//Class for Peripherals
	class HeadphoneData
	{
	public:
		static const double HD[16];
	};
	class PrinterData
	{
	public:
		static const double PD[16];
	};
	class ScannerData
	{
	public:
		static const double SD[16];
	};
	class SmartwatchData
	{
	public:
		static const double SWD[16];
	};
	class JoystickData
	{
	public:
		static const double JD[16];
	};
	class WebcamData
	{
	public:
		static const double WD[16];
	};
	//Class for storing typical cost of various types of substance
	class TypeCost
	{
	public:
		static const double basem, preciousm, hazardousm;	//more to be added
	};
	//This class contains data checking and value assigning functions
	class DataManip
	{
	public:
		static void ChecknSum();
		static void AggregateSum();		
		//function checkdata()
		//function assignvalue()
		//function writedata()		
		//other functions		
	};

}