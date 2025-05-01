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

    static void addCustomer();
    static void editCustomer();
    static void deleteCustomer();

    Customer 

};

#endif //CUSTOMER_H
