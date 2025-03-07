#include "../header/game_manager.h"
#include <iostream>

using namespace std;

int main() {
    // Initialize the game map with a simple layout
    vector<vector<int>> mapLayout = {
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}
    };

    int mapWidth = 4;
    int mapHeight = 4;

    // Create the game map
    GameMap gameMap(mapLayout, mapWidth, mapHeight);

    // Initialize the player
    Player player(CharacterType::PLAYER, "Player", 0, 100, 10, 0, 0, 50);

    // Initialize the game manager
    bool isOver = false;
    Game_Manager gameManager(gameMap, player, &isOver);

    // Start the game
    gameManager.start();

    return 0;
}