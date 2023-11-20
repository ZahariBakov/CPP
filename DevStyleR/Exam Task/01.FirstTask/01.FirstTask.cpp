#include <iostream>
#include <vector>
#include <string>

// RepairRecord structure
struct RepairRecord {
    std::string licensePlate;
    std::string ownerName;
    std::string repairDescription;
    double repairCost;
    std::vector<std::string> partsUsed;
    int laborHours;
};

// Function to add a new repair record
void addRepairRecord(std::vector<RepairRecord>& records) {
    RepairRecord newRecord;

    // Input validation for license plate number
    std::cout << "Enter license plate number: ";
    while (true) {
        std::cin >> newRecord.licensePlate;
        if (newRecord.licensePlate.size() >= 3) {
            break;
        }
        std::cin.clear();
        std::cout << "Invalid input. Please enter a license plate number that is longer than two characters: ";
    }

    // Input for owner's name
    std::cout << "Enter owner's name: ";
    std::cin.ignore();  // Clear the newline character from the buffer
    std::getline(std::cin, newRecord.ownerName);

    // Input for repair description
    std::cout << "Enter repair description: ";
    std::getline(std::cin, newRecord.repairDescription);

    // Input validation for repair cost
    std::cout << "Enter repair cost: ";
    while (!(std::cin >> newRecord.repairCost)) {
        std::cout << "Invalid input. Please enter a valid number for repair cost: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Input validation for labor hours
    std::cout << "Enter the number of labor hours: ";
    while (!(std::cin >> newRecord.laborHours)) {
        std::cout << "Invalid input. Please enter a valid number for labor hours: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Input for parts used
    std::cout << "Enter parts used (enter 'done' when finished):\n";
    while (true) {
        std::string part;
        std::cout << "  - ";
        std::cin.clear();
        std::cin >> part;

        if (part == "done") {
            break;
        }

        newRecord.partsUsed.push_back(part);
    }

    // Add the new record to the vector
    records.push_back(newRecord);
    std::cout << "Repair record added successfully.\n";
}

// Function to display all repair records
void displayRepairRecords(const std::vector<RepairRecord>& records) {
    // Display all repair records in a formatted manner
    std::cout << "---- All Repair Records ----\n";
    for (const auto& record : records) {
        std::cout << "License Plate: " << record.licensePlate << "\n";
        std::cout << "Owner's Name: " << record.ownerName << "\n";
        std::cout << "Repair Description: " << record.repairDescription << "\n";
        std::cout << "Repair Cost: " << record.repairCost << "\n";
        std::cout << "Labor Hours: " << record.laborHours << "\n";

        std::cout << "Parts Used:\n";
        for (const auto& part : record.partsUsed) {
            std::cout << "  - " << part << "\n";
        }

        std::cout << "----------------------------\n";
    }
}

// Function to search for a repair record by license plate number
const RepairRecord* searchByLicensePlate(const std::vector<RepairRecord>& records, const std::string& licensePlate) {
    // Search for a repair record by license plate number
    for (const auto& record : records) {
        if (record.licensePlate == licensePlate) {
            return &record;
        }
    }

    // Return nullptr if no record is found
    return nullptr;
}

// Main function
int main() {
    // Initial values
    std::vector<RepairRecord> repairRecords = {
        {"CA1245PK", "Ivan Petrov", "Oil Change", 180.0, {"Oil", "Filter"}, 3},
        {"PB7762AH", "Maria Stoianova", "Brake Replacement", 300.0, {"Brake Pads", "Brake Fluid"}, 5},
    };

    int choice;
    do {
        // Display the main menu
        std::cout << "\n---- Car Repair Shop Management System ----\n";
        std::cout << "1. Add Repair Record\n";
        std::cout << "2. Display All Repair Records\n";
        std::cout << "3. Search for Repair Record by License Plate\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Switch based on the user's choice
        switch (choice) {
        case 1:
            addRepairRecord(repairRecords);
            break;
        case 2:
            displayRepairRecords(repairRecords);
            break;
        case 3: {
            std::string searchLicensePlate;
            std::cout << "Enter license plate number to search: ";
            std::cin >> searchLicensePlate;
            const RepairRecord* foundRecord = searchByLicensePlate(repairRecords, searchLicensePlate);
            if (foundRecord) {
                // Display the found record
                std::cout << "Record found:\n";
                std::cout << "License Plate: " << foundRecord->licensePlate << "\n";
                std::cout << "Owner's Name: " << foundRecord->ownerName << "\n";
                std::cout << "Repair Description: " << foundRecord->repairDescription << "\n";
                std::cout << "Repair Cost: " << foundRecord->repairCost << "\n";
                std::cout << "Labor Hours: " << foundRecord->laborHours << "\n";
                std::cout << "Parts Used:\n";
                for (const auto& part : foundRecord->partsUsed) {
                    std::cout << "  - " << part << "\n";
                }
            }
            else {
                // Indicate that the record was not found
                std::cout << "Record not found.\n";
            }
            break;
        }
        case 4:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}


// TODO...
// Demo - how the values changing.
// Run program
// Now you see option menu:
// ---- Car Repair Shop Management System ----
// 1. Add Repair Record
// 2. Display All Repair Records
// 3. Search for Repair Record by License Plate
// 4. Exit
// Enter your choice :
// 
// ---------------------------------------------------------
// 
// Let's add a new vehicle to our database.
// 
// Now choose option:
// 1 
// Then you see this text "Enter license plate number: "
// A4972MA
// 
// Then you see this text "Enter owner's name: "
// Petar Dimitrov
// 
// Then you see this text "Enter repair description: "
// Changing the spark plugs
// 
// Then you see this text "Enter repair cost: "
// Four hundred
// 
// Then you see this text "Invalid input. Please enter a valid number for repair cost: "
// 400
// 
// Then you see this text "Enter the number of labor hours: "
// two
// 
// Then you see this text "Invalid input. Please enter a valid number for labor hours: "
// 2
// Then you see this text  "Enter parts used (enter 'done' when finished):"
//                            -
// spark plugs - 4ps.
// done
// Then you see this text "Repair record added successfully."
// 
// Then you will return to optpion menu.
// 
// ---------------------------------------------------------
// 
// Let's now look at all the vehicles in our database.
// Now choose option:
// 2
// And now you see this text:
// 
// ---- All Repair Records ----
// License Plate: CA1245PK
// Owner's Name: Ivan Petrov
// Repair Description : Oil CHange
// Repair Cost : 180
// Labor Hours : 3
// Parts Used :
// -Oil
// - Filter
// ----------------------------
// License Plate : PB7762AH
// Owner's Name: Maria Stoianova
// Repair Description : Brake Replacement
// Repair Cost : 300
// Labor Hours : 5
// Parts Used :
// -Brake Pads
// - Brake Fluid
// ----------------------------
// License Plate : A4972MA
// Owner's Name: Petar Dimitrov
// Repair Description : Changing the spark plugs
// Repair Cost : 400
// Labor Hours : 2
// Parts Used :
// -spark
// - plugs
// - -
// -4ps.
//----------------------------
// 
// And again go back to option menu.
// 
// ---------------------------------------------------------
//
// Let's now search for a vehicle by registration number.
// 
// Now choose option:
// 3
// Now you see this text "Enter license plate number to search: "
// PB7762AH
// 
// And now you see this text:
// 
// Record found:
// License Plate : PB7762AH
// Owner's Name: Maria Stoianova
// Repair Description : Brake Replacement
// Repair Cost : 300
// Labor Hours : 5
// Parts Used :
// -Brake Pads
// - Brake Fluid
// 
// And again go back to option menu.
// 
// ---------------------------------------------------------
// 
// Let's now search for a vehicle with a wrong license plate.
// Now choose option:
// 3
// Now you see this text "Enter license plate number to search: "
// B0055EA
// 
// Now you see this text "Record not found."
// 
// And again go back to option menu.
// 
// Now choose option:
// 4
// 
// Exit program

// Quick access to commands
// 1
// A4972MA
// Petar Dimitrov
// Changing the spark plugs
// four hundred
// 400
// two
// 2
// spark plugs - 4ps.
// done
//
// 2
//
// 3 
// PB7762AH
//
// 3
// B0055EA
//
// 4

 

