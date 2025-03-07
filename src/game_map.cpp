#include "../header/game_map.h"
#include <iostream>
using namespace std;

GameMap::GameMap() : height(0), width(0), numEnemy(0), enemyKilled(0) {
    mapMatrix.resize(0, vector<shared_ptr<Object>>(0));
}

// GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h){
//     mapMatrix.resize(h, vector<shared_ptr<Object>>(w));
//     height = h;
//     width = w;
// }
GameMap::GameMap(const vector<vector<int>>& initMatrix, int w, int h) : height(h), width(w), numEnemy(0), enemyKilled(0) {
    mapMatrix.resize(h, vector<shared_ptr<Object>>(w));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch (initMatrix[y][x]) {
            case 1:
                mapMatrix[y][x] = make_shared<Object>("Barrier", 100, true);  // Barrier object
                break;
            // case 2:
            //     mapMatrix[y][x] = make_shared<Skeleton>("Skeleton", 75, 10, "Bow and Arrow");
            //     numEnemy++;
            //     break;
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

// void GameMap::initMap1(){
//     for(int y = 1; y <= this->height; y++){
//         for(int x = 1; x <= this->width; x++){
//             if(y == this->height && x == this->width / 2){//place player on the bottom middle of the map
//                 shared_ptr<Inventory> inv = make_shared<Inventory>();
//                 mapMatrix[y][x] = make_shared<Player>(CharacterType::PLAYER, "Player", 0, 100, 10, y, x, inv, 0);
//             }
//         }
//     }   
// }

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

int GameMap::getNumEnemy() const {
    return numEnemy;
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

void GameMap::removeObjectAt(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw out_of_range("Invalid map coordinates");
    }
    mapMatrix[y][x] = make_shared<Object>();  // Replace with an empty object
}
