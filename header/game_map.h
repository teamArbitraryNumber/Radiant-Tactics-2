#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <vector>
#include <memory> // For smart pointers
#include "character.h"
#include "object.h"
#include "enemy.h"

class Player; // Forward declaration
using namespace std;

class GameMap {
private:
    int height;//{};
    int width;//{};
    int numEnemy;//{};
    int enemyKilled;//{};
    vector<vector<shared_ptr<Object> > > mapMatrix;  // Use smart pointers to handle objects
    vector<shared_ptr<Enemy>> enemies; // Store enemy objects
    shared_ptr<Player> player; // Store the player

public:
    GameMap();
    GameMap(const vector<vector<int> >& initMatrix, int w, int h);
    ~GameMap() {
        for (auto& row : mapMatrix) {
            for (auto& obj : row) {
                obj.reset(); // Reset each shared_ptr to release memory
            }
            row.clear(); // Clear each row vector
        }
        mapMatrix.clear();
    };

    vector<vector<shared_ptr<Object> > >& getMapMatrix();
    void killEnemy(int x, int y);
    shared_ptr<Object> getObjectAt(int x, int y);
    void setObjectAt(int x, int y, const shared_ptr<Object>& obj);
    void removeObjectAt(int x, int y);

    bool isTerrain(int x, int y) const;
    bool isEnemy(int x, int y) const;
    bool isPositionEmpty(int row, int col);

    int getNumEnemy() const;
    void setNumEnemy(int num);
    int getEnemyKilled() const;
    void setPlayer(shared_ptr<Player> p);
    shared_ptr<Player> getPlayer();
    void addEnemy(shared_ptr<Enemy> enemy);
    vector<shared_ptr<Enemy>>& getEnemies();
    int getWidth() const;
    int getHeight() const;
    void printMap() const;
};

#endif