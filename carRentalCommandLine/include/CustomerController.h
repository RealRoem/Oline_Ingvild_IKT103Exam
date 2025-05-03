#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H

#include "Customer.h"
#include "storage.h"

class CustomerController {
    public:
    Storage &m_storage; // Referanse til Storage-objektet

    static void addCustomer(Storage &storage);
    static void editCustomer(Storage &storage);
    static void deleteCustomer(Storage &storage);

    static void searchCustomer(Storage &storage);
    static void numberOfCustomers(Storage &storage);

    static Customer getCustomerInfo();
    static void printCustomerInfo(Storage &storage);
};


#endif //CUSTOMERCONTROLLER_H
