#include "LuxuryCar.h"

double getLuxuryKmTax(int dayTax, std::string car) {
    double km;
    double tax;

    std::cout << "Enter the distance traveled in kilometers for car " << car << ". " << std::endl;
    std::cin >> km;

    if (km < 200.0) {
        tax = dayTax * 0.6;
    }
    else {
        tax = dayTax * 0.4;
    }

    return tax;
}

LuxuryCar::LuxuryCar(std::string make, std::string model, std::string type, std::string color,
	std::string vin, std::string plate, double fuelConsumption, int taxPerDay)
	: Car(make, model, type, color, vin, plate, fuelConsumption, taxPerDay) {}

double LuxuryCar::calculatePrice() {
	int dayTax = this->getDayTax();
	double kmTax = getLuxuryKmTax(dayTax, this->getMake());

	return dayTax * kmTax;
}
