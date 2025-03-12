#include "inventory.h"

using namespace std;

void Inventory::printInv()
{
    int i, j;
    cout << "Inventory: " << endl;
    cout << endl;
    cout << "Potion Item List:" << endl;
    for (i = 0; i < potionList.size(); i++)
    {
        cout << "   " << i+1 << ". " << potionList[i].getName() << endl;
    }
    for (i = 0; i < weaponList.size(); i++)
    {
        cout << "   " << i+1 << ". " << weaponList[i].getName() << endl;
    }
}

// Add Weapon to inventory
void Inventory::addWeapon(DamageItem weaponToAdd)
{
    if (inventoryCounter < inventorySize)
    {
        weaponList.push_back(weaponToAdd);
        inventoryCounter++;
    }
    else
    {
        invFullWeapon(weaponToAdd);
    }
}

// Add Potion to inventory
void Inventory::addPotion(HealingItem potionToAdd)
{
    if (inventoryCounter < inventorySize)
    {
        potionList.push_back(potionToAdd);
        inventoryCounter++;
    }
    else
    {
        invFullHealing(potionToAdd);
    }
}

// Checks if item is in inventory
bool Inventory::hasPotion(string itemToCompare)
{
    for (int i = 0; i < potionList.size(); i++)
    {
        if (potionList[i].getName() == itemToCompare)
        {
            return true;
        }
    }
}
bool Inventory::hasWeapon(string itemToCompare)
{
    for (int i = 0; i < weaponList.size(); i++)
    {
        if (weaponList[i].getName() == itemToCompare)
        {
            return true;
        }
    }
}

// If Inventory Full
void Inventory::invFullHealing(HealingItem itemToAdd)
{
    int input = -1;
    int i;
    int j;
    cout << "Current inventory is full, pick an option: " << endl;
    cout << "1. Delete potion item from inventory and replace it with new item." << endl;
    cout << "1. Delete damage item from inventory and replace it with new item." << endl;
    cout << "3. Discard new item." << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "Select An Item to replace." << endl;
        cout << "Potion Item List:" << endl;
        for (i = 0; i < potionList.size(); i++)
        {
            cout << "   " << i << ". " << potionList[i].getName() << endl;
        }
        cin >> input;
        cout << potionList[input].getName() << " will get replaced by " << itemToAdd.getName() << endl;
        potionList[input] = itemToAdd;
    }
    else if (input == 2)
    {
        cout << "Select An Item to replace." << endl;
        cout << "Damage Item List:" << endl;
        for (i = 0; i < weaponList.size(); i++)
        {
            cout << "   " << i << ". " << weaponList[i].getName() << endl;
        }
        cin >> input;
        cout << weaponList[input].getName() << " will get replaced by " << itemToAdd.getName() << endl;
        weaponList.erase(weaponList.begin() + input);
        potionList.push_back(itemToAdd);
    }
    else if (input == 3)
    {
        return;
    }
    else
    {
        cout << "Invalid Input, try again." << endl
             << endl;
        invFullHealing(itemToAdd);
    }

    cout << endl;
}

void Inventory::invFullWeapon(DamageItem itemToAdd)
{
    int input = -1;
    int i;
    int j;
    cout << "Current inventory is full, pick an option: " << endl;
    cout << "1. Delete potion item from inventory and replace it with new item." << endl;
    cout << "1. Delete damage item from inventory and replace it with new item." << endl;
    cout << "3. Discard new item." << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "Select An Item to replace." << endl;
        cout << "Potion Item List:" << endl;
        for (i = 0; i < potionList.size(); i++)
        {
            cout << "   " << i << ". " << potionList[i].getName() << endl;
        }
        cin >> input;
        cout << potionList[input].getName() << " will get replaced by " << itemToAdd.getName() << endl;
        potionList.erase(potionList.begin() + input);
        weaponList.push_back(itemToAdd);
    }
    else if (input == 2)
    {
        cout << "Select An Item to replace." << endl;
        cout << "Damage Item List:" << endl;
        for (i = 0; i < weaponList.size(); i++)
        {
            cout << "   " << i << ". " << weaponList[i].getName() << endl;
        }
        cin >> input;
        cout << weaponList[input].getName() << " will get replaced by " << itemToAdd.getName() << endl;
        weaponList[input] = itemToAdd;
    }
    else if (input == 3)
    {
        return;
    }
    else
    {
        cout << "Invalid Input, try again." << endl
             << endl;
        invFullWeapon(itemToAdd);
    }

    cout << endl;
}

