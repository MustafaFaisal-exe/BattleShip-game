//#pragma once
//
//#include <iostream>
//
//#include <SFML/Network.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
//
//void HoveringHelpWindow(sf::RenderWindow &window)
//{
//	sf::RectangleShape Help_Background(sf::Vector2f(window.getSize()));
//	Help_Background.setFillColor(sf::Color(0, 0, 0, 130));
//
//	//Creating the help window
//	sf::RectangleShape subHelpWindow(sf::Vector2f(400, 300));
//	subHelpWindow.setPosition(100, 100);
//	subHelpWindow.setFillColor(sf::Color::Black);
//
//	sf::Font used_font;
//	used_font.loadFromFile("C:/FinalYearProject/Times New Roman/times new roman.ttf");
//
//	sf::Text TextUsed;
//	TextUsed.setFont(used_font);
//	TextUsed.setFillColor(sf::Color::Green);
//	TextUsed.setPosition(70, 70);
//	TextUsed.setCharacterSize(24);
//	TextUsed.setString("The goal of the game is to sink your opponent's fleet of ships before they sink yours.\n The game is played on a grid,\n and each player takes turns guessing the coordinates of the opponent's ships.\nPress escape to go back to main menu\n");
//
//
//	window.draw(Help_Background);
//	window.draw(subHelpWindow);
//	window.draw(TextUsed);
//
//
//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
//		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//
//		if (subHelpWindow.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
//		}
//	}
//	window.display();
//
//}
