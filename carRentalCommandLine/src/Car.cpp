#include "Car.h"

#include <iostream>
#include <ostream>

void Car::addCar() {
std::cout << "Car added" << std::endl;

}

void getCarInfo() {
    std::string regNo;
    std::string carModel;
    int seats;
    std::string gearbox;
    int dailyRentalCost;

    std::cout << "Enter registration number: " << std::endl;
    std::cin.ignore();
    std::cin >> regNo;
    std::cout << "Enter car model: " << std::endl;
    std::getline(std::cin, carModel);
    std::cout << "Enter number of seats: " << std::endl;
    std::cin.ignore();
    std::cin >> seats;
    std::cout << "Enter type of gearbox: " << std::endl;
    std::cin >> gearbox;
    std::cout << "Enter daily rental cost: " << std::endl;
    std::cin >> dailyRentalCost;
}