// Set inventory size
void Inventory::setInvSize(int newSize)
{
    inventorySize = newSize;
}
void Inventory::setInvCounter(int newSize)
{
    inventoryCounter = newSize;
}

int Inventory::equipWeapon(int origDamage)
{
    int input = -1;
    cout << "Pick an Option" << endl;
    cout << "1. Select Weapon To Equip." << endl;
    cout << "2. Leave" << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "Damage Item List:" << endl;
        int i;
        for (i = 0; i < weaponList.size(); i++)
        {
            cout << "   " << i << ". " << weaponList[i].getName() << endl;
        }
        if (input < weaponList.size())
        {
            return weaponList[input].getDamage();
        }
        else
        {
            cout << "Invalid Input, try again." << endl;
            equipWeapon(origDamage);
        }
    }
    else if (input == 2)
    {
        return origDamage;
    }
    else
    {
        cout << "Invalid Input, try again." << endl;
        equipWeapon(origDamage);
    }
}

int Inventory::usePotion()
{
    int input = -1;
    cout << "Pick an Option" << endl;
    cout << "1. Select a potion to use: " << endl;
    cout << "2. Leave" << endl;
    cin >> input;
    if (input == 1)
    {
        cout << "   Potions:" << endl;
        int i;
        for (i = 0; i < potionList.size(); i++)
        {
            cout << "   " << i << ". " << potionList[i].getName() << endl;
        }
        cin >> input;
        if (input >= potionList.size())
        {
            cout << "Invalid Input, try again." << endl;
            usePotion();
        }
        // Delete potion and return healing amount;
        int healingAmount = potionList[input].getHealingAmount();
        potionList.erase(potionList.begin() + input);
        inventoryCounter--;
        return healingAmount;
    }
    else if (input == 2)
    {
        return 0;
    }
    else
    {
        cout << "Invalid Input, try again." << endl;
        usePotion();
    }
}

int Inventory::market(int currGold)
{
    int newGold = currGold;
    cout << endl;
    cout << "Current Gold: " << currGold << endl;
    cout << "Select an Option: " << endl;
    cout << "   " << "1. Buy Items" << endl;
    cout << "   " << "2. Leave" << endl;
    int input = -1;
    if (input == 1)
    {
        cout << "Merchant List: " << endl;
        cout << " 1. Small Potion - 10 Gold" << endl;
        cout << " 2. Large Potion - 35 Gold" << endl;
        cout << " 3. Mystic Elixir - 300 Gold" << endl;
        cout << " 4. Basic Sword - 25 Gold" << endl;
        cout << " 5. Greater Sword - 100 Gold" << endl;
        cout << " 6. Magic Wand - 200 Gold" << endl;
        if(input == 1 && currGold >= 10){
            addPotion(SMALL_POTION);
            newGold -= 10;
            market(newGold);
        }else if(input == 2 && currGold >= 35){
            addPotion(LARGE_POTION);
            newGold -= 35;
            market(newGold);
        }else if(input == 3 && currGold >= 300){
            addPotion(MYSTIC_ELIXIR);
            newGold -= 300;
            market(newGold);
        }else if(input == 4 && currGold >= 25){
            addWeapon(BASIC_SWORD);
            newGold -= 25;
            market(newGold);
        }else if(input == 5 && currGold >= 100){
            addWeapon(GREATER_SWORD);
            newGold -= 100;
            market(newGold);
        }else if(input == 6 && currGold >= 200){
            addWeapon(MAGIC_WAND);
            newGold -= 200;
            market(newGold);
        }else{
            cout << "Invalid Input or Insufficient Gold" << endl;
            cout << endl;
            market(newGold);
        }
    }
    else if (input == 2)
    {
        return newGold;
    }
    else
    {
        cout << "Invalid input" << endl;
        cout << endl;
        market(currGold);
    }
}