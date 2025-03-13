#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "game_map.h"
#include "player.h"
#include "enemy.h"
#include <iostream>
#include "animation.h"
// #include "inventory.h"
// #include "item.h"

using namespace std;
class Game_Manager{
    private:
        GameMap& gameMap;
        
        
        /*Player*/shared_ptr<Player> player;
        // shared_ptr<Inventory> inventory;
        
        bool isPlayerTurn;
    public:
        bool *isOver;
        bool end;//{};
        int enemyGoal;//{}; //amount of enemies needed to kill to get next level
        Game_Manager(GameMap& map, shared_ptr<Player> p, bool* over)
        : gameMap(map), player(p), isOver(over), end(false), enemyGoal(0), isPlayerTurn(true) {}

        ~Game_Manager(){};
        void start();
        int takeAction();
        GameMap& getGameMap() {
            return gameMap;
        };
        // void movePlayer(char input, int new_x, int new_y);
        // void managePlayerInventory(shared_ptr<Inventory> inv);
        bool isPlayerNextToEnemy();
        shared_ptr<Enemy> getAdjacentEnemy();
        void playerTurn();
        bool isEnemyDefeated();
        void enemyTurn();
        void startCombat(shared_ptr<Enemy>& enemy);
        void moveEnemies();
            void displayCommands() ;

};

#endif