#include <iostream>
#include "include/map.h"

#define border_left char(221)
#define border_right char(222)
#define border_top char(223)
#define border_bottom char(220)
#define border_corner char(219)


Map::Map(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->map = std::vector<std::vector<char>>(rows, std::vector<char>(cols, ' '));
}

void Map::setSize() {
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    this->map = std::vector<std::vector<char>>(rows, std::vector<char>(cols, ' '));
    std::cout << "New map size set successfully!\n";
}

void Map::initialize() {
    for (int i = 1; i < rows-1; i++) {
        map[i][0] = border_left;
        map[i][cols-1] = border_right;
    }

    for (int i = 1; i < cols-1; i++) {
        map[0][i] = border_top;
        map[rows-1][i] = border_bottom;
    }

    map[0][0] = map[0][cols-1] = map[rows-1][0] = map[rows-1][cols-1] = border_corner;
    
    for (int i = 1; i < rows-1; i++) {
        for (int j = 1; j < cols-1; j++) {
            map[i][j] = ' ';
        }
    }
}

void Map::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}

bool Map::isCharacter(int x, int y, char c) {
    if (map[x][y] != c)
        return false;
    else
        return true;
}

void Map::setPosition(int x, int y, char c) {
    map[x][y] = c;
}