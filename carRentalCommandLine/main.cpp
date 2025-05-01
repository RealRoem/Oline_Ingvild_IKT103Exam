#include <iostream>
#include "Car.h"
#include "Customer.h"
#include "menu.h"
#include "sqlite_orm.h"
#include "storage.h"
#include <filesystem>

#include "CarController.h"
#include "CustomerController.h"

namespace fs = std::filesystem;

int main()
{ /*
   fs::remove("carRental.sqlite");
   fs::copy_file("carRental.sqlite.bak", "carRental.sqlite"); */

  auto storage = init_storage("carRental.sqlite");
  storage.sync_schema();

  while (true) {
    printMenu();

    switch (getUserInput()) {
      case 1: CarController::addCar(storage);
       break;
      case 2: CarController::editCar(storage);
       break; /*
       if (!CarController::existsCar(storage, carId)) {
         std::cout << "Car does not exist" << std::endl;
       }
       break; */
      case 3: CarController::removeCar(storage);
        break;
      case 4: CustomerController::addCustomer(storage);
          break;
      case 5: CustomerController::editCustomer(storage);
          break;
      case 6: CustomerController::deleteCustomer(storage);
          break;
      /*
        case 7: { // Assign car to customer
          int carId, customerId;
          std::cout << "Enter carID: ";
          std::cin >> carId;
          std::cout << "Enter customerID: ";
          std::cin >> customerId;
          CarController::assignCarToCustomer(storage, carId, customerId);
          std::cout << "Car assigned" << std::endl;
          break; }
        case 8: { // Unassign car to customer
          int carId, customerId;
          std::cout << "Enter carID: ";
          std::cin >> carId;
          std::cout << "Enter customerID: ";
          std::cin >> customerId;
          CarController::unassignCarToCustomer(storage, carId, customerId);
          std::cout << "Car removed" << std::endl;
          break; }
      // Show statistics:
        case 9: CarController::numberOfCars();
          std::cout << "Number of cars: " << CarController::numberOfCars() << std::endl;
          break;
        case 10: Customer::numberOfCustomers();
          std::cout << "Number of customers: " << Customer::numberOfCustomers() << std::endl;
          break;
        case 11: CarController::activeRentals();
          std::cout << "Number of active rentals: " << CarController::activeRentals() << std::endl;
          break;
        case 12: CarController::completedRentals();
          std::cout << "Number of completed rentals: " << CarController::completedRentals() << std::endl;
          break;
        case 13: // Export all information to a file
          break;
        case 14: // Import all information to a file
          break; */
          case 15:
            return 0;
      default:
        std::cout << "Invalid Choice" << std::endl;
      break;
    }
  }
    return 0;
}

