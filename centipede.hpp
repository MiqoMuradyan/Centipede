#pragma once

#include <iostream>

#include "enums.hpp"

class Centipede {
public:
    std::pair<int, int> getPosition();
    void setPosition(int x, int y);
    
private:
    EDirections moveDirection;
    // std::pair<int, int> 
    int posX;
    int posY;
};