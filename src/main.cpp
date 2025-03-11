#include "../header/game_manager.h"
#include "../header/enemy.h"
#include <iostream>

using namespace std;

int main() {
    // Initialize the game map with a simple layout
    vector<vector<int>> mapLayout = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}
    };

    int mapWidth = 4;
    int mapHeight = 4;

    // Create the game map
    GameMap gameMap(mapLayout, mapWidth, mapHeight);

    // Initialize the player
    auto player = make_shared<Player>(CharacterType::PLAYER, "Player", 0, 100, 10, 0, 0, 50);
    gameMap.setPlayer(player); // Set the player in the map
    player->setType("Player");
    // Add enemies to the map
    auto skeleton = make_shared<Skeleton>();
    skeleton->setColPosition(2); // Set initial position
    skeleton->setRowPosition(2);
    skeleton->setType("Skeleton");
    gameMap.addEnemy(skeleton);

    auto goblin = make_shared<Goblin>();
    goblin->setColPosition(3); // Set initial position
    goblin->setRowPosition(3);
    goblin->setType("Goblin");
    gameMap.addEnemy(goblin);

    // Initialize the game manager
    bool isOver = false;
    Game_Manager gameManager(gameMap, player, &isOver);

    // Start the game
    gameManager.start();

    return 0;
}