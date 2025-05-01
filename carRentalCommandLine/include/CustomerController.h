#ifndef CUSTOMERCONTROLLER_H
#define CUSTOMERCONTROLLER_H

#include "Customer.h"
#include "storage.h"

class CustomerController {
    public:
    Storage &m_storage; // Referanse til Storage-objektet

    static void addCustomer(Storage &storage);
    static void editCustomer();
    static bool existsCustomer();
    static void deleteCustomer();

    static Customer getCustomerInfo();
};


#endif //CUSTOMERCONTROLLER_H
