#include "../header/inventory.h"
#include "../header/item.h"
#include <iostream>

int main() {
    // Create an inventory
    Inventory myInventory;

    // Add some items to the inventory
    myInventory.addWeapon(BASIC_SWORD);
    myInventory.addWeapon(GREATER_SWORD);
    myInventory.addPotion(SMALL_POTION);
    myInventory.addPotion(LARGE_POTION);

    // Print the inventory
    std::cout << "Initial Inventory:" << std::endl;
    myInventory.printInv();
    std::cout << std::endl;

    // Equip a weapon
    int originalDamage = 10;
    int newDamage = myInventory.equipWeapon(originalDamage);
    std::cout << "Original Damage: " << originalDamage << ", New Damage: " << newDamage << std::endl;
    std::cout << std::endl;

    // Use a potion
    int healingAmount = myInventory.usePotion();
    std::cout << "Healing Amount: " << healingAmount << std::endl;
    std::cout << std::endl;

    // Print the inventory after using a potion
    std::cout << "Inventory after using a potion:" << std::endl;
    myInventory.printInv();
    std::cout << std::endl;

    // Test the market function
    int currentGold = 500;
    std::cout << "Entering the market with " << currentGold << " gold." << std::endl;
    currentGold = myInventory.market(currentGold);
    std::cout << "Remaining gold after market: " << currentGold << std::endl;
    std::cout << std::endl;

    // Print the inventory after market transactions
    std::cout << "Inventory after market transactions:" << std::endl;
    myInventory.printInv();
    std::cout << std::endl;

    return 0;
}