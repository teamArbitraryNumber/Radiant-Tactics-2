#include "../header/enemy.h"
#include <iostream>
#include <queue>

Enemy::Enemy(string type, int health, int damage, int x, int y)
    : Character(type, 0, health, damage, x, y), enemyType(type) {}

// Movement logic: Move towards the player
void Enemy::move(GameMap& map) {
   int width = map.getWidth();
    int height = map.getHeight();

    // Get player position
    shared_ptr<Object> playerObj = map.getObjectAt(0, 0); // TODO: Replace with actual player position retrieval
    int playerX = playerObj->getColPosition();
    int playerY = playerObj->getRowPosition();

    int startX = col_pos;
    int startY = row_pos;

    // Directions: Right, Left, Down, Up
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS setup
    queue<pair<int, int>> q;
    unordered_map<int, pair<int, int>> parent; // Stores the parent of each cell for backtracking
    unordered_map<int, bool> visited; // Keeps track of visited positions

    // Convert (x, y) to a unique key for the map
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
            if (obj && obj->getType() != "empty") continue;  // Avoid occupied spaces

            // Mark as visited and store parent for backtracking
            visited[toKey(newX, newY)] = true;
            parent[toKey(newX, newY)] = {x, y};

            // Stop BFS when reaching the player
            if (newX == playerX && newY == playerY) {
                found = true;
                break;
            }

            q.push({newX, newY});
        }
    }

    // If no path found, stay in place
    if (!found) return;

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
