#ifndef MENU_HPP
#define MENU_HPP

#include "game.hpp"
#include "screen.hpp"

class Menu {
private:
    MenuScreen menuScreen;

public:
    Menu();
    int menuButtons();
    void handleChoice(int choice);

};

#endif //MENU_HPP