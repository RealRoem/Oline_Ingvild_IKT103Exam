#include "Car.h"

#include <iostream>

void Car::addCar(Storage &storage) {
    Car car = getCarInfo(); //henter informasjon om bilen fra brukerinput
    storage.insert(car); //legger til bilen i databasen
    std::cout << "Car added" << std::endl;
}

Car Car::getCarInfo() {
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