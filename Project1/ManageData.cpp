#include "ManageData.h"
#include"Analyze.h"
#include <stdexcept>

using namespace std;

namespace ManageData
{
	//All data is in kg

	//FOR LAPTOP DATA:
	const double LaptopData::gold = 0.000775, LaptopData::mercury = 0.000297, LaptopData::copper = 0.078591, LaptopData::plastics = 0.225, LaptopData::ceramics = 0.155,
	LaptopData::steel = 0.035, LaptopData::lithium = 0.007, LaptopData::lead = 0.001524, LaptopData::carbon = 0.025, LaptopData::glass = 0.332, LaptopData::silver = 0.0055,
	LaptopData::nickel = 0.001024, LaptopData::aluminum = 0.215, LaptopData::magnesium = 0.525, LaptopData::electrolyte = 0.055, LaptopData::silicon= 0.01;

	//FOR MOBILE DATA:
	
	//FOR PC DATA:

	//FOR TABLET DATA:

	double DataManip::test() //Testing...
	{
		return 5.5;
	}
}