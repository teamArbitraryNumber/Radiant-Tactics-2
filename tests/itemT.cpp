#include "gtest/gtest.h"
#include "../header/item.h"


TEST(ItemTest, HealingItem) {
    HealingItem item("Potion", 10);
    EXPECT_EQ(item.getName(), "Potion");
    EXPECT_EQ(item.getType(), "Healing");
    EXPECT_EQ(item.getHealingAmount(), 10);
}

TEST(ItemTest, DamageItem) {
    DamageItem item("Sword", 15);
    EXPECT_EQ(item.getName(), "Sword");
    EXPECT_EQ(item.getType(), "Damage");
    EXPECT_EQ(item.getDamage(), 15);
}

TEST(ItemTest, UseItem) {
    HealingItem item("Potion", 10);
    testing::internal::CaptureStdout();
    item.useItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Potion used! Restores 10 HP.\n");
}

TEST(ItemTest, DisplayItem) {
    HealingItem item("Potion", 10);
    testing::internal::CaptureStdout();
    item.displayItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Item: Potion (Healing)\n");
}

TEST(ItemTest, DisplayDamageItem) {
    DamageItem item("Sword", 15);
    testing::internal::CaptureStdout();
    item.displayItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Item: Sword (Damage)\n");
}

// Edge Case: Test Healing Item with 0 healing amount
TEST(ItemTest, HealingItemZeroHealing) {
    HealingItem item("Small Potion", 0);
    EXPECT_EQ(item.getName(), "Small Potion");
    EXPECT_EQ(item.getType(), "Healing");
    EXPECT_EQ(item.getHealingAmount(), 0);
    testing::internal::CaptureStdout();
    item.useItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Small Potion used! Restores 0 HP.\n");
}

// Edge Case: Test Damage Item with 0 damage amount
TEST(ItemTest, DamageItemZeroDamage) {
    DamageItem item("Rusty Sword", 0);
    EXPECT_EQ(item.getName(), "Rusty Sword");
    EXPECT_EQ(item.getType(), "Damage");
    EXPECT_EQ(item.getDamage(), 0);
    testing::internal::CaptureStdout();
    item.useItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Rusty Sword used! Deals 0 damage.\n");
}

// Edge Case: Test Item with negative healing amount (if applicable)
TEST(ItemTest, HealingItemNegativeHealing) {
    HealingItem item("Poison Potion", -10);
    EXPECT_EQ(item.getName(), "Poison Potion");
    EXPECT_EQ(item.getType(), "Healing");
    EXPECT_EQ(item.getHealingAmount(), -10);
    testing::internal::CaptureStdout();
    item.useItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Poison Potion used! Restores -10 HP.\n");
}

// Edge Case: Test Item with negative damage amount (if applicable)
TEST(ItemTest, DamageItemNegativeDamage) {
    DamageItem item("Bamboo Stick", -5);
    EXPECT_EQ(item.getName(), "Bamboo Stick");
    EXPECT_EQ(item.getType(), "Damage");
    EXPECT_EQ(item.getDamage(), -5);
    testing::internal::CaptureStdout();
    item.useItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Bamboo Stick used! Deals -5 damage.\n");
}

// Test Special Item with 0 healing amount
TEST(ItemTest, SpecialItemPhoenixFeather) {
    DamageItem item("Phoenix Feather", 0);
    EXPECT_EQ(item.getName(), "Phoenix Feather");
    EXPECT_EQ(item.getType(), "Damage");
    EXPECT_EQ(item.getDamage(), 0);
    testing::internal::CaptureStdout();
    item.useItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Phoenix Feather used! Deals 0 damage.\n");
}


