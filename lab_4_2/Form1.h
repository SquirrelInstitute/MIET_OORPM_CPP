#pragma once
#include "Form2.h"

namespace lab_4_2 {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class Form1 : public Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	private:
		Button^ btnGraph;

	private:
		void InitializeComponent(void)
		{
			this->btnGraph = gcnew Button();

			this->SuspendLayout();

			// btnGraph
			this->btnGraph->Location = Point(80, 60);
			this->btnGraph->Name = L"btnGraph";
			this->btnGraph->Size = Drawing::Size(180, 45);
			this->btnGraph->Text = L"Построить график";
			this->btnGraph->UseVisualStyleBackColor = true;
			this->btnGraph->Click += gcnew EventHandler(this, &Form1::btnGraph_Click);

			// Form1
			this->ClientSize = Drawing::Size(350, 180);
			this->Controls->Add(this->btnGraph);
			this->Name = L"Form1";
			this->Text = L"П-21Д Перелыгин Андрей, приложение №2";

			this->ResumeLayout(false);
		}

	private:
		System::Void btnGraph_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Form2^ graphForm = gcnew Form2();
			graphForm->ShowDialog();
		}
	};
}