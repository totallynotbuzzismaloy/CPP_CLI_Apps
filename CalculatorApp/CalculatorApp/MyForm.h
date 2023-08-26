#pragma once
#include <string>
namespace CalculatorApp {

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
			myFillList();
			SetOnClickListener(btnList, true);
			SetOnClickListener(NonNumbBtnList, false);
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
	private: System::Windows::Forms::Button^ closeBtn;
	private: System::Windows::Forms::Label^ outputLabel;
	private: System::Windows::Forms::Button^ AllClearBtn;
	private: System::Windows::Forms::Button^ SignBth;
	private: System::Windows::Forms::Button^ PercentBtn;
	private: System::Windows::Forms::Button^ DivideBtn;
	private: System::Windows::Forms::Button^ MultiplyBtn;
	private: System::Windows::Forms::Button^ NineBtn;
	private: System::Windows::Forms::Button^ EightBtn;
	private: System::Windows::Forms::Button^ SevenBtn;
	private: System::Windows::Forms::Button^ AdditionBtn;
	private: System::Windows::Forms::Button^ SixBtn;
	private: System::Windows::Forms::Button^ FiveBtn;
	private: System::Windows::Forms::Button^ FourBtn;
	private: System::Windows::Forms::Button^ EqualBtn;
	private: System::Windows::Forms::Button^ DotBtn;
	private: System::Windows::Forms::Button^ ZeroBtn;
	private: System::Windows::Forms::Button^ SubBtn;
	private: System::Windows::Forms::Button^ ThreeBtn;
	private: System::Windows::Forms::Button^ TwoBtn;
	private: System::Windows::Forms::Button^ OneBtn;

	private: System::Collections::Generic::List<Control^>^ btnList = gcnew System::Collections::Generic::List<Control^>;
	private: System::Collections::Generic::List<Control^>^ NonNumbBtnList = gcnew System::Collections::Generic::List<Control^>;

