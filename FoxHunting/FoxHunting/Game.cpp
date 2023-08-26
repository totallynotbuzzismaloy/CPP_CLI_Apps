#include "Game.h"

Game::Game(int n, int m, int foxes) {
	this->n = n;
	this->m = m;
	this->foxes = foxes;
	matrix = gcnew array<int, 2> (n, m);
}

array<int, 2>^ Game::getFoxMatrix(int x, int y) {
	this->x = x;
	this->y = y;
	return generateFoxes();
}

array<int, 2>^ Game::generateFoxes() {
	Random^ myRandom = gcnew Random();
	for (int i = 0; i < foxes;) {
		int index1 = myRandom->Next(0, n);
		int index2 = myRandom->Next(0, m);
		if (matrix[index1, index2] != 0 || (index1 == x && index2 == y)) continue;
		matrix[index1, index2] = 1;
		++i;
	}
	return matrix;
}

array<int>^ Game::getClickPos(Button^ btn) {
	array<int>^ returnArr = gcnew array<int>(2);
	char n1 = btn->Tag->ToString()[0];
	char n2 = btn->Tag->ToString()[1];
	returnArr[0] = n1 - '0';
	returnArr[1] = n2 - '0';
	
	return returnArr;
}