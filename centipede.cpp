#include "centipede.hpp"

coordinates CentipedeSegment::getPosition() {
    return {posX, posY};
}

void CentipedeSegment::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

EDirections CentipedeSegment::getDirection() {
    return moveDirection;
}

void CentipedeSegment::setDirection(EDirections direction) {
    moveDirection = direction;
}

coordinates CentipedeSegment::computeNextPosition() {
    int nextX = posX;
    int nextY = posY;

    switch (moveDirection) {
    case up:
            --nextY;
        break;
    case down:
            ++nextY;
        break;
    case right:
            ++nextX;
        break;
    case left:
            --nextX;
        break;
    }

    return {nextX, nextY};
}

void CentipedeSegment::moveSegment() {

    const auto [newPosX, newPosY] = computeNextPosition();
    posX = newPosX;
    posY = newPosY;
}

Centipede::Centipede() : centipedeBody(segmentsCount) {}

std::vector<CentipedeSegment> Centipede::getCentipede() {
    return centipedeBody;
}

void Centipede::move() {    
    centipedeBody[0].moveSegment();    
    for(int i = 1; i < centipedeBody.size(); ++i)
    {
        centipedeBody[i].moveSegment();
        centipedeBody[i].setDirection(centipedeBody[i - 1].getDirection());
    }
}

void Centipede::moveDown() {
    auto previousDirection = centipedeBody[0].getDirection();

    centipedeBody[0].setDirection(down);
    move();

    if(previousDirection == right) {
        centipedeBody[0].setDirection(left);
    }
    else {
        centipedeBody[0].setDirection(right);
    }
}

void Centipede::deleteLastSegment() {
    centipedeBody.pop_back();

    /// TODO: if vector is empty call centipedeCreate function (write function :))
}

void Centipede::createCentipede() {
    // stex dnum em -i vor skzbic chereva pochi masy heto gnalov haytnvi
    for(int i = 0; i < segmentsCount; ++i) {
        centipedeBody[i].setPosition(-i, 0);
    }
}