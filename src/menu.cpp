#include <iostream>
#include "include/game.h"
#include "include/menu.h"
#include "include/utils.h"

Menu::Menu() = default;

void Menu::start(Map *map) {
    std::cout << "Welcome to ~Spike Survival~!\n\n";
    menu(map);
}

void Menu::menu(Map* map) {
    std::cout << "Select an option to continue.\n";
    std::cout << "1. New Game\n2. Settings\n3. Exit\nChoice: ";
    std::cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3) {
        clearScreen();
        std::cout << "Invalid choice.\nSelect an option to continue: \n\n";
        std::cout << "1. New Game\n2. Settings\n3. Quit\nChoice: ";
        std::cin >> choice;
    }

    Game game;

    switch(choice) {
        case 1:
            clearScreen();
            game.run(map);
            break;
        case 2:
            clearScreen();
            settings(map);
            break;
        case 3:
            exit(0);
            break;
    }
}

void Menu::settings(Map* map) {
    std::cout << "Settings:\n";
    std::cout << "1. Change Map Size\n2. Back\nChoice: ";
    std::cin >> choice;
    while (choice != 1 && choice != 2) {
        clearScreen();
        std::cout << "Invalid choice.\nSelect an option to continue: \n\n";
        std::cout << "1. Change Map Size\n2. Back\nChoice: ";
        std::cin >> choice;
    }
    switch(choice) {
        case 1:
            clearScreen();
            map->setSize();
            menu(map);
            break;
        case 2:
            clearScreen();
            menu(map);
            break;
    }
}