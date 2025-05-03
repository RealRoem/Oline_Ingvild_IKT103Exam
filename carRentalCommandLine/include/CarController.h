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

    static void searchCar(Storage &storage);
    static void numberOfCars(Storage &storage);

    static Car getCarInfo();
    static void printCarInfo(Storage &storage);
};

#endif //CARCONTROLLER_H
