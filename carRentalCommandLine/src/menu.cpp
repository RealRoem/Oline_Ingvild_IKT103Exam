#include "menu.h"
#include <iostream>
#include "CarController.h"
#include "CustomerController.h"
#include "RentalController.h"
#include "storage.h"

void printMenu(){
    std::cout << "1. Add car" << std::endl;
    std::cout << "2. Edit car" << std::endl;
    std::cout << "3. Remove car" << std::endl;
    std::cout << std::endl;
    std::cout << "4. Add customer" << std::endl;
    std::cout << "5. Edit customer" << std::endl;
    std::cout << "6. Remove customer" << std::endl;
    std::cout << std::endl;
    std::cout << "7. Assign car to customer" << std::endl;
    std::cout << "8. Unassign car to customer" << std::endl;
    std::cout << "9. Show statistics" << std::endl;
    std::cout << "10. Export all information to a file" << std::endl;
    std::cout << "11. Import all information from a file" << std::endl;
    std::cout << std::endl;
    std::cout << "12. Exit" << std::endl;
    std::cout << std::endl;
  };

void showStatisticsMenu(Storage &storage) {
    int statisticsMenu;;
    std::cout << "\n Statistics menu: \n";
    std::cout << "1. Total number of customers\n";
    std::cout << "2. Total number of cars\n";
    std::cout << "3. Number of assigned cars\n";
    std::cout << "4. Number of available cars\n";
    std::cout << "Enter your choice: ";
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

  int getUserInput(){
      std::cout << "Enter your choice: " << std::endl ;
      int userChoice = 0;
      std::cin >> userChoice;
      return userChoice;
  }