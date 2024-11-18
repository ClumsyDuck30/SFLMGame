#include "Board.h"

Board::Board(RenderWindow* win) {
    VideoMode desktopMode = VideoMode::getDesktopMode();
    this->height = desktopMode.width;
    this->width = desktopMode.height;
    this->boardSize = 20;
    this->bWindow = win;
	xCellSize = 49.5;
	yCellSize = 36.5;
	playerX.setSize(Vector2f(xCellSize, yCellSize));
	Texture xplayer;
	xplayer.loadFromFile("../Data/Textures/player-x.png");
	playerX.setTexture(&xplayer);
	playerY.setSize(Vector2f(xCellSize, yCellSize));
	Texture yplayer;
	yplayer.loadFromFile("../Data/Textures/player-o.png");
	playerY.setTexture(&yplayer);
	grid.resize(20);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			grid[i].push_back(' ');
		}
	}
}

void Board::draw(char x, char o) {
	//Sprite background;
	Texture texture_background;
	if (!texture_background.loadFromFile("../Data/Textures/game-ui.png")) {
		cout << "Error: Cannot find game-ui.png.";
	}
	RectangleShape background;
	background.setSize(Vector2f(1366.f, 768.f));
	background.setTexture(&texture_background);

	// Title
	RectangleShape title(Vector2f(215.f, 65.f));
	Texture texture_title;
	if (!texture_title.loadFromFile("../Data/Textures/game-title.png")) {
		cout << "Error: Cannot find game-title.png.";
	}
	title.setTexture(&texture_title);
	title.setPosition(1080, 100);
	vector<RectangleShape> tick;
	bool isClose = false;
	bool valid = false;
	bool currentPlayer = 1; // 1 = x, 0 = o
	while(bWindow->isOpen())
	{

		Event event;
		while (bWindow->pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed:
				cout << "Closed the caro game.";
				bWindow->close();
				break;
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left) {
					valid = false;
					int x = event.mouseButton.x;
					int y = event.mouseButton.y;
					//if (x < 28 || x > 1015 || y < 20 || y > 675) continue;
					boardOperation(x, y, valid, currentPlayer, tick);
					if (valid) currentPlayer = !currentPlayer;
					cout << x << " " << y << endl;
				}
			}
		}		
		bWindow->clear(Color::White);
		bWindow->draw(background);
		bWindow->draw(title);
		for (int i = 0; i < tick.size(); i++) bWindow->draw(tick[i]);
		bWindow->display();		
	}
}

bool Board::isEmpty(int row, int col) {
	return grid[row][col] == ' ';
}

void Board::placeMark(int row, int col, char mark) {
	grid[row][col] = mark;
}

bool Board::checkWin(int x, int y) {
    char tmpValue = grid[x][y];
    // Toa do 1 nua cua 8 o xung quanh
    int dx[4] = { -1, -1, -1, 0 };
    int dy[4] = { -1, 0, 1, -1 };
    {
        for (int k = 0; k < 4; k++) {
            int cnt = 1;
            // first xet len tren
            // second xet xuong
            int tmpFirstX = x + dx[k]; // toa do x tren
            int tmpSecondX = x - dx[k];// toa do x duoi
            int tmpFirstY = y + dy[k]; // toa do y tren
            int tmpSecondY = y - dy[k]; // toa do y duoi
            // xet toa do di len
            while (tmpFirstX >= 0 && tmpFirstY >= 0 && grid[tmpFirstX][tmpFirstY] == tmpValue && cnt < 5) {
                cnt++;
                tmpFirstX += dx[k];
                tmpFirstY += dy[k];
            }
            // xet toa do di xuong
            while (tmpSecondX < boardSize && tmpSecondY < boardSize && grid[tmpSecondX][tmpSecondY] == tmpValue && cnt < 5) {
                cnt++;
                tmpSecondX -= dx[k];
                tmpSecondY -= dy[k];
            }
            if (cnt == 5) return true;
        }
        return false;
    }
}

bool Board::fullBoard() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++)
			if (grid[i][j] == ' ') return false;
	}
	return true;
}

void Board::boardOperation(int x, int y, bool& valid, bool currentPlayer, vector<RectangleShape>& tick) {
	int xCell = (x - 28) / xCellSize;
	int yCell = (y - 21) / yCellSize;
	valid = isEmpty(xCell, yCell);
	if (valid && currentPlayer) {
		placeMark(xCell, yCell, 'x');
		playerX.setPosition(Vector2f(xCell * xCellSize + 28, yCell * yCellSize + 20));
		tick.push_back(playerX);
		
	}
	else if (valid) {
		placeMark(xCell, yCell, 'o');
		playerY.setPosition(Vector2f(xCell * xCellSize + 28, yCell * yCellSize + 20));
		tick.push_back(playerY);
	}

	if (checkWin(xCell, yCell)) {
		bWindow->close();
		cout << "END";
	}

	else if (fullBoard()) {
		bWindow->close();
		cout << "END";
	}
}
