#include <iostream>
#include <queue>
#include <string>
#include <sstream>

std::queue<int> readInput() {
    std::queue<int> orders;
    std::string ordersStr;
    getline(std::cin, ordersStr);

    std::istringstream istr(ordersStr);
    int order;

    while (istr >> order) {
        orders.push(order);
    }

    return orders;
}

int findBiggest(std::queue<int> numbers) {
    int biggest = 0;

    while (!numbers.empty()) {
        int current = numbers.front(); numbers.pop();
        if (current >= biggest) {
            biggest = current;
        }
    }

    return biggest;
}

void printSolution(int biggestOrder, std::queue<int>& orders) {
    std::cout << biggestOrder << std::endl;

    if (orders.empty()) {
        std::cout << "Orders complete";
    }
    else {
        std::cout << "Orders left: ";

        while (!orders.empty()) {
            std::cout << orders.front() << " ";
            orders.pop();
        }

        std::cout << std::endl;
    }
}

int main() {
    int foodQuantity = 0;
    std::cin >> foodQuantity;
    std::cin.ignore();

    std::queue<int> orders = readInput();
    int biggestOrder = findBiggest(orders);

    int currentOrder;

    while (!orders.empty()) {
        currentOrder = orders.front();

        if (currentOrder <= foodQuantity) {
            foodQuantity -= currentOrder;
            orders.pop();
        }
        else {
            break;
        }
    }

    printSolution(biggestOrder, orders);

    return 0;
}
