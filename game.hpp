#ifndef GAME_HPP
#define GAME_HPP

#include <chrono>
#include <iostream>

#include "board.hpp"
#include "screen.hpp"
#include "scoreManager.hpp"

using SteadyClock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<SteadyClock>; 

class Game {
public:
    Game();
    ~Game();
    void start();
    void cooldownManager();
    void shootManager();
    void inputHandling();

private:
    Board board;
    GameScreen screen;
    ScoreManager scoreManager;

    const std::chrono::milliseconds centipedeMovingTime{200};
    const std::chrono::milliseconds bulletMovingTime{30};
    const std::chrono::milliseconds shotCooldownTime{200};

    TimePoint centipedeMovingStartTime;
    TimePoint bulletMovingStartTime;
    TimePoint shotCooldownStartTime;

    int cursorX;
    int cursorY;

    int scoreAmount = 100;
    
};

#endif //GAME_HPP