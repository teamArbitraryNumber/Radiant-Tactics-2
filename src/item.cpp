#include "../header/item.h"
#include <iostream>

void Item::displayItem() const {
    std::cout << "Item: " << name << " (" << type << ")" << std::endl; // Added endl here
}

// Healing Item Implementation
HealingItem::HealingItem(const std::string& name, int healAmt)
    : Item(name, "Healing"), healingAmount(healAmt) {}

void HealingItem::useItem() const {
    std::cout << name << " used! Restores " << healingAmount << " HP." << std::endl; // Added endl here
}

// Damage Item Implementation
DamageItem::DamageItem(const std::string& name, int dmgAmt)
    : Item(name, "Damage"), damage(dmgAmt) {}

void DamageItem::useItem() const {
    std::cout << name << " used! Deals " << damage << " damage." << std::endl; // Added endl here
}