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
    // Constructor
    Item(const std::string& itemName, const std::string& itemType) 
        : name(itemName), type(itemType) {}

    virtual ~Item() = default;

    // Getters
    std::string getName() const { return name; }
    std::string getType() const { return type; }

    // Virtual function for item effects
    virtual void useItem() const = 0;

    // Display item details
    virtual void displayItem() const;
};

// Healing Item
class HealingItem : public Item {
private:
    int healingAmount;
    int duration; // For turn-based effects

public:
    HealingItem(const std::string& name, int healAmt, int turns = 0);
    void useItem() const override;
};

// Boosting Item
class BoostingItem : public Item {
private:
    std::string statType;
    int statIncrease;
    int duration;

public:
    BoostingItem(const std::string& name, const std::string& stat, int increase, int turns);
    void useItem() const override;
};

// Battle Item
class BattleItem : public Item {
private:
    int damage;
    int effectDuration;

public:
    BattleItem(const std::string& name, int dmg, int duration = 0);
    void useItem() const override;
};

// Special Item
class SpecialItem : public Item {
public:
    SpecialItem(const std::string& name);
    void useItem() const override;
};

#endif // ITEM_H
