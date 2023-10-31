#include <iostream>
#include <queue>
#include <string>
#include <sstream>

int readInput() {
	int input;
	std::cin >> input;

	return input;
}

bool canComplete(std::queue<int> liters,
				 std::queue<int> pumps) {
	int curFuel = 0;

	while (!liters.empty()) {
		int fuel = liters.front(); liters.pop();
		int dist = pumps.front(); pumps.pop();

		curFuel += fuel;
		if (curFuel < dist) {
			return false;
		}
		curFuel -= dist;
	}

	return true;
}

int circlePumps(std::queue<int>& liters,
				std::queue<int>& pumps) {
	int index = 0;

	while (!canComplete(liters, pumps)) {
		int pumpLiters = liters.front(); liters.pop();
		liters.push(pumpLiters);
		int pumpDist = pumps.front(); pumps.pop();
		pumps.push(pumpDist);
		++index;
	}

	return index;
}

int main() {
	int stationNumbers = readInput();

	std::queue<int> liters;
	std::queue<int> pumps;

	for (int i = 0; i < stationNumbers; ++i) {
		liters.push(readInput());
		pumps.push(readInput());
	}

	int result = circlePumps(liters, pumps);

	std::cout << result << std::endl;

	return 0;
}
