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
	cout << '\n';
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

void Rotate(char** board, int size, char part, char direction) {
	int minRow, maxRow, minCol, maxCol;
	int half = size / 2;
	switch (part) {
	case 'q':
		minRow = 0;
		maxRow = half;
		minCol = 0;
		maxCol = half;
		break;
	case 'w':
		minRow = 0;
		maxRow = half;
		minCol = half;
		maxCol = size;
		break;
	case 'a':
		minRow = half;
		maxRow = size;
		minCol = 0;
		maxCol = half;
		break;
	case 's':
		minRow = half;
		maxRow = size;
		minCol = half;
		maxCol = size;
		break;
	}

	char** newBoard = new char* [half];	// copy of part of the board
	for (int i = minRow; i < maxRow; i++) {
		newBoard[i-minRow] = new char[half];
		for (int j = minCol; j < maxCol; j++) {
			newBoard[i - minRow][j - minCol] = board[i][j];
		}
	}

	if (direction == 'x')
		for(int i = minRow, r = 0; i < maxRow; i++, r++)
			for (int j = minCol, c = 0; j < maxCol; j++, c++) {
				board[i][j] = newBoard[c][half - 1 - r];
			}
	else
		for (int i = minRow, r = 0; i < maxRow; i++, r++)
			for (int j = minCol, c = 0; j < maxCol; j++, c++) {
				board[i][j] = newBoard[half - 1 - c][r];
			}
}

bool MoveTicTacToe(char** board, int size, Player* player, int winning) {
	bool put = false;
	while (!put)
	{
		cout << "Tura gracza " << player->GetName() << '\n';
		string move;
		cin >> move;
		char part = move[0];
		int k = move[1] - '0';
		if (k != 0 && (part == 'q' || part == 'w' || part == 'a' || part == 's'))
			put = player->PutButton(board, size, part, k);
		else
			cout << "Zly input\n";
	}
	DrawBoardTicTacToe(board, size);
	return player->HasWon(board, size, winning);
}

bool MovePentago(char** board, int size, Player* player, int winning) {
	bool put = false;
	bool rotate = false;
	while (!put && !rotate) {
		cout << "Tura gracza " << player->GetName() << '\n';
		string move;
		cin >> move;
		if (move == "p" || move == "h" || move == "m") {
			// opcje, z ktorych trzeba wyjsc
			bool quit = false;
			string input;
			while (!quit) {
				cin >> input;
				if (input == "q")
					quit = true;
			}
		}
		else if (move == "o")
			//wczytanie predefiniowanej planszy
			;
		else if (move == "u")
			// undo
			;
		else {
			char part = move[0];
			int k = move[1] - '0';
			if (k != 0 && (part == 'q' || part == 'w' || part == 'a' || part == 's'))
				put = player->PutButton(board, size, part, k);
			else
				cout << "Zly input\n";
			if (put) {
				DrawBoardPentago(board, size);
				while (!rotate) {
					cin >> move;
					part = move[0];
					char direction = move[1];
					if ((direction == 'z' || direction == 'x') && (part == 'q' || part == 'w' || part == 'a' || part == 's')) {
						Rotate(board, size, part, direction);
						rotate = true;
					}
					else
						cout << "Zly input\n";
				}
			}
		}
	}
	DrawBoardPentago(board, size);
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
		bool oneWon = MoveTicTacToe(board, size, one, winning);
		if (oneWon) {
			cout << "Wygral gracz 1 -> x";
			end = true;
		}
		else {
			end = IsDraw(board, size);
		}
		if (!end) {
			bool twoWon = MoveTicTacToe(board, size, two, winning);
			if (twoWon) {
				cout << "Wygral gracz 2 -> o";
				end = true;
			}
			else {
				end = IsDraw(board, size);
			}
		}

	}
}

void GamePentago(char** board, int size, int winning, Player* one, Player* two) {
	bool end = false;
		DrawBoardPentago(board, size);
	while (!end) {
		bool oneWon = MovePentago(board, size, one, winning);
		if (oneWon) {
			cout << "Wygral gracz 1 -> x";
			end = true;
		} else {
			end = IsDraw(board, size);
		}
		if (!end) {
			bool twoWon = MovePentago(board, size, two, winning);
			if (twoWon) {
				cout << "Wygral gracz 2 -> o";
				end = true;
			} else {
				end = IsDraw(board, size);
			}
		}
		
	}
}