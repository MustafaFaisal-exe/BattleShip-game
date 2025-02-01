//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include <sstream>
//using namespace std;
//
//sf::Texture gridTexture, missTexture, destructTexture, shipTexture, rotateTexture;
//
//sf::SoundBuffer backgroundMusic;
//sf::SoundBuffer boomBuffer;
//sf::SoundBuffer bruhBuffer;
//sf::SoundBuffer fallingBuffer;
//sf::SoundBuffer splashBuffer;
//sf::SoundBuffer getOutBuffer;
//
//void setupShips(sf::Sprite ships[]) {
//    for (int i = 0; i < 5; i++) {
//        ships[i].setTexture(shipTexture);
//        ships[i].setPosition(ships[i].getPosition().x, ships[i].getPosition().y);
//    }
//}
//
//// Initialize textures
//bool loadTextures() {
//    if (!gridTexture.loadFromFile("C:/FinalYearProject/tile.jpg")) {
//        cout << "ERROR::COULD NOT LOAD THE GRID TILE\n";
//        return false;
//    }
//    if (!missTexture.loadFromFile("C:/FinalYearProject/Tile_green.jpg")) {
//        cout << "ERROR::COULD NOT LOAD THE MISS TILE\n";
//        return false;
//    }
//    if (!destructTexture.loadFromFile("C:/FinalYearProject/TileRed.jpg")) {
//        cout << "ERROR::COULD NOT LOAD THE DESTRUCT TILE\n";
//        return false;
//    }
//    if (!shipTexture.loadFromFile("C:/FinalYearProject/battleships.png")) {
//        cout << "ERROR::COULD NOT LOAD THE SHIP TEXTURE\n";
//        return false;
//    }
//    if (!rotateTexture.loadFromFile("C:/FinalYearProject/rotate.png")) {
//        cout << "ERROR::COULD NOT LOAD THE ROTATE TEXTURE\n";
//        return false;
//    }
//    return true;
//}
//
//void setupGrid(sf::RectangleShape grid[][10], const sf::Texture& texture, float offsetX, float offsetY) {
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            grid[i][j].setSize(sf::Vector2f(50, 50));
//            grid[i][j].setPosition(offsetX + i * 50, offsetY + j * 50);
//            grid[i][j].setTexture(&texture);
//            grid[i][j].setOutlineColor(sf::Color(0, 0, 139));
//            grid[i][j].setOutlineThickness(1.f);
//        }
//    }
//}
//
//// Helper function to determine if a player has won
//bool winner(bool array[][10]) {
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            if (array[i][j] == true) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//void AI_GRID(bool grid[][10], int ships_size[]) {
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            grid[i][j] = false;
//        }
//    }
//
//    srand(time(0)); 
//
//    for (int k = 0; k < 5; k++) { 
//        int ship = ships_size[k];
//        bool placed = false;
//
//        while (!placed) {
//            // random between vertical or horizontal
//            bool isVertical = rand() % 2;
//
//            // Random starting point
//            int startX = rand() % 10;
//            int startY = rand() % 10;
//
//            bool fits = true;
//            if (isVertical) {
//                if (startY + ship > 10) {
//                    //if ship out of the screen, ship does not fit
//                    fits = false;
//                }
//                else {
//                    for (int i = 0; i < ship; ++i) {
//                        if (grid[startY + i][startX]) {
//                            fits = false;
//                            break;
//                        }
//                    }
//                }
//            }
//            else { 
//                if (startX + ship > 10) {
//                    fits = false;
//                }
//                else {
//                    for (int i = 0; i < ship; ++i) {
//                        if (grid[startY][startX + i]) {
//                            fits = false;
//                            break;
//                        }
//                    }
//                }
//            }
//
//            // if ship fits successfully, mark it on the grid
//            if (fits) {
//                if (isVertical) {
//                    for (int i = 0; i < ship; ++i) {
//                        grid[startY + i][startX] = true;
//                    }
//                }
//                else {
//                    for (int i = 0; i < ship; ++i) {
//                        grid[startY][startX + i] = true;
//                    }
//                }
//                placed = true;
//            }
//        }
//    }
//
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            cout << grid[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//void animateMissile(sf::Sprite pause, sf::Sprite backgroundSprite, bool IsSingle,int rotation,sf::RectangleShape Player_grid[][10],sf::Sprite missile,sf::RectangleShape Player2_board[10][10],sf::RenderWindow& window,int gridX,int gridY,sf::Texture& destructTexture,sf::Sprite ships[]) {
//
//    sf::Sound falling;
//    if (!fallingBuffer.loadFromFile("C:/FinalYearProject/falling.wav"))
//        cout << "ERROR::BUFFER NOT FOUND\n";
//    falling.setBuffer(fallingBuffer);
//
//    float missileSpeed = 4.0f;
//    if (rotation == 90) { 
//        missile.setPosition(0.f, 200 + gridY * 50 + 25 - missile.getGlobalBounds().height / 2);
//    }
//    else if (rotation == -90) { 
//        missileSpeed = -4.0f;
//        missile.setPosition(window.getSize().x + 25, 300 + gridY * 50);
//    }
//
//    missile.setRotation(rotation);
//    float targetX;
//    if (rotation == 90) {
//        targetX = 1000 + gridX * 50 + 25 - missile.getGlobalBounds().width / 2;
//    }
//    else {
//        targetX = 200 + gridX * 50 + 25 - missile.getGlobalBounds().width / 2;
//    }
//
//    falling.play();
//    while ((rotation == 90 && missile.getPosition().x < targetX) ||
//        (rotation == -90 && missile.getPosition().x > targetX)) {
//        missile.move(missileSpeed, 0.0f);
//
//        window.clear();
//
//        window.draw(backgroundSprite);
//        window.draw(pause);
//
//        for (int i = 0; i < 10; i++) {
//            for (int j = 0; j < 10; j++) {
//                window.draw(Player_grid[i][j]);
//                window.draw(Player2_board[i][j]);
//            }
//        }
//
//        if (IsSingle) {
//            for (int i = 0; i < 5; i++) {
//                window.draw(ships[i]);
//            }
//        }
//
//        window.draw(missile);
//        window.display();
//
//        sf::sleep(sf::milliseconds(1));
//    }
//    falling.stop();
//}
//
//void LeaderBoardDisplay(sf::RenderWindow& window) {
//    cout << "In leaderboard function\n";
//    window.clear(sf::Color::Blue);
//
//    sf::Font font;
//    if (!font.loadFromFile("C:/FinalYearProject/Times New Roman/times new roman.ttf")) {
//        cout << "ERROR::COULD NOT LOAD THE LOADING FONT!" << "\n";
//        return;
//    }
//
//    sf::Text text;
//    text.setFillColor(sf::Color::Yellow);
//    text.setFont(font);
//    text.setCharacterSize(30);  
//
//    // Arrays for Players and their scores
//    string Player[1000], score[1000];
//    ifstream fr("C:/FinalYearProject/LeaderBoard.txt");
//    int index = 0;
//
//    while (getline(fr, Player[index]) && getline(fr, score[index])) {
//        index++;
//    }
//
//    // sorting the list
//    for (int i = 0; i < index - 1; i++) {
//        bool swapped = false;
//        for (int j = 0; j < index - i - 1; j++) {
//            if (stoi(score[j]) < stoi(score[j + 1])) {
//                swap(score[j], score[j + 1]);
//                swap(Player[j], Player[j + 1]);
//                swapped = true;
//            }
//        }
//
//        if (!swapped) {
//            break;
//        }
//    }
//
//    // Displaying top 5
//    for (int i = 0; i < min(5, index); i++) {
//        text.setPosition(400, 200 + 100 * i);  
//        text.setString(Player[i] + " : " + score[i]);
//        window.draw(text);
//    }
//
//    window.display();
//
//    bool waiting = true;
//    sf::Event event;
//    while (waiting) {
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//                waiting = false;
//            }
//            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
//                return;
//            }
//        }
//    }
//}
//
//
//void Win(sf::Sprite backgroundSprite, sf::RenderWindow& window, int PlayerTurn, sf::Event event, int score) {
//    window.clear();
//    window.draw(backgroundSprite);
//
//    sf::Font font;
//    if (!font.loadFromFile("C:/FinalYearProject/Times New Roman/times new roman.ttf")) {
//        cout << "ERROR::COULD NOT LOAD THE LOADING FONT!" << "\n";
//        return;
//    }
//
//    // Display winner/loser message
//    sf::Text textWinner, scoreText, promptText, usernameText;
//    textWinner.setFont(font);
//    textWinner.setFillColor(sf::Color::Yellow);
//    textWinner.setCharacterSize(60);
//    if (PlayerTurn)
//        textWinner.setString("You won!");
//    else
//        textWinner.setString("You lost!");
//    textWinner.setPosition(window.getSize().x / 2.f - textWinner.getLocalBounds().width / 2.f, 200.f);
//
//    //Score
//    scoreText.setFont(font);
//    scoreText.setFillColor(sf::Color::White);
//    scoreText.setCharacterSize(40);
//    scoreText.setString("Your score: " + to_string(score));
//    scoreText.setPosition(window.getSize().x / 2.f - scoreText.getLocalBounds().width / 2.f, 300.f);
//
//    //username prompt
//    promptText.setFont(font);
//    promptText.setFillColor(sf::Color::Yellow);
//    promptText.setCharacterSize(30);
//    promptText.setString("Enter your username and press Enter:");
//    promptText.setPosition(window.getSize().x / 2.f - promptText.getLocalBounds().width / 2.f, 400.f);
//
//    // Username
//    sf::String playerInput;
//    usernameText.setFont(font);
//    usernameText.setFillColor(sf::Color::White);
//    usernameText.setCharacterSize(30);
//    usernameText.setPosition(window.getSize().x / 2.f - 150.f, 450.f); // Adjust position for input text
//
//    while (true) {
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//                return;
//            }
//            if (event.type == sf::Event::TextEntered) {
//                if (event.text.unicode == '\b' && !playerInput.isEmpty()) {
//                    playerInput.erase(playerInput.getSize() - 1, 1);
//                }
//                else if (event.text.unicode == '\r') {
//                    if (!playerInput.isEmpty()) {
//                        //write username in file
//                        ofstream file("C:/FinalYearProject/LeaderBoard.txt", ios::app);
//                        if (file.is_open()) {
//                            file << playerInput.toAnsiString() << "\n" << score << "\n";
//                            file.close();
//                            cout << "Username saved: " << playerInput.toAnsiString() << "\n";
//                        }
//                        else {
//                            cout << "ERROR::COULD NOT OPEN FILE TO WRITE USERNAME\n";
//                        }
//
//                        // display leaderBoard
//                        LeaderBoardDisplay(window);
//                        return;
//                    }
//                }
//                else if (playerInput.getSize() < 100) { 
//                    playerInput += event.text.unicode;
//                }
//            }
//
//            usernameText.setString(playerInput);
//
//            window.clear(sf::Color::Blue);
//            window.draw(textWinner);
//            window.draw(scoreText);
//            window.draw(promptText);
//            window.draw(usernameText);
//            window.display();
//        }
//    }
//}
//
//void pause(sf::RenderWindow &window) {
//    sf::Texture resume;
//    sf::Sprite resumeSprite;
//
//    if (!resume.loadFromFile("C:\FinalYearProject/resume.png")) {
//        cout << "ERROR::COULD NOT LOAD THE RESUME BUTTON\n";
//    }
//    resumeSprite.setTexture(resume);
//    resumeSprite.setPosition(600, 600);
//
//    sf::RectangleShape resumeMenu;
//    resumeMenu.setFillColor(sf::Color::Blue);
//    resumeMenu.setSize(sf::Vector2f(800, 800));
//    resumeMenu.setPosition(100, 100);
//
//    window.draw(resumeMenu);
//    window.draw(resumeSprite);
//    window.display();
//
//    sf::Event pauseEvent;
//
//    while (window.pollEvent(pauseEvent)) {
//        sf::Vector2i mousPosPause(pauseEvent.mouseButton.x, pauseEvent.mouseButton.y);
//        if (resumeSprite.getGlobalBounds().contains(mousPosPause.x, mousPosPause.y)) {
//            return;
//        }
//        
//    }
//}
//
//
//void game(bool IsSingle, bool Player[][10], bool Player2[][10], sf::RenderWindow& window, sf::RectangleShape Player_grid[][10], sf::Sprite ships[], sf::Sprite rotate[], int ships_size[]) {
//    sf::Font font;
//    sf::Text mainText;
//    sf::Text inputText;
//
//    //Pause button
//    sf::Texture texturePause;
//    sf::Sprite pauseSprite;
//
//    if (!texturePause.loadFromFile("C:/FinalYearProject/pauseButton.png"))
//        cout << "ERROR::COULD NOT LOAD THE PAUSE BUTTON\n";
//
//    pauseSprite.setTexture(texturePause);
//    pauseSprite.setScale(0.5, 0.5);
//    pauseSprite.setPosition(1650, 10);
//
//    //Sound effects
//    sf::Sound backgroundSound;
//    if (!backgroundMusic.loadFromFile("C:/FinalYearProject/gameMusic.mp3")) {
//        cout << "ERROR::BUGGER NOT FOUND\n";
//    }
//    backgroundSound.setBuffer(backgroundMusic);
//    backgroundSound.setLoop(true);
//
//    sf::Sound boom;
//    if (!boomBuffer.loadFromFile("C:/FinalYearProject/boom.wav"))
//        cout << "ERROR::BUFFER NOT FOUND\n";
//    boom.setBuffer(boomBuffer);
//
//    sf::Sound getOut;
//    if (!getOutBuffer.loadFromFile("C:/FinalYearProject/getout.wav"))
//        cout << "ERROR::BUFFER NOT FOUND\n";
//    getOut.setBuffer(getOutBuffer);
//
//    sf::Sound splash;
//    if (!splashBuffer.loadFromFile("C:/FinalYearProject/splash.wav"))
//        cout << "ERROR::BUFFER NOT FOUND\n";
//    splash.setBuffer(splashBuffer);
//
//    sf::Sound bruh;
//    if (!bruhBuffer.loadFromFile("C:/FinalYearProject/bruh.wav"))
//        cout << "ERROR::BUFFER NOT FOUND\n";
//    bruh.setBuffer(bruhBuffer);
//
//    backgroundSound.play();
//
//
//    //AI GRID FORMATION
//    if (IsSingle) {
//        AI_GRID(Player2, ships_size);
//    }
//        
//    
//
//    if (!font.loadFromFile("C:/FinalYearProject/Times New Roman/times new roman.ttf")) {
//        cout << "ERROR::COULD NOT LOAD THE FONT\n";
//    }
//
//    mainText.setFont(font);
//    mainText.setCharacterSize(32);
//    mainText.setFillColor(sf::Color::Yellow);
//    mainText.setPosition(800, 100);
//
//    inputText.setFont(font);
//    inputText.setCharacterSize(24);
//    inputText.setFillColor(sf::Color::White);
//    inputText.setPosition(600, 500); 
//
//    string inputString;
//
//    if (!loadTextures()) {
//        cout << "Failed to load textures. Exiting game.\n";
//    }
//
//    //Background
//    sf::Texture background;
//    sf::Sprite backgroundSprite;
//
//    if (!background.loadFromFile("C:/FinalYearProject/gamebackground.png")) {
//        cout << "ERROR::COULD NOT LOAD THE GAME BACKGROUND\n";
//    }
//    
//
//    // Setup grids
//    sf::RectangleShape Player2_board[10][10];
//    setupGrid(Player_grid, gridTexture, 200, 200);    
//    setupGrid(Player2_board, gridTexture, 1000, 200);
//
//    bool PlayerTurn = true;
//    bool win = false;
//    int score = 100;
//
//    bool PlayerAttacks[10][10] = { false };
//    bool AIAttacks[10][10] = { false };
//
//
//    // Missile
//    sf::Texture missile;
//    if (!missile.loadFromFile("C:/FinalYearProject/missile.png")) {
//        cout << "ERROR::COULD NOT LOAD THE MISSILE\n";
//    }
//
//    sf::Sprite missileSprite;
//    missileSprite.setTexture(missile);
//    missileSprite.setScale(0.25, 0.25);
//
//    setupShips(ships);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
//                sf::Vector2i mousPosPause(event.mouseButton.x, event.mouseButton.y);
//                if (pauseSprite.getLocalBounds().contains(mousPosPause.x, mousPosPause.y)) {
//                    pause(window);
//                }
//            }
//
//            if (win) {
//                Win(backgroundSprite, window, PlayerTurn, event, score);
//                backgroundSound.stop();
//                return;
//            }
//            else {
//                if (PlayerTurn) {
//                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                        sf::Vector2i mousePos2(event.mouseButton.x, event.mouseButton.y);
//                        if (mousePos2.x >= 1000 && mousePos2.x <= 1500 && mousePos2.y >= 200 && mousePos2.y <= 700) {
//                            cout << "x:" << mousePos2.x << " y: " << mousePos2.y << "\n";
//                            int gridX = (mousePos2.x - 1000) / 50;
//                            int gridY = (mousePos2.y - 200) / 50;
//
//                            if (gridX >= 0 && gridX < 10 && gridY >= 0 && gridY < 10 && !AIAttacks[gridY][gridX] && !Player2_board[gridX][gridY].getRotation()) {
//                                boom.play();
//                                sf::sleep(sf::seconds(1));
//                                animateMissile(pauseSprite, backgroundSprite, IsSingle, 90, Player_grid, missileSprite, Player2_board, window, gridX, gridY, destructTexture, ships);
//
//                                // Attack logic
//                                if (Player2[gridY][gridX] == true) {
//                                    getOut.play();
//                                    sf::sleep(sf::seconds(1));
//                                    Player2[gridY][gridX] = false;
//                                    Player2_board[gridX][gridY].setTexture(&destructTexture);
//                                    Player2_board[gridX][gridY].setRotation(1);
//                                    win = winner(Player2);
//                                }
//                                else {
//                                    bruh.play();
//                                    sf::sleep(sf::seconds(1));
//                                    Player2_board[gridX][gridY].setTexture(&missTexture);
//                                }
//                                score--;
//                                PlayerTurn = false; 
//                            }
//                        }
//                    }
//                }
//
//                else {
//                    if (IsSingle) {
//                        int x, y;
//                        do {
//                            x = rand() % 10;
//                            y = rand() % 10;
//                        } while (PlayerAttacks[x][y]);
//
//                        PlayerAttacks[x][y] = true;
//                        boom.play();
//                        sf::sleep(sf::seconds(1));
//                        animateMissile(pauseSprite, backgroundSprite, IsSingle, -90, Player_grid, missileSprite, Player2_board, window, y, x, destructTexture, ships);
//
//                        if (Player[x][y]) {
//                            getOut.play();
//                            sf::sleep(sf::seconds(1));
//                            Player[x][y] = false;
//                            Player_grid[y][x].setTexture(&destructTexture);
//                            win = winner(Player);
//                        }
//                        else {
//                            bruh.play();
//                            sf::sleep(sf::seconds(1));
//                            Player_grid[y][x].setTexture(&missTexture);
//                        }
//                        PlayerTurn = true;
//                    }
//                    
//                    else {
//                        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                            sf::Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);
//                            if (mousePos.x >= 200 && mousePos.x <= 700 && mousePos.y >= 200 && mousePos.y <= 700) {
//                                int grid2X = (mousePos.x - 200) / 50;
//                                int grid2Y = (mousePos.y - 200) / 50;
//
//                                if (grid2X >= 0 && grid2X < 10 && grid2Y >= 0 && grid2Y < 10) {
//                                    boom.play();
//                                    sf::sleep(sf::seconds(1));
//                                    animateMissile(pauseSprite, backgroundSprite,IsSingle, -90, Player_grid, missileSprite, Player2_board, window, grid2X, grid2Y, destructTexture, ships);
//
//                                    if (Player[grid2Y][grid2X]) {
//                                        getOut.play();
//                                        sf::sleep(sf::seconds(1));
//                                        Player[grid2Y][grid2X] = false;
//                                        Player_grid[grid2X][grid2Y].setTexture(&destructTexture);
//                                        win = winner(Player);
//                                    }
//                                    else {
//                                        bruh.play();
//                                        sf::sleep(sf::seconds(1));
//                                        Player_grid[grid2X][grid2Y].setTexture(&missTexture);
//                                    }
//                                    PlayerTurn = true;
//                                }
//                            }
//                        }
//                        continue;
//
//                    }
//                }
//            }
//        }
//
//        if (!win) {
//            window.clear();
//
//            window.draw(backgroundSprite);
//
//            if (PlayerTurn) {
//                if (IsSingle)
//                    mainText.setString("Your turn");
//                else
//                    mainText.setString("Player1 Turn");
//            }
//            else {
//                if (IsSingle)
//                    mainText.setString("AI's turn");
//                else
//                    mainText.setString("Player2 Turn");
//            }
//
//            window.draw(mainText);
//            window.draw(pauseSprite);
//
//            for (int i = 0; i < 10; i++) {
//                for (int j = 0; j < 10; j++) {
//                    window.draw(Player_grid[i][j]);
//                    window.draw(Player2_board[i][j]);
//                }
//            }
//
//            if (IsSingle) {
//                for (int i = 0; i < 5; i++) {
//                    window.draw(ships[i]);
//                }
//            }
//            
//            inputText.setString(inputString);
//            window.draw(inputText);
//
//            window.display();
//        }
//        
//    }
//}
