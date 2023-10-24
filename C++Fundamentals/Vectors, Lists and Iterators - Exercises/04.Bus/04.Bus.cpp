#include <iostream>
#include <vector>

int convertTime(int time) {
    if (time > 60) {
        int minutes = time % 100;
        int hours = time / 100;
        time = (hours * 60) + minutes;
    }

    return time;
}

std::vector<int> readInput(int n) {
    std::vector<int> result(n);
    int militaryTime;

    for (int i = 0; i < n; ++i) {
        std::cin >> militaryTime;
        result[i] = convertTime(militaryTime);
    }

    return result;
}

void printNearestBus(int n, std::vector<int>& busesArrivalTimes, int trainArrivelTime) {
    int bestBus = 0;
    int minTime = 1499;
    int diff;

    for (int i = 0; i < n; ++i) {
        int diff = trainArrivelTime - busesArrivalTimes[i];

        if (diff <= minTime) {
            bestBus = i + 1;
            minTime = diff;
        }
    }

    std::cout << bestBus << std::endl;
}

int main() {
    int numberOfBuses;
    std::cin >> numberOfBuses;

    std::vector<int> busesArrivalTimes = readInput(numberOfBuses);

    int trainArrivelTime;
    std::cin >> trainArrivelTime;
    trainArrivelTime = convertTime(trainArrivelTime);

    printNearestBus(numberOfBuses, busesArrivalTimes, trainArrivelTime);

    return 0;
}
