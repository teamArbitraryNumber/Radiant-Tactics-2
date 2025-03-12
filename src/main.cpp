#include "../header/game_manager.h"
#include "../header/enemy.h"
#include <iostream>

using namespace std;

GameMap initMap1();
GameMap initMap2(shared_ptr<Player> p);

int main() {
    // Initialize the game map with a simple layout
    //                                            All maps will be 11 x 11

    GameMap gameMap1 = initMap1();//initialize gameMap1
    
    // Initialize the game manager
    bool isOver = false;
    Game_Manager gameManager(gameMap1, gameMap1.getPlayer(), &isOver);

    // Start the game

    gameManager.start();//begin map 1
    
    gameMap1 = initMap2(gameMap1.getPlayer());//update game map
    gameManager.end = false;
    gameManager.enemyGoal = 3;//update game manager
    gameManager.start();//begin map 2
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
    skeleton->setType("Skeleton");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap1.addEnemy(skeleton);

    auto goblin = make_shared<Goblin>(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   1   ,   4);
    goblin->setType("Goblin");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap1.addEnemy(goblin);
    return gameMap1;
};

GameMap initMap2(shared_ptr<Player> p){
    vector<vector<int>> mapLayout2 = {//0 = empty, 1 = barrier, 2 = door
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 1, 0, 0, 0, 1, 2, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }; 
    GameMap gameMap2(mapLayout2, 11, 11);
    p->setPosition(2, 2);
    gameMap2.setPlayer(p);
    


    auto skeleton = make_shared<Skeleton>(CharacterType::SKELETON, "Skeleton",  5    ,  70,   10  ,  9   ,  9  );
    skeleton->setType("Skeleton");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap2.addEnemy(skeleton);

    auto goblin1 = make_shared<Goblin>(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   9   ,   7);
    goblin1->setType("Goblin");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap2.addEnemy(goblin1);

    auto goblin2 = make_shared<Goblin>(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   2   ,   7);
    goblin2->setType("Goblin");//must initialize type, there is a bug in constructor ( type always gets initialized to null)
    gameMap2.addEnemy(goblin2);
    
    return gameMap2;
}