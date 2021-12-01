#pragma once
#include <string>
#include<iostream>
#include "Player.h"

using namespace std;

string GetName() {
	string name;
	cin >> name;
	return name;
}

void DrawBoardPentago(char** board, int size) {
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

void DrawBoardTicTacToe(char** board, int size) {
	cout << "\n";
	for (int j = 0; j < size; j++)
		cout << "+---";
	cout << "+\n";
	
	for (int i = 0; i < size; i++)
	{
		cout << '|';
		for (int j = 0; j < size; j++)
		{
			cout << ' ' << board[i][j] << " |";
		}
		cout << "\n";
		for (int j = 0; j < size; j++)
			cout << "+---";
		cout << "+\n";
	}
	cout << '\n';
}

bool Move(char** board, int size, Player* player, int winning) {
	bool put = false;
	while (!put)
	{
		cout << "Podaj wspolrzedne pola (rzad kolumna):\t";
		int row, col;
		cin >> row >> col;
		if (!(row > size || row < 1 || col > size || col < 1))
		{
			put = player->PutButton(board, row - 1, col - 1);
		}
	}
	DrawBoardTicTacToe(board, size);
	return player->HasWon(board, size, winning);
}

bool IsDraw(char** board, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (board[i][j] == ' ')
				return false;
	cout << "\nRemis!!!\n";
	return true;
}

void GameTicTacToe(char** board, int size, int winning, Player* one, Player* two) {
	bool end = false;
		DrawBoardTicTacToe(board, size);
	while (!end) {
		bool oneWon = Move(board, size, one, winning);
		if (oneWon) {
			cout << "Wygral gracz 1 -> x";
			end = true;
		} else {
			end = IsDraw(board, size);
		}
		if (!end) {
			bool twoWon = Move(board, size, two, winning);
			if (twoWon) {
				cout << "Wygral gracz 2 -> o";
				end = true;
			} else {
				end = IsDraw(board, size);
			}
		}
		
	}
}