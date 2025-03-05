#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream> 
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>

class Inventory{
    vector<Item> weaponList;
    vector<Item> potionList;
    int inventorySize = 10;
    int inventoryCounter = 0;
    string currWeapon = "";


    void addWeapon(string);
    void addPotion(string);

    int equipWeapon(int);
    int usePotion(int);

    bool hasPotion(string);
    bool hasWeapon(string);

    void invFull(string);

    void setInvSize(int);
};
#endif