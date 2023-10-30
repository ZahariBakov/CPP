#include <iostream>
#include <stack>
#include <string>
#include <sstream>

std::stack<int> readInput() {
    std::stack<int> stack;
    std::string stackStr;

    getline(std::cin, stackStr);

    std::istringstream istr(stackStr);

    int piece;
    while (istr >> piece) {
        stack.push(piece);
    }

    return stack;
}

int sumRacksNeeded(int rackCapacity, std::stack<int>& box) {
    int usedRacks = 1;
    int currentRack = rackCapacity;
    int currentClothes;

    while (!box.empty()) {
        currentClothes = box.top();
        
        if (currentClothes <= currentRack) {
            currentRack -= currentClothes;
            box.pop();
        }
        else {
            usedRacks++;
            currentRack = rackCapacity;
        }
    }

    return usedRacks;
}

int main() {
    std::stack<int> box = readInput();
    int rackCapacity;
    std::cin >> rackCapacity;

    int racks = sumRacksNeeded(rackCapacity, box);

    std::cout << racks << std::endl;

    return 0;
}
