#include "include/utils.h"

void clearScreen() {
    #include <stdlib.h>
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}