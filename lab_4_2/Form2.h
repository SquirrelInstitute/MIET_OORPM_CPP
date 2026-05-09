#pragma once

namespace lab_4_2 {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class Form2 : public Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();

			this->Paint += gcnew PaintEventHandler(this, &Form2::Form2_Paint);
			this->Click += gcnew EventHandler(this, &Form2::Form2_Click);

			isGraphDrawn = false;
		}

	private:
		bool isGraphDrawn;

	private:
		void InitializeComponent(void)
		{
			this->SuspendLayout();

			// Form2
			this->ClientSize = Drawing::Size(750, 500);
			this->Name = L"Form2";
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Text = L"Вариант 1, график функции";

			this->ResumeLayout(false);
		}

	private:
		float F(float x)
		{
			return (float)(x + Math::Log(x + 0.5) - 0.5);
		}

	private:
		System::Void Form2_Paint(System::Object^ sender, PaintEventArgs^ e)
		{
			if (isGraphDrawn)
			{
				DrawGraph(e->Graphics);
			}
			else
			{
				DrawStartScreen(e->Graphics);
			}
		}

	private:
		System::Void Form2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			isGraphDrawn = true;
			this->Invalidate();
		}

	private:
		void DrawStartScreen(Graphics^ g)
		{
			g->Clear(Color::White);

			SolidBrush^ brush = gcnew SolidBrush(Color::DarkBlue);

			System::Drawing::Font^ titleFont = gcnew System::Drawing::Font(
				L"Arial",
				18.0F,
				FontStyle::Bold
			);

			System::Drawing::Font^ textFont = gcnew System::Drawing::Font(
				L"Arial",
				12.0F,
				FontStyle::Regular
			);

			g->DrawString(
				L"Лабораторная работа №4",
				titleFont,
				brush,
				PointF(230.0F, 120.0F)
			);

			g->DrawString(
				L"Приложение №2, построение графика функции",
				textFont,
				brush,
				PointF(190.0F, 175.0F)
			);

			g->DrawString(
				L"Вариант 1",
				textFont,
				brush,
				PointF(330.0F, 220.0F)
			);

			g->DrawString(
				L"Щелкните по форме, чтобы построить график",
				textFont,
				brush,
				PointF(195.0F, 270.0F)
			);
		}

	private:
		void DrawGraph(Graphics^ g)
		{
			g->Clear(Color::White);

			Pen^ axisPen = gcnew Pen(Color::Black, 1.0F);
			Pen^ graphPen = gcnew Pen(Color::Red, 2.0F);
			Pen^ framePen = gcnew Pen(Color::Gray, 1.0F);

			SolidBrush^ textBrush = gcnew SolidBrush(Color::Blue);

			System::Drawing::Font^ font = gcnew System::Drawing::Font(
				L"Arial",
				9.0F,
				FontStyle::Bold
			);

			System::Drawing::Font^ formulaFont = gcnew System::Drawing::Font(
				L"Arial",
				12.0F,
				FontStyle::Bold
			);

			int k = 70;
			int i = 70;
			int l = this->ClientSize.Width - 50;
			int j = this->ClientSize.Height - 80;

			float x1 = 0.0F;
			float x2 = 3.0F;

			float Fmin = F(x1);
			float Fmax = F(x1);

			for (float x = x1; x <= x2; x += 0.01F)
			{
				float y = F(x);

				if (y < Fmin)
				{
					Fmin = y;
				}

				if (y > Fmax)
				{
					Fmax = y;
				}
			}

			float a = (float)(i - j) / (Fmax - Fmin);
			float b = j - Fmin * (float)(i - j) / (Fmax - Fmin);

			g->DrawRectangle(framePen, k, i, l - k, j - i);

			// Ось OX
			if (b >= i && b <= j)
			{
				g->DrawLine(axisPen, k, (int)b, l, (int)b);
				g->DrawString(L"X", font, textBrush, PointF((float)l - 15, (float)b + 5));
			}

			// Ось OY
			int c = (int)Math::Round(k - x1 * (l - k) / (x2 - x1));

			if (c >= k && c <= l)
			{
				g->DrawLine(axisPen, c, i, c, j);
				g->DrawString(L"Y", font, textBrush, PointF((float)c + 5, (float)i));
			}

			g->DrawString(
				L"y = x + ln(x + 0.5) - 0.5",
				formulaFont,
				textBrush,
				PointF(220.0F, 25.0F)
			);

			g->DrawString(L"0", font, textBrush, PointF((float)k - 10, (float)j + 10));
			g->DrawString(L"3", font, textBrush, PointF((float)l - 5, (float)j + 10));
			g->DrawString(L"x", font, textBrush, PointF((float)l + 5, (float)j + 10));
			g->DrawString(L"y", font, textBrush, PointF((float)k - 25, (float)i));

			int DX = 2;

			int XL = k;
			int YL = (int)Math::Round(a * F(x1) + b);

			float dx = DX * (x2 - x1) / (l - k);
			float currentX = x1;

			for (int X = k + DX; X <= l; X += DX)
			{
				currentX = currentX + dx;

				int Y = (int)Math::Round(a * F(currentX) + b);

				g->DrawLine(graphPen, XL, YL, X, Y);

				XL = X;
				YL = Y;
			}
		}
	};
}