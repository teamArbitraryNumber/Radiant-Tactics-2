#ifndef INVENTORY_H
#define INVENTORY_H

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
#include "item.h"

class Inventory
{       // The class
public: // Access specifier
    int inventorySize;
    int inventoryCounter;
    vector<DamageItem> weaponList;
    vector<HealingItem> potionList;
    Inventory()
    { // Constructor
        inventorySize = 15;
        inventoryCounter = 0;
    }
    void addWeapon(DamageItem);
    void addPotion(HealingItem);

    int equipWeapon(int);
    int usePotion();

    bool hasPotion(string);
    bool hasWeapon(string);

    void invFullHealing(HealingItem);
    void invFullWeapon(DamageItem);

    void setInvSize(int);
    void setInvCounter(int);

    int market(int);

    //Print Inventory
    void printInv();

    //Destructor
    ~Inventory(){}
};

#endif

