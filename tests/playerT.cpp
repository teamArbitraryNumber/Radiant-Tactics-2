/*#include "gtest/gtest.h"
#include "../header/player.h"

TEST(PlayerTest, Constructor) {
    Inventory inv;
    Player player(inv, 0, 100);
    EXPECT_EQ(player.getHealth(), 100);
    EXPECT_EQ(player.getDamage(), 10);
    EXPECT_EQ(player.getCurrency(), 0);
}

TEST(PlayerTest, Heal) {
    Inventory inv;
    Player player(inv, 0, 100);
    player.setHealth(50);
    player.heal(50);
    EXPECT_EQ(player.getHealth(), 100);
}

TEST(PlayerTest, SetCurrency) {
    Inventory inv;
    Player player(inv, 0, 100);
    player.setCurrency(50);
    EXPECT_EQ(player.getCurrency(), 50);
}

TEST(PlayerTest, GetDisplayChar) {
    Inventory inv;
    Player player(inv, 0, 100);
    EXPECT_EQ(player.getDisplayChar(), "P");
}

TEST(PlayerTest, Mod) {
    Inventory inv;
    Player player(inv, 0, 100);
    EXPECT_EQ(player.mod(5, 3), 2);
    EXPECT_EQ(player.mod(-1, 3), 2);
}

TEST(PlayerTest, Move) {
    Inventory inv;
    Player player(inv, 0, 100);
    pair<int, int> pos = player.move('w', 3, 3);
    EXPECT_EQ(pos.first, 0);
    EXPECT_EQ(pos.second, 0);
    pos = player.move('s', 3, 3);
    EXPECT_EQ(pos.first, 0);
    EXPECT_EQ(pos.second, 1);
    pos = player.move('a', 3, 3);
    EXPECT_EQ(pos.first, 2);
    EXPECT_EQ(pos.second, 1);
    pos = player.move('d', 3, 3);
    EXPECT_EQ(pos.first, 0);
    EXPECT_EQ(pos.second, 1);
}

TEST(PlayerTest, GetPosition) {
    Inventory inv;
    Player player(inv, 0, 100);
    pair<int, int> pos = player.getPosition();
    EXPECT_EQ(pos.first, 0);
    EXPECT_EQ(pos.second, 0);
}

TEST(PlayerTest, SetPosition) {
    Inventory inv;
    Player player(inv, 0, 100);
    player.setPosition(1, 1);
    pair<int, int> pos = player.getPosition();
    EXPECT_EQ(pos.first, 1);
    EXPECT_EQ(pos.second, 1);
}

TEST(PlayerTest, Attack) {
    Inventory inv;
    Player player(inv, 0, 100);
    CharacterType charType = CharacterType::ORC;
    Character enemy(charType, "Orc", 100, 100, 10);
    player.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 90);
}

TEST(PlayerTest, Attack2) {
    Inventory inv;
    Player player(inv, 0, 100);
    CharacterType charType = CharacterType::ORC;
    Character enemy(charType, "Orc", 100, 100, 10);
    player.setDamage(100);
    player.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 0);
}

TEST(PlayerTest, Attack3) {
    Inventory inv;
    Player player(inv, 0, 100);
    CharacterType charType = CharacterType::ORC;
    Character enemy(charType, "Orc", 100, 100, 10);
    player.setDamage(100);
    player.attack(enemy);
    player.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 0);
}
//test: constructor initializes player with 100 health, 10 damage, empty inventory, and 0 currency

TEST(PlayerTest, Constructor2) {
    Inventory inv;
    Player player(inv, 0, 100);
    EXPECT_EQ(player.getHealth(), 100);
    EXPECT_EQ(player.getDamage(), 10);
    EXPECT_EQ(player.getCurrency(), 0);
}

TEST(PlayerTest, testCharacterMovement) {
    Player mc(0, 0);
    int width = 5, height = 5;

    auto newPosition = mc.move('w', height, width);
    EXPECT_EQ(newPosition, std::make_pair(0, 4)); // Wrap around to the bottom

    newPosition = mc.move('a', height, width);
    EXPECT_EQ(newPosition, std::make_pair(4, 4)); // Wrap around to the right

    newPosition = mc.move('s', height, width);
    EXPECT_EQ(newPosition, std::make_pair(4, 0)); // Wrap around to the top

    newPosition = mc.move('d', height, width);
    EXPECT_EQ(newPosition, std::make_pair(0, 0)); // Wrap around to the left
}
*/




