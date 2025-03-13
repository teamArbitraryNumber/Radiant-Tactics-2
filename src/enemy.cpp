#include "../header/enemy.h"
#include "../header/player.h"
#include "../header/game_map.h"
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <limits>
#include <cstdlib> // For rand()
#include <ctime>  // For time()

Enemy::Enemy(CharacterType char_type, string type, int value, int h, int d, int row, int col)
    : Character(char_type, type, value, h, d, row, col), enemyType(type) {}

int Enemy::mod(int value, int limit){
    return (value % limit + limit ) % limit;
}
// Movement logic: Move towards the player
void Enemy::move(shared_ptr<Enemy>& enemy, GameMap& map) {
    /*int width = map.getWidth();
    int height = map.getHeight();

    // Get player position
    shared_ptr<Object> playerObj;
    int playerX = -1, playerY = -1;

    int enemyX = getColPosition();
    int enemyY = getRowPosition();

    // Find the player's and enemy's actual position
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            shared_ptr<Object> obj = map.getObjectAt(x, y);
            if(obj){
                if (obj->getType() == "Player") {
                    playerX = x;
                    playerY = y;
                    break;
                }
            }  
        }
    }
    pair<int, int> possibleMoves[4] = {
        {mod(enemyX, width), mod(enemyY - 1, height)}, // Up
        {mod(enemyX, width), mod(enemyY + 1, height)}, // Down
        {mod(enemyX - 1, width), mod(enemyY, height)}, // Left
        {mod(enemyX + 1, width), mod(enemyY, height)}  // Right
    };
    int bestMoveIndex = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < 4; i++) {
        int newX = possibleMoves[i].first;
        int newY = possibleMoves[i].second;

        //newX = mod(newX, width); 
        //newY = mod(newY, height);
        // Ensure the new position is within the map boundaries
        //if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
            shared_ptr<Object> objAtNewPos = map.getObjectAt(newX, newY);
            
            // Check if the new position is empty (no barrier or other object)
            if (objAtNewPos && objAtNewPos->getType() == "Null") {
                // Calculate the distance to the player for this move
                int distance = abs(playerX - newX) + abs(playerY - newY);
                
                // If this move brings the enemy closer to the player, update bestMoveIndex
                if (distance < minDistance) {
                    minDistance = distance;
                    bestMoveIndex = i;
                }
            }
        //}
    }
    if (bestMoveIndex != -1) {
        int newX = possibleMoves[bestMoveIndex].first;
        int newY = possibleMoves[bestMoveIndex].second;

        int oldX = getColPosition();
        int oldY = getRowPosition();
        // Update the enemy's position
        setColPosition(newX);
        setRowPosition(newY);

        // Update the game map with the new position
        if (newX >= 0 && newX < width && newY >= 0 && newY < height){
            map.removeObjectAt(oldX, oldY);
            map.setObjectAt(newX, newY, enemy);
        }
       
    }
    */

    int width = map.getWidth();
    int height = map.getHeight();

    // Get player position
    shared_ptr<Object> playerObj;
    int playerX = -1, playerY = -1;

    // Find the player's position
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

    // Check if the enemy is already adjacent to the player
    int enemyX = getColPosition();
    int enemyY = getRowPosition();

    // Directions: Up, Down, Left, Right
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool isAdjacent = false;
    for (auto [dx, dy] : directions) {
        int adjacentX = (enemyX + dx + width) % width; // Wrap around horizontally
        int adjacentY = (enemyY + dy + height) % height; // Wrap around vertically

        if (adjacentX == playerX && adjacentY == playerY) {
            isAdjacent = true;
            break;
        }
    }

    // If the enemy is already adjacent to the player, do not move
    if (isAdjacent) {
        return;
    }

    // BFS setup
    queue<pair<int, int>> q;
    unordered_map<int, pair<int, int>> parent; // Tracks movement path
    unordered_map<int, bool> visited;

    // Lambda to convert (x, y) to a unique key
    auto toKey = [&](int x, int y) { return y * width + x; };

    // Start BFS from the enemy's current position
    int startX = getColPosition();
    int startY = getRowPosition();
    q.push({startX, startY});
    visited[toKey(startX, startY)] = true;

    bool found = false;

    // Perform BFS to find the shortest path to the player
    while (!q.empty() && !found) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int newX = (x + dx + width) % width; // Wrap around horizontally
            int newY = (y + dy + height) % height; // Wrap around vertically

            // Check if already visited
            if (visited[toKey(newX, newY)]) continue;

            // Check if the space is walkable (empty or player)
            shared_ptr<Object> obj = map.getObjectAt(newX, newY);
            if (obj) {
                // Avoid barriers and other enemies
                if (obj->isBarrier() || (obj->getType() != "Player" && obj->getType() != "Null")) {
                    continue;
                }
            }

            // Mark as visited and store parent for pathfinding
            visited[toKey(newX, newY)] = true;
            parent[toKey(newX, newY)] = {x, y};

            // If we reach the player, stop BFS
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

        if (current == make_pair(startX, startY)) break; // Stop at the first move
    }

    // Move the enemy to the first step in the path
    int newX = previous.first;
    int newY = previous.second;

    // Update the enemy's position
    setColPosition(newX);
    setRowPosition(newY);

    // Update the game map
    map.removeObjectAt(startX, startY);
    map.setObjectAt(newX, newY, enemy);
}


// Attack logic
void Enemy::attack(Character &player) {
    int damage = getDamage(); // Assuming getDamage() returns the enemy's damage
    player.setHealth(player.getHealth() - damage);
    cout << enemyType << " attacks for " << damage << " damage!" << endl;
}

// Skeleton enemy implementation
Skeleton::Skeleton() : Enemy(CharacterType::SKELETON, "Skeleton",  5    ,  70,   10  ,  0   ,  0  ) {}
//                                  CharacterType      type      value     h     d     row   col
Skeleton::Skeleton(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col ) : Enemy(charType, type, value, h, d, row, col) {}

string Skeleton::getDisplayChar(){
    return "💀";
}

// Goblin enemy implementation
Goblin::Goblin() : Enemy(CharacterType::GOBLIN,   "Goblin",    2     ,  80   , 5  ,   0   ,   0) {}
//                              CharacterType       type      value     h      d     row     col
Goblin::Goblin(CharacterType charType, string type,  int value,  int h,   int d  ,  int row, int col ) : Enemy(charType, type, value, h, d, row, col){}

string Goblin::getDisplayChar(){
    return "👺";
}

int Enemy::dropCurrency() {
    srand(time(0)); // Seed the random number generator
    int minCurrency = 5;  // Minimum currency dropped
    int maxCurrency = 20; // Maximum currency dropped
    return minCurrency + (rand() % (maxCurrency - minCurrency + 1));
}