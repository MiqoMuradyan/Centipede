#pragma once 

#include "enums.hpp"

class Character {
protected:
    char symbol;
    ECharactersType characterType;

public:
    Character();
    // Character(int posX, int posY);
    // Character(int posX, int posY, int health);
    ~Character();
    // int getX();
    // void setX(int x);
    // int getY();
    // void setY(int y);
    ECharactersType getType();
    Blank die();
};

class Blank:Character {
public:
    Blank(int posX, int posY);
};

class Bullet:Character{
public:
    Bullet(int posX, int posY);
};

class Player:Character {
public:
    Player(int posX, int posY, int health);
    ~Player();

    Bullet shoot();
};

class Centipede:Character {
public:
    Centipede(int posX, int posY, int health);
    ~Centipede();    
};

class Mushroom:Character {
public:
    Mushroom(int posX, int posY);
    ~Mushroom();
};