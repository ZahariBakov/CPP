#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int surface_n; // the number of points used to draw the surface of Mars.
    std::cin >> surface_n; 
    std::cin.ignore();

    for (int i = 0; i < surface_n; i++) {
        int land_x; // X coordinate of a surface point. (0 to 6999)
        int land_y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        std::cin >> land_x >> land_y; 
        std::cin.ignore();
    }

    int turn = 0;
    int shipPower = 3;

    // game loop
    while (1) {
        int x;
        int y;
        int h_speed; // the horizontal speed (in m/s), can be negative.
        int v_speed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        std::cin >> x >> y >> h_speed >> v_speed >> fuel >> rotate >> power; 
        std::cin.ignore();

        if (turn > 0) {
            if (v_speed > -40) {
                shipPower--;

                if (shipPower < 0) {
                    shipPower = 0;
                }
            }
            else if (v_speed < -40) {
                shipPower ++;

                if (shipPower > 4) {
                    shipPower = 4;
                }
            }
        }

        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        std::cout << "0" << " " << shipPower << std::endl;

        turn++;
    }
}