#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include "car.h"
#include "storage.h"

class CarController {
  public:
    Storage &m_storage; // Referanse til Storage-objektet

    static void addCar(Storage &storage);
    static void editCar();
    static bool existsCar();
    static void removeCar();
    static void assignCarToCustomer();
    static void unassignCarToCustomer();

    static Car getCarInfo();
};

#endif //CARCONTROLLER_H
