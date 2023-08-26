#pragma once
using namespace System;
using namespace System::Windows::Forms;
ref class Game
{
public: 
	Game(int, int, int);
	array<int, 2>^ getFoxMatrix(int, int);
	array<int>^ getClickPos(Button^);
private:
	int n, m, foxes, x, y;
	array<int, 2>^ matrix;
	array<int, 2>^ generateFoxes();
};

