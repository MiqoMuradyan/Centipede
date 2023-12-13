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
