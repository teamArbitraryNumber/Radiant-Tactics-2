#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib> // For rand()

enum ColorCode {
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37,
    DEFAULT = 39
};

#define RED "\033[31m"
#define ORANGE "\033[33m"
#define YELLOW_LIGHT "\033[93m"
#define RESET "\033[0m"

void animateWelcomeMessage(int durationSeconds = 7);

// void animateFlame(int durationSeconds = 3);         // Animate the flame
void displayInstructions(); 
void animateTorch(int durationSeconds = 5); // New function for torch animation
void animateGameOver(int durationSeconds = 5); // New function for Game Over animation


#endif // ANIMATED_HEADER_H

