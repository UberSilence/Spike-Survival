#include "include/menu.h"
#include "include/map.h"

int main() {
    Map map(20,20);
    Menu menu;
    menu.start(&map);
    return 0;
}