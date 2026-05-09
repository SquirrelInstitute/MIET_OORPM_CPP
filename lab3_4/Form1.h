#pragma once

namespace lab3 {

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

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 300);
			this->Name = L"Form1";
			this->Text = L"Задумайте целое число от 1 до 9 (Перелыгин)";
			this->DoubleClick += gcnew System::EventHandler(this, &Form1::Form1_DoubleClick);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void Form1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		int left = 1;
		int right = 9;
		int mid;
		System::Windows::Forms::DialogResult result;

		MessageBox::Show(
			L"Задумайте целое число от 1 до 9 и отвечайте на вопросы.",
			L"Угадатор"
		);
		while (left < right)
		{
			mid = (left + right) / 2;

			result = MessageBox::Show(
				L"Ваше число больше " + mid.ToString() + L"?",
				L"Угадывание числа",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		MessageBox::Show(
			L"Вы задумали число " + left.ToString(),
			L"Результат"
		);
	}
	};
}