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

    void addCar();
    void editCar();
    void removeCar();
    void assignCarToCustomer();
    void unassignCarToCustomer();
};

#endif //CAR_H