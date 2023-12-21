#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "board.hpp"
#include "character.hpp"

#include <iostream>
#include <ncurses.h>


class GameScreen {

public:
    GameScreen();
    ~GameScreen();

    void updateGameWindow(matrixOfCharacters table);
    void updateScoreDisplay(int score, int hightScore);

private : 
    const int GAME_SCREEN_HEIGHT = 30;
    const int GAME_SCREEN_WIDTH = 80;

    int offsetX = 1;
    int offsetY = 1;

    WINDOW *gameWindow;
};


class MenuScreen{
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
    "Rules",
    "Help",
    "Quit",
    };

};

#endif //SCREEN_HPP