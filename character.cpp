#pragma once
#include "character.hpp"

Character::Character() {
    characterType = blank;
}

ECharactersType Character::getType() {
    return characterType;
}

void Character::setType(ECharactersType type) {
    characterType = type;
}

void Character::reduceHealth() {
    if(health > 1) {
        --health;
    }
    else {
        characterType = blank;
    }
}

int Character::getHealth() {
    return health;
}
