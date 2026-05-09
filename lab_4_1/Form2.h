#pragma once

namespace lab_4_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
		}

	protected:
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnStop;
	private: System::Windows::Forms::Button^ btnRetry;
	private: System::Windows::Forms::Button^ btnIgnore;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnRetry = (gcnew System::Windows::Forms::Button());
			this->btnIgnore = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();

			// 
			// btnStop
			// 
			this->btnStop->BackColor = System::Drawing::Color::LightCoral;
			this->btnStop->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnStop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnStop->FlatAppearance->BorderColor = System::Drawing::Color::DarkRed;
			this->btnStop->FlatAppearance->BorderSize = 2;
			this->btnStop->ForeColor = System::Drawing::Color::Black;
			this->btnStop->Location = System::Drawing::Point(35, 45);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(100, 35);
			this->btnStop->TabIndex = 0;
			this->btnStop->TabStop = false;
			this->btnStop->Text = L"Стоп";
			this->btnStop->UseVisualStyleBackColor = false;
			this->btnStop->Click += gcnew System::EventHandler(this, &Form2::btnStop_Click);

			// 
			// btnRetry
			// 
			this->btnRetry->BackColor = System::Drawing::Color::LightGreen;
			this->btnRetry->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRetry->DialogResult = System::Windows::Forms::DialogResult::Retry;
			this->btnRetry->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRetry->ForeColor = System::Drawing::Color::DarkGreen;
			this->btnRetry->Location = System::Drawing::Point(155, 45);
			this->btnRetry->Name = L"btnRetry";
			this->btnRetry->Size = System::Drawing::Size(100, 35);
			this->btnRetry->TabIndex = 1;
			this->btnRetry->Text = L"Повтор";
			this->btnRetry->UseVisualStyleBackColor = false;

			// 
			// btnIgnore
			// 
			this->btnIgnore->BackColor = System::Drawing::Color::LightYellow;
			this->btnIgnore->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnIgnore->DialogResult = System::Windows::Forms::DialogResult::Ignore;
			this->btnIgnore->FlatStyle = System::Windows::Forms::FlatStyle::Standard;
			this->btnIgnore->ForeColor = System::Drawing::Color::DarkOrange;
			this->btnIgnore->Location = System::Drawing::Point(275, 45);
			this->btnIgnore->Name = L"btnIgnore";
			this->btnIgnore->Size = System::Drawing::Size(110, 35);
			this->btnIgnore->TabIndex = 2;
			this->btnIgnore->Text = L"Пропустить";
			this->btnIgnore->UseVisualStyleBackColor = false;

			// 
			// Form2
			// 
			this->AcceptButton = this->btnRetry;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnIgnore;
			this->ClientSize = System::Drawing::Size(420, 130);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnRetry);
			this->Controls->Add(this->btnIgnore);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Вариант 1";
			this->ResumeLayout(false);
		}

#pragma endregion

	private: System::Void btnStop_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->DialogResult = System::Windows::Forms::DialogResult::Abort;
		this->Close();
	}
	};
}