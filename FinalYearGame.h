#pragma once

#include<iostream>
#include<sstream>
#include<vector>
#include<ctime>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class FinalYearGame
{
private:
	sf::RenderWindow window;

	sf::Event ev;

	sf::RectangleShape grid[10][10];

	//Buttons
	sf::RectangleShape StartButton;

	//variables
	bool gamestart;

	//Functions
	void initVariables();
	void initButtons();
	void initGrid();
	void initWindow();

public:
	FinalYearGame();
	virtual ~FinalYearGame();


	//Functions
	const sf::RenderWindow& getWindow() const;
	void renderButtons();
	void updateGrid();
	void update();
	void renderGrid(sf::RenderWindow& window);
	void render();
};

