#ifndef CENTIPEDE_HPP
#define CENTIPEDE_HPP

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
    EDirections moveDirection = right;
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
    std::vector<EDirections> moveHistory;
};

#endif //CENTIPEDE_HPP