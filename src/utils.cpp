#include "include/utils.h"
#include <cstdlib>
#include <bits/stdc++.h>

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int random_number(int low, int high) {
    std::random_device random_device; 
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<> dist(low,high);
    return dist(engine);
}