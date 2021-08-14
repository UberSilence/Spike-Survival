#include <iostream>
#include "include/utils.h"
#include "include/game.h"
#include "include/menu.h"

Menu::Menu() = default;

void Menu::start() {
    std::cout << "Welcome to ~Spike Survival~!\nSelect an option to continue: \n\n";
    std::cout << "1. New Game\n2. Quit\nChoice: ";
    std::cin >> choice;
    while (choice != 1 && choice != 2) {
        clearScreen();
        std::cout << "Invalid choice.\nSelect an option to continue: \n\n";
        std::cout << "1. New Game\n2. Quit\nChoice: ";
        std::cin >> choice;
    }
    if (choice == 1) {
        clearScreen();
        Game game;
        game.run();
    } else if (choice == 2) {
        exit(0);
    }
}