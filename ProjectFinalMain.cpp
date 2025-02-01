//#include <iostream>
//#include <fstream>
//#include <ctime>
//
//#include "fleet_placement.h"
//#include "LoadingScreen.h"
//#include "helpScreen.h"
//#include "homescreen.h"
//
//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//
//using namespace std;
//
//sf::RenderWindow window;
//sf::SoundBuffer buffer;
//sf::Sound sound;
//
//void HandleMainMenuEvents(const sf::Vector2f& mousePos, int& screen, sf::FloatRect(&buttonPressed)[4]) {
//	if (buttonPressed[0].contains(mousePos)) {
//		screen = 3;
//		loadingScreen(window);
//		sound.stop();
//		std::cout << "SinglePlayer\n";
//	}
//	else if (buttonPressed[1].contains(mousePos)) {
//		loadingScreen(window);
//		sound.stop();
//		screen = 5;
//		std::cout << "Multiplayer\n";
//	}
//	else if (buttonPressed[2].contains(mousePos.x, mousePos.y)) {
//		screen = 6;
//		std::cout << "Displaying Help...\n";
//	}
//	else if (buttonPressed[3].contains(mousePos)) {
//		sound.stop();
//		sf::SoundBuffer closeBuffer;
//		sf::Sound closeSound;
//		closeBuffer.loadFromFile("C:/FinalYearProject/bruh.wav");
//		closeSound.setBuffer(closeBuffer);
//		closeSound.play();
//		sf::sleep(sf::seconds(1));
//		window.close();
//	}
//}
//
//void MainMenu(sf::FloatRect(&buttonPressed)[4]) {
//	string ButtonName[4] = { "SinglePlayer", "MultiPlayer", "Help", "Exit" };
//
//	// Background
//	sf::Image mainMenu;
//	sf::Texture texture;
//	sf::Sprite sprite;
//
//	// Buttons
//	sf::Image buttons[4];
//	sf::Texture textureButton[4];
//	sf::Sprite spriteButton[4];
//
//	// Text
//	sf::Font font;
//	sf::Text text[4];
//
//	if (!font.loadFromFile("C:/FinalYearProject/Times New Roman/times new roman.ttf")) {
//		cout << "ERROR::COULD NOT LOAD THE FONT!" << "\n";
//	}
//
//	if (!mainMenu.loadFromFile("C:/FinalYearProject/MainMenuBackground.png")) {
//		cout << "ERROR::COULD NOT LOAD THE BACKGROUND IMAGE!" << "\n";
//	}
//	texture.loadFromImage(mainMenu);
//	sprite.setTexture(texture);
//	window.clear();
//	window.draw(sprite);
//
//	for (int i = 0; i < 4; i++) {
//		if (!buttons[i].loadFromFile("C:/FinalYearProject/button.png")) {
//			std::cout << "ERROR::COULD NOT LOAD THE BUTTON!" << "\n";
//		}
//
//		textureButton[i].loadFromImage(buttons[i]);
//		spriteButton[i].setTexture(textureButton[i]);
//		spriteButton[i].setPosition(sf::Vector2f(700, 200 + 200 * i));
//		window.draw(spriteButton[i]);
//
//		text[i].setFont(font);
//		text[i].setFillColor(sf::Color::White);
//		text[i].setOutlineColor(sf::Color::Cyan);
//		text[i].setOutlineThickness(1.f);
//		text[i].setCharacterSize(40.f);
//
//		text[i].setString(ButtonName[i]);
//
//		sf::FloatRect textBounds = text[i].getLocalBounds();
//
//		text[i].setPosition(
//			spriteButton[i].getPosition().x + (spriteButton[i].getGlobalBounds().width / 2.f) - (textBounds.width / 2.f),
//			spriteButton[i].getPosition().y + (spriteButton[i].getGlobalBounds().height / 2.f) - (textBounds.height / 2.f) - 5.f
//		);
//
//		window.draw(text[i]);
//		buttonPressed[i] = spriteButton[i].getGlobalBounds();
//	}
//
//	window.display();
//}
//
//void PollEvents(int& screen, sf::FloatRect(&buttonPressed)[4],sf::Sprite ships[], sf::Sprite rotate[],sf::RectangleShape start, bool grid[][10], bool isDragging, int draggingIndex, int ship_size[], sf::Vector2f offset) {
//	sf::Event ev;
//	while (window.pollEvent(ev)) {
//		sf::Vector2f mousePos(ev.mouseButton.x, ev.mouseButton.y);
//		if (ev.type == sf::Event::Closed) {
//			
//			window.close();
//		}
//		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Enter && screen == 0) {
//			loadingScreen(window);
//			screen = 2;
//		}
//		else if (screen == 2 && ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left) {
//			HandleMainMenuEvents(mousePos, screen, buttonPressed);
//		}
//		else if (screen == 6 && ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape) {
//			screen = 2;
//		}
//	}
//	
//}
//
//int main() {
//	int screen = 0;
//	bool loadingComplete = false;
//
//	sf::FloatRect buttonPressed[4];
//	sf::RectangleShape rectangle_grid[10][10];
//	sf::RectangleShape start;
//	sf::Sprite rotate[5];
//	sf::Vector2f offset;
//	sf::Sprite ships[5];
//
//	bool Player1[10][10] = { { false } };
//	bool Ai_grid[10][10] = { { false } };
//	bool Player2[10][10] = { { false } };
//	int ship_size[] = { 5, 4, 3, 3, 2 };
//	bool isDragging = false;
//	int draggingIndex = -1;
//	bool IsSingle;
//
//	if (!buffer.loadFromFile("C:/FinalYearProject/backgroundmusic.mp3")) {
//		cout << "ERROR::COULD NOT LOAD THE BACKGROUND MUSIC\n";
//	}
//
//	sound.setBuffer(buffer);
//	sound.setLoop(true);
//	sound.play();
//	
//	window.create(sf::VideoMode(1792, 1024), "Battleship", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
//	window.setFramerateLimit(60);
//
//	window.clear();
//	while (window.isOpen()) {
//		PollEvents(screen, buttonPressed,ships, rotate, start, Player1, isDragging, draggingIndex, ship_size, offset);
//		cout << "INSIDE MAIN::Screen = " << screen << "\n";
//		if (screen == 0)
//			homescreen(window);
//
//		else if (screen == 2) {
//			MainMenu(buttonPressed);
//		}
//		else if (screen == 3) {
//			cout << "FleetPlacement starts\n";
//			screen = fleet(0, Player1, Ai_grid, window, rectangle_grid, ships, rotate);
//			IsSingle = true;
//		}
//		else if (screen == 4) {
//			cout << "Game\n";
//			if (IsSingle)
//				game(IsSingle, Player1, Ai_grid, window, rectangle_grid, ships, rotate, ship_size);
//			else
//				game(IsSingle, Player1, Player2, window, rectangle_grid, ships, rotate, ship_size);
//			screen = 2;
//			sound.play();
//			
//		}
//		else if (screen == 6) {
//			HoveringHelpWindow(window);
//			
//		}
//		else if (screen == 5) {
//			screen = fleet(0, Player1, Ai_grid, window, rectangle_grid, ships, rotate);
//			screen = fleet(1, Player2, Ai_grid, window, rectangle_grid, ships, rotate);
//			cout << "-----Player1-------------\n";
//			for (int i = 0; i < 10; i++) {
//				for (int j = 0; j < 10; j++) {
//					cout << Player1[i][j] << " ";
//				}
//				cout << endl;
//			}
//			cout << "-----Player2-------------\n";
//			for (int i = 0; i < 10; i++) {
//				for (int j = 0; j < 10; j++) {
//					cout << Player2[i][j] << " ";
//				}
//				cout << endl;
//			}
//			IsSingle = false;
//		}
//	}
//}