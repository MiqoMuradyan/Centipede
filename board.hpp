#pragma once

#include <array>
#include <iostream>
#include <memory>

#include "character.hpp"
#include "enums.hpp"


static const int boardHeight = 40;
static const int boardWidth = 40;

const int mushroomsCountMin = 20;
const int mushroomsCountMax = 30;

using arrayOfCharacters = std::array<Character, boardWidth>;
using matrixOfCharacters = std::array<arrayOfCharacters, boardHeight>;

class Board {
private:
    bool isLose = false;
    matrixOfCharacters table;
    void destroyLine(int lineIndex);

public:
    Board();
    ~Board();

    void generateRandomMushrooms();
    void shoot(int cursorY, int cursorX);
    void moveBulletsUp();
    void checkEnemyCollision(int posY, int posX);


    void updatePlayerPosition(int positionX, int positionY);
    matrixOfCharacters getTable();
    bool getIsLose();
};