#pragma once
#include "CheckWinner.h"
#include <format>
namespace TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: array<Button^, 2>^ Buttons = gcnew array<Button^, 2>(3, 3);
		     bool isStarted = false;
			 int size = 52, countClicks = 0;
			 int rows = Buttons->GetUpperBound(0) + 1;
			 int columns = Buttons->Length / (Buttons->GetUpperBound(0) + 1);

	private: System::Windows::Forms::Button^ closeBtn;
	private: System::Windows::Forms::Button^ gameBtn;
	private: System::Windows::Forms::Label^ PlayerTurnLabel;


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
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->gameBtn = (gcnew System::Windows::Forms::Button());
			this->PlayerTurnLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// closeBtn
			// 
			this->closeBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->closeBtn->ForeColor = System::Drawing::Color::White;
			this->closeBtn->Location = System::Drawing::Point(297, 12);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(24, 24);
			this->closeBtn->TabIndex = 3;
			this->closeBtn->Text = L"X";
			this->closeBtn->UseVisualStyleBackColor = false;
			this->closeBtn->Click += gcnew System::EventHandler(this, &MyForm::closeBtn_Click);
			// 
			// gameBtn
			// 
			this->gameBtn->Location = System::Drawing::Point(101, 263);
			this->gameBtn->Name = L"gameBtn";
			this->gameBtn->Size = System::Drawing::Size(115, 31);
			this->gameBtn->TabIndex = 4;
			this->gameBtn->Text = L"Start Game";
			this->gameBtn->UseVisualStyleBackColor = true;
			this->gameBtn->Click += gcnew System::EventHandler(this, &MyForm::gameBtn_Click);
			// 
			// PlayerTurnLabel
			// 
			this->PlayerTurnLabel->Location = System::Drawing::Point(101, 235);
			this->PlayerTurnLabel->Name = L"PlayerTurnLabel";
			this->PlayerTurnLabel->Size = System::Drawing::Size(115, 23);
			this->PlayerTurnLabel->TabIndex = 5;
			this->PlayerTurnLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(333, 306);
			this->Controls->Add(this->PlayerTurnLabel);
			this->Controls->Add(this->gameBtn);
			this->Controls->Add(this->closeBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: Void InitButtons(){
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				Buttons[i, j] = gcnew Button();
				Buttons[i, j]->Location = Point(5 + j * size, 50 + i * size);
				Buttons[i, j]->Size = Drawing::Size(size, size);
				Buttons[i, j]->Text = String::Empty;
				Buttons[i, j]->Click += gcnew System::EventHandler(this, &MyForm::MouseClickListener);
				this->Controls->Add(Buttons[i, j]);
			}
		}
	}
		   Void MouseClickListener(System::Object^ sender, System::EventArgs^ e) {
			   Button^ btn = safe_cast<Button^>(sender);
			   CheckWinner check(Buttons);
			   if (countClicks % 2 == 0) {
				   btn->Text = "0";
				   btn->Enabled = false;
				   this->PlayerTurnLabel->Text = "Player(X) turn now";
			   }
			   else {
				   btn->Text = "X";
				   btn->Enabled = false;
				   this->PlayerTurnLabel->Text = "Player(O) turn now";
			   }
			   String^ winner = check.checkTheWinner();
			   if (winner != String::Empty) gameOver(winner);
			   if (countClicks == (rows * columns) - 1) gameOver();
			   countClicks++;
			   
			}

		   Void gameOver(String^ winner) {
			   MessageBox::Show(String::Format("Player {0} won!", winner), "Winner!!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   gameBtn->Text = "Try again";
			   this->PlayerTurnLabel->Text = String::Empty;
			   this->gameBtn->Enabled = true;
			   countClicks = 0;
		   }

		   Void gameOver() {
			   MessageBox::Show("Draw", "No winner!!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   gameBtn->Text = "Try again";
			   this->PlayerTurnLabel->Text = String::Empty;
			   this->gameBtn->Enabled = true;
			   countClicks = 0;
		   }

		   Void refresh() {
			   for (int i = 0; i < rows; ++i) {
				   for (int j = 0; j < columns; ++j) {
					   Buttons[i, j]->Text = String::Empty;
					   Buttons[i, j]->Enabled = true;
				   }
			   }
		   }

	private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void gameBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!isStarted) {
			this->PlayerTurnLabel->Text = "Player(0) turn now";
			this->gameBtn->Text = String::Empty;
			this->gameBtn->Enabled = false;
			InitButtons();
			isStarted = true;
	}
		else {
			refresh();
			this->PlayerTurnLabel->Text = "Player(0) turn now";
			this->gameBtn->Text = String::Empty;
			this->gameBtn->Enabled = false;
		}
}
};
}
