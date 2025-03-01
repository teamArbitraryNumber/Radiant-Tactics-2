#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <vector>
#include <memory> // For smart pointers
#include "item.h"
#include "character.h"
#include "object.h"
using namespace std;

class GameMap {
private:
    int height{};
    int width{};
    int numSkeleton{};
    int skeletonKilled{};
    vector<vector<shared_ptr<Object>>> mapMatrix;  // Use smart pointers to handle objects

public:
    GameMap();
    GameMap(const vector<vector<int>>& initMatrix, int w, int h);
    ~GameMap() 
    {
        for (auto& row : mapMatrix) {
        for (auto& obj : row) {
            obj.reset(); // Reset each shared_ptr to release memory
        }
        row.clear(); // Clear each row vector
    }
    mapMatrix.clear();
    };

    void killSkeleton(int x, int y);
    shared_ptr<Object> getObjectAt(int x, int y);
    void setObjectAt(int x, int y, const shared_ptr<Object>& obj);

    int getNumSkeleton() const;
    int getSkeletonsKilled() const;
    int getWidth() const;
    int getHeight() const;
    void printMap(int playerX, int playerY) const;
};

#endif