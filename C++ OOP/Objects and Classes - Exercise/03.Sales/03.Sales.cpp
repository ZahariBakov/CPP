#include <iostream>
#include <string>
#include <map>
#include <iomanip>

class Sale {
public:
	void readInput() {
		std::cin >> count;

		double currSales;
		for (int i = 0; i < count; ++i) {
			std::cin >> town >> product >> price >> quantity;

			cities[town] += (price * quantity);
		}
	}

	void printInfo() {
		for (const std::pair<std::string, double>& pair : cities) {
			std::cout << pair.first << " -> " << std::fixed << std::setprecision(2) << pair.second << std::endl;
		}
	}

private:
	std::string town;
	std::string product;
	double price;
	double quantity;
	int count = 0;
	std::map<std::string, double> cities;
};

int main() {
	Sale towns;
	towns.readInput();
	towns.printInfo();
	

	return 0;
}
