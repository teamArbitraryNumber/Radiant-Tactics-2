#include <inventory.h>
#include <item.h>
using namespace std;




//Add Weapon to inventory
void Inventory::addWeapon(string weaponToAdd){
    if(inventoryCounter < inventorySize){
        weaponList.push_back(weaponToAdd);
        inventoryCounter++;
    }else{
        invFull(weaponToAdd);
    }
    
}


//Add Potion to inventory
void Inventory::addPotion(string potionToAdd){
    if(inventoryCounter < inventorySize){
        potionList.push_back(potionToAdd);
        inventoryCounter++;
    }else{
        invFull(potionToAdd);
    }
    
}

//Checks if item is in inventory
bool Inventory::hasPotion(string itemToCompare){
    for(int i = 0; i < potionList.size(); i++){
        if(potionList[i] == itemToCompare){
            return true;
        }
    }
}
bool Inventory::hasWeapon(string itemToCompare){
for(int i = 0; i < weaponList.size(); i++){
        if(weaponList[i] == itemToCompare){
            return true;
        }
    }
}

//If Inventory Full
void Inventory::invFull(string itemToAdd){
    int input = -1;
    int i;
    int j;
    cout << "Current inventory is full, pick an option: " << endl;
    cout << "1. Delete item in inventory and replace it with new item." << endl;
    cout << "2. Discard new item." << endl;
    cin >> input;

    //Inventory Management
    if(input == 1){

        //Print inventory
        cout << "Inventory: " << endl;

        cout << "   Weapons:" << endl;
        for(i = 0; i < weaponList.size(); i++){
            cout << "   " << i+1 << ". " << weaponList[i] << endl;
        }
        cout << "   Potions:" << endl;
        i = 0;
        for(j = weaponList.size(); i < (potionList.size()+ weaponList.size()); j++){
            cout << "   " << j+1 << ". " << potionList[i] << endl;
            i++;
        }
        cout << endl;
        cout << "Select Item to Replace: " << endl;
        cin >> input;
        cout << endl;

        //Replace the item
        if(input > 0 && input < weaponList.size()){
            cout <<  weaponList[input - 1] << " will replace" << itemToAdd << endl;
            weaponList[input - 1] = itemToAdd;
        }else if(input >= weaponList.size()){
            cout <<  potionList[(input - 1)- weaponList.size()] << " will replace" << itemToAdd << endl;
            potionList[(input - 1)- weaponList.size()] = itemToAdd;
        }
    }else if(input == 2){
        cout << itemToAdd << " has been discarded." << endl;
    }else{
        cout << "Invalid input, try again\n" << endl;
        invFull(itemToAdd);
    }
    cout << endl;
}


//Set inventory size
void Inventory::setInvSize(int newSize){
    inventorySize = newSize;
}



int equipWeapon(int damageAmount){
    
}



int Inventory::usePotion(){
    cout << "Select a potion to use: " << endl;
    cout << "   Potions:" << endl;
    int i;
    for(i = 0; i < potionList.size(); i++){
        cout << "   " << i+1 << ". " << potionList[i] << endl;
    }

    //Delete potion and return healing amount;
    int healingAmount = potionList[i].healingAmount();
    potionList.erase(potionList.begin() + i);
    return healingAmount;
}


void market(int currGold){
    cout << endl;
    cout << "Current Gold: " << currGold << endl;
    cout << "Select an Option: " << endl;
    cout << "   " << "1. Buy Items" << endl;
    cout << "   " << "2. Leave" << endl;
    int input = 0;
    if(input == 1){
        cout << "Merchant List: " << endl;
        //Implement Later
    }else if(input == 2){
        return;
    }else{
        cout << "Invalid input" << endl;
        cout << endl;
        market(currGold);
    }
}