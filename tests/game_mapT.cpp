#include "gtest/gtest.h"
#include "../header/game_map.h"

TEST(GameMapTest, Constructor) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    EXPECT_EQ(map.getWidth(), 3);
    EXPECT_EQ(map.getHeight(), 3);
    EXPECT_EQ(map.getNumEnemy(), 0);
    EXPECT_EQ(map.getEnemyKilled(), 0);
}

TEST(GameMapTest, KillSkeleton) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    map.killEnemy(1, 1);
    EXPECT_EQ(map.getNumEnemy(), 0);
    EXPECT_EQ(map.getEnemyKilled(), 1);
}

TEST(GameMapTest, GetObjectAt) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    shared_ptr<Object> obj = map.getObjectAt(1, 1);
    EXPECT_EQ(obj, nullptr);
}

TEST(GameMapTest, SetObjectAt) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    shared_ptr<Object> obj = make_shared<Object>("character", 10);
    map.setObjectAt(1, 1, obj);
    shared_ptr<Object> obj2 = map.getObjectAt(1, 1);
    EXPECT_EQ(obj, obj2);
}

TEST(GameMapTest, PrintMap) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    testing::internal::CaptureStdout();
    map.printMap(1, 1);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "0 0 0 \n0 P 0 \n0 0 0 \n");
}

TEST(GameMapTest, Destructor) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap* map = new GameMap(matrix, 3, 3);
    delete map;
}

TEST(GameMapTest, Destructor2) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
}

TEST(GameMapTest, Destructor3) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    shared_ptr<Object> obj = make_shared<Object>("character", 10);
    map.setObjectAt(1, 1, obj);
}

TEST(GameMapTest, Destructor4) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    shared_ptr<Object> obj = make_shared<Object>("character", 10);
    map.setObjectAt(1, 1, obj);
    shared_ptr<Object> obj2 = make_shared<Object>("sword", 5);
    map.setObjectAt(1, 2, obj2);
}

TEST(GameMapTest, Destructor5) {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    shared_ptr<Object> obj = make_shared<Object>("character", 10);
    map.setObjectAt(1, 1, obj);
    shared_ptr<Object> obj2 = make_shared<Object>("sword", 5);
    map.setObjectAt(1, 2, obj2);
    shared_ptr<Object> obj3 = make_shared<Object>("potion", 15);
    map.setObjectAt(1, 3, obj3);
}

TEST(GameMapTest, NumSkeletonAfterAction){
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    GameMap map(matrix, 3, 3);
    map.killEnemy(1, 1);
    EXPECT_EQ(map.getNumEnemy(), 0);
    EXPECT_EQ(map.getEnemyKilled(), 1);
}