#include "gtest/gtest.h"
#include "../header/player.h"

// Player Tests
TEST(PlayerTest, Constructor) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    EXPECT_EQ(player.getHealth(), 100);
    EXPECT_EQ(player.getDamage(), 10);
    EXPECT_EQ(player.getCurrency(), 0);
}

TEST(PlayerTest, Heal) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    player.setHealth(50);
    player.heal(50);
    EXPECT_EQ(player.getHealth(), 100);
}

TEST(PlayerTest, SetCurrency) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    player.setCurrency(50);
    EXPECT_EQ(player.getCurrency(), 50);
}

TEST(PlayerTest, GetDisplayChar) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    EXPECT_EQ(player.getDisplayChar(), "☺");
}

TEST(PlayerTest, Mod) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    EXPECT_EQ(player.mod(5, 3), 2);
    EXPECT_EQ(player.mod(-1, 3), 2);
}

TEST(PlayerTest, Move) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    pair<int, int> pos = player.move('w', 3, 3);
    EXPECT_EQ(pos.first, 0);
    EXPECT_EQ(pos.second, 2); // Wrapped around to the bottom
    pos = player.move('s', 3, 3);
    EXPECT_EQ(pos.first, 0);
    EXPECT_EQ(pos.second, 0); // Wrapped around to the top
    pos = player.move('a', 3, 3);
    EXPECT_EQ(pos.first, 2); // Wrapped around to the right
    EXPECT_EQ(pos.second, 0);
    pos = player.move('d', 3, 3);
    EXPECT_EQ(pos.first, 0); // Wrapped around to the left
    EXPECT_EQ(pos.second, 0);
}

TEST(PlayerTest, GetPosition) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    pair<int, int> pos = player.getPosition();
    EXPECT_EQ(pos.first, 0);
    EXPECT_EQ(pos.second, 0);
}

TEST(PlayerTest, SetPosition) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    player.setPosition(1, 1);
    pair<int, int> pos = player.getPosition();
    EXPECT_EQ(pos.first, 1);
    EXPECT_EQ(pos.second, 1);
}

TEST(PlayerTest, Constructor2) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    EXPECT_EQ(player.getHealth(), 100);
    EXPECT_EQ(player.getDamage(), 10);
    EXPECT_EQ(player.getCurrency(), 0);
}

TEST(PlayerTest, TestCharacterMovement) {
    Player player(CharacterType::PLAYER, "Player", 100, 100, 10, 0, 0, 0);
    int width = 5, height = 5;

    auto newPosition = player.move('w', height, width);
    EXPECT_EQ(newPosition, std::make_pair(0, 4)); // Wrap around to the bottom

    newPosition = player.move('a', height, width);
    EXPECT_EQ(newPosition, std::make_pair(4, 4)); // Wrap around to the right

    newPosition = player.move('s', height, width);
    EXPECT_EQ(newPosition, std::make_pair(4, 0)); // Wrap around to the top

    newPosition = player.move('d', height, width);
    EXPECT_EQ(newPosition, std::make_pair(0, 0)); // Wrap around to the left
}



