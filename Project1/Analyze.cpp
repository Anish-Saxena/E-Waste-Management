#include"Analyze.h"
#include "ManageData.h"
#include <stdexcept>

using namespace std;
using namespace ManageData;

namespace Analyze
{
	//Testing phase (7th Oct 2017), say the given data values are obtained after ManageData functions act on user surveys, 
	//assigning hard coded values for testing purposes to the variables to showcase Analyze functions. Values represent 
	//about 20 laptops, 20 mobile phones-tablets and 5-10 computers worth of E-waste
	double GlobalData::gold = 0.0194, GlobalData::aluminum = 7.452, GlobalData::carbon = 0.945, GlobalData::copper = 2.541, GlobalData::electrolyte = 1.512, 
	GlobalData::glass = 10.11, GlobalData::lead = 0.051, GlobalData::lithium = 0.255, GlobalData::magnesium = 17.8, GlobalData::mercury = 0.0068, GlobalData::ceramics=5.435,
	GlobalData::nickel = 0.0291, GlobalData::plastics = 8.11, GlobalData::silicon = 0.41, GlobalData::silver = 0.175, GlobalData::steel = 1.04;
}