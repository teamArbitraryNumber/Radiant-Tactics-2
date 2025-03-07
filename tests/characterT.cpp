/*#include "gtest/gtest.h"
#include "../header/character.h"

TEST(CharacterTest, Constructor) {
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    EXPECT_EQ(chara.getHealth(), 100);
    EXPECT_EQ(chara.getDamage(), 10);
}

TEST(CharacterTest, SetHealth) {
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    chara.setHealth(50);
    EXPECT_EQ(chara.getHealth(), 50);
}

TEST(CharacterTest, SetDamage) {
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    chara.setDamage(50);
    EXPECT_EQ(chara.getDamage(), 50);
}

TEST(CharacterTest, IsAlive) {
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    EXPECT_EQ(chara.isAlive(), true);
    chara.setHealth(0);
    EXPECT_EQ(chara.isAlive(), false);
}

TEST(CharacterTest, Attack) {
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    Character enemy(CharacterType::ORC, "Orc", 100, 100, 10);
    chara.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 90);
}

TEST(CharacterTest, Attack2) {
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    Character enemy(CharacterType::ORC, "Orc", 100, 100, 10);
    chara.setDamage(100);
    chara.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 0);
}

TEST(CharacterTest, Attack3) {
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    Character enemy(CharacterType::ORC, "Orc", 100, 100, 10);
    chara.setDamage(100);
    chara.attack(enemy);
    chara.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 0);
}

TEST(CharacterTest, Attack4) {
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    Character enemy(CharacterType::ORC, "Orc", 100, 100, 10);
    chara.setDamage(100);
    chara.attack(enemy);
    chara.attack(enemy);
    chara.attack(enemy);
    EXPECT_EQ(enemy.getHealth(), 0);
}

TEST(CharacterTest, InvalidHealth){
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    chara.setHealth(-1);
    EXPECT_EQ(chara.getHealth(), 0);
}

TEST(CharacterTest, InvalidDamage){
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    chara.setDamage(-1);
    EXPECT_EQ(chara.getDamage(), 0);
}

TEST(CharacterTest, InvalidDamage2){
    Character chara(CharacterType::PLAYER, "Player", 100, 100, 10);
    chara.setDamage(1000);
    EXPECT_EQ(chara.getDamage(), 0);
}*/

