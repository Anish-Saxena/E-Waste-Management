#include"Processes.h"

namespace Processes
{


	void Metaldef(Process p[])
	{
		
		//Process 0: Ion Exchange Process, for base metals, to get them from extraction to refining phase, also makes precious metals go from extraction to refining

		p[0].information = "Ion Exchange process, Hydrometallurgy.";
		p[0].category = 0;
		p[0].type = 'B';
		p[0].cost = 750000;
		p[0].efficiency = 0.92;
		p[0].maxefficiency = 0.99;
		p[0].economicfactors[0] = 1.05;
		p[0].economicfactors[1] = 1.05;
		p[0].amountinput[0] = 100;
		p[0].amountinput[1] = 250;
		p[0].carbonfootprint[0] = 55000;
		p[0].carbonfootprint[1] = 80000;
		p[0].stagefrom = 2;
		p[0].stageto = 3;
		p[0].othertypes.stagefrom = 2;
		p[0].othertypes.stageto = 3;
		p[0].othertypes.typeof = 'P';

		//Process 1: Adsorption, for Precious Metalss, to get them from extraction to refining phase, doesn't act on other types of E-waste

		p[1].information = "Adsorption process, Hydrometallury.";
		p[1].category = 0;
		p[1].type = 'P';
		p[1].cost = 500000;
		p[1].efficiency = 0.97;
		p[1].maxefficiency = 0.99;
		p[1].economicfactors[0] = 0.98;
		p[1].economicfactors[1] = 1.05;
		p[1].amountinput[0] = 1.5;
		p[1].amountinput[1] = 250;
		p[1].carbonfootprint[0] = 25000;
		p[1].carbonfootprint[1] = 65000;
		p[1].stagefrom = 2;
		p[1].stageto = 3;
		p[1].othertypes.stagefrom = -1;
		p[1].othertypes.stageto = -1;
		p[1].othertypes.typeof = 'Z';

		//Process 2: Vat Leaching, for Precious Metalss, to get them from leaching to extraction phase, also makes base Metalss go from leaching to extraction

		p[2].information = "Vat Leaching, Hydrometallurgy.";
		p[2].type = 'P';
		p[2].category = 0;
		p[2].cost = 320000;
		p[2].efficiency = 0.85;
		p[2].maxefficiency = 0.90;
		p[2].economicfactors[0] = 0.95;
		p[2].economicfactors[1] = 1.05;
		p[2].amountinput[0] = 1.2;
		p[2].amountinput[1] = 200;
		p[2].carbonfootprint[0] = 35000;
		p[2].carbonfootprint[1] = 60000;
		p[2].stagefrom = 1;
		p[2].stageto = 2;
		p[2].othertypes.stagefrom = 1;
		p[2].othertypes.stageto = 2;
		p[2].othertypes.typeof = 'B';

		//Process 3: Caustic Leaching, for Precious Metalss, to get them from leaching to extraction phase, doesn't act on other types of E-waste

		p[3].information = "Caustic Leaching, Hydrometallurgy.";
		p[3].type = 'P';
		p[3].category = 0;
		p[3].cost = 270000;
		p[3].efficiency = 0.80;
		p[3].maxefficiency = 0.90;
		p[3].economicfactors[0] = 0.90;
		p[3].economicfactors[1] = 1;
		p[3].amountinput[0] = 1.0;
		p[3].amountinput[1] = 100;
		p[3].carbonfootprint[0] = 30000;
		p[3].carbonfootprint[1] = 60000;
		p[3].stagefrom = 1;
		p[3].stageto = 2;
		p[3].othertypes.stagefrom = -1;
		p[3].othertypes.stageto = -1;
		p[3].othertypes.typeof = 'Z';

		//Process 4: Autoclave leaching, for precious Metalss, to get them from leaching to extraction phase, also makes hazardous Metalss go from leaching to extraction

		p[4].information = "Autoclave leaching, Hydrometallurgy.";
		p[4].type = 'P';
		p[4].category = 0;
		p[4].cost = 975000;
		p[4].efficiency = 0.95;
		p[4].maxefficiency = 0.999;
		p[4].economicfactors[0] = 0.99;
		p[4].economicfactors[1] = 1.05;
		p[4].amountinput[0] = 1.5;
		p[4].amountinput[1] = 250;
		p[4].carbonfootprint[0] = 40000;
		p[4].carbonfootprint[1] = 65000;
		p[4].stagefrom = 1;
		p[4].stageto = 2;
		p[4].othertypes.stagefrom = 1;
		p[4].othertypes.stageto = 2;
		p[4].othertypes.typeof = 'H';

		//Process 5: Shaft Furnace calcination, for base Metalss, to get them from Purification to recovery, also makes hazardous Metalss go from purifcation to recovery

		p[5].information = "Shaft furnace calcination, pyrometallurgy.";
		p[5].type = 'B';
		p[5].category = 0;
		p[5].cost = 500000;
		p[5].efficiency = 0.97;
		p[5].maxefficiency = 0.9999;
		p[5].economicfactors[0] = 1.05;
		p[5].economicfactors[1] = 1;
		p[5].amountinput[0] = 120;
		p[5].amountinput[1] = 300;
		p[5].carbonfootprint[0] = 25000;
		p[5].carbonfootprint[1] = 65000;
		p[5].stagefrom = 1;
		p[5].stageto = 2;
		p[5].othertypes.stagefrom = 1;
		p[5].othertypes.stageto = 2;
		p[5].othertypes.typeof = 'H';

		//Process 6: Shaft Furnace calcination, for base Metalss, to get them from Purification to recovery, also makes hazardous Metalss go from purifcation to recovery

		p[6].information = "Fluidized bed reactor, pyrometallurgy.";
		p[6].type = 'B';
		p[6].category = 0;
		p[6].cost = 620000;
		p[6].efficiency = 0.975;
		p[6].maxefficiency = 0.9999;
		p[6].economicfactors[0] = 1.1;
		p[6].economicfactors[1] = 1.01;
		p[6].amountinput[0] = 150;
		p[6].amountinput[1] = 375;
		p[6].carbonfootprint[0] = 40000;
		p[6].carbonfootprint[1] = 50000;
		p[6].stagefrom = 1;
		p[6].stageto = 2;
		p[6].othertypes.stagefrom = 1;
		p[6].othertypes.stageto = 2;
		p[6].othertypes.typeof = 'H';

		//Process 7: Pyrolytic Extraction: for base Metalss, to get them from Purification to recovery, also makes hazardous Metalss go from purification to recovery

		p[7].information = "Pyrolytic Extraction, pyrometallurgy.";
		p[7].type = 'B';
		p[7].category = 0;
		p[7].cost = 580000;
		p[7].efficiency = 0.95;
		p[7].maxefficiency = 0.99;
		p[7].economicfactors[0] = 1.1;
		p[7].economicfactors[1] = 1.005;
		p[7].amountinput[0] = 100;
		p[7].amountinput[1] = 250;
		p[7].carbonfootprint[0] = 45000;
		p[7].carbonfootprint[1] = 50000;
		p[7].stagefrom = 1;
		p[7].stageto = 2;
		p[7].othertypes.stagefrom = 1;
		p[7].othertypes.stageto = 2;
		p[7].othertypes.typeof = 'H';

		//Process 8: Parke's Process, for hazardous Metalss, to get them from Purification to recovery, also makes precious Metalss go from purification and recovery

		p[8].information = "Parke's Process, pyrometallurgy.";
		p[8].type = 'H';
		p[8].category = 0;
		p[8].cost = 450000;
		p[8].efficiency = 0.97;
		p[8].maxefficiency = 0.9999;
		p[8].economicfactors[0] = 1.05;
		p[8].economicfactors[1] = 1.06;
		p[8].amountinput[0] = 0.5;
		p[8].amountinput[1] = 250;
		p[8].carbonfootprint[0] = 60000;
		p[8].carbonfootprint[1] = 80000;
		p[8].stagefrom = 1;
		p[8].stageto = 2;
		p[8].othertypes.stagefrom = 1;
		p[8].othertypes.stageto = 2;
		p[8].othertypes.typeof = 'P';

		//Process 9: Distillation process: for hazardous Metalss, to get them from Purification to recovery, doesn't act on other types of e-waste

		p[9].information = "Distillation process, hydrometallurgy.";
		p[9].type = 'H';
		p[9].category = 0;
		p[9].cost = 400000;
		p[9].efficiency = 0.92;
		p[9].maxefficiency = 0.97;
		p[9].economicfactors[0] = 1.01;
		p[9].economicfactors[1] = 1.029;
		p[9].amountinput[0] = 0.6;
		p[9].amountinput[1] = 225;
		p[9].carbonfootprint[0] = 50000;
		p[9].carbonfootprint[1] = 75000;
		p[9].stagefrom = 1;
		p[9].stageto = 2;
		p[9].othertypes.stagefrom = -1;
		p[9].othertypes.stageto = -1;
		p[9].othertypes.typeof = 'Z';

		//Process 10: Extractive Roasting: for hazardous Metalss, to get them from Purification to recovery, also makes base Metalss go from purification to recovery

		p[10].information = "Extractive Roasting, pyrometallurgy.";
		p[10].type = 'H';
		p[10].category = 0;
		p[10].cost = 600000;
		p[10].efficiency = 0.75;
		p[10].maxefficiency = 0.95;
		p[10].economicfactors[0] = 0.99;
		p[10].economicfactors[1] = 1.042;
		p[10].amountinput[0] = 0.5;
		p[10].amountinput[1] = 240;
		p[10].carbonfootprint[0] = 60000;
		p[10].carbonfootprint[1] = 80000;
		p[10].stagefrom = 1;
		p[10].stageto = 2;
		p[10].othertypes.stagefrom = 1;
		p[10].othertypes.stageto = 2;
		p[10].othertypes.typeof = 'B';

		//Process 11: Mertill-Crowe Process: for precious Metalss, to get them from Recovery to refining, doesn't act on other types of E-waste

		p[11].information = "Merill-Crowe Process, hydrometallurgy.";
		p[11].type = 'P';
		p[11].category = 0;
		p[11].cost = 400000;
		p[11].efficiency = 0.82;
		p[11].maxefficiency = 0.96;
		p[11].economicfactors[0] = 1.03;
		p[11].economicfactors[1] = 1.057;
		p[11].amountinput[0] = 1.5;
		p[11].amountinput[1] = 250;
		p[11].carbonfootprint[0] = 35000;
		p[11].carbonfootprint[1] = 60000;
		p[11].stagefrom = 2;
		p[11].stageto = 3;
		p[11].othertypes.stagefrom = -1;
		p[11].othertypes.stageto = -1;
		p[11].othertypes.typeof = 'Z';

		//Process 12: Park and Fray Process, for precious Metalss, to get them from recovery to refining, doesn't act on other types of E-waste

		p[12].information = "Park and Fray Process, hydrometallurgy.";
		p[12].type = 'P';
		p[12].category = 0;
		p[12].cost = 350000;
		p[12].efficiency = 0.97;
		p[12].maxefficiency = 0.9999;
		p[12].economicfactors[0] = 1.2;
		p[12].economicfactors[1] = 1.08;
		p[12].amountinput[0] = 1.5;
		p[12].amountinput[1] = 250;
		p[12].carbonfootprint[0] = 40000;
		p[12].carbonfootprint[1] = 60000;
		p[12].stagefrom = 2;
		p[12].stageto = 3;
		p[12].othertypes.stagefrom = -1;
		p[12].othertypes.stageto = -1;
		p[12].othertypes.typeof = 'Z';

		//Process 13: Kogan Process, for base Metalss, to get them from recovery to refining, also makes hazardous Metalss go from recovery to refining

		p[13].information = "Kogan Process, hydrometallurgy.";
		p[13].type = 'B';
		p[13].category = 0;
		p[13].cost = 750000;
		p[13].efficiency = 0.85;
		p[13].maxefficiency = 0.99;
		p[13].economicfactors[0] = 1.01;
		p[13].economicfactors[1] = 1.2;
		p[13].amountinput[0] = 150;
		p[13].amountinput[1] = 375;
		p[13].carbonfootprint[0] = 35000;
		p[13].carbonfootprint[1] = 80000;
		p[13].stagefrom = 2;
		p[13].stageto = 3;
		p[13].othertypes.stagefrom = 2;
		p[13].othertypes.stageto = 3;
		p[13].othertypes.typeof = 'H';

		//Process 14: Unicore Process, for base Metalss, to get them from recovery to refining, also makes precious Metalss go from recovery to refining

		p[14].information = "Unicore Process, pyrometallurgy.";
		p[14].type = 'B';
		p[14].category = 0;
		p[14].cost = 600000;
		p[14].efficiency = 0.95;
		p[14].maxefficiency = 0.99;
		p[14].economicfactors[0] = 1.001;
		p[14].economicfactors[1] = 1.08;
		p[14].amountinput[0] = 150;
		p[14].amountinput[1] = 375;
		p[14].carbonfootprint[0] = 35000;
		p[14].carbonfootprint[1] = 80000;
		p[14].stagefrom = 2;
		p[14].stageto = 3;
		p[14].othertypes.stagefrom = 2;
		p[14].othertypes.stageto = 3;
		p[14].othertypes.typeof = 'P';

		//Process 15: Ronnskar Smetler process: for hazardous Metalss, to get them from recovery to refining, also makes precious Metalss go from recovery to refining

		p[15].information = "Ronnskar Smelter Process, pyrometallugry.";
		p[15].type = 'H';
		p[15].category = 0;
		p[15].cost = 700000;
		p[15].efficiency = 0.97;
		p[15].maxefficiency = 0.99;
		p[15].economicfactors[0] = 1.04;
		p[15].economicfactors[1] = 1.08;
		p[15].amountinput[0] = 0.25;
		p[15].amountinput[1] = 400;
		p[15].carbonfootprint[0] = 45000;
		p[15].carbonfootprint[1] = 65000;
		p[15].stagefrom = 2;
		p[15].stageto = 3;
		p[15].othertypes.stagefrom = 2;
		p[15].othertypes.stageto = 3;
		p[15].othertypes.typeof = 'P';

		//Process 16: Outotec Process, for hazardous Metalss, to get them from recovery to refining, doesn't act on other types of E-waste

		p[16].information = "Outotec Process, pyrometallurgy.";
		p[16].type = 'H';
		p[16].category = 0;
		p[16].cost = 450000;
		p[16].efficiency = 0.90;
		p[16].maxefficiency = 0.97;
		p[16].economicfactors[0] = 1.01;
		p[16].economicfactors[1] = 1.02;
		p[16].amountinput[0] = 0.5;
		p[16].amountinput[1] = 250;
		p[16].carbonfootprint[0] = 55000;
		p[16].carbonfootprint[1] = 90000;
		p[16].stagefrom = 2;
		p[16].stageto = 3;
		p[16].othertypes.stagefrom = -1;
		p[16].othertypes.stageto = -1;
		p[16].othertypes.typeof = 'Z';

		//Process 17: Mecucci and Scott Process, for hazardous Metalss, to get them from recovery to refining, doesn't act on other types of E-waste

		p[17].information = "Mecucci and Scott Process, hydrometallurgy.";
		p[17].type = 'H';
		p[17].category = 0;
		p[17].cost = 350000;
		p[17].efficiency = 0.90;
		p[17].maxefficiency = 0.95;
		p[17].economicfactors[0] = 0.94;
		p[17].economicfactors[1] = 1.012;
		p[17].amountinput[0] = 0.45;
		p[17].amountinput[1] = 350;
		p[17].carbonfootprint[0] = 45000;
		p[17].carbonfootprint[1] = 60000;
		p[17].stagefrom = 2;
		p[17].stageto = 3;
		p[17].othertypes.stagefrom = -1;
		p[17].othertypes.stageto = -1;
		p[17].othertypes.typeof = 'Z';

		//Process 18: Electrorefining process: for precious Metalss, to get them from refining phase to done!, also makes hazardous Metalss go from refining to done!

		p[18].information = "Electrorefining Process, electrometallurgy.";
		p[18].type = 'P';
		p[18].category = 0;
		p[18].cost = 900000;
		p[18].efficiency = 0.98;
		p[18].maxefficiency = 0.99999;
		p[18].economicfactors[0] = 1.01;
		p[18].economicfactors[1] = 1.006;
		p[18].amountinput[0] = 1.4;
		p[18].amountinput[1] = 400;
		p[18].carbonfootprint[0] = 40000;
		p[18].carbonfootprint[1] = 100000;
		p[18].stagefrom = 3;
		p[18].stageto = 4;
		p[18].othertypes.stagefrom = 3;
		p[18].othertypes.stageto = 4;
		p[18].othertypes.typeof = 'H';

		//Process 19: Noranda process: for precious Metalss, to get them from refining phase to done1, also makes hazardous Metalss go from refining to done!

		p[19].information = "Noranda Process, pyrometallurgy.";
		p[19].type = 'P';
		p[19].category = 0;
		p[19].cost = 800000;
		p[19].efficiency = 0.94;
		p[19].maxefficiency = 0.99;
		p[19].economicfactors[0] = 1.01;
		p[19].economicfactors[1] = 1.09;
		p[19].amountinput[0] = 1.8;
		p[19].amountinput[1] = 240;
		p[19].carbonfootprint[0] = 45000;
		p[19].carbonfootprint[1] = 90000;
		p[19].stagefrom = 3;
		p[19].stageto = 4;
		p[19].othertypes.stagefrom = 3;
		p[19].othertypes.stageto = 4;
		p[19].othertypes.typeof = 'H';

		//Process 20: Veit Process: for base Metalss, to get them from refining to done!, doesn't act onother types of E-waste

		p[20].information = "Veit Process, hydrometallurgy.";
		p[20].type = 'B';
		p[20].category = 0;
		p[20].cost = 400000;
		p[20].efficiency = 0.92;
		p[20].maxefficiency = 0.98;
		p[20].economicfactors[0] = 1.01;
		p[20].economicfactors[1] = 1.08;
		p[20].amountinput[0] = 150;
		p[20].amountinput[1] = 400;
		p[20].carbonfootprint[0] = 55000;
		p[20].carbonfootprint[1] = 75000;
		p[20].stagefrom = 3;
		p[20].stageto = 4;
		p[20].othertypes.stagefrom = -1;
		p[20].othertypes.stageto = -1;
		p[20].othertypes.typeof = 'Z';

		//Process 21: Fire refining: for base Metalss, to get them from refining to done!, doesn't act onother types of E-waste

		p[21].information = "Fire refining, pyrometallurgy.";
		p[21].type = 'B';
		p[21].category = 0;
		p[21].cost = 520000;
		p[21].efficiency = 0.94;
		p[21].maxefficiency = 0.99;
		p[21].economicfactors[0] = 1.001;
		p[21].economicfactors[1] = 1.06;
		p[21].amountinput[0] = 175;
		p[21].amountinput[1] = 300;
		p[21].carbonfootprint[0] = 50000;
		p[21].carbonfootprint[1] = 60000;
		p[21].stagefrom = 3;
		p[21].stageto = 4;
		p[21].othertypes.stagefrom = -1;
		p[21].othertypes.stageto = -1;
		p[21].othertypes.typeof = 'Z';

		//Refining of hazardous Metalss is done along with their recovery, software will take care of that
	}
}