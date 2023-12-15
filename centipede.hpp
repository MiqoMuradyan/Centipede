#pragma once

#include <iostream>
#include <vector>

#include "enums.hpp"

using coordinates = std::pair<int, int>;

class CentipedeSegment {
public:
    coordinates getPosition();
    void setPosition(int x, int y);
    EDirections getDirection();
    void setDirection(EDirections direction);
    coordinates computeNextPosition();
    void moveSegment();
    
    
private:
    EDirections moveDirection;
    int posX;
    int posY;
};

class Centipede {
public:
    Centipede();
    void move();
    void moveDown();
    std::vector<CentipedeSegment> getCentipede();
    void deleteLastSegment();
    void createCentipede();

private:
    const int segmentsCount = 12;
    std::vector<CentipedeSegment> centipedeBody;
};