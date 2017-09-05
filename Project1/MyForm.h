#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  Note;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ListBox^  listBox3;
	private: System::Windows::Forms::ListBox^  listBox4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;





	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->Note = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Full Name:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(217, 9);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(325, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Age:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(217, 46);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(142, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Home Address:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(217, 88);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(325, 126);
			this->textBox3->TabIndex = 5;
			// 
			// Note
			// 
			this->Note->AutoSize = true;
			this->Note->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Note->Location = System::Drawing::Point(213, 251);
			this->Note->Name = L"Note";
			this->Note->Size = System::Drawing::Size(724, 46);
			this->Note->TabIndex = 7;
			this->Note->Text = L"Enter information only about electronic gadgets owned personally by you in the fi"
				L"elds below. \r\nIf you share it with other(s), please tick the \"Shared\" checkbox.\r"
				L"\n";
			this->Note->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(13, 347);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 24);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Mobile Phone(s):";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click_1);
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 24;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"0", L"1", L"2", L"3", L"4", L">4" });
			this->listBox1->Location = System::Drawing::Point(217, 347);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 28);
			this->listBox1->TabIndex = 9;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(14, 401);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 24);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Laptop(s):";
			// 
			// listBox2
			// 
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 24;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"0", L"1", L"2", L"3", L"4", L">4" });
			this->listBox2->Location = System::Drawing::Point(217, 401);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(120, 28);
			this->listBox2->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(13, 260);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(147, 25);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Please Note:";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(580, 347);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(198, 24);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Personal Computer(s):";
			// 
			// listBox3
			// 
			this->listBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 24;
			this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"0", L"1", L"2", L"3", L"4", L">4" });
			this->listBox3->Location = System::Drawing::Point(833, 347);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(120, 28);
			this->listBox3->TabIndex = 14;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox3_SelectedIndexChanged);
			// 
			// listBox4
			// 
			this->listBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 24;
			this->listBox4->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"0", L"1", L"2", L"3", L"4", L">4" });
			this->listBox4->Location = System::Drawing::Point(833, 401);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(120, 28);
			this->listBox4->TabIndex = 15;
			this->listBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox4_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(580, 401);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(83, 24);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Tablet(s)";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(386, 351);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 24);
			this->checkBox1->TabIndex = 17;
			this->checkBox1->Text = L"Shared";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->Location = System::Drawing::Point(386, 401);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(80, 24);
			this->checkBox2->TabIndex = 18;
			this->checkBox2->Text = L"Shared";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox3->Location = System::Drawing::Point(1026, 351);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(80, 24);
			this->checkBox3->TabIndex = 19;
			this->checkBox3->Text = L"Shared";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox4->Location = System::Drawing::Point(1026, 401);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(80, 24);
			this->checkBox4->TabIndex = 20;
			this->checkBox4->Text = L"Shared";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1154, 614);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->listBox4);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Note);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"MyForm";
			this->Text = L"User Survey";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
