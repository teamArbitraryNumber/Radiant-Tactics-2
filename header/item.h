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
    void displayItem() const;
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

// More Healing Items
const HealingItem ELVEN_REMEDY("Elven Remedy", 40);
const HealingItem DRAGON_HEART("Dragon Heart", 999);
const HealingItem HERBAL_TONIC("Herbal Tonic", 15);

// More Damage Items
const DamageItem SHADOW_DAGGER("Shadow Dagger", 20);
const DamageItem WAR_HAMMER("War Hammer", 40);
const DamageItem FLAME_BLADE("Flame Blade", 35);
const DamageItem ICE_SPEAR("Ice Spear", 30);
const DamageItem VAMPIRE_FANG("Vampire Fang", 25);

// Battle & Explosive Items
const DamageItem HOLY_GRENADE("Holy Grenade", 50);
const DamageItem ACID_FLASK("Acid Flask", 30);
const DamageItem SMOKE_BOMB("Smoke Bomb", 0);

// Special Items
const DamageItem PHOENIX_FEATHER("Phoenix Feather", 0);
const DamageItem TIME_CRYSTAL("Time Crystal", 0);
const DamageItem DEMON_SEAL("Demon Seal", 0);

// Ranged & Magic Items
const DamageItem EXPLODING_ARROW("Exploding Arrow", 40);
const DamageItem MAGIC_ORB("Magic Orb", 25);
const DamageItem LIGHTNING_RUNE("Lightning Rune", 50);

// Rare & Legendary Items
const DamageItem EXCALIBUR("Excalibur", 100);
const DamageItem NECRONOMICON("Necronomicon", 0);
const DamageItem CELESTIAL_SHIELD("Celestial Shield", 0);


#endif