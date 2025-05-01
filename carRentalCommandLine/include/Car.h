#ifndef CAR_H
#define CAR_H
#include <string>

class Car {
public:
    std::string regNo;
    std::string carModel;
    int seats;
    std::string gearbox;
    int dailyRentalCost;

    int customerId;

    static void addCar();
    static void editCar();
    static bool existsCar();
    static void removeCar();
    static void assignCarToCustomer();
    static void unassignCarToCustomer();
};

#endif //CAR_H