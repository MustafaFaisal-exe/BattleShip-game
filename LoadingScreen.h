//#pragma once
//
//#include <iostream>
//#include <fstream>
//
//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//
//using namespace std;
//
//void loadingScreen(sf::RenderWindow &window) {
//	//Background image
//	sf::Image LoadScreenImage;
//	sf::Texture texture;
//	sf::Sprite sprite;
//
//	// Loading animation (big bar behind the smol bar)
//	sf::RectangleShape loadBar;
//	sf::RectangleShape loadBarMax;
//
//	sf::Font font;
//	sf::Text text;
//
//	if (!LoadScreenImage.loadFromFile("C:/FinalYearProject/LoadingScreenBackground.png")) {
//		cout << "ERROR::COULD NOT FIND THE HOME SCREEN BACKGROUND IMAGE!" << "\n";
//	}
//	texture.loadFromImage(LoadScreenImage);
//	sprite.setTexture(texture);
//
//	if (!font.loadFromFile("C:/FinalYearProject/Times New Roman/times new roman.ttf")) {
//		cout << "ERROR::COULD NOT LOAD THE LOADING FONT!" << "\n";
//	}
//
//	// Loading screen facts 
//	sf::Text loadingText;
//	loadingText.setFont(font);
//	loadingText.setFillColor(sf::Color::Yellow);
//	loadingText.setOutlineColor(sf::Color::Black);
//	loadingText.setOutlineThickness(1.f);
//	loadingText.setCharacterSize(20);
//	loadingText.setPosition(window.getSize().x / 2.0f, 920);
//
//	ifstream fr("C:/FinalYearProject/loading screen tips.txt");
//	if (!fr.is_open()) {
//		cout << "ERROR::COULD NOT OPEN THE LOADING SCREEN TIPS FILE!" << "\n";
//		return;
//	}
//
//	srand((time(0)));
//	int randLine = rand() % 11 + 1;
//	string temp;
//	for (int i = 0; i < randLine; ++i) {
//		if (!getline(fr, temp)) {
//			temp = "No fact available!";
//			break;
//		}
//	}
//	loadingText.setString(temp);
//	sf::FloatRect textBounds = loadingText.getLocalBounds();
//	loadingText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
//	loadingText.setPosition(window.getSize().x / 2.0f, 920);
//	fr.close();
//
//	// Loading bar max setup
//	loadBarMax.setFillColor(sf::Color(255, 255, 255, 0));
//	loadBarMax.setOutlineColor(sf::Color::Yellow);
//	loadBarMax.setOutlineThickness(2.f);
//	loadBarMax.setSize(sf::Vector2f(1642, 50));
//	loadBarMax.setPosition(sf::Vector2f(50, 850));
//
//	// Loading... text
//	text.setFont(font);
//	text.setFillColor(sf::Color::Yellow);
//	text.setOutlineColor(sf::Color::Black);
//	text.setOutlineThickness(1.f);
//	text.setCharacterSize(40);
//	text.setPosition(window.getSize().x / 2.0f, 800);
//	sf::FloatRect textBoundsLoading = text.getLocalBounds();
//	text.setOrigin(textBoundsLoading.left + textBoundsLoading.width / 2.0f, textBoundsLoading.top + textBoundsLoading.height / 2.0f);
//
//	// Load bar setup
//	loadBar.setFillColor(sf::Color::Yellow);
//	loadBar.setSize(sf::Vector2f(0, 50));
//	loadBar.setPosition(sf::Vector2f(50, 850));
//
//	// Animation loop
//	const float maxWidth = 1642;
//	const float increment = 10;
//	const sf::Time delay = sf::milliseconds(30);
//	sf::Clock clock;
//	int dotCount = 0;
//	string baseText = "Loading";
//	string tempLoading;
//	int dotUpdateCounter = 0;
//
//	while (loadBar.getSize().x < maxWidth) {
//		window.clear();
//		window.draw(sprite);
//		window.draw(loadBarMax);
//
//		if (dotUpdateCounter % 10 == 0) {
//			dotCount = (dotCount + 1) % 4;
//			tempLoading = baseText;
//			for (int i = 0; i < dotCount; i++) {
//				tempLoading += '.';
//			}
//			text.setString(tempLoading);
//
//			sf::FloatRect textBoundsLoading = text.getLocalBounds();
//			text.setOrigin(textBoundsLoading.left + textBoundsLoading.width / 2.0f, textBoundsLoading.top + textBoundsLoading.height / 2.0f);
//			text.setPosition(window.getSize().x / 2.0f, 800);
//		}
//		dotUpdateCounter++;
//
//		window.draw(text);
//		window.draw(loadBar);
//		window.draw(loadingText);
//
//		// incrementing loading bar size
//		float newWidth = loadBar.getSize().x + increment;
//		loadBar.setSize(sf::Vector2f(newWidth, 50));
//		window.display();
//
//		while (clock.getElapsedTime() < delay);
//		clock.restart();
//	}
//
//}
