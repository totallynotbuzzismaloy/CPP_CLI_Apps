#pragma once
#include "Game.h"
#include "CountingFoxes.h"

namespace FoxHunting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ theGameForm
	/// </summary>
	public ref class theGameForm : public System::Windows::Forms::Form
	{
	public:
		theGameForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		theGameForm(Form^ form, int n, int m, int foxes) {
			form->Hide();
			nSize = n;
			mSize = m;
			rClickNumb = 0;
			lClickNumb = 0;
			foxFound = 0;
			this->foxes = foxes;
			isFirstStep = true;
			Buttons = gcnew array<Button^, 2>(nSize, mSize);
			matrix = gcnew array<int, 2>(nSize, mSize) { {0} };
			game = gcnew Game(nSize, mSize, this->foxes);
			InitButtons();
			//button1_Click();
		}

	private: array<Button^, 2>^ Buttons;
			 int nSize, mSize, foxes, rClickNumb, lClickNumb, x{ 0 }, y{ 0 }, foxFound;
			 array<int, 2>^ matrix;
		     const int size{ 45 };
			 bool isFirstStep;
			 Game^ game;
			 CountingFoxes^ countFox;


	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~theGameForm()
		{
			if (components)
			{
				delete components;
			}
		}
 
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// theGameForm
			// 
			this->ClientSize = System::Drawing::Size(666, 466);
			this->Name = L"theGameForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: Void InitButtons() {
		//Buttons = gcnew array<Button^, 2>(nSize, mSize);
		for (int i = 0; i < nSize; ++i) {
			for (int j = 0; j < mSize; ++j) {
				Buttons[i, j] = gcnew Button();
				Buttons[i, j]->Location = Point(10 + j * size, 25 + i * size);
				Buttons[i, j]->Size = Drawing::Size(size, size);
				Buttons[i, j]->Text = "?";
				Buttons[i, j]->Tag = String::Format("{0}{1}", i, j);
				Buttons[i, j]->MouseDown += gcnew MouseEventHandler(this, &theGameForm::OnMouseClick);
				this->Controls->Add(Buttons[i, j]);
			}
		}
	}
		   Void OnMouseClick(Object^ sender, MouseEventArgs^ e) {
			   Button^ btn = safe_cast<Button^>(sender);
			   switch (e->Button) {
					case System::Windows::Forms::MouseButtons::Left:
						LeftMouseBtnPressed(btn);
						break;
					case System::Windows::Forms::MouseButtons::Right:
						RightMouseBtnPressed(btn);
						break;
			   }
		   }

		   Void RightMouseBtnPressed(Button^ btn) {
			   rClickNumb++;
			   this->Text = String::Format("Left Clicks: {0}, Right Clicks: {1}", lClickNumb, rClickNumb);
			   if (btn->Text == "?") btn->Text = "T_T";
			   else btn->Text = "?"; 
			}

		   Void LeftMouseBtnPressed(Button^ btn) {
			   array<int>^ indexes = game->getClickPos(btn);
			   int numb = 0;
			   btn->Enabled = false;
			   if (isFirstStep) {
				   matrix = game->getFoxMatrix(indexes[0], indexes[1]);
				   countFox = gcnew CountingFoxes(matrix);
				   numb = countFox->getFoxNumber(indexes[0], indexes[1]);
				   btn->Text = numb <= foxes ? Convert::ToString(numb) : Convert::ToString(foxes);
				   lClickNumb++;
				   this->Text = String::Format("Left Clicks: {0}, Right Clicks: {1}", lClickNumb, rClickNumb);
				   isFirstStep = false;
			   }
			   else {
				   lClickNumb++;
				   this->Text = String::Format("Left Clicks: {0}, Right Clicks: {1}", lClickNumb, rClickNumb);
				   if (matrix[indexes[0], indexes[1]] == 1) {
					   btn->Text = "FOX";
					   foxFound++;
					   checkVictory();
				   }
				   else {
					   numb = countFox->getFoxNumber(indexes[0], indexes[1]);
					   btn->Text = numb <= foxes ? Convert::ToString(numb) : Convert::ToString(foxes);
				   }
			   }
		   }

		   Void checkVictory() {
			   if (foxFound == foxes) {
				   String^ msg = "Congratulations, you have found all the foxes!";
				   String^ title = "Congratulations!!!";
				   MessageBox::Show(msg, title, MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				   this->Close();
			   }
		   }
		   
		   
	/*private: Void button1_Click() {
		String^ text =  String::Empty;
		for (int i = 0; i < nSize; ++i) {
			for (int j = 0; j < mSize; ++j) {
				char temp1 = Buttons[i, j]->Tag->ToString()[0];
				char temp2 = Buttons[i, j]->Tag->ToString()[1];
				int n1 = temp1 - '0', n2 = temp2 - '0';
				text += String::Format("{0}{1}  ", n1, n2);
			}
			text += "\n";
		}
		MessageBox::Show(text, "error");
	}*/
};
}
