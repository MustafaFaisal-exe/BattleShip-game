//#pragma once
//
//
//#include <iostream>
//
//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//
//using namespace std;
//
//void homescreen(sf::RenderWindow &window) {
//	//Background
//	sf::Image HomeScreenImage;
//	sf::Texture texture;
//	sf::Sprite sprite;
//
//	//Enter text
//	sf::Font font;
//	sf::Text text;
//
//	if (!font.loadFromFile("C:/FinalYearProject/Times New Roman/times new roman.ttf"))
//		cout << "ERROR::COULD NOT LOAD THE FONT!" << "\n";
//
//	text.setFont(font);
//	text.setFillColor(sf::Color::Yellow);
//	text.setCharacterSize(40);
//	text.setOutlineColor(sf::Color::Black);
//	text.setOutlineThickness(2.f);
//	text.setString("Press Enter");
//
//	float xPos = (window.getSize().x - text.getGlobalBounds().width) / 2.0f - text.getGlobalBounds().left;
//
//
//	text.setPosition(xPos, 900);
//
//	if (!HomeScreenImage.loadFromFile("C:/FinalYearProject/HomeScreenBackground.png")) {
//		cout << "ERROR::COULD NOT FOUND THE HOME SCREEN BACKGROUND IMAGE!" << "\n";
//	}
//	texture.loadFromImage(HomeScreenImage);
//	sprite.setTexture(texture);
//
//	window.draw(sprite);
//	window.draw(text);
//	window.display();
//}