#include "Rental.h"
#include <iostream>
#include "RentalController.h"
#include "CustomerController.h"
#include "CarController.h"

void RentalController::assignCarToCustomer(Storage &storage) {
    Rental rental = getRentalInfo(storage);
    storage.replace(rental);
    std::cout << "Rental added" << std::endl;
}

void RentalController::unassignCarToCustomer(Storage &storage) {
    std::string regNo;
    std::string startTime;
    auto rental = storage.get<Rental>(std::make_tuple (regNo, startTime));
    rental.status = false;
    storage.update(rental);

    std::cout << "Rental ended for customer ID " << rental.customerId << " with car "<< rental.regNo << std::endl;
}

void RentalController::activeRentals(Storage &storage) {
    auto activeRental = storage.count<Rental>(sqlite_orm::where(sqlite_orm::c(&Rental::status) == true));
    std::cout << "Number of active rentals: " << activeRental << std::endl;
}

void RentalController::completedRentals(Storage &storage) {
    auto completedRental = storage.count<Rental>(sqlite_orm::where(sqlite_orm::c(&Rental::status) == false));
    std::cout << "Number of completed rentals: " << completedRental << std::endl;
}

Rental RentalController::getRentalInfo(Storage &storage) {
    int customerId;
    std::string regNo;
    std::string startTime;

    CustomerController::searchCustomer(storage);
    std::cout << "Enter customer ID to rental: " << std::endl;
    std::cin >> customerId;

    CarController::searchCar(storage);
    std::cout << "Enter registration number to rental: " << std::endl;
    std::cin >> regNo;
    std::cout << "Enter starting time: " << std::endl;
    std::cin >> startTime;

    std::cin.ignore();

    return Rental{customerId, regNo, startTime, true};
}

