#pragma once
#include "character.hpp"

ECharactersType Character::getType() {
    return characterType;
}

void Character::setType(ECharactersType type) {
    characterType = type;
}

void Character::reduceHealth() {
    /// TODO: Miqo es masy dzi aveli lav gri if-y
    if(health > 0) {
        --health;
    }
    if(health == 0) {
        characterType = blank;
    }
    /*
    health > 0 ? --health : characterType = blank;
    
    if(health = 0) {
        characterType = blank;
    }
    */
}
