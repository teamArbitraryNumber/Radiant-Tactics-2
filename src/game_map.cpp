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
    if(mapMatrix[y][x]->getType() == "Skeleton" || mapMatrix[y][x]->getType() == "Goblin" || mapMatrix[y][x]->getType() == "Orc" 
        || mapMatrix[y][x]->getType() == "Slime" || mapMatrix[y][x]->getType() == "Knight"){
        return true;
    }
    return false;
}

vector<vector<shared_ptr<Object> > >& GameMap::getMapMatrix(){
    return mapMatrix;
}

void GameMap::killEnemy(int x, int y) {
    /*for (auto it = enemies.begin(); it != enemies.end(); ++it) {
        if ((*it)->getRowPosition() == x && (*it)->getColPosition() == y) {
            
            // Check if it's a Slime and if it can split
            //Slime* slimePtr = dynamic_cast<Slime*>(it->get());
            //if (slimePtr && slimePtr->specialAbility(*this)) {
                //return;  // Slime duplicated, so do not remove it
            //}

            std::cout << (*it)->getDisplayChar() << " was defeated!" << std::endl;
            enemies.erase(it);
            return;
        }
    }*/
    for (auto it = enemies.begin(); it != enemies.end(); ) {
        if ((*it)->getRowPosition() == x && (*it)->getColPosition() == y) {
            if ((*it)->getType() == "Slime") {
                shared_ptr<Slime> slime = dynamic_pointer_cast<Slime>(*it);
                if (slime && slime->specialAbility(*this)) {
                    return;
                }
            }
            
            std::cout << (*it)->getDisplayChar() << " was defeated!" << std::endl;
            it = enemies.erase(it);
            return;
        } else {
            ++it;
        }
    }
}


// Function to check if a position is empty (No enemies or obstacles)
bool GameMap::isPositionEmpty(int row, int col) {
    return getObjectAt(row, col) == nullptr;
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

int GameMap::getEnemyKilled() const {//this function ain't used
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
    for(auto it = enemies.begin(); it != enemies.end(); ++it){//delete from enemies list
        if((*it)->getRowPosition() == y && (*it)->getColPosition() == x){
            enemies.erase(it);
            break;
        }
    }
}

void GameMap::setPlayer(shared_ptr<Player> p) {
    player = p;
    mapMatrix[p->getRowPosition()][p->getColPosition()] = player;
}

// Get the player
shared_ptr<Player> GameMap::getPlayer() {
    return player;
}

void GameMap::spawnBoss() {
    auto radiantDragon = std::make_shared<RadiantDragon>();
    radiantDragon->setColPosition(5);
    radiantDragon->setRowPosition(5);
    addEnemy(radiantDragon);
    std::cout << "🐉 The Radiant Dragon has appeared!" << std::endl;
}
