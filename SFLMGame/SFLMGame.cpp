//#include <vector>
//#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace std;
//using namespace sf;
//
//
//
//// Hàm khởi tạo bàn cờ
//void resetBoard(vector<vector<char>>& board, char& currentPlayer, int boardSize) {
//    board.assign(boardSize, vector<char>(boardSize, ' '));
//    currentPlayer = 'X';
//}
//
//// Hàm vẽ nút
//void drawButton(sf::RenderWindow& window, sf::RectangleShape& button, const sf::Text& text) {
//    window.draw(button);
//    window.draw(text);
//}
//
//// Hàm xử lý chuột trong menu và hiện hitbox chọn kích thước bàn chơi
//void handleMouseMenu(sf::RenderWindow& window, const sf::Event& event, int& boardSize, bool& inMenu, vector<vector<char>>& board, char& currentPlayer, int& cellSize, int GAME_AREA_SIZE, int WINDOW_WIDTH, int WINDOW_HEIGHT) {
//    //if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//        //int mouseX = event.mouseButton.x;
//        //int mouseY = event.mouseButton.y;
//
//        // Tạo nút chọn kích thước bàn chơi
//        sf::RectangleShape button5x5(sf::Vector2f(150, 50));
//        button5x5.setPosition(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT / 2 - 100);
//        button5x5.setFillColor(sf::Color::Green);
//
//        sf::RectangleShape button7x7(sf::Vector2f(150, 50));
//        button7x7.setPosition(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT / 2);
//        button7x7.setFillColor(sf::Color::Green);
//
//        sf::RectangleShape button9x9(sf::Vector2f(150, 50));
//        button9x9.setPosition(WINDOW_WIDTH / 2 - 75, WINDOW_HEIGHT / 2 + 100);
//        button9x9.setFillColor(sf::Color::Green);
//        
//
//        sf::Font font;
//        sf::Text text5x5("5x5", font, 24);
//        text5x5.setFillColor(sf::Color::Black);
//        text5x5.setPosition(button5x5.getPosition().x + 50, button5x5.getPosition().y + 10);
//
//        sf::Text text7x7("7x7", font, 24);
//        text7x7.setFillColor(sf::Color::Black);
//        text7x7.setPosition(button7x7.getPosition().x + 50, button7x7.getPosition().y + 10);
//
//        sf::Text text9x9("9x9", font, 24);
//        text9x9.setFillColor(sf::Color::Black);
//        text9x9.setPosition(button9x9.getPosition().x + 50, button9x9.getPosition().y + 10);
//
//        // ve button
//        drawButton(window, button5x5, text5x5);
//        drawButton(window, button7x7, text7x7);
//        drawButton(window, button9x9, text9x9);
//
//        int mouseX = event.mouseButton.x;
//        int mouseY = event.mouseButton.y;
//        
//        if (button5x5.getGlobalBounds().contains(mouseX, mouseY)) {
//            boardSize = 5;
//            inMenu = false;
//        }
//        else if (button7x7.getGlobalBounds().contains(mouseX, mouseY)) {
//            boardSize = 7;
//            inMenu = false;
//        }
//        else if (button9x9.getGlobalBounds().contains(mouseX, mouseY)) {
//            boardSize = 9;
//            inMenu = false;
//        }
//        resetBoard(board, currentPlayer, boardSize);
//        cellSize = GAME_AREA_SIZE / boardSize;
//    //}
//}
//bool checkWin(vector<vector<char>>& board, int x, int y, char& c, int d) {
//    return false;
//}
//
//bool checkDraw(vector<vector<char>>& c) {
//    return false;
//}
//
//// Hàm xử lý chuột trong game
//void handleMouseGame(const sf::Event& event, int& hoverRow, int& hoverCol, vector<vector<char>>& board, char& currentPlayer, bool& gameEnded, string& gameMessage, int boardSize, int cellSize, int& scoreX, int& scoreO) {
//    // Hiệu ứng di chuyển chuột vào các ô
//    if (event.type == sf::Event::MouseMoved) {
//        int mouseX = event.mouseMove.x;
//        int mouseY = event.mouseMove.y;
//
//        hoverCol = mouseX / cellSize;
//        hoverRow = mouseY / cellSize;
//
//        // Khi di chuyển ra ngoài thì không còn hiệu ứng highlight
//        if (hoverRow < 0 || hoverRow >= boardSize || hoverCol < 0 || hoverCol >= boardSize) {
//            hoverRow = -1;
//            hoverCol = -1;
//        }
//    }
//    // Click chuột
//    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//        int mouseX = event.mouseButton.x;
//        int mouseY = event.mouseButton.y;
//
//        int col = mouseX / cellSize;
//        int row = mouseY / cellSize;
//
//        if (row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ') {
//            board[row][col] = currentPlayer;
//
//            if (checkWin(board, row, col, currentPlayer, 5)) { // Ae viết hàm checkWin xong gọi nó vô nha
//                gameMessage = "Player " + string(1, currentPlayer) + " wins!";
//                if (currentPlayer == 'X') scoreX++;
//                else scoreO++;
//                gameEnded = true;
//            }
//            else if (checkDraw(board)) { // Ae viết hàm checkDraw xong gọi nó vô nha
//                gameMessage = "Draw!";
//                gameEnded = true;
//            }
//            else {
//                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
//            }
//        }
//    }
//}
//
//// Hàm xử lý chuột khi trò chơi kết thúc
//void handleMouseGameOver(const sf::Event& event, bool& gameEnded, string& gameMessage, vector<vector<char>>& board, char& currentPlayer, int& boardSize, int& cellSize, int GAME_AREA_SIZE, int WINDOW_WIDTH, int WINDOW_HEIGHT) {
//    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//        int mouseX = event.mouseButton.x;
//        int mouseY = event.mouseButton.y;
//        sf::Font font;
//        // Tạo nút Play Again
//        sf::RectangleShape playAgainButton(sf::Vector2f(150, 50));
//        playAgainButton.setPosition(WINDOW_WIDTH - 400, WINDOW_HEIGHT / 2 - 100); //vị trí nút
//        playAgainButton.setFillColor(sf::Color::Yellow); // màu nền hitbox
//
//        sf::Text playAgainText("Play Again", font, 24);
//        playAgainText.setFillColor(sf::Color::Black); //màu text
//        playAgainText.setPosition(playAgainButton.getPosition().x + 20, playAgainButton.getPosition().y + 10); // tọa độ text
//
//        // Kiểm tra nếu nút Play Again được nhấn
//        if (playAgainButton.getGlobalBounds().contains(mouseX, mouseY)) {
//            //trả về lại các biến như cũ
//            gameEnded = false;
//            gameMessage = "";
//            resetBoard(board, currentPlayer, boardSize);
//        }
//    }
//}
//
//
//int main() {
//    // Lấy độ phân giải màn hình hiện tại
//    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
//    const int SCREEN_WIDTH = desktopMode.width;
//    const int SCREEN_HEIGHT = desktopMode.height;
//
//    const int WINDOW_WIDTH = SCREEN_WIDTH; //pixel
//    const int WINDOW_HEIGHT = SCREEN_HEIGHT; //pixel
//    const int GAME_AREA_SIZE = WINDOW_HEIGHT;  // Khu vực chơi hình vuông bằng chiều cao cửa sổ
//    int boardSize = 9;                        // Kích thước bàn cờ
//    int cellSize = GAME_AREA_SIZE / boardSize;  // Kích thước mỗi ô
//    char currentPlayer = 'X';                 // Người chơi hiện tại
//    vector<vector<char>> board(boardSize, vector<char>(boardSize, ' '));  // Ma trận bàn cờ
//
//    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Caro", sf::Style::Titlebar | sf::Style::Close);
//    window.setFramerateLimit(120);
//
//    // font arial t đang để đường dẫn tương đối ngay trong file (project)/assets/fonts/arial.ttf
//    sf::Font font;
//    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
//        cout << "Font lỗi" << endl;
//    }
//
//    // Biến trạng thái
//    bool inMenu = true;
//    bool gameEnded = false;
//    string gameMessage = "";
//    int scoreX = 0, scoreO = 0;
//
//    // Hiệu ứng chuột
//    int hoverRow = -1, hoverCol = -1;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) { //kiem tra cua so window con chay khong
//                window.close();
//            }
//            if (inMenu) { //inmenu la dang trong giao dien chon kich thuoc ban co
//                // gọi hàm xử lý chuột menu nha ae
//            }
//            else if (!gameEnded) {
//                // Gọi hàm xử lý chuột ingame để nó cập nhật tọa độ x y liên tục
//            }
//            else if (gameEnded) {
//                //Gọi hàm xử lý chuột khi endgame nha ae
//            }
//        }
//        window.clear(sf::Color::White);
//        if (inMenu) { // trong menu
//            //Gọi Hàm xử lý chuột trước khi chơi, ae thêm phần đồ họa, thuật toán thêm nhé
//            handleMouseMenu(window, event, boardSize, inMenu, board, currentPlayer, cellSize, GAME_AREA_SIZE, WINDOW_WIDTH, WINDOW_HEIGHT);
//        }
//        else {
//            handleMouseGame(event, hoverRow, hoverCol, board, currentPlayer, gameEnded, gameMessage, boardSize, cellSize, scoreX, scoreO);
//            for (int i = 0; i < boardSize; i++) {
//                for (int j = 0; j < boardSize; j++) {
//                    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
//                    cell.setPosition(j * cellSize, i * cellSize);
//                    //Màu highlight di chuột
//                    if (i == hoverRow && j == hoverCol && board[i][j] == ' ') {
//                        cell.setFillColor(sf::Color(200, 200, 200));
//                    }
//                    else {
//                        cell.setFillColor(sf::Color::White);
//                    }
//                    //Viền
//                    cell.setOutlineColor(sf::Color::Black);
//                    cell.setOutlineThickness(1);
//                    window.draw(cell);
//                    //Đánh X O
//                    if (board[i][j] != ' ') {
//                        sf::Text text;
//                        text.setFont(font);
//                        text.setString(board[i][j]);
//                        text.setCharacterSize(cellSize - 10);
//                        text.setFillColor(board[i][j] == 'X' ? sf::Color::Red : sf::Color::Cyan);
//                        text.setPosition(j * cellSize + 5, i * cellSize - 5);
//                        window.draw(text);
//                    }
//                }
//            }
//            // Tỉ số bên cạnh
//            sf::Text scoreText("X: " + to_string(scoreX) + " - O: " + to_string(scoreO), font, 24);
//            scoreText.setFillColor(sf::Color::Black);
//            scoreText.setPosition(GAME_AREA_SIZE + 10, 50);
//            window.draw(scoreText);
//
//            if (gameEnded) {
//                //gameMessage là cái trạng thái thắng thua hòa, ae chỉnh lại cũng được
//                sf::Text endText(gameMessage, font, 24);
//                endText.setFillColor(sf::Color::Black);
//                endText.setPosition(GAME_AREA_SIZE + 10, 100);
//                window.draw(endText);
//
//                // gọi lại hàm xử lý chuột khi kết thúc game...
//            }
//        }
//        window.display();
//    }
//    return 0;
//}

#include "Application.h"

void main() {
	Application app;
	app.Run();
}