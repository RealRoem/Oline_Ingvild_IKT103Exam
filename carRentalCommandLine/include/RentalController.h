#ifndef RENTALCONTROLLER_H
#define RENTALCONTROLLER_H
#include "Rental.h"
#include "storage.h"

class RentalController {
public:
    static void assignCarToCustomer(Storage &storage);
    static void unassignCarToCustomer(Storage &storage);

    static void activeRentals(Storage &storage);
    static void completedRentals(Storage &storage);

    static Rental getRentalInfo(Storage &storage);
};
#endif //RENTALCONTROLLER_H
