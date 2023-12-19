#ifndef MENU_HPP
#define MENU_HPP

#include "game.hpp"
#include "screen.hpp"

class Menu {
public:
    Menu();
    int menuButtons();
    void handleChoice(int choice);

private:
    MenuScreen menuScreen;
};

#endif //MENU_HPP