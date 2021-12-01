#include<iostream>
#include"Functions.h"
#include"Player.h"
using namespace std;

int main()
{
	Player* one = new Player();
	Player* two = new Player();/*
	one->SetName(GetName());
	two->SetName(GetName());

	cout << "First player's name: " << one->GetName();
	cout << "\nSecond player's name: " << two->GetName();*/
	int size = 6;
	char** board = new char*[size];
	for (int i = 0; i < size; i++)
		board[i] = new char[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			board[i][j] = (i + j) % 2 == 0 ? 'o' : 'x';

	DrawBoard(board, size);

	return 0;
}