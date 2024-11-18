#include "Menu.h"

Menu::Menu(RenderWindow* win) {
	selectedOption = 0;
	mWindow = win;
}

void Menu::draw() {
	// draw menu
	vector<string> imagePaths = {
	"pixil-frame-0.png","pixil-frame-1.png","pixil-frame-2.png",
	"pixil-frame-3.png","pixil-frame-4.png","pixil-frame-5.png",
	"pixil-frame-6.png","pixil-frame-7.png","pixil-frame-8.png",
	"pixil-frame-9.png","pixil-frame-10.png","pixil-frame-11.png",
	"pixil-frame-12.png","pixil-frame-13.png","pixil-frame-14.png",
	"pixil-frame-15.png","pixil-frame-16.png","pixil-frame-17.png",
	"pixil-frame-18.png","pixil-frame-19.png","pixil-frame-20.png",
	"pixil-frame-21.png","pixil-frame-22.png","pixil-frame-23.png",
	"pixil-frame-24.png","pixil-frame-25.png","pixil-frame-26.png",
	"pixil-frame-27.png","pixil-frame-28.png","pixil-frame-29.png"
	};
	vector<Texture> textures(imagePaths.size());
	for (size_t i = 0; i < imagePaths.size(); ++i) {
		if (!textures[i].loadFromFile("../Data/Pics/pixelFrame/" + imagePaths[i])) {
			cout << "Test 1: fail !" << endl;
			; //Thoat chuong trinh neu gap loi
		}
	}
	//----------------------------------------
	//Tai anh [Giao dien: screen] vao textures
	vector<string> screenUI = {
		"../Data/Pics/pixelFrame/main-screen-decorate.png"
	};
	vector<Texture> ScreenTextures(screenUI.size());
	for (size_t i = 0; i < screenUI.size(); ++i) {
		if (!ScreenTextures[i].loadFromFile(screenUI[i])) {
			cout << "Test 2: fail !" << endl;
			return; //Thoat chuong trinh neu gap loi
		}
	}
	mWindow->clear();

	//Sprite
	Sprite sprite;
	Sprite screen;
	//change config
	sprite.setScale(12.f, 12.f);
	sprite.setPosition(280.f, -444.f);
	//Variable to control frame and time
	size_t currentFrame = 0;
	size_t currentScreen = 0;
	//Logic 
	bool isStop = false;//Stop at the last frame
	bool isButton = false;//Are u click any button
	bool isHidden = false;//Clear screen
	bool isScreenHidden = false; // clear background
	bool printMenu = true;
	//Time
	Clock frameClock;
	const Time frameDelay = milliseconds(100);//Delay time : 100ms

	RectangleShape option1(Vector2f(470.f, 85.f));
	RectangleShape option2(Vector2f(470.f, 85.f));
	RectangleShape option3(Vector2f(470.f, 85.f)); //voi man hinh 1366 768 pixel
	option1.move(Vector2f(446.f, 338.f));
	option2.move(Vector2f(446.f, 460.f));
	option3.move(Vector2f(446.f, 581.f));

	// Check programe
	while (mWindow->isOpen()) {
		Event event;
		while (mWindow->pollEvent(event)) {			
			if (event.type == Event::Closed) {
				mWindow->close();
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape) { //Click Esc to exit window
					mWindow->close();
				}
				if (event.key.code == Keyboard::E) {
					isHidden = true;
				}
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				int mouseX = event.mouseButton.x;
				int mouseY = event.mouseButton.y;
				if (option1.getGlobalBounds().contains(mouseX, mouseY)) {
					selectedOption = 10;
					printMenu = false;
				}
				else if (option2.getGlobalBounds().contains(mouseX, mouseY)) {
					selectedOption = 20;
					printMenu = false;
				}
				else if (option3.getGlobalBounds().contains(mouseX, mouseY)) {
					selectedOption = 30; // Doc huong dan
					printMenu = false;
				}
			}

		}
		if (!printMenu) break;
		// Update frame
		if (!isStop && !isHidden && frameClock.getElapsedTime() >= frameDelay) {
			currentFrame = (currentFrame + 1) % imagePaths.size();
			sprite.setTexture(textures[currentFrame]);
			frameClock.restart();
			if (currentFrame == imagePaths.size() - 1) {
				isStop = true;
			}
		}
		if (currentScreen == 0) {
			screen.setTexture(ScreenTextures[currentScreen]);
		}
		mWindow->draw(screen);
		if (!isHidden) {
			mWindow->draw(sprite);
		}
		mWindow->display();
	}
}

int Menu::getSelectedOption() {
	return this->selectedOption;
}

/*
* 446 338
919 338
918 428
447 425
447 460
446 548
916 548
918 462
446 580
446 666
915 666
918 583
*/