#include "Car.h"
#include "CarController.h"
#include <iostream>
#include "storage.h"


void CarController::addCar(Storage &storage) {
    Car car = getCarInfo(); //henter informasjon om bilen fra brukerinput
    storage.replace(car); //legger til bilen i databasen. replace istedenfor insert fordi PK ikke er int
    std::cout << "Car added successfully" << std::endl;
}

Car CarController::getCarInfo() {
    std::string regNo;
    std::string carModel;
    int seats;
    std::string gearbox;
    int dailyRentalCost;

    std::cout << "Enter registration number: " << std::endl;
    std::cin >> regNo;
    std::cin.ignore(); //fjerner \n før getline
    std::cout << "Enter car model: " << std::endl;
    std::getline(std::cin, carModel);
    std::cout << "Enter number of seats: " << std::endl;
    std::cin >> seats;
    std::cout << "Enter type of gearbox: " << std::endl;
    std::cin >> gearbox;
    std::cout << "Enter daily rental cost: " << std::endl;
    std::cin >> dailyRentalCost;

    return Car{regNo, carModel, seats, gearbox, dailyRentalCost};
}


void CarController::editCar(Storage &storage) {
    std::string regNo;
    std::cout << "Enter registration number to edit: " << std::endl;
    std::cin >> regNo;
    auto car = storage.get_pointer<Car>(regNo); //returnerer en nullptr hvis regNo ikke finnes, slik at if(car) blir false

    if(car) {
        std::cin.ignore();

        std::cout << "Enter new registration number: ";
        std::getline(std::cin, car->regNo);
        std::cout << "Enter new car model: ";
        std::getline(std::cin, car->carModel);
        std::cout << "Enter new number of seats: ";
        std::cin >> car->seats;
        std::cout << "Enter new type of gearbox: ";
        std::cin >> car->gearbox;
        std::cout << "Enter new daily rental cost: ";
        std::cin >> car->dailyRentalCost;
        storage.update (*car);
        std::cout << "Car edited successfully" << std::endl;
    } else {
        std::cout << "Car not found" << std::endl;
    }
}

void CarController::removeCar(Storage &storage) {
    int inputId;
    std::cout << "Enter registration number to delete: " << std::endl;
    std::cin >> inputId;
    auto car = storage.get_pointer<Car>(inputId);
    if(car) {
        storage.remove<Car>(inputId);
        std::cout << "Car deleted successfully" << std::endl;
    } else {
        std::cout << "Car not found" << std::endl;
    }
}

/*
bool CarController::existsCar() {

} */

