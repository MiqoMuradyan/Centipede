#pragma once 

#include "enums.hpp"

class Character {
public:
    ECharactersType getType();
    void setType(ECharactersType type);
    void reduceHealth();

private:
    char symbol;
    ECharactersType characterType;
    int health = 4;
};

