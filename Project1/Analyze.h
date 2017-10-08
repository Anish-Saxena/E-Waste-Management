#pragma once

namespace Analyze
{
	//This class stores aggregate data values for whole survey
	class GlobalData
	{
	public:
		static double gold, silver, copper, mercury, steel, aluminum, lead, ceramics,
		lithium, nickel, magnesium, carbon, electrolyte, plastics, glass, silicon;
		static int surveytakers, laptopnumber, mobilenumber, tabletnumber, pcnumber;
		static int totalshared, laptopshared, mobileshared, tabletshared, pcshared;		
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
	};
	
}