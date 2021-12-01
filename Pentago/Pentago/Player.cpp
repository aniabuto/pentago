#include "Player.h"
#include <string>
#include<iostream>

using namespace std;

void Player::SetName(string name) {
	this->name = name;
}

string Player::GetName() {
	return this->name;
}

void Player::SetColor(char color) {
	this->color = color;
}

char Player::GetColor() {
	return this->color;
}

bool Player::HasWon(char** board, int size, int winning) {
	// horizontally:
	for (int i = 0; i < size; i++) {
		int mine = 0;
		for (int j = 0; j < size; j++)
			if (board[i][j] == this->color)
				mine++;
		if (mine == winning)
			return true;
	}

	// vartically:
	for (int i = 0; i < size; i++) {
		int mine = 0;
		for (int j = 0; j < size; j++)
			if (board[j][i] == this->color)
				mine++;
		if (mine == winning)
			return true;
	}

	// diagonally (left top -> right bottom):
	int mine = 0;
	for (int i = 0; i < size; i++) {
		if (board[i][i] == this->color)
				mine++;
		if (mine == winning)
			return true;
	}

	// diagonally (right top -> left bottom):
	mine = 0;
	for (int i = 0; i < size; i++) {
		if (board[i][size - i - 1] == this->color)
			mine++;
		if (mine == winning)
			return true;
	}

	return false;
}

bool Player::PutButton(char** board, int row, int col) {
	if (board[row][col] != ' ')
		return false;
	board[row][col] = this->color;
	return true;
}