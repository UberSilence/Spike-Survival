#include <iostream>
#include <conio.h>
#include <windows.h>
#include "include/game.h"
#include "include/utils.h"

#define player_character char(2)
#define border_left char(221)
#define border_right char(222)
#define border_top char(223)
#define border_bottom char(220)
#define border_corner char(219)

Game::Game() = default;

void Game::run() {
    char map[20][20];
    int score = 0;
    for (int i = 1; i < 19; i++) {
        map[i][0] = border_left;
        map[i][19] = border_right;
    }

    for (int i = 1; i < 19; i++) {
        map[0][i] = border_top;
        map[19][i] = border_bottom;
    }
    map[0][0] = map[0][19] = map[19][0] = map[19][19] = border_corner;
    
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 19; j++) {
            map[i][j] = ' ';
        }
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }

    int x = 5;
    int y = 5;
    bool gameOver = false;
    while (!gameOver) {
        char input = getch();
        switch (input) {
            case 'a':
                map[x][y] = ' ';
                if (map[x][y - 1] != '#') {
                    y--;
                }
                break;
            case 'd':
                map[x][y] = ' ';
                if (map[x][y + 1] != '#') {
                    y++;
                }
                break;
            case 'w':
                map[x][y] = ' ';
                if (map[x - 1][y] != '#') {
                    x--;
                }
                break;
            case 's':
                map[x][y] = ' ';
                if (map[x + 1][y] != '#') {
                    x++;
                }
                break;
            case 'q':
                gameOver = true;
                break;
            default:
                break;
        }

        if (map[x][y] == char(4)) {
            std::cout << "You lost!\n";
            std::cout << "Your score was: " << score << std::endl;
            getch();
            gameOver = true;
        } else {
            map[x][y] = player_character;
        }
        clearScreen();
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                std::cout << map[i][j];
            }
            std::cout << std::endl;
        }

        int x2 = rand() % 18 + 1;
        int y2 = rand() % 18 + 1;
        while (map[x2][y2] == char(4)) {
            x2 = rand() % 18 + 1;
            y2 = rand() % 18 + 1;
        }
        map[x2][y2] = char(4);
        score++;
        std::cout << "Score: " << score << std::endl;
    }
}