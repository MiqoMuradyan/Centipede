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

Centipede::Centipede() : centipedeBody(segmentsCount), moveHistory(segmentsCount) {
}

std::vector<CentipedeSegment> Centipede::getCentipede() {
    return centipedeBody;
}

void Centipede::move() {
    moveHistory.insert(moveHistory.begin(), centipedeBody[0].getDirection());
    moveHistory.pop_back();

    for(int i = 0; i < centipedeBody.size(); ++i){
        centipedeBody[i].setDirection(moveHistory[i]);
        centipedeBody[i].moveSegment();
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
    if(centipedeBody.size() == 1){
        std::vector<CentipedeSegment>(segmentsCount).swap(centipedeBody);
        std::vector<EDirections>(segmentsCount).swap(moveHistory);
        createCentipede();
    }
    else{
        centipedeBody.pop_back();
        moveHistory.pop_back();
    }
}

void Centipede::createCentipede() {
    for(int i = 0; i < segmentsCount; ++i) {
        centipedeBody[i].setPosition(-i, 0);
        moveHistory[i] = EDirections::right;
    }
}
