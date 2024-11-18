#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player {
private:
	string name; // user name
	char mark; // x, o || x, y
	unsigned int score, step;
public:
	Player(char c);
	// buoc di
	string getName();
	char getMark();
	void setName(string newName);
	unsigned int getScore();
};