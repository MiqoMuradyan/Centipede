#include "centipede.hpp"

std::pair<int, int> Centipede::getPosition() {
    return {posX, posY};
}

void Centipede::setPosition(int x, int y) {
    posX = x;
    posY = y;
}