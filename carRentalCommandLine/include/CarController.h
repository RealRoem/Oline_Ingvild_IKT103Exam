#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include "car.h"
#include "storage.h"

class CarController {
  public:
    Storage &m_storage; // Referanse til Storage-objektet

    static void addCar(Storage &storage);
    static void editCar(Storage &storage);
    static void removeCar(Storage &storage);
    static void assignCarToCustomer();
    static void unassignCarToCustomer();

    static Car getCarInfo();
    static void printCarInfo();
};

#endif //CARCONTROLLER_H
