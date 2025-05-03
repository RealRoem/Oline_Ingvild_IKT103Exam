#ifndef STORAGE_H
#define STORAGE_H

#include "sqlite_orm.h"
#include <string>
#include "Car.h"
#include "Customer.h"
#include "Rental.h"


inline auto init_storage(const std::string &filename) {
    using namespace sqlite_orm;
    auto storage = make_storage(filename,
        make_table("car",
                        make_column("regNo", &Car::regNo, primary_key()),
                        make_column("carModel", &Car::carModel),
                        make_column("seats", &Car::seats),
                        make_column("gearbox", &Car::gearbox),
                        make_column("dailyRentalCost", &Car::dailyRentalCost)
                        ),
        make_table("customer",
                        make_column("customerId", &Customer::customerId,primary_key().autoincrement()),
                        make_column("customerName", &Customer::customerName),
                        make_column("dateofBirth", &Customer::dateofBirth),
                        make_column("mail", &Customer::mail),
                        make_column("phonenumber", &Customer::phonenumber)
                        ),
        make_table("rental",
                        make_column("regNo", &Rental::regNo),
                        make_column("customerId", &Rental::customerId),
                        make_column("startTime", &Rental::startTime),
                        make_column("status", &Rental::status),
                        primary_key(&Rental::regNo, &Rental::startTime),
                        foreign_key(&Rental::customerId).references(&Customer::customerId),
                        foreign_key(&Rental::regNo).references(&Car::regNo)
                        ));
    return storage;
}
using Storage = decltype(init_storage(""));


#endif //STORAGE_H
