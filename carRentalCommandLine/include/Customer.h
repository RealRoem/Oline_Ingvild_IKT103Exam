#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>


class Customer {
public:
    int customerId;
    std::string customerName;
    std::string dateofBirth;
    std::string mail;
    std::string phonenumber;

    static void addCustomer();
    static void editCustomer();
    static bool existsCustomer();
    static void deleteCustomer();

};

#endif //CUSTOMER_H
