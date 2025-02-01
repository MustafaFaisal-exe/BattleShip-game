//#pragma once
//
//#include "Game.h"
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <ctime>
//#include <random>
//using namespace std;
//
//
//bool canPlaceShip(bool Ai_Grid[][10], int x, int y, int size, bool horizontal) {
//    if (horizontal) {
//        if (x + size > 10) 
//            return false; 
//        for (int i = 0; i < size; ++i) {
//            if (Ai_Grid[y][x + i]) 
//                return false;
//        }
//    }
//    else {
//        if (y + size > 10) 
//            return false;
//        for (int i = 0; i < size; ++i) {
//            if (Ai_Grid[y + i][x]) 
//                return false; 
//        }
//    }
//    return true;
//}
//
//
//void PrintGrid(bool Player_Grid[][10]) {
//    cout << "----------------------------" << endl;
//    cout << "---------Player-------------" << endl;
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            cout << Player_Grid[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int fleet(int PlayerNum, bool Player1[][10], bool Player2[][10], sf::RenderWindow& window, sf::RectangleShape rectangle_grid[][10], sf::Sprite ships[], sf::Sprite rotate[]) {
//    bool isCorrect = true;
//    const int NUM_SHIPS = 5;
//    
//    //Background image
//    sf::Texture background;
//    sf::Sprite gamebackgroundSprite;
//
//    if (!background.loadFromFile("C:/FinalYearProject/gamebackground.png")) {
//        cout << "ERROR::COULD NOT LOAD THE GAME BACKGROUND\n";
//    }
//    gamebackgroundSprite.setTexture(background);
//
//    //window.draw(backgroundSprite);
//    //window.display();
//
//    // Define the number of ships and their sizes
//    const sf::IntRect shipRects[NUM_SHIPS] = {
//        sf::IntRect(3, 5, 43, 250),
//        sf::IntRect(45, 5, 40, 200),
//        sf::IntRect(89, 5, 44, 150),
//        sf::IntRect(132, 5, 44, 150),
//        sf::IntRect(176, 5, 44, 100)
//    };
//
//    int ship_size[] = { 5, 4, 3, 3, 2 };
//
//    
//
//    //start button
//    sf::Texture textureStart;
//    sf::Sprite start;
//
//    sf::Font font;
//    sf::Text startText;
//
//    if (!font.loadFromFile("C:/FinalYearProject/Times New Roman/times new roman.ttf")) {
//        cout << "ERROR::COULD NOT LOAD THE FONT!" << "\n";
//    }
//
//
//    if (!textureStart.loadFromFile("C:/FinalYearProject/button.png")) {
//        cout << "ERROR::COULD NOT LOAD THE BUTTON!" << "\n";
//    }
//    start.setTexture(textureStart);
//
//    start.setPosition(800.f, 800.f);
//
//    startText.setFont(font);
//
//    startText.setOrigin(startText.getLocalBounds().left + startText.getLocalBounds().width / 2.f, startText.getLocalBounds().top + startText.getLocalBounds().height / 2.f);
//
//    startText.setPosition(start.getGlobalBounds().left + start.getGlobalBounds().width / 2.f, start.getGlobalBounds().top + start.getGlobalBounds().height / 2.f);
//
//    startText.setString("Start");
//
//    //grid tile texture
//    sf::Texture tileTexture;
//    sf::Sprite tileSprite;
//
//    if (!tileTexture.loadFromFile("C:/FinalYearProject/tile.jpg"))
//        cout << "ERROR::COULD NOT LOAD THE TEXTURE OF TILE\n";
//
//    tileSprite.setTexture(tileTexture);
//
//    // Create a 10x10 grid of rectangles
//    
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            rectangle_grid[i][j].setTexture(&tileTexture);
//            rectangle_grid[i][j].setOutlineColor(sf::Color(0, 0, 139));
//            rectangle_grid[i][j].setOutlineThickness(1.f);
//            rectangle_grid[i][j].setSize(sf::Vector2f(50, 50));
//            rectangle_grid[i][j].setPosition(sf::Vector2f(200 + 50 * i + 800 * PlayerNum, 200 + 50 * j));
//        }
//    }
//
//    // Load battleships
//    sf::Texture texture;
//    if (!texture.loadFromFile("C:/FinalYearProject/battleships.png")) {
//        cout << "Error loading texture" << endl;
//    }
//
//    //load rotate symbol
//    sf::Texture textureRotate;
//    if (!textureRotate.loadFromFile("C:/FinalYearProject/rotate.png")) {
//        cout << "Error loading texture" << endl;
//    }
//
//    // Create the ships
//    
//    for (int i = 0; i < NUM_SHIPS; ++i) {
//        ships[i].setTexture(texture);
//        ships[i].setTextureRect(shipRects[i]);
//        ships[i].setPosition(200.0f + i * 50.0f + 800 * PlayerNum, 200.0f);
//        ships[i].setScale(1, 1.1);
//        ships[i].setRotation(0);
//
//        cout << int(ships[i].getLocalBounds().height / 44.5) << "\n";
//
//        rotate[i].setTexture(textureRotate);
//        rotate[i].setPosition(sf::Vector2f(ships[i].getPosition().x, ships[i].getPosition().y - 50));
//        rotate[i].setScale(0.75, 0.75);
//
//    }
//
//    // dragging
//    bool isDragging = false;
//    int draggingIndex = -1;
//    sf::Vector2f offset;
//
//
//    while (window.isOpen()) {
//        sf::Event event;
//
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonPressed) {
//                if (event.mouseButton.button == sf::Mouse::Button::Left) {
//                    auto mouse_pos = sf::Mouse::getPosition(window);
//                    auto translated_pos = window.mapPixelToCoords(mouse_pos);
//
//                    // Check if the mouse is over any sprite
//                    for (int i = 0; i < 5; i++) {
//                        if (ships[i].getGlobalBounds().contains(translated_pos)) {
//                            isDragging = true;
//                            draggingIndex = i;
//
//                            offset = ships[i].getPosition() - translated_pos;
//                            break;
//                        }
//                    }
//                    for (int i = 0; i < 10; i++) {
//                        for (int j = 0; j < 10; j++) {
//                            Player1[i][j] = false;
//                        }
//                    }
//                }
//            }
//            //rotate button clicked
//            if (event.type == sf::Event::MouseButtonPressed) {
//                if (event.mouseButton.button == sf::Mouse::Button::Left) {
//                    auto mouse_pos = sf::Mouse::getPosition(window);
//                    auto translated_pos = window.mapPixelToCoords(mouse_pos);
//
//                    for (int i = 0; i < 5; i++) {
//                        if (rotate[i].getGlobalBounds().contains(translated_pos)) {
//
//                            if (ships[i].getRotation() == 0) {
//                                ships[i].setPosition(sf::Vector2f(ships[i].getPosition().x,
//                                    ships[i].getPosition().y + 50));
//
//                                ships[i].setRotation(270);
//                            }
//                            else {
//                                ships[i].setPosition(sf::Vector2f(ships[i].getPosition().x,
//                                    ships[i].getPosition().y - 50));
//                                ships[i].setRotation(0);
//                            }
//                            break;
//                        }
//                    }
//                }
//            }
//
//            //Start button pressed
//            if (event.type == sf::Event::MouseButtonPressed) {
//                if (event.mouseButton.button == sf::Mouse::Left) {
//                    auto mouse_pos = sf::Mouse::getPosition(window);
//                    auto translated_pos = window.mapPixelToCoords(mouse_pos);
//
//                    if (start.getGlobalBounds().contains(translated_pos)) {
//                        for (int i = 0; i < 5; i++) {
//                            int start_index_x = (ships[i].getPosition().x - 200 - 800 * PlayerNum) / 50;
//                            int start_index_y = (ships[i].getPosition().y - 200) / 50 - (ships[i].getRotation() / 270);
//
//                            for (int j = 0; j < ship_size[i]; j++) {
//                                if (start_index_x >= 10 || start_index_x < 0 || start_index_y >= 10 || start_index_y < 0) {
//                                    cout << "Ship " << i << " Out of range\n";
//                                    isCorrect = false;
//                                    for (int i = 0; i < 10; i++) {
//                                        for (int j = 0; j < 10; j++) {
//                                            Player1[i][j] = false;
//                                        }
//                                    }
//                                    break;
//                                }
//                                if (Player1[start_index_y][start_index_x] == false) {
//                                    if (ships[i].getRotation() == 0)
//                                        Player1[start_index_y++][start_index_x] = true;
//                                    else
//                                        Player1[start_index_y][start_index_x++] = true;
//                                }
//                                else {
//                                    isCorrect = false;
//                                    cout << "Invalid Placement. Ships should not overlap" << "\n";
//                                    for (int i = 0; i < 10; i++) {
//                                        for (int j = 0; j < 10; j++) {
//                                            Player1[i][j] = false;
//                                        }
//                                    }
//                                    break;
//                                }
//                            }
//                        }
//                        if (isCorrect) {
//                            PrintGrid(Player1);
//                            start.setColor(sf::Color(255, 255, 255, 0));
//                            window.draw(start);
//                            window.draw(startText);
//                            window.display();
//                            return 4;
//                        }
//                    }
//                    for (int i = 0; i < 10; i++) {
//                        for (int j = 0; j < 10; j++)
//                            cout << Player1[i][j] << " ";
//                        cout << "\n";
//                    }
//                    cout << "__________________________________" << "\n";
//                }
//            }
//
//            if (event.type == sf::Event::MouseButtonReleased) {
//                if (event.mouseButton.button == sf::Mouse::Button::Left) {
//                    if ((ships[draggingIndex].getPosition().x < 200 + 800 * PlayerNum || ships[draggingIndex].getPosition().x > 700 + 800 * PlayerNum
//                        ||
//                        ships[draggingIndex].getPosition().y < 200 || ships[draggingIndex].getPosition().y > 700)) {
//
//
//                        if (ships[draggingIndex].getRotation() == 0) {
//                            ships[draggingIndex].setPosition(200.0f + draggingIndex * 50.0f + 800 * PlayerNum, 200.0f);
//                            rotate[draggingIndex].setPosition(sf::Vector2f(ships[draggingIndex].getPosition().x, ships[draggingIndex].getPosition().y - 50));
//                        }
//                        else {
//                            ships[draggingIndex].setPosition(200.0f + draggingIndex * 50.0f + 800 * PlayerNum, 250.0f);
//                            rotate[draggingIndex].setPosition(sf::Vector2f(ships[draggingIndex].getPosition().x - 50, ships[draggingIndex].getPosition().y));
//                        }
//                    }
//
//                    isDragging = false;
//                    draggingIndex = -1;
//                }
//            }
//
//
//            // Update the position of the dragged sprite if dragging
//            if (isDragging && draggingIndex != -1) {
//                auto mouse_pos = sf::Mouse::getPosition(window);
//                auto translated_pos = window.mapPixelToCoords(mouse_pos);
//
//                ships[draggingIndex].setPosition(translated_pos + offset);
//                if (ships[draggingIndex].getRotation() == 0)
//                    rotate[draggingIndex].setPosition(sf::Vector2f(translated_pos.x + offset.x, translated_pos.y + offset.y - 50));
//                else
//                    rotate[draggingIndex].setPosition(sf::Vector2f(translated_pos.x + offset.x - 50, translated_pos.y + offset.y - 50));
//
//                //if ship is in grid
//                if (ships[draggingIndex].getPosition().x > 200 + 800 * PlayerNum && ships[draggingIndex].getPosition().x < 700 + 800 * PlayerNum
//                    &&
//                    ships[draggingIndex].getPosition().y > 200 && ships[draggingIndex].getPosition().y < 700) {
//
//
//
//                    if (ships[draggingIndex].getRotation() == 0) {
//                        ships[draggingIndex].setPosition(sf::Vector2f(int(ships[draggingIndex].getPosition().x / 50.0) * 50,
//                            int(ships[draggingIndex].getPosition().y / 50.0) * 50));
//
//                        rotate[draggingIndex].setPosition(sf::Vector2f(int(ships[draggingIndex].getPosition().x / 50.0) * 50,
//                            int(ships[draggingIndex].getPosition().y / 50.0) * 50 - 50));
//                    }
//
//                    else {
//                        ships[draggingIndex].setPosition(sf::Vector2f(int(ships[draggingIndex].getPosition().x / 50.0) * 50,
//                            int(ships[draggingIndex].getPosition().y / 50.0) * 50 + 50));
//
//                        rotate[draggingIndex].setPosition(sf::Vector2f(int(ships[draggingIndex].getPosition().x / 50.0) * 50 - 50,
//                            int(ships[draggingIndex].getPosition().y / 50.0) * 50 - 50));
//                    }
//                }
//            }
//
//            window.clear();
//
//            window.draw(gamebackgroundSprite);
//
//            for (int i = 0; i < 10; i++) {
//                for (int j = 0; j < 10; j++) {
//                    window.draw(rectangle_grid[i][j]);
//                }
//            }
//
//            for (int i = 0; i < NUM_SHIPS; ++i) {
//                window.draw(ships[i]);
//                window.draw(rotate[i]);
//            }
//            window.draw(start);
//
//            window.draw(startText);
//
//            window.display();
//        }
//    }
//}