#include "gtest/gtest.h"
#include "../header/inventory.h"

TEST(InventoryTest, Constructor) {
    Inventory inv;
    EXPECT_EQ(inv.inventorySize, 15);
    EXPECT_EQ(inv.inventoryCounter, 0);
}

TEST(InventoryTest, AddWeapon) {
    Inventory inv;
    DamageItem item("Sword", 10);
    inv.addWeapon(item);
    EXPECT_EQ(inv.weaponList.size(), 1);
    EXPECT_EQ(inv.inventoryCounter, 1);
}

TEST(InventoryTest, AddPotion) {
    Inventory inv;
    HealingItem item("Potion", 10);
    inv.addPotion(item);
    EXPECT_EQ(inv.potionList.size(), 1);
    EXPECT_EQ(inv.inventoryCounter, 1);
}

TEST(InventoryTest, EquipWeapon) {
    Inventory inv;
    DamageItem item("Sword", 10);
    inv.addWeapon(item);
    int newDamage = inv.equipWeapon(5);
    EXPECT_EQ(newDamage, 10);
}

TEST(InventoryTest, UsePotion) {
    Inventory inv;
    HealingItem item("Potion", 10);
    inv.addPotion(item);
    int healingAmount = inv.usePotion();
    EXPECT_EQ(healingAmount, 10);
    EXPECT_EQ(inv.potionList.size(), 0);
    EXPECT_EQ(inv.inventoryCounter, 0);
}

TEST(InventoryTest, HasPotion) {
    Inventory inv;
    HealingItem item("Potion", 10);
    inv.addPotion(item);
    EXPECT_TRUE(inv.hasPotion("Potion"));
    EXPECT_FALSE(inv.hasPotion("Super Potion"));
}

TEST(InventoryTest, HasWeapon) {
    Inventory inv;
    DamageItem item("Sword", 10);
    inv.addWeapon(item);
    EXPECT_TRUE(inv.hasWeapon("Sword"));
    EXPECT_FALSE(inv.hasWeapon("Axe"));
}

TEST(InventoryTest, SetInvSize) {
    Inventory inv;
    inv.setInvSize(20);
    EXPECT_EQ(inv.inventorySize, 20);
}

TEST(InventoryTest, SetInvCounter) {
    Inventory inv;
    inv.setInvCounter(10);
    EXPECT_EQ(inv.inventoryCounter, 10);
}

TEST(InventoryTest, Market) {
    Inventory inv;
    int remainingGold = inv.market(100);
    EXPECT_EQ(remainingGold, 100);
}

TEST(InventoryTest, PrintInv) {
    Inventory inv;
    DamageItem item1("Sword", 10);
    HealingItem item2("Potion", 10);
    inv.addWeapon(item1);
    inv.addPotion(item2);
    testing::internal::CaptureStdout();
    inv.printInv();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Weapon List:\n   1. Sword\n\nPotion List:\n   1. Potion\n");
}

