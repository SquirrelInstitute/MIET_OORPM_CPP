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
			this->ClientSize = System::Drawing::Size(400, 300);
			this->Name = L"Form1";
			this->Text = L"Приложение 2. Перелыгин Андрей Романович П-21Д";
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->ResumeLayout(false);
		}
#pragma endregion

	private: System::Void Form1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		System::Windows::Forms::DialogResult result;

		result = MessageBox::Show(
			L"Перелыгин Андрей Романович П-21Д",
			L"Вариант 1",
			MessageBoxButtons::AbortRetryIgnore,
			MessageBoxIcon::Information,
			MessageBoxDefaultButton::Button2
		);

		if (result == System::Windows::Forms::DialogResult::Abort)
		{
			MessageBox::Show(L"Нажата кнопка Стоп", L"Результат");
		}
		else if (result == System::Windows::Forms::DialogResult::Retry)
		{
			MessageBox::Show(L"Нажата кнопка Повтор", L"Результат");
		}
		else if (result == System::Windows::Forms::DialogResult::Ignore)
		{
			MessageBox::Show(L"Нажата кнопка Пропустить", L"Результат");
		}
	}
	};
}