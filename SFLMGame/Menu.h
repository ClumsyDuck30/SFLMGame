#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Menu {
private:
	vector <int> option; // List option which user can choose
	RenderWindow* mWindow;
	int selectedOption; // Option was chosen by user
public:
	Menu(RenderWindow* win);
	void draw();
	int getSelectedOption();
};