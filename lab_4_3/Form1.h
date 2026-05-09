#pragma once
#include "Form2.h"

namespace lab_4_3 {

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
		Button^ btnOpenEditor;

	private:
		void InitializeComponent(void)
		{
			this->btnOpenEditor = gcnew Button();

			this->SuspendLayout();

			// btnOpenEditor
			this->btnOpenEditor->Location = Point(70, 55);
			this->btnOpenEditor->Name = L"btnOpenEditor";
			this->btnOpenEditor->Size = Drawing::Size(220, 45);
			this->btnOpenEditor->Text = L"Открыть графический редактор";
			this->btnOpenEditor->UseVisualStyleBackColor = true;
			this->btnOpenEditor->Click += gcnew EventHandler(this, &Form1::btnOpenEditor_Click);

			// Form1
			this->ClientSize = Drawing::Size(370, 170);
			this->Controls->Add(this->btnOpenEditor);
			this->Name = L"Form1";
			this->Text = L"П-21Д Перелыгин Андрей, приложение №3";

			this->ResumeLayout(false);
		}

	private:
		System::Void btnOpenEditor_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Form2^ editorForm = gcnew Form2();

			// Немодальный режим
			editorForm->Show();
		}
	};
}