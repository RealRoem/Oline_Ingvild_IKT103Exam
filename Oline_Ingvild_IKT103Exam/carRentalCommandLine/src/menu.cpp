#include "menu.h"
#include <iostream>
#include "CarController.h"
#include "CustomerController.h"
#include "RentalController.h"
#include "ImportExportController.h"
#include "storage.h"

using namespace std;

void printMenu() {
    cout << "\n=== Main Menu ===\n";
    cout << "  1. Car Management\n";
    cout << "  2. Customer Management\n";
    cout << "  3. Rental Management\n";
    cout << "  4. Show Statistics\n";
    cout << "  5. Import/Export Data\n";
    cout << "  6. Exit\n";
    cout << "=====================\n";
}

void showCarMenu(Storage &storage) {
    bool running = true;
    while (running) {
        cout << "\n=== Car Management ===\n";
        cout << " 1. Add car\n";
        cout << " 2. Edit car\n";
        cout << " 3. Delete car\n";
        cout << " 4. View number of cars\n";
        cout << " 5. Back to main menu\n";
        cout << "=====================\n";

        switch (getUserInput()) {
            case 1: CarController::addCar(storage);
                break;
            case 2: CarController::editCar(storage);
                break;
            case 3: CarController::removeCar(storage);
                break;
            case 4: CarController::numberOfCars(storage);
                break;
            case 5: (running = false);
        }
    }
}

void showCustomerMenu(Storage &storage) {
    bool running = true;
    while (running) {
        cout << "\n=== Customer Management ===\n";
        cout << " 1. Add customer\n";
        cout << " 2. Edit customer\n";
        cout << " 3. Delete customer\n";
        cout << " 4. View number of customers\n";
        cout << " 5. Back to main menu\n";
        cout << "=====================\n";

        switch (getUserInput()) {
            case 1: CustomerController::addCustomer(storage);
                break;
            case 2: CustomerController::editCustomer(storage);
                break;
            case 3: CustomerController::deleteCustomer(storage);
                break;
            case 4: CustomerController::numberOfCustomers(storage);
                break;
            case 5: running = false;
        }
    }
}

void showRentalMenu(Storage &storage) {
    bool running = true;
    while (running) {
        cout << "\n=== Rental Management ===\n";
        cout << "1. Assign car to customer\n";
        cout << "2. Unassign car to customer\n";
        cout << "3. Number of active rentals\n";
        cout << "4. Number of completed rentals\n";
        cout << "5. Back to main menu\n";
        cout << "=====================\n";

        switch (getUserInput()) {
            case 1: RentalController::assignCarToCustomer(storage);
                break;
            case 2: RentalController::unassignCarToCustomer(storage);
                break;
            case 3: RentalController::activeRentals(storage);
                break;
            case 4: RentalController::completedRentals(storage);
                break;
            case 5: running = false;
        }
    }
}

void showAllStatistics(Storage &storage) {
    CarController::numberOfCars(storage);
    CustomerController::numberOfCustomers(storage);
    RentalController::activeRentals(storage);
    RentalController::completedRentals(storage);
}

void ImportExportMenu(Storage &storage) {
    bool running = true;
    while (running) {
        cout << "\n=== Import/Export Menu ===\n";
        cout << "1. Export all information to JSON file\n";
        cout << "2. Import all information from JSON file\n";
        cout << "3. Back to main menu\n";
        cout << "=====================\n";

        int choice = getUserInput();
        string filename;

        switch (choice) {
            case 1:
                cout << "Enter filename for export (e.g., data.json): ";
                cin >> filename;
                ImportExportController::exportData(storage, filename);
                break;
            case 2:
                cout << "Enter filename for import (e.g., data.json): ";
                cin >> filename;
                ImportExportController::importData(storage, filename);
                break;
            case 3:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

int getUserInput(){
    cout << "Enter your choice: " << endl;
    int userChoice = 0;
    cin >> userChoice;
    return userChoice;
}