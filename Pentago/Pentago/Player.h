#pragma once
#include <string>

using namespace std;

class Player {
private:
	string name;
	char color;

public:
	void SetName(string name);
	string GetName();

	void SetColor(char color);
	char GetColor();

	bool HasWon(char** board, int size, int winning);

	bool PutButton(char**  board, int row, int col);	//returns true if successful
};