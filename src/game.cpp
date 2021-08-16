#include <iostream>
#include <conio.h>
#include <windows.h>
#include "include/game.h"
#include "include/utils.h"

#define player_character char(2)
#define spike char(4)
#define border_left char(221)
#define border_right char(222)
#define border_top char(223)
#define border_bottom char(220)
#define border_corner char(219)

Game::Game() = default;

void Game::run(Map *map) {
    score = 0;

    map->initialize();

    int x = 10;
    int y = 10;

    map->setPosition(x, y, player_character);
    map->print();

    bool gameOver = false;
    while (!gameOver) {
        char input = getch();
        switch (input) {
            case 'a':
                map->setPosition(x, y, ' ');
                if (!(map->isBorder(x, y - 1))) {
                    y--;
                }
                break;
            case 'd':
                map->setPosition(x, y, ' ');
                if (!(map->isBorder(x, y + 1))) {
                    y++;
                }
                break;
            case 'w':
                map->setPosition(x, y, ' ');
                if (!map->isBorder(x - 1, y)) {
                    x--;
                }
                break;
            case 's':
                map->setPosition(x, y, ' ');
                if (!map->isBorder(x + 1, y)) {
                    x++;
                }
                break;
            case 'q':
                gameOver = true;
                break;
            default:
                break;
        }

        if (map->isCharacter(x, y, spike)) {
            std::cout << "You lost!\n";
            std::cout << "Your score was: " << score << std::endl;
            getch();
            gameOver = true;
        } else {
            map->setPosition(x, y, player_character);
        }
        clearScreen();
        map->print();

        int x2 = rand() % 18 + 1;
        int y2 = rand() % 18 + 1;
        while (map->isCharacter(x2, y2, spike)) {
            x2 = rand() % 18 + 1;
            y2 = rand() % 18 + 1;
        }
        map->setPosition(x2, y2, spike);
        score++;
        std::cout << "Score: " << score << std::endl;
    }
}