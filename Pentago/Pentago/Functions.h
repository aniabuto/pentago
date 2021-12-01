#pragma once
#include <string>
#include<iostream>

using namespace std;

string GetName() {
	string name;
	cin >> name;
	return name;
}

void DrawBoard(char** board, int size) {
	cout << "+---+---+---+  +---+---+---+\n";
	for (int i = 0; i < size; i++)
	{
		cout << '|';
		for (int j = 0; j < size; j++)
		{
			cout << ' ' << board[i][j] << " |";
			if (j == 2)
				cout << "  |";
		}
		cout << "\n+---+---+---+  +---+---+---+\n";
		if (i == 2)
			cout << "\n+---+---+---+  +---+---+---+\n";
	}
}