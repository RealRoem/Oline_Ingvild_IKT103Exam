#include "Car.h"
#include "CarController.h"
#include <iostream>
#include "storage.h"


void CarController::addCar(Storage &storage) {
    Car car = getCarInfo(); //henter informasjon om bilen fra brukerinput
    storage.replace(car); //legger til bilen i databasen. replace istedenfor insert fordi PK ikke er int
    std::cout << "Car added successfully" << std::endl;

    printCarInfo(storage);
}

Car CarController::getCarInfo() {
    std::string regNo;
    std::string carModel;
    int seats;
    std::string gearbox;
    int dailyRentalCost;

    std::cout << "Enter registration number: ";
    std::cin >> regNo;
    std::cin.ignore(); //fjerner \n før getline
    std::cout << "Enter car model: ";
    std::getline(std::cin, carModel);
    std::cout << "Enter number of seats: ";
    while (!(std::cin >> seats)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }
    std::cout << "Enter type of gearbox: ";
    std::cin >> gearbox;
    std::cout << "Enter daily rental cost: ";
    while (!(std::cin >> dailyRentalCost)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }

    return Car{regNo, carModel, seats, gearbox, dailyRentalCost};
}

void CarController::editCar(Storage &storage) {
    std::string oldRegNo;
    std::cout << "Enter registration number to edit: ";
    std::cin >> oldRegNo;

    auto car = storage.get_pointer<Car>(oldRegNo); //returnerer en nullptr hvis regNo ikke finnes, slik at if(car) blir false
    if(car) {

        std::cin.ignore();
        Car editedCar;

        std::cout << "Enter new registration number: ";
        std::getline(std::cin, editedCar.regNo);
        std::cout << "Enter new car model: ";
        std::getline(std::cin, editedCar.carModel);
        std::cout << "Enter new number of seats: ";
        std::cin >> editedCar.seats;
        std::cout << "Enter new type of gearbox: ";
        std::cin >> editedCar.gearbox;
        std::cout << "Enter new daily rental cost: ";
        std::cin >> editedCar.dailyRentalCost;

        storage.replace(editedCar);

        if (editedCar.regNo != oldRegNo) {
            storage.remove<Car>(oldRegNo);
        }
        std::cout << "Car edited successfully" << std::endl;
    } else {
        std::cout << "Car not found." << std::endl;
    } printCarInfo(storage);
}

void CarController::removeCar(Storage &storage) {
    std::string regNo;
    std::cout << "Enter registration number to delete: ";
    std::cin >> regNo;

    auto car = storage.get_pointer<Car>(regNo);
    if(car) {
        storage.remove<Car>(regNo);
        std::cout << "Car deleted successfully" << std::endl;
    } else {
        std::cout << "Car not found" << std::endl;
    } printCarInfo(storage);
}

void CarController::printCarInfo(Storage &storage) {
    auto cars = storage.get_all<Car>();
    for (const auto& car : cars) {
        std::cout << "---------------------------\n";
        std::cout << "Registration number:         " << car.regNo << '\n';
        std::cout << "Car model:                   " << car.carModel << '\n';
        std::cout << "Seats:                       " << car.seats << '\n';
        std::cout << "Gearbox:                     " << car.gearbox << '\n';
        std::cout << "Daily rental cost:           " << car.dailyRentalCost << '\n';
        std::cout << "---------------------------\n";
    }
}

/*
bool CarController::existsCar() {

} */

