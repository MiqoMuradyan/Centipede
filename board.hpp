#pragma once

#include <array>
#include <iostream>

#include "character.hpp"
#include "enums.hpp"


const int BOARD_HEIGHT = 40;
const int BOARD_WIDTH = 40;

const int MUSHROOMS_COUNT_MIN = 20;
const int MUSHROOMS_COUNT_MAX = 30;

using arrayOfCharacters = std::array<Character, BOARD_WIDTH>;
using matrixOfCharacters = std::array<arrayOfCharacters, BOARD_HEIGHT>;

class Board {
public:
    Board();
    ~Board();

    void generateRandomMushrooms();
    void shoot(int cursorY, int cursorX);
    void moveBulletsUp();
    void checkEnemyCollision(int posY, int posX);
    void movePlayer(EDirections direction);
    matrixOfCharacters getTable();
    bool getIsLose();

private:
    int playerPosX;
    int playerPosY;
    bool isLose = false;
    matrixOfCharacters table;
};