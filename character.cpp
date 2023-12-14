#pragma once
#include "character.hpp"

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
    /*
    health > 0 ? --health : characterType = blank;
    
    if(health = 0) {
        characterType = blank;
    }
    */
}
