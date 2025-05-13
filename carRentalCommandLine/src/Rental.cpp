#include "Rental.h"
#include <iostream>
#include <iomanip>
#include <set>
#include <ctime>
#include <chrono>
#include <sstream>
#include "RentalController.h"
#include "CustomerController.h"
#include "CarController.h"

using namespace std;

void RentalController::assignCarToCustomer(Storage &storage) {
    cout << "\n=== All Cars in Database ===" << endl;
    CarController::printCarInfo(storage);

    cout << "\n=== Available Cars for Rental ===" << endl;
    auto allCars = storage.get_all<Car>();
    auto activeRentals = storage.get_all<Rental>(sqlite_orm::where(sqlite_orm::c(&Rental::status) == true));

    set<string> rentedCars;
    for (const auto& rental : activeRentals) {
        rentedCars.insert(rental.regNo);
    }

    int availableCount = 0;
    bool headerPrinted = false;

    for (const auto& car : allCars) {
        if (rentedCars.find(car.regNo) == rentedCars.end()) {
            if (!headerPrinted) {
                cout << "\n================================ Available Cars ================================" << endl;
                cout << left
                     << setw(18) << "Reg. Number"
                     << setw(15) << "Model"
                     << setw(10) << "Seats"
                     << setw(15) << "Gearbox"
                     << setw(12) << "Daily Cost"
                     << "\n" << string(70, '-') << "\n";
                headerPrinted = true;
            }
            cout << left
                 << setw(18) << car.regNo
                 << setw(15) << car.carModel
                 << setw(10) << car.seats
                 << setw(15) << car.gearbox
                 << setw(12) << car.dailyRentalCost
                 << "\n";
            availableCount++;
        }
    }

    if (availableCount == 0) {
        cout << "No cars available for rental at the moment." << endl;
        return;
    }

    cout << "\n=== Customers ===" << endl;
    CustomerController::printCustomerInfo(storage);

    Rental rental = getRentalInfo(storage);

    cout << "\nTrying to insert rental:" << endl;
    cout << "Customer ID: " << rental.customerId << endl;
    cout << "Car RegNo: " << rental.regNo << endl;
    cout << "Start Time: " << rental.startTime << endl;
    cout << "Status: " << rental.status << endl;

    auto existingRentals = storage.get_all<Rental>(
            sqlite_orm::where(sqlite_orm::c(&Rental::regNo) == rental.regNo
                              && sqlite_orm::c(&Rental::status) == true)
    );

    if (!existingRentals.empty()) {
        cout << "Error: This car is already rented!" << endl;
        return;
    }

    storage.insert(rental);
    cout << "Rental added successfully!" << endl;
}

void RentalController::unassignCarToCustomer(Storage &storage) {
    cout << "\n=== Active Rentals ===" << endl;
    auto activeRentals = storage.get_all<Rental>(sqlite_orm::where(sqlite_orm::c(&Rental::status) == true));

    if (activeRentals.empty()) {
        cout << "No active rentals to unassign." << endl;
        return;
    }

    cout << "\n================================ Active Rentals ================================" << endl;
    cout << left
         << setw(12) << "Reg. Number"
         << setw(18) << "Car Model"
         << setw(18) << "Customer"
         << setw(10) << "Cust. ID"
         << setw(20) << "Start Time"
         << "\n" << string(80, '-') << "\n";

    for (const auto& rental : activeRentals) {
        auto customer = storage.get<Customer>(rental.customerId);
        auto car = storage.get<Car>(rental.regNo);
        cout << left
             << setw(12) << rental.regNo
             << setw(18) << car.carModel
             << setw(18) << customer.customerName
             << setw(10) << rental.customerId
             << setw(20) << rental.startTime
             << "\n";
    }

    string regNo;
    string startTime;

    cout << "\nEnter car registration number to unassign: ";
    cin >> regNo;
    cout << "Enter rental start time: ";
    cin.ignore();
    getline(cin, startTime);

    // Get the specific rental
    auto rental = storage.get<Rental>(regNo, startTime);

    if (!rental.status) {
        cout << "This rental is already completed." << endl;
        return;
    }

    rental.status = false;
    storage.update(rental);

    cout << "Rental ended successfully for customer ID " << rental.customerId
         << " with car " << rental.regNo << endl;
}

void RentalController::activeRentals(Storage &storage) {
    auto activeRental = storage.count<Rental>(sqlite_orm::where(sqlite_orm::c(&Rental::status) == true));
    cout << "Number of active rentals: " << activeRental << endl;

    if (activeRental > 0) {
        cout << "\nActive Rental Details:" << endl;
        auto rentals = storage.get_all<Rental>(sqlite_orm::where(sqlite_orm::c(&Rental::status) == true));
        for (const auto& rental : rentals) {
            auto customer = storage.get<Customer>(rental.customerId);
            auto car = storage.get<Car>(rental.regNo);
            cout << "- Car: " << car.carModel << " (" << rental.regNo << ")"
                 << ", Customer: " << customer.customerName
                 << ", Started: " << rental.startTime << endl;
        }
    }

    cout << "\n=== ALL Rentals in Database (for debugging) ===" << endl;
    auto allRentals = storage.get_all<Rental>();
    for (const auto& rental : allRentals) {
        cout << "RegNo: " << rental.regNo
             << ", CustomerID: " << rental.customerId
             << ", StartTime: " << rental.startTime
             << ", Status: " << (rental.status ? "ACTIVE" : "COMPLETED") << endl;
    }
}

void RentalController::completedRentals(Storage &storage) {
    auto completedRental = storage.count<Rental>(sqlite_orm::where(sqlite_orm::c(&Rental::status) == false));
    cout << "Number of completed rentals: " << completedRental << endl;
}

Rental RentalController::getRentalInfo(Storage &storage) {
    int customerId;
    string regNo;

    cout << "\nEnter customer ID to rental: ";
    cin >> customerId;

    cout << "Enter registration number to rental: ";
    cin >> regNo;

    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);
    auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    ss << "." << setfill('0') << setw(3) << ms.count();
    string startTime = ss.str();

    cout << "Start time set to: " << startTime << endl;

    return Rental{customerId, regNo, startTime, true};
}