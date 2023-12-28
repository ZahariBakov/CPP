#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// https://www.codingame.com/ide/puzzle/power-of-thor-episode-1

int main() {
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    std::cin >> light_x >> light_y >> initial_tx >> initial_ty; 
    std::cin.ignore();

    int thorX = initial_tx;
    int thorY = initial_ty;

    // game loop
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        std::cin >> remaining_turns; 
        std::cin.ignore();

        std::string directionX = "";
        std::string directionY = "";

        if (thorX > light_x) {
            directionX = "W";
            thorX--;
        }
        else if (thorX < light_x) {
            directionX = "E";
            thorX++;
        }

        if (thorY > light_y) {
            directionY = "N";
            thorY--;
        }
        else if (thorY < light_y) {
            directionY = "S";
            thorY++;
        }

        std::cout << directionY << directionX << std::endl;
    }

    return 0;
}