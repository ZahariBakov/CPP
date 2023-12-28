#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// https://www.codingame.com/ide/puzzle/temperatures

int main() {
    int n; // the number of temperatures to analyse
    std::cin >> n; 
    std::cin.ignore();

    int closestToZero = 5530;

    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        std::cin >> t; 
        std::cin.ignore();

        if (abs(closestToZero) > abs(t)) {
            closestToZero = t;
        }
        else if (abs(closestToZero) == abs(t)) {
            if (closestToZero < 0 && t > 0) {
                closestToZero = t;
            }
        }

        if (closestToZero == 0) {
            break;
        }
    }

    if (closestToZero == 5530) {
        closestToZero = 0;
    }

    std::cout << closestToZero << std::endl;
}