#include "CheckWinner.h"

CheckWinner::CheckWinner(array<Button^, 2>^ matrix) {
	this->matrix = matrix;
	rows = matrix->GetUpperBound(0) + 1;
	columns = matrix->Length / rows;
}

String^ CheckWinner::checkTheWinner() {
	array<String^>^ winChekers = gcnew array<String^> {checkHorizontal(), checkVertical(), checkDiagRight(), checkDiagLeft()};
	for (int i = 0; i < winChekers->GetUpperBound(0) + 1; ++i) {
		if (winChekers[i] != String::Empty) return winChekers[i];
	}
	return String::Empty;
}

String^ CheckWinner::checkHorizontal() {
	String^ currPlayer{ String::Empty };
	String^ lastPlayer{ String::Empty };
	for (int i = 0; i < rows; ++i) {
		int successCount = 1;
		lastPlayer = String::Empty;
		for (int j = 0; j < columns; ++j) {
			currPlayer = matrix[i,j]->Text;
			if (currPlayer == lastPlayer && (currPlayer != String::Empty && lastPlayer != String::Empty)) {
				successCount++;
				if (successCount == rows) return currPlayer;
			}
			lastPlayer = currPlayer;
		}
	}
	return String::Empty;
}

String^ CheckWinner::checkVertical()
{
	String^ currPlayer{ String::Empty };
	String^ lastPlayer{ String::Empty };
	for (int i = 0; i < rows; ++i) {
		int successCount = 1;
		lastPlayer = String::Empty;
		for (int j = 0; j < columns; ++j) {
			currPlayer = matrix[j, i]->Text;
			if (currPlayer == lastPlayer && (currPlayer != String::Empty && lastPlayer != String::Empty)) {
				successCount++;
				if (successCount == rows) return currPlayer;
			}
			lastPlayer = currPlayer;
		}
	}
	return String::Empty;
}

String^ CheckWinner::checkDiagRight()
{
	String^ currPlayer{ String::Empty };
	String^ lastPlayer{ String::Empty };
	int successCount = 1;
	for (int i = 0; i < rows; ++i) {
		currPlayer = matrix[i, rows - (i + 1)]->Text;
		if (currPlayer != String::Empty) {
			if (lastPlayer == currPlayer) {
				successCount++;
				if (successCount == rows) return currPlayer;
			}
		}
		lastPlayer = currPlayer;
	}
	return String::Empty;
}

String^ CheckWinner::checkDiagLeft()
{
	String^ currPlayer{ String::Empty };
	String^ lastPlayer{ String::Empty };
	int successCount = 1;
	for (int i = 0; i < rows; ++i) {
		currPlayer = matrix[i, i]->Text;
		if (currPlayer != String::Empty) {
			if (lastPlayer == currPlayer) {
				successCount++;
				if (successCount == rows) return currPlayer;
			}
		}
		lastPlayer = currPlayer;
	}
	return String::Empty;
}
