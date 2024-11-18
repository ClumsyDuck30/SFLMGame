#include "Application.h"

// Ham destructor 
Application::~Application() {
	if (pWindow != nullptr) delete pWindow;
}

// Open window
void Application::Init() {

	pWindow = new RenderWindow(VideoMode(WIDTH_SCREEN, HEIGHT_SCREEN), "Caro");
	pWindow->setFramerateLimit(60);
}

void Application::Update() {
	
}

// Print on screen
void Application::Render() {
	pWindow->clear(Color::White);
	// Draw sth
	pWindow->display();
}

void Application::musicGame(Event event, Music& music, bool &isMute) {
	if (event.key.code == sf::Keyboard::M) {
		if (isMute) {
			music.setVolume(50);
			isMute = false;
		}
		else {
			music.setVolume(0);
			isMute = true;
		}
	}
}

void Application::Run() {
	Init();
	Event event;
	bool backMenu = true;
	Music music;
	if (!music.openFromFile("../Data/Sounds/feelsgood.mp3")) {
		cout << "Error: Cannot find feelsgood.mp3.";
	}
	music.setLoop(1);
	music.play();
	bool isMute = false;

	if (pWindow->isOpen()) {
		//Print Menu		
		Menu menu(pWindow);
		while (backMenu) {
			menu.draw();
			backMenu = false;
		}
		// Choose option
		int MODE = menu.getSelectedOption();
		if (MODE != 0) {
			Player player1('x');
			Player player2('o');
			Board board(pWindow);
			board.draw(player1.getMark(), player2.getMark());
			
		}


		pWindow->display();
	}
}

