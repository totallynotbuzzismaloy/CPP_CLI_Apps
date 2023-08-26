#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

ref class CheckWinner
{
public:
	CheckWinner(array<Button^, 2>^);
	String^ checkTheWinner();
private:
	String^ checkHorizontal();
	String^ checkVertical();
	String^ checkDiagRight();
	String^ checkDiagLeft();
	array<Button^, 2>^ matrix;
	int rows, columns;
};

