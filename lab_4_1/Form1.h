#pragma once
#include "Form2.h"

namespace lab_4_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->BackColor = System::Drawing::Color::LightBlue;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->button1->FlatAppearance->BorderSize = 2;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Yellow;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightGreen;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::DarkBlue;
			this->button1->Location = System::Drawing::Point(40, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"&Открыть модальную форму с кнопками";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightYellow;
			this->button2->Cursor = System::Windows::Forms::Cursors::Cross;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->ForeColor = System::Drawing::Color::DarkRed;
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(40, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 40);
			this->button2->TabIndex = 1;
			this->button2->Text = L"&Открыть модальную форму с кнопками";
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->AutoEllipsis = true;
			this->button3->BackColor = System::Drawing::Color::MistyRose;
			this->button3->Cursor = System::Windows::Forms::Cursors::Help;
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(40, 155);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 35);
			this->button3->TabIndex = 2;
			this->button3->Text = L"&Открыть модальную форму с кнопками";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(420, 250);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Name = L"Form1";
			this->Text = L"П-21Д Перелыгин Андрей, приложение №1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void ShowModalForm()
	{
		Form2^ form = gcnew Form2();

		System::Windows::Forms::DialogResult result = form->ShowDialog();

		if (result == System::Windows::Forms::DialogResult::Abort)
		{
			MessageBox::Show(L"Нажата кнопка Стоп");
		}
		else if (result == System::Windows::Forms::DialogResult::Retry)
		{
			MessageBox::Show(L"Нажата кнопка Повтор");
		}
		else if (result == System::Windows::Forms::DialogResult::Ignore)
		{
			MessageBox::Show(L"Нажата кнопка Пропустить");
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ShowModalForm();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ShowModalForm();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ShowModalForm();
	}
	};
}