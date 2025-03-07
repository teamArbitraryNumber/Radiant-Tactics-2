#include "../header/game_map.h"
#include "../header/enemy.h"
#include "../header/player.h"
#include "../header/item.h"
#include "../header/inventory.h"
#include <iostream>
using namespace std;

GameMap::GameMap() : height(0), width(0), numEnemies(0), enemiesKilled(0) {
    mapMatrix.resize(0, vector<shared_ptr<Object>>(0));
}

GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h){
    mapMatrix.resize(h, vector<shared_ptr<Object>>(w));
    height = h;
    width = w;
}
/*GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h) : height(h), width(w), numEnemies(0), enemiesKilled(0) {
    mapMatrix.resize(h, vector<shared_ptr<Object>>(w));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch (initMatrix[y][x]) {
            case 1:
                mapMatrix[y][x] = make_shared<Skeleton>("Skeleton", 100, 15, "Sword");
                numEnemies++;
                break;
            case 2:
                mapMatrix[y][x] = make_shared<Skeleton>("Skeleton", 75, 10, "Bow and Arrow");
                numEnemies++;
                break;
            case 3:
                mapMatrix[y][x] = make_shared<Skeleton>("Skeleton", 70, 7, "Magic");
                numEnemies++;
                break;
            case 4:
                mapMatrix[y][x] = make_shared<Skeleton>("Skeleton", 65, 5, "Axe");
                numEnemies++;
                break;
            case 5:
                mapMatrix[y][x] = make_shared<Skeleton>(10, "Basic Sword");
                break;
            case 6:
                mapMatrix[y][x] = make_shared<Sword>(15, "Greater Sword");
                break;
            case 7:
                mapMatrix[y][x] = make_shared<Potion>(5, "Small Potion");
                break;
            case 8:
                mapMatrix[y][x] = make_shared<Potion>(10, "Large Potion");
                break;
            default:
                mapMatrix[y][x] = make_shared<Object>();  // Empty object
                break;
            }
        }
    }
}*/

void GameMap::killEnemy(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }

    shared_ptr<Object>& obj = mapMatrix[y][x];
    if (obj->getType() == "Skeleton") {
        obj = make_shared<Object>();  // Replace with an empty object
        enemiesKilled++;
    } else {
        cerr << "No skeleton at the specified coordinates" << endl;
    }
}

void GameMap::initMap1(){
    for(int y = 0; y < this->height; y++){
        for(int x = 0; x < this->width; x++){
            if(y == this->height - 1 && x == (this->width - 1) / 2){//place player on the bottom middle of the map
                shared_ptr<Inventory> inv = make_shared<Inventory>();
                mapMatrix[y][x] = make_shared<Player>(CharacterType::PLAYER, "Player", 0, 100, 10, y, x, inv, 0);
            }
        }
    }   
}

shared_ptr<Object> GameMap::getObjectAt(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    return mapMatrix[y][x];
}

void GameMap::setObjectAt(int x, int y, const shared_ptr<Object>& obj) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    mapMatrix[y][x] = obj;
}

int GameMap::getNumEnemies() const {
    return numEnemies;
}

int GameMap::getEnemiesKilled() const {
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

void GameMap::printMap(int playerX, int playerY) const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == playerX && y == playerY) {
                cout << ":)";  // Represent the player with 'P'
            } else {
                auto obj = mapMatrix[y][x];
                if (obj->getType() == "Skeleton"||obj->getType() == "Sword"||obj->getType() == "Potion") {
                    cout << "*";
                } else {
                    cout << ". ";  // Represent empty spaces with '.'
                }
            }
            cout << "\t";
        }
        cout << endl;
    }
}

void GameMap::displayMap(){
    for(int y = 0; y < 11; y++){
        for(int x = 0; x < 11; x++){
            if(mapMatrix[y][x]){
                cout << mapMatrix[y][x]->getDisplayChar();
            }
            else{
                cout << "□";
            }
            cout << " ";
        }
        cout << endl << endl;
    }
}

void GameMap::removeObjectAt(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    mapMatrix[y][x] = make_shared<Object>();  // Replace with an empty object
}
