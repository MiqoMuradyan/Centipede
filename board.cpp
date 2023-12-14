#include "board.hpp"

Board::Board() {
    generateRandomMushrooms();

    playerPosY = boardHeight - 2;
    playerPosX = boardWidth / 2;   
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
            positionY = (rand() % (boardHeight - 2)) + 1;

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
        if (playerPosY < boardHeight - 1) {
            ++playerPosY;
        }
        break;
    case right:
        if (playerPosX < boardWidth - 1){
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
