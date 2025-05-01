#include "Car.h"
#include "CarController.h"
#include <iostream>
#include "storage.h"


void CarController::addCar(Storage &storage) {
    Car car = getCarInfo(); //henter informasjon om bilen fra brukerinput
    storage.replace(car); //legger til bilen i databasen. replace istedenfor insert fordi PK ikke er int
    std::cout << "Car added successfully" << std::endl;
}

void CarController::editCar(Storage &storage) {
    std::string regNo;
    std::cout << "Enter registration number: " << std::endl;
    std::cin >> regNo;
    if (get<Car>(regNo)) {
        std::cout << "Registration number not found" << std::endl;
    }
try {
    Car car storage.get<Car>(regNo);

    std::string regNo;
    std::string carModel;
    int seats;
    std::string gearbox;
    int dailyRentalCost;

    std::cout << "Enter new registration number: " << regNo << std::endl;
    std::cin >> regNo;
    std::cout << "Enter seat number: " << std::endl;
    std::cin >> seats;
    std::cout << "Enter gearbox number: " << std::endl;
    std::cin >> gearbox;
    std::cout << "Enter daily rental cost: " << std::endl;
    std::cin >> dailyRentalCost;

    storage.replace(regNo, carModel, seats, gearbox);
    std::cout << "Car edited successfully" << std::endl;
}
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
/*
bool CarController::existsCar() {

} */

