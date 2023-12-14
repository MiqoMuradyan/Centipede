#include "board.hpp"

Board::Board() {
    table[0] = generateRow();    
}

Board::~Board() {

}

matrixOfCharacters Board::getTable() {
    return table;
}

bool Board::getIsLose() {
    return isLose;
}

//Works
void Board::generateRandomMushrooms() {
    srand(time(NULL));
    int mushroomsCount = (rand() % (mushroomsCountMax - mushroomsCountMin + 1)) + mushroomsCountMin;
    
    int positionX;
    int positionY;
    for (int i = 0; i < mushroomsCount; ++i){
        do
        {
            positionX = rand() % boardWidth;
            positionY = (rand() % (boardHeight - 1)) + 1;

        } while (table[positionY][positionX].getType() == mushroom);
        
        table[positionY][positionX].setType(mushroom);
    }
}

//Works
void Board::shoot(int cursorY, int cursorX) {
    int bulletIndexY = cursorY - 1;
    const int bulletIndexX = cursorX;

    table[bulletIndexY][bulletIndexX].setType(bullet);
}

void Board::updatePlayerPosition(int positionX, int positionY) {
    for (int i = boardHeight - 2; i < boardHeight; ++i) {
        for (int j = 0; j < boardWidth; ++j) {
            table[i][j].setBlock(false);
        }
    }

    table[positionY][positionX].setBlock(true);

    /// TODO: Need to give this function a directon, and current x, y to 
    // set it blank and update player position
}

//Works
void Board::moveBulletsUp() {
    for (int i = 0; i < boardHeight - 2; ++i)
    {
        for (int j = 0; j < boardWidth; ++j)
        {
            if (table[i][j].getType() == bullet)
            {
                if(i - 1 >= 0) {
                    if (table[i - 1][j].getType() == blank)
                    {
                        table[i - 1][j].setType(bullet);
                        table[i][j].setType(blank);
                    }
                    else
                    {
                        table[i][j].setType(blank);
                        checkEnemyCollision(i - 1, j);
                    }
                }
                else {
                    table[i][j].setType(blank);
                }
            }
        }
    }
}

//Works
void Board::checkEnemyCollision(int posY, int posX) {
    if (table[posY][posX].getType() == mushroom) {
        table[posY][posX].reduceHealth();
    }
    else {
        table[posY][posX].setType(blank);
    }
}
