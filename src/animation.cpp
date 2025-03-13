#include "../header/animation.h"

// void animateWelcomeMessage(int durationSeconds) {
//     std::string message = "WELCOME TO RADIANT TACTICS 2";
//     std::vector<ColorCode> colors = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
//     int colorIndex = 0;
//     int position = 0;

//     auto startTime = std::chrono::steady_clock::now();
//     auto endTime = startTime + std::chrono::seconds(durationSeconds);

//     while (std::chrono::steady_clock::now() < endTime) {
//         // Clear screen
//         std::cout << "\033[2J\033[H";

//         // Move the message to the right
//         std::cout << std::string(position, ' ');

//         // Change color and print the message
//         std::cout << "\033[" << colors[colorIndex] << "m" << message << "\033[" << DEFAULT << "m" << std::endl;

//         // Update color and position
//         colorIndex = (colorIndex + 1) % colors.size();
//         position = (position + 1) % 20;

//         // Wait for 200 milliseconds
//         std::this_thread::sleep_for(std::chrono::milliseconds(200));
//     }
//         // std::cout << "\033[2J\033[H";

// }

void animateWelcomeMessage(int durationSeconds) {
    std::string message = "WELCOME TO RADIANT TACTICS 2";
    std::vector<ColorCode> colors = { GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
    int colorIndex = 0;
    int position = 0;

    // Timer to stop the animation after a certain duration
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

    // After the animation ends, leave the final frame on the screen
    std::cout << "\033[H"; // Move cursor to the top-left corner
    std::cout << std::string(position, ' '); // Move the message to the right
    std::cout << "\033[" << colors[colorIndex] << "m" << message << "\033[" << DEFAULT << "m" << std::endl;
}



void animateTorch(int durationSeconds) {
    int offset = 0;
    int direction = 1;
    std::string colors[] = {RED, ORANGE, YELLOW_LIGHT};
    int colorIndex = 0;

    auto startTime = std::chrono::steady_clock::now();
    auto endTime = startTime + std::chrono::seconds(durationSeconds);

    while (std::chrono::steady_clock::now() < endTime) {
        // Clear screen
        std::cout << "\033[2J\033[H";

        // Adjust vertical offset for flickering effect
        for (int i = 0; i < offset; i++) {
            std::cout << std::endl;
        }

        // Print the flame with the changing color
        std::cout << colors[colorIndex];
        std::cout << "⠀⠀⠀⠀⠀⢱⣆⠀⠀⠀⠀⠀⠀\n";
        std::cout << "⠀⠀⠀⠀⠀⠀⠈⣿⣷⡀⠀⠀⠀⠀\n";
        std::cout << "⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣧⠀⠀⠀\n";
        std::cout << "⠀⠀⠀⠀⡀⢠⣿⡟⣿⣿⣿⡇⠀⠀\n";
        std::cout << "⠀⠀⠀⠀⣳⣼⣿⡏⢸⣿⣿⣿⢀⠀\n";
        std::cout << "⠀⠀⠀⣰⣿⣿⡿⠁⢸⣿⣿⡟⣼⡆\n";
        std::cout << "⢰⢀⣾⣿⣿⠟⠀⠀⣾⢿⣿⣿⣿⣿\n";
        std::cout << "⢸⣿⣿⣿⡏⠀⠀⠀⠃⠸⣿⣿⣿⡿\n";
        std::cout << "⢳⣿⣿⣿⠀⠀⠀⠀⠀⠀⢹⣿⡿⡁\n";
        std::cout << "⠀⠹⣿⣿⡄⠀⠀⠀⠀⠀⢠⣿⡞⠁\n";
        std::cout << "⠀⠀⠈⠛⢿⣄⠀⠀⠀⣠⠞⠋⠀⠀\n";
        std::cout << "⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀\n";
        std::cout << RESET; // Reset color after the flame

        // Change animation state
        offset += direction;
        if (offset > 1 || offset < 0) direction = -direction;  // Slight movement up and down

        colorIndex = (colorIndex + 1) % 3;  // Cycle through colors

        // Random flicker speed
        int flickerSpeed = 100 + (std::rand() % 200);
        std::this_thread::sleep_for(std::chrono::milliseconds(flickerSpeed));
    }
        std::cout << "\033[2J\033[H";
}

void displayInstructions() {
    std::string instructions =
        "In this game you get to pick any type of player you want to be. You will be walking around the map but beware of enemies such as skeletons and goblins. If they get close enough you have the option to either have a turn based fight with them, use your inventory, or accept defeat and do nothing.\n\n"
        "You will have currency and with each enemy you defeat they will drop a certain amount of coins that you can get. You can use this currency to buy from the merchant.\n\n"
        "The merchant has potions to help with your health or can help provide weapons to help kill the enemy. Once you make it to the door, you will go through it and the next map will load. Press the x key to see the list commands you can use to see various things such as your health or buy from the merchant.";

    // std::cout << instructions << std::endl;

    std::vector<std::string> flameColors = { ORANGE, YELLOW_LIGHT, };
    int colorIndex = 0;

    // Display the instructions with flickering flame colors
    for (size_t i = 0; i < instructions.length(); ++i) {
        // Change color every 10 characters for a flickering effect
        if (i % 10 == 0) {
            colorIndex = (colorIndex + 1) % flameColors.size();
            std::cout << flameColors[colorIndex];
        }

        // Print the current character
        std::cout << instructions[i];

        // Add a slight delay for a smoother flickering effect
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    // Reset color after printing the instructions
    std::cout << RESET << std::endl;
}