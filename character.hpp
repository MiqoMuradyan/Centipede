#pragma once 

#include "enums.hpp"

class Character {
public:
    Character();

    ECharactersType getType();
    void setType(ECharactersType type);
    void reduceHealth();

private:
    char symbol;
    ECharactersType characterType;
    int health = 4;
};

