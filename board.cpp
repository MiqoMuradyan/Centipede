#include "board.hpp"

Board::Board() {
    generateRandomMushrooms();

    playerPosY = BOARD_HEIGHT - 2;
    playerPosX = BOARD_WIDTH / 2;   
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
    int mushroomsCount = (rand() % (MUSHROOMS_COUNT_MAX - MUSHROOMS_COUNT_MIN + 1)) + MUSHROOMS_COUNT_MIN;
    
    int positionX;
    int positionY;
    for (int i = 0; i < mushroomsCount; ++i){
        do
        {
            positionX = rand() % BOARD_WIDTH;
            positionY = (rand() % (BOARD_HEIGHT - 2)) + 1;

        } while (table[positionY][positionX].getType() == mushroom);
        
        table[positionY][positionX].setType(mushroom);
    }
}

//Works
void Board::shoot(int cursorY, int cursorX) {
    int bulletIndexY = cursorY - 1;
    const int bulletIndexX = cursorX;

    /// TODO: Check if in this coordinates stay Mushroom uremn piti kyanq tani voch te texy grvi

    table[bulletIndexY][bulletIndexX].setType(bullet);
}


//Works
void Board::movePlayer(EDirections direction) {
    table[playerPosY][playerPosX].setType(blank);
    
    switch (direction) {
    case up:
        if (playerPosY > 0) {
            --playerPosY;
        }
        break;
    case down:
        if (playerPosY < BOARD_HEIGHT - 1) {
            ++playerPosY;
        }
        break;
    case right:
        if (playerPosX < BOARD_WIDTH - 1){
            ++playerPosX;
        }   
        break;
    case left:
        if (playerPosX > 0) {
            --playerPosX;
        }
        break;
    
    }

    table[playerPosY][playerPosX].setType(player);
}

//Works
void Board::moveBulletsUp() {
    for (int i = 0; i < BOARD_HEIGHT - 2; ++i)
    {
        for (int j = 0; j < BOARD_WIDTH; ++j)
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
