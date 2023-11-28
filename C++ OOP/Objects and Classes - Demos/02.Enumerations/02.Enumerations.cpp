#include <iostream>

enum class EngineType {
    ON, 
    OFF,
    HALT,
    DAMAGED,
    REPAIRED
};

void processEngineOn() {
    // TODO: Some logic
}

void processEngineOff() {
    // TODO: Some logic
}

void processEngineHalt() {
    // TODO: Some logic
}

void processEngineDamaged() {
    // TODO: Some logic
}

void processEngineRepaired() {
    // TODO: Some logic
}

void processEngine(EngineType engineType) {
    switch (engineType) {
    case EngineType::ON:
        processEngineOn();
        break;
    case EngineType::OFF:
        processEngineOff();
        break;
    case EngineType::HALT:
        processEngineHalt();
        break;
    case EngineType::DAMAGED:
        processEngineDamaged();
        break;
    case EngineType::REPAIRED:
        processEngineRepaired();
        break;
    default:
        break;
    }
}

int main() {
    EngineType type = EngineType::ON;
    processEngine(type);

    enum planets {
        earth = 3, mars, jupiter, saturn, uranus, neptune
    };

    // We can do math in this enum, because it is just const int underneath
    std::cout << "Earth (" << earth << ") is " << uranus - earth << " planets away from " 
        << "uranus (" << uranus << ")." << std::endl;

    enum class Planets {
        earth = 3, mars, jupiter, saturn, uranus, neptune
    };

    Planets planetEarth = Planets::earth;
    // the line below will cause a compilation error - 
    // just earth means the other enum's earth
    // Planets planetsEarthInvalid = earth;

    // You can also specify the type the enum class uses
    // NOTE: we can't do math on these without explicitly
    // converting them to a numeric type


    enum class PlanetsChar : char {
        earth = 'e',
        mars = 'm',
        jupiter = 'j',
        saturn = 's',
        uranus = 'u',
        neptune = 'n'
    };
    PlanetsChar planetsEarthChar = PlanetsChar::earth;

    std::cout << (char)planetsEarthChar << std::endl;

    return 0;
}
