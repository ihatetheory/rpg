#include <iostream>

#include "stats.h"

int main() {

    bool isRunning(true);
    while (isRunning) {
        /**
         * Here is the main body of our rpg
         */

        std::cout << "We are inside the main game loop, aren't you happy?\n";
        isRunning = false;
    }

    Stats s(10u, 2u, 5u);
    std::cout << "\n Core:"
              << "\n - Stamina: " << s.getStat(CORESTATS::STAMINA)
              << "\n - Strength: " << s.getStat(CORESTATS::STRENGTH)
              << "\n - Intelect: " << s.getStat(CORESTATS::INTELECT)
              << "\n - Luck: " << s.getStat(CORESTATS::LUCK)
              << "\n Armor: "
              << "\n - Pierce: " << s.getStat(ARMORSTATS::PIERCE)
              << "\n - Slash: " << s.getStat(ARMORSTATS::SLASH)
              << "\n - Slam: " << s.getStat(ARMORSTATS::SLAM)
              << "\n - Slap: " << s.getStat(ARMORSTATS::SLAP)
              << "\n Resistance: "
              << "\n - File: " << s.getStat(RESISTATS::FIRE)
              << "\n - Water: " << s.getStat(RESISTATS::WATER)
              << "\n - Air: " << s.getStat(RESISTATS::AIR)
              << "\n - Earth: " << s.getStat(RESISTATS::EARTH)
              << '\n';
    s.setCoreStats({2u, 3u, 4u, 5u});
    s.setArmorStats({1u, 2u, 3u, 4u});
    s.setResistanceStats(32u);
    std::cout << "\n Core:"
              << "\n - Stamina: " << s.getStat(CORESTATS::STAMINA)
              << "\n - Strength: " << s.getStat(CORESTATS::STRENGTH)
              << "\n - Intelect: " << s.getStat(CORESTATS::INTELECT)
              << "\n - Luck: " << s.getStat(CORESTATS::LUCK)
              << "\n Armor: "
              << "\n - Pierce: " << s.getStat(ARMORSTATS::PIERCE)
              << "\n - Slash: " << s.getStat(ARMORSTATS::SLASH)
              << "\n - Slam: " << s.getStat(ARMORSTATS::SLAM)
              << "\n - Slap: " << s.getStat(ARMORSTATS::SLAP)
              << "\n Resistance: "
              << "\n - File: " << s.getStat(RESISTATS::FIRE)
              << "\n - Water: " << s.getStat(RESISTATS::WATER)
              << "\n - Air: " << s.getStat(RESISTATS::AIR)
              << "\n - Earth: " << s.getStat(RESISTATS::EARTH)
              << '\n';
    return 0;
}