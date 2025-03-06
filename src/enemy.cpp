#include "../header/enemy.h"
#include "../header/player.h"
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <limits>

Enemy::Enemy(CharacterType char_type, string type, int value, int h, int d, int row, int col)
    : Character(char_type, type, value, h, d, row, col), enemyType(type) {}

// Movement logic: Move towards the player
void Enemy::move(GameMap& map) {
    int width = map.getWidth();
    int height = map.getHeight();

    // Get player position
    shared_ptr<Object> playerObj;
    int playerX = -1, playerY = -1;

    // Find the player's actual position
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            shared_ptr<Object> obj = map.getObjectAt(x, y);
            if (obj && obj->getType() == "Player") {
                playerX = x;
                playerY = y;
                break;
            }
        }
    }

    if (playerX == -1 || playerY == -1) {
        return; // Player not found, do nothing
    }

    int startX = col_pos;
    int startY = row_pos;

    // Directions: Right, Left, Down, Up
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS setup
    queue<pair<int, int>> q;
    unordered_map<int, pair<int, int>> parent; // Tracks movement path
    unordered_map<int, bool> visited;

    // Lambda to convert (x, y) to a unique key
    auto toKey = [&](int x, int y) { return y * width + x; };

    q.push({startX, startY});
    visited[toKey(startX, startY)] = true;

    bool found = false;

    while (!q.empty() && !found) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            // Check bounds
            if (newX < 0 || newX >= width || newY < 0 || newY >= height) continue;

            // Check if already visited
            if (visited[toKey(newX, newY)]) continue;

            // Check if space is occupied
            shared_ptr<Object> obj = map.getObjectAt(newX, newY);
            if (obj && obj->getType() != "empty" && obj->getType() != "Player") continue;  // Avoid obstacles/enemies

            // Mark as visited and store parent for pathfinding
            visited[toKey(newX, newY)] = true;
            parent[toKey(newX, newY)] = {x, y};

            // If we reached the player, stop BFS
            if (newX == playerX && newY == playerY) {
                found = true;
                break;
            }

            q.push({newX, newY});
        }
    }

    if (!found) return; // No valid path to player

    // Backtrack to find the first move
    pair<int, int> current = {playerX, playerY};
    pair<int, int> previous = {startX, startY};

    while (parent.count(toKey(current.first, current.second))) {
        previous = current;
        current = parent[toKey(current.first, current.second)];

        if (current == make_pair(startX, startY)) break;  // Stop at the first move
    }

    // Move the enemy to the first step in the path
    setColPosition(previous.first);
    setRowPosition(previous.second);
}

// Attack logic
void Enemy::attack(Character& player) {
    int targetHealth = player.getHealth();
    player.setHealth(targetHealth - damage);
    
    cout << enemyType << " attacks!" << endl; //Attack implenentation placeholder
}

// Display character for rendering
string Enemy::getDisplayChar() const {
    return enemyType == "Skeleton" ? "S" : "G";
}

// Skeleton enemy implementation
Skeleton::Skeleton() : Enemy(CharacterType::SKELETON, "Skeleton",  5    ,  70,   10  ,  0   ,  0  ) {}
//                                  CharacterType      type      value     h     d     row   col

// Goblin enemy implementation
Goblin::Goblin() : Enemy(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   0   ,   0) {}
//                              CharacterType       type      value     h      d     row     col