#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// https://www.codingame.com/ide/puzzle/the-descent

int main() {
    std::vector<int> mountains;

    // game loop
    while (1) {
        int maxIdx = 0;
        int maxNum = 0;

        for (int i = 0; i < 8; i++) {
            int mountain_h; // represents the height of one mountain.
            std::cin >> mountain_h; 
            mountains.push_back(mountain_h);
            std::cin.ignore();

            if (mountain_h > maxNum) {
                maxNum = mountain_h;
                maxIdx = i;
            }
        }

        std::cout << maxIdx << std::endl;
        
    }
}