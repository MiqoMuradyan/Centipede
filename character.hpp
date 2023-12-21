#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "enums.hpp"

class Character {
public:
    Character();
    ECharactersType getType();
    void setType(ECharactersType type);
    void reduceHealth();
    int getHealth();

private:
    ECharactersType characterType;
    int health = 4;
};

#endif //CHARACTER_HPP