#include <iostream>
#include <vector>

class Engine {
public:
    virtual void start() {
        std::cout << "Engine starting..." << std::endl;
    }
};

class Vehicle {
public:
    Vehicle(std::string brand, std::string model, int year) : brand(brand), model(model), year(year) {}

    virtual void displayInfo() {
        std::cout << year << " " << brand << " " << model << std::endl;
    }

protected:
    std::string brand;
    std::string model;
    int year;
};

class Car : public Vehicle {
public:
    Car(std::string brand, std::string model, int year, int numDoors)
        : Vehicle(brand, model, year), numDoors(numDoors) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        std::cout << "Number of doors: " << numDoors << std::endl;
    }

private:
    int numDoors;
};

class Bicycle : public Vehicle {
public:
    Bicycle(std::string brand, std::string model, int year, int numGears)
        : Vehicle(brand, model, year), numGears(numGears) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        std::cout << "Number of gears: " << numGears << std::endl;
    }

private:
    int numGears;
};

class MotorizedVehicle : public Vehicle, public Engine {
public:
    MotorizedVehicle(std::string brand, std::string model, int year, std::string fuelType, int horsepower)
        : Vehicle(brand, model, year), Engine(), fuelType(fuelType), horsepower(horsepower) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        std::cout << "Fuel type: " << fuelType << ", Horsepower: " << horsepower << std::endl;
    }

private:
    std::string fuelType;
    int horsepower;
};

class TrafficSimulation {
public:
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAllVehicles() {
        for (const auto& vehicle : vehicles) {
            vehicle->displayInfo();
            // For MotorizedVehicle, call the start() function
            MotorizedVehicle* motorizedVehicle = dynamic_cast<MotorizedVehicle*>(vehicle);
            if (motorizedVehicle) {
                motorizedVehicle->start();
            }
            std::cout << "-----------------------" << std::endl;
        }
    }

private:
    std::vector<Vehicle*> vehicles;
};

int main() {
    TrafficSimulation simulation;

    Car car("Toyota", "Camry", 2022, 4);
    Bicycle bicycle("Giant", "Escape", 2022, 21);
    MotorizedVehicle motorbike("Harley-Davidson", "Sportster", 2022, "Gasoline", 120);

    simulation.addVehicle(&car);
    simulation.addVehicle(&bicycle);
    simulation.addVehicle(&motorbike);

    simulation.displayAllVehicles();

    return 0;
}
