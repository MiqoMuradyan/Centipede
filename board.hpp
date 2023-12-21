#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <iostream>

#include "centipede.hpp"
#include "character.hpp"
#include "enums.hpp"


const int BOARD_HEIGHT = 30;
const int BOARD_WIDTH = 40;

const int MUSHROOMS_COUNT_MIN = 20;
const int MUSHROOMS_COUNT_MAX = 30;

using arrayOfCharacters = std::array<Character, BOARD_WIDTH>; //
using matrixOfCharacters = std::array<arrayOfCharacters, BOARD_HEIGHT>;

class Board {
public:
    Board();

    void generateRandomMushrooms();
    void shoot();
    void moveBulletsUp(); 
    void checkEnemyType(int posY, int posX);
    bool movePlayer(EDirections direction);
    matrixOfCharacters getTable();
    void insertCentipedeInTable();
    void spawnCentipede();
    void moveCentipede();

private:
    int playerPosX;
    int playerPosY;
    matrixOfCharacters table;
    Centipede centipede;
};

#endif //BOARD_HPP