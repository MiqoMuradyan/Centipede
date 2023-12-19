#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "board.hpp"
#include "character.hpp"

#include <iostream>
#include <ncurses.h>

class Screen
{
public:
    Screen();
    ~Screen();
private:
};


class GameScreen:Screen {

public:
    GameScreen();
    ~GameScreen();

    void updateGameWindow(matrixOfCharacters table);
    void updateScoreDisplay(int score, int hightScore);

private : 
    const int gameScreenHeight = 30;
    const int gameScreenWidth = 80;
    const int scoreScreenHeight = 20;
    const int scoreScreenWidth = 10;

    int offsetX = 1;
    int offsetY = 1;

    WINDOW *gameWindow;
    WINDOW *scoreWindow;
};


class MenuScreen:Screen {
public:
    MenuScreen();
    ~MenuScreen();
    void updateMenuWindow(int choice);
    
private:
    const int menuScreenHeight = 9;
    const int menuScreenWidth = 14;

    WINDOW *menuWindow;

    const std::string buttons[4] = {
    "Play",
    "Settings",
    "Help",
    "Exit",
    };

};

#endif //SCREEN_HPP