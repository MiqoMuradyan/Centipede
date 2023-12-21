#include "board.hpp"

Board::Board() {
    generateRandomMushrooms();
    playerPosY = BOARD_HEIGHT - 2;
    playerPosX = BOARD_WIDTH / 2;   
} 

matrixOfCharacters Board::getTable() {
    return table;
}

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

void Board::shoot() {
    int bulletIndexY = playerPosY - 1;
    const int bulletIndexX = playerPosX;

    if(table[bulletIndexY][bulletIndexX].getType() != blank) {
        checkEnemyType(bulletIndexY, bulletIndexX);
    }
    else {
        table[bulletIndexY][bulletIndexX].setType(bullet);
    }
}

bool Board::movePlayer(EDirections direction) {
    table[playerPosY][playerPosX].setType(blank);
    bool lifeStatus = true;

    switch (direction) {
    case up:
        if ((playerPosY > 0 && table[playerPosY - 1][playerPosX].getType() == !mushroom) || table[playerPosY - 1][playerPosX].getType() == ECharactersType::centipede) {
            --playerPosY;
        }
        break;
    case down:
        if ((playerPosY < BOARD_HEIGHT - 1 && table[playerPosY + 1][playerPosX].getType() == !mushroom) || table[playerPosY + 1][playerPosX].getType() == ECharactersType::centipede) {
            ++playerPosY;
        }
        break;
    case right:
        if ((playerPosX < BOARD_WIDTH - 1 && table[playerPosY][playerPosX + 1].getType() == !mushroom) ||  table[playerPosY][playerPosX + 1].getType() == ECharactersType::centipede){
            ++playerPosX;
        }   
        break;
    case left:
        if ((playerPosX > 0 && table[playerPosY][playerPosX - 1].getType() == !mushroom) ||  table[playerPosY][playerPosX - 1].getType() == ECharactersType::centipede) {
            --playerPosX;
        }
        break;
    
    }

    if(table[playerPosY][playerPosX].getType() == ECharactersType::centipede) {
        lifeStatus = false;
    }

    table[playerPosY][playerPosX].setType(player);

    return lifeStatus;
}

void Board::moveBulletsUp() {
    for (int i = 0; i < BOARD_HEIGHT - 1; ++i)
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
                        checkEnemyType(i - 1, j);
                    }
                }
                else {
                    table[i][j].setType(blank);
                }
            }
        }
    }
}

void Board::checkEnemyType(int posY, int posX) {
    if (table[posY][posX].getType() == mushroom) {
        table[posY][posX].reduceHealth();
    }
    else if (table[posY][posX].getType() == ECharactersType::centipede) {
        const auto [segPosX, segPosY] = centipede.getCentipede()[centipede.getCentipede().size() - 1].getPosition();
        table[segPosY][segPosX].setType(mushroom);
        centipede.deleteLastSegment();
    }
    else {
        table[posY][posX].setType(blank);
    }
}

void Board::insertCentipedeInTable() {
    for (int i = 0; i < centipede.getCentipede().size(); ++i) {
        auto [x, y] = centipede.getCentipede()[i].getPosition();

        if(x >= 0 && y >= 0) {
            table[y][x].setType(ECharactersType::centipede);
        }
    }
}

void Board::moveCentipede() {
    const auto [nextPosX, nextPosY] = centipede.getCentipede()[0].computeNextPosition();
    
    for(int i = 0; i < centipede.getCentipede().size(); ++i) {
        
        auto [x, y] = centipede.getCentipede()[i].getPosition();
        if(x >= 0 && y >= 0) {
            table[y][x].setType(blank);
        }
    }

    if(nextPosX >= BOARD_WIDTH || nextPosX < 0 || 
    table[nextPosY][nextPosX].getType() == mushroom) {

        if(nextPosY >= BOARD_HEIGHT - 1) {
            centipede.deleteLastSegment();
        }
        else {
            centipede.moveDown();
        }
    }
    else {
        centipede.move();
    }
}

void Board::spawnCentipede() {
    centipede.createCentipede();
}
