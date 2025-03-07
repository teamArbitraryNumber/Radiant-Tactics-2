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
using namespace std;

class Inventory
{       // The class
    public: // Access specifier
        int inventorySize;
        int inventoryCounter;
        vector<Item> weaponList;
        vector<Item> potionList;
        Inventory()
        { // Constructor
            inventorySize = 10;
            inventoryCounter = 0;
        }
        void addWeapon(string);
        void addPotion(string);

        int equipWeapon(int);
        int usePotion();

        bool hasPotion(string);
        bool hasWeapon(string);

        void invFull(string);

        void setInvSize(int);
        void setInvCounter(int);


        //Destructor
        ~Inventory(){}
};

#endif

