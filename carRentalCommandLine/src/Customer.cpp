#include "Customer.h"
#include "CustomerController.h"
#include <iostream>
#include "storage.h"


void CustomerController::addCustomer(Storage &storage) {
    Customer customer = getCustomerInfo(); //henter informasjon om kunden fra brukerinput
    storage.insert (customer); //legger til kunden i databasen
    std::cout << "Customer added" << std::endl;
}

Customer CustomerController::getCustomerInfo() {
    std::string customerName;
    std::string dateofBirth;
    std::string mail;
    std::string phonenumber;

    std::cout << "Enter customer name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, customerName);
    std::cout << "Enter customers date of birth: " << std::endl;
    std::cin >> dateofBirth;
    std::cout << "Enter customers mail: " << std::endl;
    std::cin >> mail;
    std::cout << "Enter customers phonenumber: " << std::endl;
    std::cin >> phonenumber;

    return Customer{-1, customerName, dateofBirth, mail, phonenumber};
}

void CustomerController::editCustomer(Storage &storage) {
    int inputId;
    std::cout << "Enter customer id to edit: " << std::endl;
    std::cin >> inputId;
    auto customer = storage.get_pointer<Customer>(inputId); //returnerer en nullptr hvis id ikke finnes, slik at if(customer) blir false
    if(customer) {
        Customer customer = getCustomerInfo();
        storage.update (customer);
        std::cout << "Customer edited successfully" << std::endl;
    } else {
        std::cout << "Customer not found" << std::endl;
    }
}

void CustomerController::deleteCustomer(Storage &storage) {
    int inputId;
    std::cout << "Enter customer id to delete: " << std::endl;
    std::cin >> inputId;
    auto customer = storage.get_pointer<Customer>(inputId);
    if(customer) {
        storage.remove<Customer>(inputId);
        std::cout << "Customer deleted successfully" << std::endl;
    } else {
        std::cout << "Customer not found" << std::endl;
    }
}


