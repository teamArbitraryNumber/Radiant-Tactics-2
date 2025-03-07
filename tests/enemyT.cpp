#include "gtest/gtest.h"
#include "../header/enemy.h"
#include "../header/game_map.h" // Include the header file that defines the 'GameMap' class


TEST(EnemyTest, Constructor) {
    Skeleton skeleton;
    EXPECT_EQ(skeleton.getHealth(), 70);
    EXPECT_EQ(skeleton.getDamage(), 10);
    EXPECT_EQ(skeleton.getDisplayChar(), "💀");
}

TEST(EnemyTest, Move) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    Skeleton skeleton;
    skeleton.setColPosition(1);
    skeleton.setRowPosition(1);
    map.setObjectAt(1, 1, make_shared<Skeleton>());
    skeleton.move(map);
    pair<int, int> pos = skeleton.getPosition();
    EXPECT_EQ(pos.first, 1);
    EXPECT_EQ(pos.second, 2);
}

TEST(EnemyTest, Move2) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    Skeleton skeleton;
    skeleton.setColPosition(1);
    skeleton.setRowPosition(1);
    map.setObjectAt(1, 1, make_shared<Skeleton>());
    skeleton.move(map);
    pair<int, int> pos = skeleton.getPosition();
    EXPECT_EQ(pos.first, 1);
    EXPECT_EQ(pos.second, 2);
}

TEST(EnemyTest, Damage){
    Skeleton skeleton;
    skeleton.setHealth(50);
    skeleton.setDamage(20);
    EXPECT_EQ(skeleton.getHealth(), 50);
    EXPECT_EQ(skeleton.getDamage(), 20);
}
