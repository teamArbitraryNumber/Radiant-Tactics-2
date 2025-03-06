#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

// Base Item Class
class Item {
protected:
    std::string name;
    std::string type;

public:
    Item(const std::string& itemName, const std::string& itemType) 
        : name(itemName), type(itemType) {}

    virtual ~Item() = default;

    std::string getName() const { return name; }
    std::string getType() const { return type; }

    virtual void useItem() const = 0;
    virtual void displayItem() const;
};

// Healing Item
class HealingItem : public Item {
private:
    int healingAmount;

public:
    HealingItem(const std::string& name, int healAmt);
    void useItem() const override;
    int getHealingAmount() const { return healingAmount; }
};

// Damage Item
class DamageItem : public Item {
private:
    int damage;

public:
    DamageItem(const std::string& name, int dmgAmt);
    void useItem() const override;
    int getDamage() const { return damage; }
};

// ===========================
// Predefined Items (Global Constants)
// ===========================

// Healing Items
const HealingItem SMALL_POTION("Small Potion", 10);
const HealingItem LARGE_POTION("Large Potion", 25);
const HealingItem MYSTIC_ELIXIR("Mystic Elixir", 50);

// Damage Items (Weapons)
const DamageItem BASIC_SWORD("Basic Sword", 15);
const DamageItem GREATER_SWORD("Greater Sword", 25);
const DamageItem MAGIC_WAND("Magic Wand", 30);

// Explosive/Battle Items
const DamageItem FIRE_BOMB("Fire Bomb", 20);
const DamageItem EXPLOSIVE_ARROW("Explosive Arrow", 35);
const DamageItem THUNDER_SCROLL("Thunder Scroll", 50);

#endif // ITEM_H
