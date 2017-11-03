#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

namespace Project1
{
	void MyForm::InsertData()
	{
		using namespace msclr::interop;
		using namespace System;

		fstream file;
		file.open("TestusersNew.csv", ios::app);

		//New record
		file << "\n";
		//Textboxes
		file << "\"" << marshal_as<string>(textBox1->Text) << "\"";	//name
		file << ";" << marshal_as<string>(textBox2->Text);	//age
		file << ";\"" << marshal_as<string>(textBox3->Text) << "\"";	//address
																		//number of each owned electronic item
		file << ";" << (int)numericUpDown8->Value;	//mobiles owned
		file << ";" << (int)numericUpDown7->Value;	//laptops owned
		file << ";" << (int)numericUpDown5->Value;	//tablets owned
		file << ";" << (int)numericUpDown6->Value;	//pcs owned
													//if any of the electronic items owned was shared
		file << ";" << (int)(checkBox4->Checked);	//mobile owned sharing
		file << ";" << (int)(checkBox3->Checked);	//laptop owned sharing
		file << ";" << (int)(checkBox1->Checked);	//tablet owned sharing
		file << ";" << (int)(checkBox2->Checked);	//pc owned sharing
													//peripherals owned
		file << ";" << (int)(checkBox5->Checked);	//headphones
		file << ";" << (int)(checkBox12->Checked);	//printer
		file << ";" << (int)(checkBox11->Checked);	//joystick
		file << ";" << (int)(checkBox10->Checked);	//scanner
		file << ";" << (int)(checkBox9->Checked);	//webcam
		file << ";" << (int)(checkBox8->Checked);	//smartwatch
													//number of each electronic item dumped
		file << ";" << (int)numericUpDown1->Value;	//mobiles dumped
		file << ";" << (int)numericUpDown2->Value;	//laptops dumped
		file << ";" << (int)numericUpDown4->Value;	//tablets dumped
		file << ";" << (int)numericUpDown3->Value;	//pcs dumped
													//if any of the electronic items dumped was shared
		file << ";" << (int)(checkBox7->Checked);	//mobile owned sharing
		file << ";" << (int)(checkBox6->Checked);	//laptop owned sharing
		file << ";" << (int)(checkBox19->Checked);	//tablet owned sharing
		file << ";" << (int)(checkBox20->Checked);	//pc owned sharing
													//peripherals dumped
		file << ";" << (int)(checkBox18->Checked);	//headphones
		file << ";" << (int)(checkBox13->Checked);	//printer
		file << ";" << (int)(checkBox14->Checked);	//joystick
		file << ";" << (int)(checkBox15->Checked);	//scanner
		file << ";" << (int)(checkBox16->Checked);	//webcam
		file << ";" << (int)(checkBox17->Checked);	//smartwatch

		file.close();
	}
}

