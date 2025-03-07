#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "game_map.h"
#include "player.h"
// #include "enemy.h"
// #include "inventory.h"
// #include "item.h"

using namespace std;
class Game_Manager{
    private:
        GameMap gameMap;
        
        bool end;//{};
        Player player;
        // shared_ptr<Inventory> inventory;
        int enemyGoal;//{}; //amount of enemies needed to kill to get next level
        bool isPlayerTurn;
    public:
        bool *isOver;
        Game_Manager(GameMap map, Player p, bool* over)
        : gameMap(map), player(p), isOver(over), end(false), enemyGoal(0), isPlayerTurn(true) {}

        ~Game_Manager(){};
        void start();
        void takeAction();
        GameMap getGameMap()const {
            return gameMap;
        };
        // void movePlayer(char input, int new_x, int new_y);
        // void managePlayerInventory(shared_ptr<Inventory> inv);
        void moveEnemies();
};

#endif