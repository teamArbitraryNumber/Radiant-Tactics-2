#include "../header/player.h"
#include <iostream>

using namespace std;

int main() {
    // Initialize a player with some default values
    Player player(CharacterType::PLAYER, "Hero", 100, 100, 10, 0, 0, 1000); // 1000 gold

    // Display initial player stats
    cout << "Initial Player Stats:" << endl;
    cout << "Health: " << player.getHealth() << endl;
    cout << "Currency: " << player.getCurrency() << endl;
    cout << "Equipped Weapon Damage: " << player.getDamage() << endl;
    cout << endl;

    // Add some items to the player's inventory
    player.getInventory().addWeapon(BASIC_SWORD);
    player.getInventory().addPotion(SMALL_POTION);
    player.getInventory().addPotion(LARGE_POTION);

    // Print the inventory
    cout << "Player's Inventory:" << endl;
    player.getInventory().printInv();
    cout << endl;

    // Test equipping a weapon
    cout << "Equipping a weapon..." << endl;
    int newDamage = player.getInventory().equipWeapon(player.getDamage());
    player.setDamage(newDamage);
    cout << "New Equipped Weapon Damage: " << player.getDamage() << endl;
    cout << endl;

    // Test using a potion
    cout << "Using a potion..." << endl;
    int healingAmount = player.getInventory().usePotion();
    player.heal(healingAmount);
    cout << "Player's Health after using potion: " << player.getHealth() << endl;
    cout << endl;

    // Test buying items from the market
    cout << "Visiting the market..." << endl;
    int remainingGold = player.getInventory().market(player.getCurrency());
    player.setCurrency(remainingGold);
    cout << "Remaining Gold: " << player.getCurrency() << endl;
    cout << endl;

    // Print the updated inventory
    cout << "Updated Player's Inventory:" << endl;
    player.getInventory().printInv();
    cout << endl;

    // Display final player stats
    cout << "Final Player Stats:" << endl;
    cout << "Health: " << player.getHealth() << endl;
    cout << "Currency: " << player.getCurrency() << endl;
    cout << "Equipped Weapon Damage: " << player.getDamage() << endl;

    return 0;
}

