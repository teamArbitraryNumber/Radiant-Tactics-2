#include "../header/enemy.h"
#include <iostream>

Enemy::Enemy(string type, int health, int damage, int x, int y)
    : Character(type, 0, health, damage, x, y), enemyType(type) {}

// Movement logic: Move towards the player
void Enemy::move(GameMap& map) {
    // Get player position (assuming player is stored in the map)
    shared_ptr<Object> playerObj = map.getObjectAt(0, 0); // Placeholder for actual player position
    int playerX = playerObj->getColPosition();
    int playerY = playerObj->getRowPosition();

    int dx = playerX - col_pos;
    int dy = playerY - row_pos;

    // Move towards player (basic AI)
    if (abs(dx) > abs(dy)) {
        setColPosition(col_pos + (dx > 0 ? 1 : -1));
    } else {
        setRowPosition(row_pos + (dy > 0 ? 1 : -1));
    }
}

// Attack logic
void Enemy::attack() {
    cout << enemyType << " attacks!" << endl; //Attack implenentation placeholder
}

// Display character for rendering
string Enemy::getDisplayChar() const {
    return enemyType == "Skeleton" ? "S" : "G";
}

// Skeleton enemy implementation
Skeleton::Skeleton(int x, int y) : Enemy("Skeleton", 100, 10, x, y) {}

// Goblin enemy implementation
Goblin::Goblin(int x, int y) : Enemy("Goblin", 80, 8, x, y) {}