#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "game_map.h"
#include "player.h"
#include "enemy.h"
#include "inventory.h"
#include "item.h"

using namespace std;
class Game_Manager{
    private:
        GameMap gameMap;
        bool isPlayerTurn;
    public:
        void startLevel();
        void start();
        void takeAction();
        GameMap& getGameMap();
        void movePlayer(char whatIsThis, int new_x, int new_y);
        void managePlayerInventory(Inventory& inv);
        void moveEnemies();
};

#endif