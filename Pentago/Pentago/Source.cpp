#include<iostream>
#include"Functions.h"
#include"Player.h"
using namespace std;

int main()
{
	Player* one = new Player();
	Player* two = new Player();
	
	one->SetName(GetName());
	two->SetName(GetName());
	one->SetColor('x');
	two->SetColor('o');

	cout << "First player's name: \"" << one->GetName() << "\" and color: \"" << one->GetColor() << '\"';
	cout << "\nSecond player's name: \"" << two->GetName() << "\" and color: \"" << two->GetColor() << '\"';

	int size = 3;
	char** board = new char*[size];
	for (int i = 0; i < size; i++) {
		board[i] = new char[size];
		for (int j = 0; j < size; j++)
			board[i][j] = ' ';
	}
	
	int winning = size <= 5 ? size : size - 1;

	/*
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			board[i][j] = (i + j) % 2 == 0 ? 'o' : 'x';
	*/
	GameTicTacToe(board, size, winning, one, two);


	return 0;
}