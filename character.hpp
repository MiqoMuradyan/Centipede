#pragma once 

#include "enums.hpp"

class Character {
public:
    Character();

    ECharactersType getType();
    void setType(ECharactersType type);

private:
    char symbol;
    ECharactersType characterType;
};

