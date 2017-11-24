#pragma once
#include<string>

using namespace std;

namespace Processes
{
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
	
	void Metaldef(Process p[]);

}