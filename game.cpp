#include "game.hpp"

Game::Game() {
    Board board;
    GameScreen screen;

    centipedeMovingStartTime = std::chrono::steady_clock::now();
    bulletMovingStartTime = std::chrono::steady_clock::now();
    shotCooldownStartTime = std::chrono::steady_clock::now();

    cursorY = BOARD_HEIGHT - 2;
    cursorX = BOARD_WIDTH / 2;
}

void Game::start() {
    lifeStatus = true;

    board.spawnCentipede();
    while (lifeStatus) {
        
        inputHandling();
        cooldownManager();       
        
        screen.updateGameWindow(board.getTable());
    }
}

void Game::inputHandling() { 
    int inputKey;
    inputKey = getch();

    switch (inputKey)
    {
    case KEY_LEFT:
    case 'a':  
        if (cursorX > 0) {
           lifeStatus = board.movePlayer(left);
        }
        break;
    case KEY_RIGHT:
    case 'd':
        if (cursorX < BOARD_WIDTH - 1) {
            lifeStatus = board.movePlayer(right);
        }            
        break;
    case KEY_UP:
    case 'w':
        if (cursorY > 0) {
            lifeStatus = board.movePlayer(up);
        }
        break;
    case KEY_DOWN:
    case 's':
        if (cursorY < BOARD_WIDTH - 1) {
            lifeStatus = board.movePlayer(down);
        }
        break;
    case ' ':
            shootManager();
        break;
    case 'q':
    case 'Q':
        lifeStatus = false;
        break;
    }
    
}

void Game::cooldownManager() {
    auto currentTime = std::chrono::steady_clock::now();
    
    if (currentTime - centipedeMovingStartTime >= centipedeMovingTime) {
        board.moveCentipede();
        board.insertCentipedeInTable();
        centipedeMovingStartTime = currentTime;
    }

    if (currentTime - bulletMovingStartTime >= bulletMovingTime) {
        board.moveBulletsUp();        
        bulletMovingStartTime = currentTime;
    }
}

void Game::shootManager() {
    auto currentTime = std::chrono::steady_clock::now();

    if (currentTime - shotCooldownStartTime >= shotCooldownTime) {
        shotCooldownStartTime = currentTime;

        board.shoot();
    }
}