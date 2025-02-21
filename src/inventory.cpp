#include <inventory.h>
using namespace std;




//Add Weapon to inventory
void addWeapon(string weaponToAdd){
    if(inventoryCounter < inventorySize){
        weaponList.push_back(weaponToAdd);
        inventoryCounter++;
    }else{
        invFull(weaponToAdd);
    }
    
}


//Add Potion to inventory
void addPotion(string potionToAdd){
    if(inventoryCounter < inventorySize){
        potionList.push_back(potionToAdd);
        inventoryCounter++;
    }else{
        invFull(potionToAdd);
    }
    
}

//Checks if item is in inventory
bool hasPotion(string itemToCompare){
    for(int i = 0; i < potionList.size(); i++){
        if(potionList[i] == itemToCompare){
            return true;
        }
    }
}
bool hasWeapon(string itemToCompare){
for(int i = 0; i < weaponList.size(); i++){
        if(weaponList[i] == itemToCompare){
            return true;
        }
    }
}

//If Inventory Full
void invFull(string itemToAdd){
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
void setInvSize(int increase){
    inventorySize += increase;
}



int equipWeapon(int damageAmount){
    
}
int usePotion(int healAmount){

}