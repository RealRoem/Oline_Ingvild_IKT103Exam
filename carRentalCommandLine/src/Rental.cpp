#include "Rental.h"
#include <iostream>
#include "RentalController.h"
#include "CustomerController.h"
#include "CarController.h"

void RentalController::assignCarToCustomer(Storage &storage) {
    Rental rental = getRentalInfo(storage);
    storage.insert(rental);
    std::cout << "Rental added" << std::endl;
}

void RentalController::unassignCarToCustomer(Storage &storage) {

}

void RentalController::activeRentals(Storage &storage) {}

void RentalController::completedRentals(Storage &storage) {}

Rental RentalController::getRentalInfo(Storage &storage) {
    int customerId;
    std::string regNo;
    std::string startTime;
    std::string endTime;

    CustomerController::searchCustomer(storage);
    std::cout << " enter customer ID to rental: " << std::endl;
    std::cin >> customerId;
    CarController::searchCar(storage);
    std::cout << " enter registration number to rental: " << std::endl;
    std::cin >> regNo;
    std::cout << " enter starting time: " << std::endl;
    std::cin >> startTime;
    std::cout << " enter ending time: " << std::endl;
    std::cin >> endTime;

    return Rental{customerId, regNo, startTime, endTime};
}
