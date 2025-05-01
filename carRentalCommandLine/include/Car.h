#ifndef CAR_H
#define CAR_H
#include <string>
#include "storage.h"


class Car {
public:
    std::string regNo;
    std::string carModel;
    int seats;
    std::string gearbox;
    int dailyRentalCost;
    int customerId;

    static void addCar(Storage &storage);
    static void editCar();
    static bool existsCar();
    static void removeCar();
    static void assignCarToCustomer();
    static void unassignCarToCustomer();
    static int numberOfCars();

    static int activeRentals();
    static int completedRentals();

    static Car getCarInfo();

};

#endif //CAR_H