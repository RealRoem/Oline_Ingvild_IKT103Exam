#include "Customer.h"
#include "CustomerController.h"
#include <iostream>
#include "storage.h"



void CustomerController::addCustomer(Storage &storage) {
    Customer customer = getCustomerInfo(); //henter informasjon om kunden fra brukerinput
    storage.insert (customer); //legger til kunden i databasen
    std::cout << "Customer added" << std::endl;

    printCustomerInfo(storage);
}

void CustomerController::editCustomer(Storage &storage) {
    int inputId;
    std::cout << "Enter customer id to edit: " << std::endl;
    std::cin >> inputId;
    auto customer = storage.get_pointer<Customer>(inputId); //returnerer en nullptr hvis id ikke finnes, slik at if(customer) blir false
    if(customer) {
        Customer updated = getCustomerInfo();
        updated.customerId = inputId;
        storage.update(updated);
        std::cout << "Customer edited successfully" << std::endl;
    } else {
        std::cout << "Customer not found" << std::endl;
    }

    printCustomerInfo(storage);
}

void CustomerController::deleteCustomer(Storage &storage) {
    int inputId;
    std::cout << "Enter customer id to delete: " << std::endl;
    std::cin >> inputId;
    auto customer = storage.get_pointer<Customer>(inputId); //returnerer en nullptr hvis id ikke finnes, slik at if(customer) blir false
    if(customer) {
        storage.remove<Customer>(inputId);
        std::cout << "Customer deleted successfully" << std::endl;
    } else {
        std::cout << "Customer not found" << std::endl;
    }

    printCustomerInfo(storage);
}

void CustomerController::searchCustomer(Storage &storage) {
    Customer newCustomer;
    std::cout << "Search for customer by name: " <<std::endl ;
    std::string searchInput;
    std::cin.ignore();
    std::getline (std::cin, searchInput);
    auto whereCondition = sqlite_orm::where(sqlite_orm::like(&Customer::customerName, searchInput));
    auto customers = storage.get_all<Customer>(whereCondition);

    if (customers.empty()) {
        std::cout << "No students found" << std::endl;
    }
    else {
        for (auto &newCustomer : customers) {
            std::cout << "id: " << newCustomer.customerId <<", name: " << newCustomer.customerName << ", date of birth: " << newCustomer.dateofBirth<< ", email: " << newCustomer.mail << ", phone number: "<< newCustomer.phonenumber << std::endl;
        }
    }
}

void CustomerController::numberOfCustomers(Storage &storage) {
    auto customercount = storage.count<Customer>();
    std::cout << "Number of customers: " << customercount << std::endl;
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

void CustomerController::printCustomerInfo(Storage &storage) {
    auto customers = storage.get_all<Customer>();
    for (const auto& [customerId, customerName, dateofBirth, mail, phonenumber] : customers) {
        std::cout << "---------------------------\n";
        std::cout << "ID:           " << customerId    << '\n';
        std::cout << "Name:         " << customerName  << '\n';
        std::cout << "Birthdate:    " << dateofBirth   << '\n';
        std::cout << "Email:        " << mail          << '\n';
        std::cout << "Phone number: " << phonenumber   << '\n';
        std::cout << "---------------------------\n";
    }

}
