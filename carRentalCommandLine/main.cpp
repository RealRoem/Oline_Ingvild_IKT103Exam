#include <iostream>
#include "Car.h"
#include "Customer.h"
#include "menu.h"
#include "sqlite_orm.h"




int main()
{
    printMenu();
   // getUserInput();
    switch (getUserInput()) {
        case 1: Car::addCar();
           std::cout << "Car added" << std::endl;
           break;
        case 2: Car::editCar();
           std::cout << "Car edited" << std::endl;
           if (!Car::existsCar()) {
             std::cout << "Car does not exist" << std::endl;
           }
           break;
        case 3: Car::removeCar();
          std::cout << "Car removed" << std::endl;
          if (!Car::existsCar()) {
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
          Car::assignCarToCustomer(carId, customerId);
          std::cout << "Car assigned" << std::endl;
          break; }
        case 8: { // Unassign car to customer
          int carId, customerId;
          std::cout << "Enter carID: ";
          std::cin >> carId;
          std::cout << "Enter customerID: ";
          std::cin >> customerId;
          Car::unassignCarToCustomer(carId);
          std::cout << "Car removed" << std::endl;
          break; }
         case 9: { // Show statistics

         case 10: // Export all information to a file
         case 11: // Import all information to a file
         default:
            std::cout << "Invalid Choice" << std::endl;
        break;
    }

    return 0;
}

