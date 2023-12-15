#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "enums.hpp"

class Character {
public:
    ECharactersType getType();
    void setType(ECharactersType type);
    void reduceHealth();
    int getHealth();

private:
    char symbol;
    ECharactersType characterType;
    int health = 4;
};

#endif //CHARACTER_HPP