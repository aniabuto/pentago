#pragma once
#include <string>

using namespace std;

class Player {
private:
	string name;

public:
	void SetName(string name);
	string GetName();
};