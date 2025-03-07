/*#include "gtest/gtest.h"
#include "../header/item.h"

#include "../header/item.h"

TEST(ItemTest, HealingItemTest) {
    HealingItem hi("Healing Potion", 20);
    EXPECT_EQ(hi.getName(), "Healing Potion");
    EXPECT_EQ(hi.getType(), "Healing Item");
}

TEST(ItemTest, BoostingItemTest) {
    BoostingItem bi("Strength Potion", "Strength", 5, 3);
    EXPECT_EQ(bi.getName(), "Strength Potion");
    EXPECT_EQ(bi.getType(), "Boosting Item");
}

TEST(ItemTest, BattleItemTest) {
    BattleItem bi("Fireball", 15);
    EXPECT_EQ(bi.getName(), "Fireball");
    EXPECT_EQ(bi.getType(), "Battle Item");
}

TEST(ItemTest, HealingItemUseTest) {
    HealingItem hi("Healing Potion", 20);
    testing::internal::CaptureStdout();
    hi.useItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Healing Potion used! Health restored by 20.\n");
}

TEST(ItemTest, BoostingItemUseTest) {
    BoostingItem bi("Strength Potion", "Strength", 5, 3);
    testing::internal::CaptureStdout();
    bi.useItem();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Strength Potion used! Strength increased by 5 for 3 turns.\n");
}
*/


