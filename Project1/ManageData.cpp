#include "ManageData.h"

#include <stdexcept>

using namespace std;

namespace ManageData
{
	//All data is in kg
	const double LaptopData::gold = 0.000775, LaptopData::mercury = 0.000297, LaptopData::copper = 0.078591, LaptopData::plastics = 0.225,
	LaptopData::steel = 0.035, LaptopData::lithium = 0.007, LaptopData::lead = 0.001524, LaptopData::carbon = 0.025, LaptopData::glass=0.570,
	LaptopData::nickel = 0.001024, LaptopData::aluminum = 0.215, LaptopData::magnesium = 0.525, LaptopData::electrolyte = 0.055, LaptopData::silicon= 0.01;
}