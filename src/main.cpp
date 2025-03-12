#include "../header/game_manager.h"
#include "../header/enemy.h"
#include <iostream>

using namespace std;

GameMap initMap1();

int main() {
    // Initialize the game map with a simple layout
    //                                            All maps will be 11 x 11

    GameMap gameMap1 = initMap1();//initialize gameMap1
    
    // Initialize the game manager
    bool isOver = false;
    Game_Manager gameManager(gameMap1, gameMap1.getPlayer(), &isOver);

    // Start the game
    gameManager.start();

    return 0;
}






GameMap initMap1(){
    vector<vector<int>> mapLayout1 = {//0 = empty, 1 = barrier, 2 = door
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1}
}; 
    GameMap gameMap1(mapLayout1, 11, 11);
    // Initialize the player
    
    auto player = make_shared<Player>(CharacterType::PLAYER, "Player", 0, 100, 10, 1, 0, 50);
    gameMap1.setPlayer(player); // Set the player in the map
    player->setType("Player");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    // Add enemies to the map
    auto skeleton = make_shared<Skeleton>(CharacterType::SKELETON, "Skeleton",  5    ,  70,   10  ,  6   ,  4  );
    //skeleton->setColPosition(2); // Set initial position
    //skeleton->setRowPosition(2);
    skeleton->setType("Skeleton");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap1.addEnemy(skeleton);

    auto goblin = make_shared<Goblin>(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   1   ,   4);
    //goblin->setColPosition(3); // Set initial position
    //goblin->setRowPosition(5);
    goblin->setType("Goblin");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap1.addEnemy(goblin);
    return gameMap1;
};