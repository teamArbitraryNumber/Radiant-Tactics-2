// main.cpp
#include "game_map.h"
#include <iostream>

int main() {
    std::vector<std::vector<int>> mapData = {
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 2},
        {0, 1, 0, 0}
    };

    GameMap gameMap(mapData, 4, 4);
    gameMap.printMap(1, 1);  // Player at (1, 1)

    // Check if a specific tile is a barrier
    auto obj = gameMap.getObjectAt(2, 0);
    if (obj->isBarrier()) {
        std::cout << "Tile (2, 0) is a barrier!" << std::endl;
    }

    return 0;
}