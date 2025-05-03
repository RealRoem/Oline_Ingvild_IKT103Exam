#include "menu.h"
#include <iostream>
#include "CarController.h"
#include "CustomerController.h"
#include "RentalController.h"
#include "storage.h"

void printMenu() {
    std::cout << "\n=== Main Menu ===\n";
    std::cout << "  1. Car Management\n";
    std::cout << "  2. Customer Management\n";
    std::cout << "  3. Rental Management\n";
    std::cout << "  4. Show Statistics\n";
    std::cout << "  5. Import/Export Data\n";
    std::cout << "  6. Exit\n";
    std::cout << "=====================\n";
}

void showCarMenu(Storage &storage) {
    bool running = true;
    while (running) {
        std::cout << "\n=== Car Management ===\n";
        std::cout << " 1. Add car\n";
        std::cout << " 2. Edit car\n";
        std::cout << " 3. Delete car\n";
        std::cout << " 4. View number of cars\n";
        std::cout << " 5. Back to main menu\n";
        std::cout << "=====================\n";

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
        std::cout << "\n=== Customer Management ===\n";
        std::cout << " 1. Add customer\n";
        std::cout << " 2. Edit customer\n";
        std::cout << " 3. Delete customer\n";
        std::cout << " 4. View number of customers\n";
        std::cout << " 5. Back to main menu\n";
        std::cout << "=====================\n";

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
    std::cout << "\n=== Rental Management ===\n";
    std::cout << "1. Assign car to customer\n";
    std::cout << "2. Unassign car to customer\n";
    std::cout << "3. Number of active rentals\n";
    std::cout << "4. Number of completed rentals\n";
    std::cout << "5. Back to main menu\n";
    std::cout << "=====================\n";

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
    int ImportExport;
    std::cout << "Export all information\n";
    std::cout << "Import all information\n";
    std::cout << "=====================\n";
    std::cin >> ImportExport;
}

  int getUserInput(){
      std::cout << "Enter your choice: " << std::endl ;
      int userChoice = 0;
      std::cin >> userChoice;
      return userChoice;
  }