	private: double firstNumb;
	private: char userAction = ' ';
	private: bool is_equal = false;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->outputLabel = (gcnew System::Windows::Forms::Label());
			this->AllClearBtn = (gcnew System::Windows::Forms::Button());
			this->SignBth = (gcnew System::Windows::Forms::Button());
			this->PercentBtn = (gcnew System::Windows::Forms::Button());
			this->DivideBtn = (gcnew System::Windows::Forms::Button());
			this->MultiplyBtn = (gcnew System::Windows::Forms::Button());
			this->NineBtn = (gcnew System::Windows::Forms::Button());
			this->EightBtn = (gcnew System::Windows::Forms::Button());
			this->SevenBtn = (gcnew System::Windows::Forms::Button());
			this->AdditionBtn = (gcnew System::Windows::Forms::Button());
			this->SixBtn = (gcnew System::Windows::Forms::Button());
			this->FiveBtn = (gcnew System::Windows::Forms::Button());
			this->FourBtn = (gcnew System::Windows::Forms::Button());
			this->EqualBtn = (gcnew System::Windows::Forms::Button());
			this->DotBtn = (gcnew System::Windows::Forms::Button());
			this->ZeroBtn = (gcnew System::Windows::Forms::Button());
			this->SubBtn = (gcnew System::Windows::Forms::Button());
			this->ThreeBtn = (gcnew System::Windows::Forms::Button());
			this->TwoBtn = (gcnew System::Windows::Forms::Button());
			this->OneBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// closeBtn
			// 
			this->closeBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->closeBtn->ForeColor = System::Drawing::Color::White;
			this->closeBtn->Location = System::Drawing::Point(6, 9);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(20, 20);
			this->closeBtn->TabIndex = 0;
			this->closeBtn->Text = L"X";
			this->closeBtn->UseVisualStyleBackColor = false;
			this->closeBtn->Click += gcnew System::EventHandler(this, &MyForm::closeBtn_Click);
			// 
			// outputLabel
			// 
			this->outputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->outputLabel->ForeColor = System::Drawing::Color::White;
			this->outputLabel->Location = System::Drawing::Point(6, 9);
			this->outputLabel->Name = L"outputLabel";
			this->outputLabel->Size = System::Drawing::Size(226, 63);
			this->outputLabel->TabIndex = 1;
			this->outputLabel->Text = L"0";
			this->outputLabel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// AllClearBtn
			// 
			this->AllClearBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->AllClearBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AllClearBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AllClearBtn->ForeColor = System::Drawing::Color::White;
			this->AllClearBtn->Location = System::Drawing::Point(6, 75);
			this->AllClearBtn->Name = L"AllClearBtn";
			this->AllClearBtn->Size = System::Drawing::Size(50, 34);
			this->AllClearBtn->TabIndex = 2;
			this->AllClearBtn->Text = L"AC";
			this->AllClearBtn->UseVisualStyleBackColor = false;
			// 
			// SignBth
			// 
			this->SignBth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->SignBth->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SignBth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SignBth->ForeColor = System::Drawing::Color::White;
			this->SignBth->Location = System::Drawing::Point(62, 75);
			this->SignBth->Name = L"SignBth";
			this->SignBth->Size = System::Drawing::Size(50, 34);
			this->SignBth->TabIndex = 3;
			this->SignBth->Text = L"+/-";
			this->SignBth->UseVisualStyleBackColor = false;
			// 
			// PercentBtn
			// 
			this->PercentBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->PercentBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PercentBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PercentBtn->ForeColor = System::Drawing::Color::White;
			this->PercentBtn->Location = System::Drawing::Point(118, 75);
			this->PercentBtn->Name = L"PercentBtn";
			this->PercentBtn->Size = System::Drawing::Size(50, 34);
			this->PercentBtn->TabIndex = 4;
			this->PercentBtn->Text = L"%";
			this->PercentBtn->UseVisualStyleBackColor = false;
			// 
			// DivideBtn
			// 
			this->DivideBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->DivideBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DivideBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DivideBtn->ForeColor = System::Drawing::Color::White;
			this->DivideBtn->Location = System::Drawing::Point(174, 75);
			this->DivideBtn->Name = L"DivideBtn";
			this->DivideBtn->Size = System::Drawing::Size(50, 34);
			this->DivideBtn->TabIndex = 5;
			this->DivideBtn->Text = L"/";
			this->DivideBtn->UseVisualStyleBackColor = false;
			// 
			// MultiplyBtn
			// 
			this->MultiplyBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->MultiplyBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MultiplyBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MultiplyBtn->ForeColor = System::Drawing::Color::White;
			this->MultiplyBtn->Location = System::Drawing::Point(174, 129);
			this->MultiplyBtn->Name = L"MultiplyBtn";
			this->MultiplyBtn->Size = System::Drawing::Size(50, 34);
			this->MultiplyBtn->TabIndex = 9;
			this->MultiplyBtn->Text = L"*";
			this->MultiplyBtn->UseVisualStyleBackColor = false;
			// 
			// NineBtn
			// 
			this->NineBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->NineBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->NineBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NineBtn->ForeColor = System::Drawing::Color::White;
			this->NineBtn->Location = System::Drawing::Point(118, 129);
			this->NineBtn->Name = L"NineBtn";
			this->NineBtn->Size = System::Drawing::Size(50, 34);
			this->NineBtn->TabIndex = 8;
			this->NineBtn->Text = L"9";
			this->NineBtn->UseVisualStyleBackColor = false;
			// 
			// EightBtn
			// 
			this->EightBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->EightBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->EightBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EightBtn->ForeColor = System::Drawing::Color::White;
			this->EightBtn->Location = System::Drawing::Point(62, 129);
			this->EightBtn->Name = L"EightBtn";
			this->EightBtn->Size = System::Drawing::Size(50, 34);
			this->EightBtn->TabIndex = 7;
			this->EightBtn->Text = L"8";
			this->EightBtn->UseVisualStyleBackColor = false;
			// 
			// SevenBtn
			// 
			this->SevenBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->SevenBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SevenBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SevenBtn->ForeColor = System::Drawing::Color::White;
			this->SevenBtn->Location = System::Drawing::Point(6, 129);
			this->SevenBtn->Name = L"SevenBtn";
			this->SevenBtn->Size = System::Drawing::Size(50, 34);
			this->SevenBtn->TabIndex = 6;
			this->SevenBtn->Text = L"7";
			this->SevenBtn->UseVisualStyleBackColor = false;
			// 
			// AdditionBtn
			// 
			this->AdditionBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->AdditionBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AdditionBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AdditionBtn->ForeColor = System::Drawing::Color::White;
			this->AdditionBtn->Location = System::Drawing::Point(174, 179);
			this->AdditionBtn->Name = L"AdditionBtn";
			this->AdditionBtn->Size = System::Drawing::Size(50, 34);
			this->AdditionBtn->TabIndex = 13;
			this->AdditionBtn->Text = L"+";
			this->AdditionBtn->UseVisualStyleBackColor = false;
			// 
			// SixBtn
			// 
			this->SixBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->SixBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SixBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SixBtn->ForeColor = System::Drawing::Color::White;
			this->SixBtn->Location = System::Drawing::Point(118, 179);
			this->SixBtn->Name = L"SixBtn";
			this->SixBtn->Size = System::Drawing::Size(50, 34);
			this->SixBtn->TabIndex = 12;
			this->SixBtn->Text = L"6";
			this->SixBtn->UseVisualStyleBackColor = false;
			// 
			// FiveBtn
			// 
			this->FiveBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->FiveBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FiveBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FiveBtn->ForeColor = System::Drawing::Color::White;
			this->FiveBtn->Location = System::Drawing::Point(62, 179);
			this->FiveBtn->Name = L"FiveBtn";
			this->FiveBtn->Size = System::Drawing::Size(50, 34);
			this->FiveBtn->TabIndex = 11;
			this->FiveBtn->Text = L"5";
			this->FiveBtn->UseVisualStyleBackColor = false;
			// 
			// FourBtn
			// 
			this->FourBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->FourBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FourBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FourBtn->ForeColor = System::Drawing::Color::White;
			this->FourBtn->Location = System::Drawing::Point(6, 179);
			this->FourBtn->Name = L"FourBtn";
			this->FourBtn->Size = System::Drawing::Size(50, 34);
			this->FourBtn->TabIndex = 10;
			this->FourBtn->Text = L"4";
			this->FourBtn->UseVisualStyleBackColor = false;
			// 
			// EqualBtn
			// 
			this->EqualBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->EqualBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->EqualBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EqualBtn->ForeColor = System::Drawing::Color::White;
			this->EqualBtn->Location = System::Drawing::Point(174, 277);
			this->EqualBtn->Name = L"EqualBtn";
			this->EqualBtn->Size = System::Drawing::Size(50, 34);
			this->EqualBtn->TabIndex = 17;
			this->EqualBtn->Text = L"=";
			this->EqualBtn->UseVisualStyleBackColor = false;
			// 
			// DotBtn
			// 
			this->DotBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->DotBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DotBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DotBtn->ForeColor = System::Drawing::Color::White;
			this->DotBtn->Location = System::Drawing::Point(118, 277);
			this->DotBtn->Name = L"DotBtn";
			this->DotBtn->Size = System::Drawing::Size(50, 34);
			this->DotBtn->TabIndex = 16;
			this->DotBtn->Text = L".";
			this->DotBtn->UseVisualStyleBackColor = false;
			// 
			// ZeroBtn
			// 
			this->ZeroBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->ZeroBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ZeroBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ZeroBtn->ForeColor = System::Drawing::Color::White;
			this->ZeroBtn->Location = System::Drawing::Point(6, 277);
			this->ZeroBtn->Name = L"ZeroBtn";
			this->ZeroBtn->Size = System::Drawing::Size(106, 34);
			this->ZeroBtn->TabIndex = 14;
			this->ZeroBtn->Text = L"0";
			this->ZeroBtn->UseVisualStyleBackColor = false;
			// 
			// SubBtn
			// 
			this->SubBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(156)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->SubBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SubBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SubBtn->ForeColor = System::Drawing::Color::White;
			this->SubBtn->Location = System::Drawing::Point(174, 228);
			this->SubBtn->Name = L"SubBtn";
			this->SubBtn->Size = System::Drawing::Size(50, 34);
			this->SubBtn->TabIndex = 21;
			this->SubBtn->Text = L"-";
			this->SubBtn->UseVisualStyleBackColor = false;
			// 
			// ThreeBtn
			// 
			this->ThreeBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->ThreeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ThreeBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ThreeBtn->ForeColor = System::Drawing::Color::White;
			this->ThreeBtn->Location = System::Drawing::Point(118, 228);
			this->ThreeBtn->Name = L"ThreeBtn";
			this->ThreeBtn->Size = System::Drawing::Size(50, 34);
			this->ThreeBtn->TabIndex = 20;
			this->ThreeBtn->Text = L"3";
			this->ThreeBtn->UseVisualStyleBackColor = false;
			// 
			// TwoBtn
			// 
			this->TwoBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->TwoBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->TwoBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TwoBtn->ForeColor = System::Drawing::Color::White;
			this->TwoBtn->Location = System::Drawing::Point(62, 228);
			this->TwoBtn->Name = L"TwoBtn";
			this->TwoBtn->Size = System::Drawing::Size(50, 34);
			this->TwoBtn->TabIndex = 19;
			this->TwoBtn->Text = L"2";
			this->TwoBtn->UseVisualStyleBackColor = false;
			// 
			// OneBtn
			// 
			this->OneBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(151)));
			this->OneBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->OneBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OneBtn->ForeColor = System::Drawing::Color::White;
			this->OneBtn->Location = System::Drawing::Point(6, 228);
			this->OneBtn->Name = L"OneBtn";
			this->OneBtn->Size = System::Drawing::Size(50, 34);
			this->OneBtn->TabIndex = 18;
			this->OneBtn->Text = L"1";
			this->OneBtn->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->ClientSize = System::Drawing::Size(236, 328);
			this->Controls->Add(this->SubBtn);
			this->Controls->Add(this->ThreeBtn);
			this->Controls->Add(this->TwoBtn);
			this->Controls->Add(this->OneBtn);
			this->Controls->Add(this->EqualBtn);
			this->Controls->Add(this->DotBtn);
			this->Controls->Add(this->ZeroBtn);
			this->Controls->Add(this->AdditionBtn);
			this->Controls->Add(this->SixBtn);
			this->Controls->Add(this->FiveBtn);
			this->Controls->Add(this->FourBtn);
			this->Controls->Add(this->MultiplyBtn);
			this->Controls->Add(this->NineBtn);
			this->Controls->Add(this->EightBtn);
			this->Controls->Add(this->SevenBtn);
			this->Controls->Add(this->DivideBtn);
			this->Controls->Add(this->PercentBtn);
			this->Controls->Add(this->SignBth);
			this->Controls->Add(this->AllClearBtn);
			this->Controls->Add(this->closeBtn);
			this->Controls->Add(this->outputLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Calculator";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void OnNumbBtnsClick(System::Object^ sender, System::EventArgs^ e) {
		//this->outputLabel->Text = "af";
		this->outputLabel->ForeColor = Color::White;
		Button^ btn = safe_cast<Button^>(sender);
		if (this->outputLabel->Text == "0" || is_equal){
			this->outputLabel->Text = btn->Text;
			is_equal = false;
	}
		else this->outputLabel->Text = this->outputLabel->Text + btn->Text;
	} 
	
	private: System::Void NonNumbBtnsClick(System::Object^ sender, System::EventArgs^ e) {
		//this->outputLabel->Text = "ff";
		Button^ btn = safe_cast<Button^>(sender);
		SelectAction(btn->Text);
	}

	private: System::Void SelectAction(String^ str) {
		if (str == "/" || str == "-" || str == "+" || str == "*" || str == "=" || str == "%")
			MathActions(System::Convert::ToChar(str)); 
		else if (str == "AC") { 
			this->outputLabel->Text = "0"; 
			this->outputLabel->ForeColor = Color::White;
			this->firstNumb = 0;
			this->userAction = ' ';
			this->is_equal = false;
		}
		else if (str == "+/-") {
			double curNum = System::Convert::ToDouble(this->outputLabel->Text);
			curNum *= -1;
			this->outputLabel->Text = System::Convert::ToString(curNum);
		}
		else if (str == ".") {
			String^ text = this->outputLabel->Text;
			if (!text->Contains(",")) this->outputLabel->Text = text + ",";
		}
		
	}

	private: System::Void MathActions(char action) {
		if (action == '=') {
			if (userAction == ' ') return;

			double second = System::Convert::ToDouble(this->outputLabel->Text);
			double res;
			switch (this->userAction) {
			case '+': res = this->firstNumb + second; break;
			case '-': res = this->firstNumb - second; break;
			case '*': res = this->firstNumb * second; break;
			case '%': res = this->firstNumb * second / 100; break;
			case '/': 
				if (second == 0) { 
					res = 0;
					this->outputLabel->ForeColor = Color::Red;
					MessageBox::Show(this, "Action is prohibited", "ERROR!!!", MessageBoxButtons::OK, MessageBoxIcon::Error); 
				}
				else res = this->firstNumb / second; 
				break;
			}
			this->is_equal = true;
			this->outputLabel->Text = System::Convert::ToString(res);
		}
		else {
			this->firstNumb = System::Convert::ToDouble(this->outputLabel->Text);
			this->userAction = action;
			this->outputLabel->Text = "0";
		}
	}

	private: System::Void SetOnClickListener(System::Collections::Generic::List<Control^>^ curList, bool TypeBtn) {
		for each (System::Windows::Forms::Control ^ curCtrl in curList) {
			if (TypeBtn) curCtrl->Click += gcnew EventHandler(this, &MyForm::OnNumbBtnsClick);
			else curCtrl->Click += gcnew EventHandler(this, &MyForm::NonNumbBtnsClick);
		}
	}

	private: System::Void myFillList() {
		int result = 0;
		for each (System::Windows::Forms::Control ^ curCtrl in Controls) {
			bool flag = System::Int32::TryParse(curCtrl->Text, result);
			if (flag && curCtrl->Name != "outputLabel") btnList->Add(curCtrl);
			else if (!flag && curCtrl->Name != "closeBtn") NonNumbBtnList->Add(curCtrl);
			else continue;
		}
	}

	/*private: bool isNumber(std::string& str) {
		std::string::const_iterator it = str.begin();
		while (it != str.end() && std::isdigit(*it)) ++it;
		return !str.empty() && it == str.end();
	}*/
	};
}
