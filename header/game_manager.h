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
        bool *isOver;
        bool end{};
        Player player;
        Inventory inventory;
        int enemyGoal{};
        bool isPlayerTurn;
    public:
        void initMap1();
        void startLevel();
        ~Game_Manager(){};
        void start();
        void takeAction();
        GameMap getGameMap()const {
            return gameMap;
        };
        void movePlayer(char input, int new_x, int new_y);
        void managePlayerInventory(Inventory& inv);
        void moveEnemies();
};

#endif