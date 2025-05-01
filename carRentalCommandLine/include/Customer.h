#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "storage.h"


class Customer {
public:
    int customerId;
    std::string customerName;
    std::string dateofBirth;
    std::string mail;
    std::string phonenumber;

    static void addCustomer(Storage &storage);
    static void editCustomer();
    static bool existsCustomer();
    static void deleteCustomer();

    static Customer getCustomerInfo();

};

#endif //CUSTOMER_H
