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

	cout << "First player's name: " << one->GetName();
	cout << "\nSecond player's name: " << two->GetName();

	return 0;
}