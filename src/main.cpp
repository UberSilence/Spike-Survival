#include <iostream>
#include <conio.h>

void clearscreen() {
    system("cls");
}

int main() {
    char map[20][20];
    int score = 0;
    for (int i = 0; i < 20; i++) {
        map[i][0] = map[i][19] = '#';
        map[0][i] = map[19][i] = '#';
    }
    
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

        if (map[x][y] == '*') {
            std::cout << "You lost!\n";
            std::cout << "Your score was: " << score << std::endl;
            getch();
            gameOver = true;
        } else {
            map[x][y] = '@';
        }
        clearscreen();
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                std::cout << map[i][j];
            }
            std::cout << std::endl;
        }

        int x2 = rand() % 20;
        int y2 = rand() % 20;
        while (x2 == 0 || x2 == 19 || y2 == 0 || y2 == 19 || map[x2][y2] == '#' || map[x2][y2] == '*') {
            x2 = rand() % 20;
            y2 = rand() % 20;
        }
        map[x2][y2] = '*';
        score++;
        std::cout << "Score: " << score << std::endl;
    }
    return 0;
}