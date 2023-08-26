#pragma once
#include "theGameForm.h"

namespace FoxHunting {

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
			changeMaxAmount();
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
	private: System::Windows::Forms::Button^ StartBtn;
	private: System::Windows::Forms::NumericUpDown^ nSizeUpDown;
	private: System::Windows::Forms::NumericUpDown^ mSizeUpDown;
	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ FoxAmount;
	private: System::Windows::Forms::Label^ label4;

	private: int nSize = 1, mSize = 2, foxAmount = 1;			 
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
			this->StartBtn = (gcnew System::Windows::Forms::Button());
			this->nSizeUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->mSizeUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->FoxAmount = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSizeUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mSizeUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FoxAmount))->BeginInit();
			this->SuspendLayout();
			// 
			// StartBtn
			// 
			this->StartBtn->Location = System::Drawing::Point(12, 149);
			this->StartBtn->Name = L"StartBtn";
			this->StartBtn->Size = System::Drawing::Size(148, 41);
			this->StartBtn->TabIndex = 0;
			this->StartBtn->Text = L"Play";
			this->StartBtn->UseVisualStyleBackColor = true;
			this->StartBtn->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::StartBtn_MouseClick);
			// 
			// nSizeUpDown
			// 
			this->nSizeUpDown->Location = System::Drawing::Point(12, 70);
			this->nSizeUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nSizeUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nSizeUpDown->Name = L"nSizeUpDown";
			this->nSizeUpDown->Size = System::Drawing::Size(70, 20);
			this->nSizeUpDown->TabIndex = 1;
			this->nSizeUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nSizeUpDown->ValueChanged += gcnew System::EventHandler(this, &MyForm::nSizeUpDown_ValueChanged);
			// 
			// mSizeUpDown
			// 
			this->mSizeUpDown->Location = System::Drawing::Point(90, 70);
			this->mSizeUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->mSizeUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->mSizeUpDown->Name = L"mSizeUpDown";
			this->mSizeUpDown->Size = System::Drawing::Size(70, 20);
			this->mSizeUpDown->TabIndex = 2;
			this->mSizeUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->mSizeUpDown->ValueChanged += gcnew System::EventHandler(this, &MyForm::mSizeUpDown_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"N size";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(101, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"M size";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(83, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"x";
			// 
			// FoxAmount
			// 
			this->FoxAmount->Location = System::Drawing::Point(90, 113);
			this->FoxAmount->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->FoxAmount->Name = L"FoxAmount";
			this->FoxAmount->Size = System::Drawing::Size(70, 20);
			this->FoxAmount->TabIndex = 6;
			this->FoxAmount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->FoxAmount->ValueChanged += gcnew System::EventHandler(this, &MyForm::FoxAmount_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 120);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Fox amount";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(186, 202);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->FoxAmount);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->mSizeUpDown);
			this->Controls->Add(this->nSizeUpDown);
			this->Controls->Add(this->StartBtn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSizeUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mSizeUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FoxAmount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: Void StartBtn_MouseClick(Object^ sender, MouseEventArgs^ e) {
				theGameForm^ form = gcnew theGameForm(this, nSize, mSize, foxAmount);
				form->FormClosed += gcnew FormClosedEventHandler(this, &MyForm::gameClosedEvent);
				form->ShowDialog();
			 }	
			 Void FoxAmount_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
				foxAmount = Convert::ToInt32(this->FoxAmount->Value);
			 }
			 Void mSizeUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
				mSize = Convert::ToInt32(this->mSizeUpDown->Value);
				changeMaxAmount();
			 }
			 Void nSizeUpDown_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
				nSize = Convert::ToInt32(this->nSizeUpDown->Value);
				changeMaxAmount();
			 }
			 Void changeMaxAmount() {
				FoxAmount->Maximum = nSize * mSize - 1;
			 }

			 Void gameClosedEvent(Object^ Sender, FormClosedEventArgs^ e) {
				 this->Show();
			 }
};
}
