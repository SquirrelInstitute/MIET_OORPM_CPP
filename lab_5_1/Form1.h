#pragma once

namespace lab_5_1 {

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
			InitializeData();
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

		MenuStrip^ menuStrip1;
		ToolStripMenuItem^ fileMenuItem;
		ToolStripMenuItem^ exitMenuItem;
		ToolStripMenuItem^ requestMenuItem;
		ToolStripMenuItem^ createRequestMenuItem;
		ToolStripMenuItem^ clearMenuItem;
		ToolStripMenuItem^ aboutMenuItem;

		System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
		ToolStripMenuItem^ contextCreateItem;
		ToolStripMenuItem^ contextClearItem;

		GroupBox^ groupBoxAuth;
		Label^ labelUser;
		Label^ labelPassword;
		TextBox^ textBoxUser;
		TextBox^ textBoxPassword;
		Button^ buttonLogin;

		GroupBox^ groupBoxMain;
		Label^ labelPhone;
		MaskedTextBox^ maskedTextBoxPhone;
		Label^ labelProblem;
		ListBox^ listBoxProblems;

		CheckBox^ checkBoxUrgent;
		CheckBox^ checkBoxVisit;
		CheckBox^ checkBoxRepeated;

		Button^ buttonCreate;
		Button^ buttonClear;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();

			this->menuStrip1 = gcnew MenuStrip();
			this->fileMenuItem = gcnew ToolStripMenuItem();
			this->exitMenuItem = gcnew ToolStripMenuItem();
			this->requestMenuItem = gcnew ToolStripMenuItem();
			this->createRequestMenuItem = gcnew ToolStripMenuItem();
			this->clearMenuItem = gcnew ToolStripMenuItem();

			this->contextMenuStrip1 = gcnew System::Windows::Forms::ContextMenuStrip(this->components);
			this->contextCreateItem = gcnew ToolStripMenuItem();
			this->contextClearItem = gcnew ToolStripMenuItem();

			this->groupBoxAuth = gcnew GroupBox();
			this->labelUser = gcnew Label();
			this->labelPassword = gcnew Label();
			this->textBoxUser = gcnew TextBox();
			this->textBoxPassword = gcnew TextBox();
			this->buttonLogin = gcnew Button();

			this->groupBoxMain = gcnew GroupBox();
			this->labelPhone = gcnew Label();
			this->maskedTextBoxPhone = gcnew MaskedTextBox();
			this->labelProblem = gcnew Label();
			this->listBoxProblems = gcnew ListBox();

			this->checkBoxUrgent = gcnew CheckBox();
			this->checkBoxVisit = gcnew CheckBox();
			this->checkBoxRepeated = gcnew CheckBox();

			this->buttonCreate = gcnew Button();
			this->buttonClear = gcnew Button();

			this->SuspendLayout();

			// menuStrip1
			this->menuStrip1->Items->AddRange(gcnew cli::array<ToolStripItem^>
			{
				this->fileMenuItem,
					this->requestMenuItem
					
			});
			this->menuStrip1->Location = Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = Drawing::Size(620, 24);
			this->menuStrip1->TabIndex = 0;

			// fileMenuItem
			this->fileMenuItem->Name = L"fileMenuItem";
			this->fileMenuItem->Size = Drawing::Size(48, 20);
			this->fileMenuItem->Text = L"Файл";
			this->fileMenuItem->DropDownItems->AddRange(gcnew cli::array<ToolStripItem^>
			{
				this->exitMenuItem
			});

			// exitMenuItem
			this->exitMenuItem->Name = L"exitMenuItem";
			this->exitMenuItem->Size = Drawing::Size(180, 22);
			this->exitMenuItem->Text = L"Выход";
			this->exitMenuItem->Click += gcnew EventHandler(this, &Form1::exitMenuItem_Click);

			// requestMenuItem
			this->requestMenuItem->Name = L"requestMenuItem";
			this->requestMenuItem->Size = Drawing::Size(58, 20);
			this->requestMenuItem->Text = L"Заявка";
			this->requestMenuItem->DropDownItems->AddRange(gcnew cli::array<ToolStripItem^>
			{
				this->createRequestMenuItem,
					this->clearMenuItem
			});

