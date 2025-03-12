#include "item.h"
#include <iostream>

void Item::displayItem() const {
    std::cout << "Item: " << name << " (" << type << ")
";
}

// Healing Item Implementation
HealingItem::HealingItem(const std::string& name, int healAmt) 
    : Item(name, "Healing"), healingAmount(healAmt) {}

void HealingItem::useItem() const {
    std::cout << name << " used! Restores " << healingAmount << " HP.
";
}

// Damage Item Implementation
DamageItem::DamageItem(const std::string& name, int dmgAmt) 
    : Item(name, "Damage"), damage(dmgAmt) {}

void DamageItem::useItem() const {
    std::cout << name << " used! Deals " << damage << " damage.
";
}