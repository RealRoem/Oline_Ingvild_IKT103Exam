#include <iostream>
#include "Car.h"
#include "Customer.h"
#include "menu.h"
#include "sqlite_orm.h"
#include "storage.h"
#include <filesystem>

#include "CarController.h"

namespace fs = std::filesystem;


int main()
{
  auto storage = init_storage("carRental.sqlite");
  storage.sync_schema();
  printMenu();

    switch (getUserInput()) {
        case 1: CarController::addCar(storage);
           if (!CarController::existsCar(storage, carId)) {
             std::cout << "Enter " << std::endl;
           }
           std::cout << "Car added" << std::endl;
           break;
        case 2: CarController::editCar();
           std::cout << "Car edited" << std::endl;
           if (!CarController::existsCar(storage, carId)) {
             std::cout << "Car does not exist" << std::endl;
           }
           break;
        case 3: CarController::removeCar();
          std::cout << "Car removed" << std::endl;
          if (!CarController::existsCar()) {
          std::cout << "Car does not exist" << std::endl;
          }
          break;
        case 4: Customer::addCustomer();
          std::cout << "Customer added" << std::endl;
          break;
        case 5: Customer::editCustomer();
          std::cout << "Customer edited" << std::endl;
          if (!Customer::existsCustomer()) {
            std::cout << "Customer does not exist" << std::endl;
          }
          break;
        case 6: Customer::deleteCustomer();
          std::cout << "Customer removed" << std::endl;
          if (!Customer::existsCustomer()) {
            std::cout << "Customer does not exist" << std::endl;
          }
          break;
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
          break;
        default:
          std::cout << "Invalid Choice" << std::endl;
          break;
    }

    return 0;
}

