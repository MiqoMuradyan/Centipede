#include "game.hpp"

Game::Game() {
    Board board;
    GameScreen screen;
    ScoreManager scoreManager;

    centipedeMovingStartTime = std::chrono::steady_clock::now();
    bulletMovingStartTime = std::chrono::steady_clock::now();
    shotCooldownStartTime = std::chrono::steady_clock::now();

    cursorY = BOARD_HEIGHT - 2;
    cursorX = BOARD_WIDTH / 2;
}

Game::~Game() {

}

void Game::start() {
    board.spawnCentipede();
    while (!board.getIsLose()) {
        
        inputHandling();
        cooldownManager();       
        
        screen.updateGameWindow(board.getTable());
        screen.updateScoreDisplay(scoreManager.getScore(), scoreManager.getHighScore());
    }
}

void Game::inputHandling() { 
    int inputKey;
    inputKey = getch();

    switch (inputKey)
    {
    case KEY_LEFT:
    case 'a':  //TODO: implement this input with KEY_LEFT, and etc.
        if (cursorX > 0) {
           board.movePlayer(left);
        }
        break;
    case KEY_RIGHT:
    case 'd':
        if (cursorX < BOARD_WIDTH - 1) {
            board.movePlayer(right);
        }            
        break;
    case KEY_UP:
    case 'w':
        if (cursorY > 0) {
            board.movePlayer(up);
        }
        break;
    case KEY_DOWN:
    case 's':
        if (cursorY < BOARD_WIDTH - 1) {
            board.movePlayer(down);
        }
        break;
    case ' ':
            shootManager();
        break;
    case 'q':
    case 'Q':
        //TODO: create logic to end game
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