			// createRequestMenuItem
			this->createRequestMenuItem->Name = L"createRequestMenuItem";
			this->createRequestMenuItem->Size = Drawing::Size(180, 22);
			this->createRequestMenuItem->Text = L"Создать заявку";
			this->createRequestMenuItem->ShortcutKeys = Keys::Control | Keys::Enter;
			this->createRequestMenuItem->Click += gcnew EventHandler(this, &Form1::buttonCreate_Click);

			// clearMenuItem
			this->clearMenuItem->Name = L"clearMenuItem";
			this->clearMenuItem->Size = Drawing::Size(180, 22);
			this->clearMenuItem->Text = L"Очистить";
			this->clearMenuItem->ShortcutKeys = Keys::Control | Keys::Delete;
			this->clearMenuItem->Click += gcnew EventHandler(this, &Form1::buttonClear_Click);

			// contextMenuStrip1
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array<ToolStripItem^>
			{
				this->contextCreateItem,
					this->contextClearItem
			});

			// contextCreateItem
			this->contextCreateItem->Name = L"contextCreateItem";
			this->contextCreateItem->Size = Drawing::Size(180, 22);
			this->contextCreateItem->Text = L"Создать заявку";
			this->contextCreateItem->Click += gcnew EventHandler(this, &Form1::buttonCreate_Click);

			// contextClearItem
			this->contextClearItem->Name = L"contextClearItem";
			this->contextClearItem->Size = Drawing::Size(180, 22);
			this->contextClearItem->Text = L"Очистить";
			this->contextClearItem->Click += gcnew EventHandler(this, &Form1::buttonClear_Click);

			// groupBoxAuth
			this->groupBoxAuth->Location = Point(20, 45);
			this->groupBoxAuth->Name = L"groupBoxAuth";
			this->groupBoxAuth->Size = Drawing::Size(560, 100);
			this->groupBoxAuth->TabIndex = 1;
			this->groupBoxAuth->TabStop = false;
			this->groupBoxAuth->Text = L"Авторизация пользовтеля";

			// labelUser
			this->labelUser->AutoSize = true;
			this->labelUser->Location = Point(20, 28);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = Drawing::Size(112, 15);
			this->labelUser->TabIndex = 0;
			this->labelUser->Text = L"&Пользователь:";
			this->labelUser->UseMnemonic = true;

			// textBoxUser
			this->textBoxUser->Location = Point(140, 25);
			this->textBoxUser->Name = L"textBoxUser";
			this->textBoxUser->Size = Drawing::Size(230, 23);
			this->textBoxUser->TabIndex = 1;

			// labelPassword
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = Point(20, 62);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = Drawing::Size(55, 15);
			this->labelPassword->TabIndex = 2;
			this->labelPassword->Text = L"П&ароль:";
			this->labelPassword->UseMnemonic = true;

			// textBoxPassword
			this->textBoxPassword->Location = Point(140, 59);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->PasswordChar = '*';
			this->textBoxPassword->Size = Drawing::Size(230, 23);
			this->textBoxPassword->TabIndex = 3;

			// buttonLogin
			this->buttonLogin->Location = Point(400, 39);
			this->buttonLogin->Name = L"buttonLogin";
			this->buttonLogin->Size = Drawing::Size(120, 30);
			this->buttonLogin->TabIndex = 4;
			this->buttonLogin->Text = L"Войти";
			this->buttonLogin->UseVisualStyleBackColor = true;
			this->buttonLogin->Click += gcnew EventHandler(this, &Form1::buttonLogin_Click);

			this->groupBoxAuth->Controls->Add(this->labelUser);
			this->groupBoxAuth->Controls->Add(this->textBoxUser);
			this->groupBoxAuth->Controls->Add(this->labelPassword);
			this->groupBoxAuth->Controls->Add(this->textBoxPassword);
			this->groupBoxAuth->Controls->Add(this->buttonLogin);

			// groupBoxMain
			this->groupBoxMain->Location = Point(20, 165);
			this->groupBoxMain->Name = L"groupBoxMain";
			this->groupBoxMain->Size = Drawing::Size(560, 300);
			this->groupBoxMain->TabIndex = 2;
			this->groupBoxMain->TabStop = false;
			this->groupBoxMain->Text = L"Данные заявки";
			this->groupBoxMain->Enabled = false;

			// labelPhone
			this->labelPhone->AutoSize = true;
			this->labelPhone->Location = Point(20, 35);
			this->labelPhone->Name = L"labelPhone";
			this->labelPhone->Size = Drawing::Size(60, 15);
			this->labelPhone->TabIndex = 0;
			this->labelPhone->Text = L"&Телефон:";
			this->labelPhone->UseMnemonic = true;

			// maskedTextBoxPhone
			this->maskedTextBoxPhone->Location = Point(140, 32);
			this->maskedTextBoxPhone->Mask = L"+7 (000) 000-00-00";
			this->maskedTextBoxPhone->Name = L"maskedTextBoxPhone";
			this->maskedTextBoxPhone->Size = Drawing::Size(160, 23);
			this->maskedTextBoxPhone->TabIndex = 1;
			this->maskedTextBoxPhone->ContextMenuStrip = this->contextMenuStrip1;

			// labelProblem
			this->labelProblem->AutoSize = true;
			this->labelProblem->Location = Point(20, 80);
			this->labelProblem->Name = L"labelProblem";
			this->labelProblem->Size = Drawing::Size(92, 15);
			this->labelProblem->TabIndex = 2;
			this->labelProblem->Text = L"Тип &проблемы:";
			this->labelProblem->UseMnemonic = true;

			// listBoxProblems
			this->listBoxProblems->FormattingEnabled = true;
			this->listBoxProblems->ItemHeight = 15;
			this->listBoxProblems->Location = Point(140, 80);
			this->listBoxProblems->Name = L"listBoxProblems";
			this->listBoxProblems->Size = Drawing::Size(180, 94);
			this->listBoxProblems->TabIndex = 3;
			this->listBoxProblems->ContextMenuStrip = this->contextMenuStrip1;

			// checkBoxUrgent
			this->checkBoxUrgent->AutoSize = true;
			this->checkBoxUrgent->Location = Point(350, 35);
			this->checkBoxUrgent->Name = L"checkBoxUrgent";
			this->checkBoxUrgent->Size = Drawing::Size(66, 19);
			this->checkBoxUrgent->TabIndex = 4;
			this->checkBoxUrgent->Text = L"Срочно";
			this->checkBoxUrgent->UseVisualStyleBackColor = true;

			// checkBoxVisit
			this->checkBoxVisit->AutoSize = true;
			this->checkBoxVisit->Location = Point(350, 70);
			this->checkBoxVisit->Name = L"checkBoxVisit";
			this->checkBoxVisit->Size = Drawing::Size(162, 19);
			this->checkBoxVisit->TabIndex = 5;
			this->checkBoxVisit->Text = L"Нужен выезд специалиста";
			this->checkBoxVisit->UseVisualStyleBackColor = true;

			// checkBoxRepeated
			this->checkBoxRepeated->AutoSize = true;
			this->checkBoxRepeated->Location = Point(350, 105);
			this->checkBoxRepeated->Name = L"checkBoxRepeated";
			this->checkBoxRepeated->Size = Drawing::Size(143, 19);
			this->checkBoxRepeated->TabIndex = 6;
			this->checkBoxRepeated->Text = L"Проблема повторяется";
			this->checkBoxRepeated->UseVisualStyleBackColor = true;

			// buttonCreate
			this->buttonCreate->Location = Point(140, 220);
			this->buttonCreate->Name = L"buttonCreate";
			this->buttonCreate->Size = Drawing::Size(130, 35);
			this->buttonCreate->TabIndex = 7;
			this->buttonCreate->Text = L"Создать заявку";
			this->buttonCreate->UseVisualStyleBackColor = true;
			this->buttonCreate->Click += gcnew EventHandler(this, &Form1::buttonCreate_Click);

			// buttonClear
			this->buttonClear->Location = Point(290, 220);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = Drawing::Size(130, 35);
			this->buttonClear->TabIndex = 8;
			this->buttonClear->Text = L"Очистить";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew EventHandler(this, &Form1::buttonClear_Click);

			this->groupBoxMain->Controls->Add(this->labelPhone);
			this->groupBoxMain->Controls->Add(this->maskedTextBoxPhone);
			this->groupBoxMain->Controls->Add(this->labelProblem);
			this->groupBoxMain->Controls->Add(this->listBoxProblems);
			this->groupBoxMain->Controls->Add(this->checkBoxUrgent);
			this->groupBoxMain->Controls->Add(this->checkBoxVisit);
			this->groupBoxMain->Controls->Add(this->checkBoxRepeated);
			this->groupBoxMain->Controls->Add(this->buttonCreate);
			this->groupBoxMain->Controls->Add(this->buttonClear);

			// Form1
			this->AutoScaleDimensions = SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = Drawing::Size(620, 500);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBoxAuth);
			this->Controls->Add(this->groupBoxMain);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Text = L"Вариант 1 - Заявка в техподдержку. Перелыгин";

			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion

	private:
		void InitializeData()
		{
			this->listBoxProblems->Items->Add(L"Проблема с интернетом");
			this->listBoxProblems->Items->Add(L"Ошибка в программе");
			this->listBoxProblems->Items->Add(L"Не работает оборудование");
			this->listBoxProblems->Items->Add(L"Нет доступа к системе");
			this->listBoxProblems->Items->Add(L"Другая проблема");

			this->listBoxProblems->SelectedIndex = 0;
		}

		void buttonLogin_Click(Object^ sender, EventArgs^ e)
		{
			if (this->textBoxUser->Text->Trim() != L"" && this->textBoxPassword->Text->Trim() != L"")
			{
				this->groupBoxMain->Enabled = true;
				MessageBox::Show(L"Доступ к оформлению заявки открыт", L"Авторизация");
			}
			else
			{
				MessageBox::Show(L"Введите имя пользователя и пароль", L"Ошибка");
			}
		}

		void buttonCreate_Click(Object^ sender, EventArgs^ e)
		{
			if (this->groupBoxMain->Enabled == false)
			{
				MessageBox::Show(L"Сначала введите пользователя и пароль", L"Доступ закрыт");
				return;
			}

			if (this->maskedTextBoxPhone->MaskFull == false)
			{
				MessageBox::Show(L"Введите номер телефона полностью", L"Ошибка ввода");
				return;
			}

			if (this->listBoxProblems->SelectedIndex == -1)
			{
				MessageBox::Show(L"Выберите тип проблемы", L"Ошибка ввода");
				return;
			}

			String^ result = L"Заявка в техподдержку создана\n\n";
			result += L"Оператор: " + this->textBoxUser->Text + L"\n";
			result += L"Телефон: " + this->maskedTextBoxPhone->Text + L"\n";
			result += L"Тип проблемы: " + this->listBoxProblems->SelectedItem->ToString() + L"\n\n";
			result += L"Дополнительные признаки:\n";

			if (this->checkBoxUrgent->Checked)
			{
				result += L"- срочно\n";
			}

			if (this->checkBoxVisit->Checked)
			{
				result += L"- нужен выезд специалиста\n";
			}

			if (this->checkBoxRepeated->Checked)
			{
				result += L"- проблема повторяется\n";
			}

			if (!this->checkBoxUrgent->Checked &&
				!this->checkBoxVisit->Checked &&
				!this->checkBoxRepeated->Checked)
			{
				result += L"- не выбраны\n";
			}

			MessageBox::Show(result, L"Итог заявки");
		}

		void buttonClear_Click(Object^ sender, EventArgs^ e)
		{
			this->maskedTextBoxPhone->Clear();
			this->listBoxProblems->SelectedIndex = 0;
			this->checkBoxUrgent->Checked = false;
			this->checkBoxVisit->Checked = false;
			this->checkBoxRepeated->Checked = false;
		}

		void exitMenuItem_Click(Object^ sender, EventArgs^ e)
		{
			Application::Exit();
		}

		void aboutMenuItem_Click(Object^ sender, EventArgs^ e)
		{
			MessageBox::Show(
				L"Лабораторная работа №5\nВариант 1\nПриложение: заявка в техподдержку",
				L"О программе"
			);
		}
	};
}