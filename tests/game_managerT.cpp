/*#include "gtest/gtest.h"
#include "../header/game_manager.h"

TEST(GameManagerTest, Constructor) {
    Game_Manager gm;
    EXPECT_EQ(gm.getGameMap().getHeight(), 0);
    EXPECT_EQ(gm.getGameMap().getWidth(), 0);
    EXPECT_EQ(gm.getGameMap().getNumSkeleton(), 0);
    EXPECT_EQ(gm.getGameMap().getSkeletonsKilled(), 0);
}

TEST(GameManagerTest, SetGameMap) {
    Game_Manager gm;
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    GameMap gameMap(matrix, 3, 3);
    gm.setGameMap(gameMap);
    EXPECT_EQ(gm.getGameMap().getHeight(), 3);
    EXPECT_EQ(gm.getGameMap().getWidth(), 3);
    EXPECT_EQ(gm.getGameMap().getNumSkeleton(), 0);
    EXPECT_EQ(gm.getGameMap().getSkeletonsKilled(), 0);
}

TEST(GameManagerTest, SetPlayer) {
    Game_Manager gm;
    Player player;
    gm.setPlayer(player);
    EXPECT_EQ(gm.getPlayer().getHealth(), 100);
    EXPECT_EQ(gm.getPlayer().getDamage(), 10);
}

TEST(GameManagerTest, SetInventory) {
    Game_Manager gm;
    Inventory inv;
    gm.setInventory(inv);
    EXPECT_EQ(gm.getInventory().getInvSize(), 0);
    EXPECT_EQ(gm.getInventory().getInventoryCounter(), 0);
}

TEST(GameManagerTest, SetEnemyGoal) {
    Game_Manager gm;
    gm.setEnemyGoal(5);
    EXPECT_EQ(gm.getEnemyGoal(), 5);
}

TEST(GameManagerTest, SetIsPlayerTurn) {
    Game_Manager gm;
    gm.setIsPlayerTurn(true);
    EXPECT_EQ(gm.getIsPlayerTurn(), true);
}*/

