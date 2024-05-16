#include <iostream>

int main() {

    bool isRunning(true);
    while (isRunning) {
        /**
         * Here is the main body of our rpg
         */

        std::cout << "We are inside the main game loop, aren't you happy?\n";
        isRunning = false;
    }

    return 0;
}