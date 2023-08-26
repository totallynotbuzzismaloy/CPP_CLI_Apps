#include "CountingFoxes.h"

CountingFoxes::CountingFoxes(array<int, 2>^ matrix) {
	this->matrix = matrix;
	n = matrix->GetUpperBound(0) + 1;
	m = matrix->Length / n;
}

int CountingFoxes::getFoxNumber(int pos1, int pos2) {
	int number = checkHorizontal(pos1) + checkVertical(pos2) + checkDiagonals(pos1, pos2);
	return number;
}

int CountingFoxes::checkHorizontal(int x) {
	int counter = 0;
	for (int i = 0; i < m; ++i) {
		if (matrix[x, i] == 1) counter++;
	}
	return counter;
}

int CountingFoxes::checkVertical(int y) {
	int counter = 0;
	for (int i = 0; i < n; ++i) {
		if (matrix[i, y] == 1) counter++;
	}
	return counter;
}

int CountingFoxes::checkDiagonals(int x, int y) {
	int counter = 0, istep = x, jstep = y;
	do {
		if (matrix[istep, jstep] == 1) counter++;
		istep++;
		jstep++;
	} while (istep < n && jstep < m);

	istep = x, jstep = y;

	do {
		if (matrix[istep, jstep] == 1) counter++;
		istep--;
		jstep--;
	} while (istep >= 0 && jstep >= 0);

	istep = x, jstep = y;

	do {
		if (matrix[istep, jstep] == 1) counter++;
		istep--;
		jstep++;
	} while (istep >= 0 && jstep < m);

	istep = x, jstep = y;

	do {
		if (matrix[istep, jstep] == 1) counter++;
		istep++;
		jstep--;
	} while (istep < n && jstep >= 0);

	return counter;
}

