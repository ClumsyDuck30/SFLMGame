#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include "Menu.h"
#include "Player.h"

#define TITLE "Caro"

class Application {
private:
	void Init();
	void Update();
	void Render();
	void musicGame(Event event, Music& music, bool& isMute);
	RenderWindow* pWindow;
public:
	VideoMode desktopMode = VideoMode::getDesktopMode();
	int const WIDTH_SCREEN = desktopMode.width;
	int const HEIGHT_SCREEN = desktopMode.height;
	void Run();
	~Application();
};