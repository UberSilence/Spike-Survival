#include <vector>

#ifndef MAP_H
#define MAP_H

class Map {
    private:
        int rows;
        int cols;
        std::vector<std::vector<char>> map;
    public:
        Map(int _rows, int _cols);
        void initialize();
        void print();
        void setSize();
        bool isCharacter(int x, int y, char c);
        bool isBorder(int x, int y);
        void setPosition(int x, int y, char c);
};

#endif