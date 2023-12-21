#include "menu.hpp"

Menu::Menu() {

    while (true)
    {
        handleChoice(menuButtons());
    }
}

int Menu::menuButtons() {
    int choice;
    int highlight = 0;

    while (true) {
        menuScreen.updateMenuWindow(highlight);
        choice = getch();
        
        switch (choice) 
        {
        case 'w':
            if (highlight > 0) {
                --highlight;
            }
            break;

        case 's':            
            if (highlight < 3) {
                ++highlight;
            }
            break;

        case 10:
            return highlight;
        }
    }
} 

void Menu::handleChoice(int choice) {
    Game game;
    switch (choice) 
    {
    case 0:
        game.start();
        erase();
        break;


    case 3:
    std::exit(0);
        break;

    default:
        break;
    }

}