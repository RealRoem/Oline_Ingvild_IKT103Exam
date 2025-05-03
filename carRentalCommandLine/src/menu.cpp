#include "menu.h"
#include <iostream>
#include "CarController.h"
#include "CustomerController.h"
#include "RentalController.h"
#include "storage.h"

void printMenu() {
    std::cout << "\n=== Main Menu ===\n";
    std::cout << " 1. Car Management\n";
    std::cout << " 2. Customer Management\n";
    std::cout << " 3. Rental Management\n";
    std::cout << " 4. Show Statistics\n";
    std::cout << " 5. Import/Export Data\n";
    std::cout << " 6. Exit\n";
    std::cout << "=====================\n";
}

void showCarMenu(Storage &storage) {
    int carManagement;
    std::cout << "\n=== Car Management ===\n";
    std::cout << " 1. Add car\n";
    std::cout << " 2. Edit car\n";
    std::cout << " 2. Delete car\n";
    std::cout << " 3. View number of cars\n";
    std::cout << "=====================\n";

    switch (getUserInput()) {
        case 1: CarController::addCar(storage);
        break;
        case 2: CarController::editCar(storage);
        break;
        case 3: CarController::removeCar(storage);
        break;
    }
}

void showCustomerMenu(Storage &storage) {
    int customerManagement;
    std::cout << "\n=== Customer Management ===\n";
    std::cout << " 1. Add customer\n";
    std::cout << " 2. Edit customer\n";
    std::cout << " 3. Delete customer\n";
    std::cout << " 4. View number of customers\n";
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
    }
}

void showRentalMenu(Storage &storage) {
    int rentalManagement;
    std::cout << "\n=== Rental Management ===\n";
    std::cout << "1. Assign car to customer\n";
    std::cout << "2. Unassign car to customer\n";
    std::cout << "3. Number of assigned cars\n";
    std::cout << "4. Number of available cars\n";
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
    }
}

void showStatisticsMenu(Storage &storage) {
    int statisticsMenu;;
    std::cout << "\n=== Statistics menu: ===\n";
    std::cout << "1. Total number of customers\n";
    std::cout << "2. Total number of cars\n";
    std::cout << "3. Number of assigned cars\n";
    std::cout << "4. Number of available cars\n";
    std::cout << "Enter your choice: ";
    std::cout << "=====================\n";
    std::cin >> statisticsMenu;

    switch (statisticsMenu) {
        case 1: CarController::numberOfCars(storage);
            std::cout << "Total number of customers: ";
        break;
        case 2: CustomerController::numberOfCustomers(storage);
            std::cout << "Total number of cars: ";
        break;
        case 3: RentalController::activeRentals(storage);
            std::cout << "Number of assigned cars: ";
        break;
        case 4: RentalController::completedRentals(storage);
            std::cout << "Number of available cars: ";
        break;
        default:
            std::cout << "Invalid choice. Returning to main menu.\n";
    }
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