#include "map.h"

#ifndef MENU_H
#define MENU_H

class Menu {
    private:
        int choice;
    public:
        Menu();
        void menu(Map *map);
        void start(Map *map);
        void settings(Map *map);
};

#endif