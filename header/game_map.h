#ifndef GAME_MAP_H
#define GAME_MAP_H
#include <vector>
#include <string>
#include <iostream>
#include "object.h"
using namespace std;

class GameMap {
    private:
        vector<vector<Object>> map;
        int rows;
        int cols;
    public:
        GameMap();
        GameMap(int rows, int cols);
        void printMap() const;
        void setMap(int rows, int cols);
        void setMap(vector<vector<Object>> newMap);
        vector<vector<Object>> getMap() const;
        int getRows() const;
        int getCols() const;
        void setRows(int newRows);
        void setCols(int newCols);
};

#endif