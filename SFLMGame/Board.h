#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Board {
private:
	unsigned int boardSize, width, height;
	vector<vector<char>> grid;
	float xCellSize, yCellSize;
	RenderWindow* bWindow;
	RectangleShape playerX, playerY;
public:
	Board(RenderWindow* win);
	void draw(char x, char o);
	bool isEmpty(int row, int col);
	void placeMark(int row, int col, char mark);
	bool checkWin(int x, int y);
	bool fullBoard();
	void boardOperation(int x, int y, bool& valid, bool currentPlayer, vector<RectangleShape>& tick);
};

