#include "../header/game_map.h"
#include "../header/player.h"
#include <iostream>
using namespace std;

GameMap::GameMap() : height(0), width(0), numEnemy(0), enemyKilled(0) {
    mapMatrix.resize(0, vector<shared_ptr<Object>>(0));
}

GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h) : height(h), width(w), numEnemy(0), enemyKilled(0) {
    mapMatrix.resize(h, vector<shared_ptr<Object>>(w));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch (initMatrix[y][x]) {
            case 1:
                mapMatrix[y][x] = make_shared<Object>("Barrier", 100, true);  // Barrier object
                break;
            case 2:
                mapMatrix[y][x] = make_shared<Object>(true, "Door", 100);     // Door object
                break;
            default:
                mapMatrix[y][x] = make_shared<Object>();  // Empty object
                break;
            }
        }
    }
}

bool GameMap::isTerrain(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    return mapMatrix[y][x]->isBarrier();
}

bool GameMap::isEnemy(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    if(mapMatrix[y][x]->getType() == "Skeleton" || mapMatrix[y][x]->getType() == "Goblin"){
        return true;
    }
    return false;
}

vector<vector<shared_ptr<Object> > >& GameMap::getMapMatrix(){
    return mapMatrix;
}

void GameMap::killEnemy(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }

    shared_ptr<Object>& obj = mapMatrix[y][x];
    if (obj->getType() == "Skeleton") {
        obj = make_shared<Object>();  // Replace with an empty object
        enemyKilled++;
    } else {
        cerr << "No skeleton at the specified coordinates" << endl;
    }
}


shared_ptr<Object> GameMap::getObjectAt(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    return mapMatrix[y][x];
}

void GameMap::addEnemy(shared_ptr<Enemy> enemy) {
    enemies.push_back(enemy);
    numEnemy++;
    mapMatrix[enemy->getRowPosition()][enemy->getColPosition()] = enemy;
}

// Get all enemies
vector<shared_ptr<Enemy>>& GameMap::getEnemies() {
    return enemies;
}

void GameMap::setObjectAt(int x, int y, const shared_ptr<Object>& obj) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    mapMatrix[y][x] = obj;
}

int GameMap::getNumEnemy() const {
    return numEnemy;
}
void GameMap::setNumEnemy(int num){
    numEnemy = num;
}

int GameMap::getEnemyKilled() const {
    int count = 0;
    for (const auto& row : mapMatrix) {
        for (const auto& obj : row) {
            if (obj->getType() == "Skeleton") {
                count++;
            }
        }
    }
    return count;
}

int GameMap::getWidth() const {
    return width;
}

int GameMap::getHeight() const {
    return height;
}

void GameMap::printMap() const {
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << mapMatrix[i][j]->getDisplayChar() << "\t";
            //cout << mapMatrix[i][j]->getType() << "\t";
        }
        cout << endl << endl;
    }
    cout << endl;
}

void GameMap::removeObjectAt(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    mapMatrix[y][x] = make_shared<Object>();  // Replace with an empty object
}

void GameMap::setPlayer(shared_ptr<Player> p) {
    player = p;
    mapMatrix[p->getRowPosition()][p->getColPosition()] = player;
}

// Get the player
shared_ptr<Player> GameMap::getPlayer() {
    return player;
}
