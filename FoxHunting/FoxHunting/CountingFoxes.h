#pragma once
using namespace System;
using namespace System::Windows::Forms;

ref class CountingFoxes
{
	public:
		CountingFoxes(array<int, 2>^);
		int getFoxNumber(int, int);
	private:
		array<int, 2>^ matrix;
		int n;
		int m;
		int checkHorizontal(int);
		int checkVertical(int);
		int checkDiagonals(int, int);
};

