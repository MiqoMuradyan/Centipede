#pragma once
#include "character.hpp"

Character::Character(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
}

Character::Character(int posX, int posY, int health) {
    this->posX = posX;
    this->posY = posY;
    this->health = health;
}

int Character::getX() {
    return posX;
}

void Character::setX(int x) {
    posX = x;
}

int Character::getY() {
    return posY;
}

void Character::setY(int y) {
    posY = y;
}

ECharactersType Character::getType() {
    return characterType;
}

Blank Character::die() {
    Blank blank(posX, posY);
    return blank;
}

Blank::Blank(int posX, int posY):Character(posX, posY){
    symbol = ' ';
    characterType = blank;
}

Bullet::Bullet(int posX, int posY):Character(posX, posY){
    symbol = '|';
    characterType = bullet;
}

Player::Player(int posX, int posY, int health):Character(posX, posY, health){
    symbol = '^';
    characterType = player;
}

Player::~Player() {

}

Bullet Player::shoot() {
    Bullet bullet(posX, posY);
    return bullet;
}


Centipede::Centipede(int posX, int posY, int health):Character(posX, posY, health){
    symbol = 'o';
    characterType = centipede;
}

Centipede::~Centipede() {

}

Mushroom::Mushroom(int posX, int posY):Character(posX, posY) {
    symbol = '#';
    characterType = mushroom;
    health = 4;
}