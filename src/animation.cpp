#include "../header/animation.h"

void animateWelcomeMessage(int durationSeconds) {
    std::string message = "WELCOME TO RADIANT TACTICS 2";
    std::vector<ColorCode> colors = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
    int colorIndex = 0;
    int position = 0;

    auto startTime = std::chrono::steady_clock::now();
    auto endTime = startTime + std::chrono::seconds(durationSeconds);

    while (std::chrono::steady_clock::now() < endTime) {
        // Clear screen
        std::cout << "\033[2J\033[H";

        // Move the message to the right
        std::cout << std::string(position, ' ');

        // Change color and print the message
        std::cout << "\033[" << colors[colorIndex] << "m" << message << "\033[" << DEFAULT << "m" << std::endl;

        // Update color and position
        colorIndex = (colorIndex + 1) % colors.size();
        position = (position + 1) % 20;

        // Wait for 200 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
        // std::cout << "\033[2J\033[H";

}
