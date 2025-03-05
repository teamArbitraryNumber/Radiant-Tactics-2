#include "item.h"

// Display item details (base class)
void Item::displayItem() const {
    std::cout << "Item: " << name << " (" << type << ")\n";
}

// Healing Item Implementation
HealingItem::HealingItem(const std::string& name, int healAmt, int turns) 
    : Item(name, "Healing"), healingAmount(healAmt), duration(turns) {}

void HealingItem::useItem() const {
    std::cout << name << " used! Restores " << healingAmount;
    if (duration > 0)
        std::cout << " HP per turn for " << duration << " turns.";
    std::cout << "\n";
}

// Boosting Item Implementation
BoostingItem::BoostingItem(const std::string& name, const std::string& stat, int increase, int turns)
    : Item(name, "Boosting"), statType(stat), statIncrease(increase), duration(turns) {}

void BoostingItem::useItem() const {
    std::cout << name << " used! Increases " << statType << " by " << statIncrease 
              << " for " << duration << " turns.\n";
}

// Battle Item Implementation
BattleItem::BattleItem(const std::string& name, int dmg, int duration) 
    : Item(name, "Battle"), damage(dmg), effectDuration(duration) {}

void BattleItem::useItem() const {
    std::cout << name << " used! Deals " << damage << " damage";
    if (effectDuration > 0)
        std::cout << " and affects the enemy for " << effectDuration << " turns.";
    std::cout << "\n";
}

// Special Item Implementation
SpecialItem::SpecialItem(const std::string& name) 
    : Item(name, "Special") {}

void SpecialItem::useItem() const {
    std::cout << name << " used! Provides a unique effect.\n";
}
