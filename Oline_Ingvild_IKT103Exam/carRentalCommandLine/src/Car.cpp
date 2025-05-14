#include "Car.h"
#include "CarController.h"
#include <iostream>
#include "storage.h"
#include <iomanip>
#include <menu.h>

using namespace std;

void CarController::addCar(Storage &storage) {
    Car car = getCarInfo(); //henter informasjon om bilen fra brukerinput
    storage.replace(car); //legger til bilen i databasen. replace istedenfor insert fordi PK ikke er int
    cout << "Car added successfully" << endl;

    printCarInfo(storage);
}

Car CarController::getCarInfo() {
    string regNo;
    string carModel;
    int seats;
    string gearbox;
    int dailyRentalCost;

    cout << "Enter registration number: ";
    cin >> regNo;
    cin.ignore(); //fjerner \n før getline
    cout << "Enter car model: ";
    getline(cin, carModel);
    cout << "Enter number of seats: ";
    while (!(cin >> seats)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cout << "Enter type of gearbox: ";
    cin >> gearbox;
    cout << "Enter daily rental cost: ";
    while (!(cin >> dailyRentalCost)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number: ";
    }

    return Car{regNo, carModel, seats, gearbox, dailyRentalCost};
}

void CarController::editCar(Storage &storage) {
    printCarInfo(storage);
    string oldRegNo;
    cout << "Enter registration number to edit: ";
    cin >> oldRegNo;

    auto car = storage.get_pointer<Car>(oldRegNo); //returnerer en nullptr hvis regNo ikke finnes, slik at if(car) blir false
    if(car) {

        cin.ignore();
        Car editedCar;

        cout << "Enter new registration number: ";
        getline(cin, editedCar.regNo);
        cout << "Enter new car model: ";
        getline(cin, editedCar.carModel);
        cout << "Enter new number of seats: ";
        cin >> editedCar.seats;
        cout << "Enter new type of gearbox: ";
        cin >> editedCar.gearbox;
        cout << "Enter new daily rental cost: ";
        cin >> editedCar.dailyRentalCost;

        storage.replace(editedCar);

        if (editedCar.regNo != oldRegNo) {
            storage.remove<Car>(oldRegNo);
        }
        cout << "Car edited successfully" << endl;
    } else {
        cout << "Car not found." << endl;
    } printCarInfo(storage);
}

void CarController::removeCar(Storage &storage) {
    printCarInfo(storage);
    string regNo;
    cout << "Enter registration number to delete: ";
    cin >> regNo;

    auto car = storage.get_pointer<Car>(regNo);
    if(car) {
        storage.remove<Car>(regNo);
        cout << "Car deleted successfully" << endl;
    } else {
        cout << "Car not found" << endl;
    } printCarInfo(storage);
}

void printCarHeader() {
    cout << "\n================================ Cars ================================" << std::endl;
    cout << left
              << setw(18) << "Reg. Number"
              << setw(15) << "Model"
              << setw(10) << "Seats"
              << setw(15) << "Gearbox"
              << setw(12) << "Daily Cost"
              << "\n" << string(70, '-') << "\n";
}

void printCarRow(const Car& car) {
    cout << left
              << setw(18) << car.regNo
              << setw(15) << car.carModel
              << setw(10) << car.seats
              << setw(15) << car.gearbox
              << setw(12) << car.dailyRentalCost
              << "\n";
}

void CarController::printCarInfo(Storage &storage) {
    auto cars = storage.get_all<Car>();
    printCarHeader();
    for (const auto& car : cars) {
        printCarRow(car);
    }
}

void CarController::searchCar(Storage &storage) {
    cout << "Search for car by gearbox type (a/m): " << endl ;
    string searchInput;
    cin.ignore();
    getline (cin, searchInput);
    const string searchCondition = searchInput + "%";
    auto whereCondition = sqlite_orm::where(sqlite_orm::like(&Car::gearbox, searchCondition));
    auto cars = storage.get_all<Car>(whereCondition);
    if (cars.empty()) {
        cout << "No cars found" << endl;
        showRentalMenu(storage);
    }
    else {
        printCarHeader();
        for (const auto& car : cars) {
            printCarRow(car);        }
    }
}

void CarController::numberOfCars(Storage &storage) {
    auto carcount = storage.count<Car>();
    cout << "Number of cars: " << carcount << endl;
}