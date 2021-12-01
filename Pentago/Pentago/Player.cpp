#include "Player.h"
#include <string>

using namespace std;

void Player::SetName(string name) {
	this->name = name;
}

string Player::GetName() {
	return this->name;
}