#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>

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

void animateWelcomeMessage(int durationSeconds = 7);

#endif // ANIMATED_HEADER_H

