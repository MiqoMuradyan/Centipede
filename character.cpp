#pragma once
#include "character.hpp"

Character::Character() {

}

ECharactersType Character::getType() {
    return characterType;
}

void Character::setType(ECharactersType type) {
    characterType = type;
}

void Character::reduceHealth() {
    health > 0 ? --health : characterType = blank;  
}
