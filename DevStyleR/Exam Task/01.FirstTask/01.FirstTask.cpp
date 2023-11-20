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
    std::vector<RepairRecord> repairRecords;

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


//TODO...
// Demo - how the values changing.
