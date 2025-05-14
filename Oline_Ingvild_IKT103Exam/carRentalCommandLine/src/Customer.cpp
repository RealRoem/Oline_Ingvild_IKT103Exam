#include "Customer.h"
#include "CustomerController.h"
#include <iostream>
#include "storage.h"
#include <iomanip>

using namespace std;

void CustomerController::addCustomer(Storage &storage) {
    Customer customer = getCustomerInfo(); //henter informasjon om kunden fra brukerinput
    storage.insert (customer); //legger til kunden i databasen
    cout << "Customer added" << endl;

    printCustomerInfo(storage);
}

void CustomerController::editCustomer(Storage &storage) {
    printCustomerInfo(storage);
    int inputId;
    cout << "Enter customer id to edit: " << endl;
    cin >> inputId;
    auto customer = storage.get_pointer<Customer>(inputId); //returnerer en nullptr hvis id ikke finnes, slik at if(customer) blir false
    if(customer) {
        Customer updated = getCustomerInfo();
        updated.customerId = inputId;
        storage.update(updated);
        cout << "Customer edited successfully" << std::endl;
    } else {
        cout << "Customer not found" << endl;
    }

    printCustomerInfo(storage);
}

void CustomerController::deleteCustomer(Storage &storage) {
    printCustomerInfo(storage);
    int inputId;
    cout << "Enter customer id to delete: " << endl;
    cin >> inputId;
    auto customer = storage.get_pointer<Customer>(inputId); //returnerer en nullptr hvis id ikke finnes, slik at if(customer) blir false
    if(customer) {
        storage.remove<Customer>(inputId);
        cout << "Customer deleted successfully" << endl;
    } else {
        cout << "Customer not found" << endl;
    }

    printCustomerInfo(storage);
}
void printCustomerHeader() {
    cout << "\n===================================== Customers =====================================" << std::endl;
    cout << left
              << setw(6)  << "ID"
              << setw(20) << "Name"
              << setw(15) << "Date of birth"
              << setw(30) << "Email"
              << setw(15) << "Phone"
              << "\n" << string(86, '-') << "\n";
}

void printCustomerRow(const Customer &customer) {
    cout << left
              << setw(6)  << customer.customerId
              << setw(20) << customer.customerName
              << setw(15) << customer.dateofBirth
              << setw(30) << customer.mail
              << setw(15) << customer.phonenumber
              << "\n";
}

void CustomerController::searchCustomer(Storage &storage) {
    cout << "Search for customer by name: " << endl ;
    string searchInput;
    cin.ignore();
    getline (cin, searchInput);
    const std::string searchCondition = searchInput + "%";
    auto whereCondition = sqlite_orm::where(sqlite_orm::like(&Customer::customerName, searchCondition));
    auto customers = storage.get_all<Customer>(whereCondition);

    if (customers.empty()) {
        cout << "Customer not found" << endl;
    }
    else {
        printCustomerHeader();
        for (const auto &customer : customers) {
            printCustomerRow(customer);
        }
    }
}


void CustomerController::numberOfCustomers(Storage &storage) {
    auto customercount = storage.count<Customer>();
    cout << "Number of customers: " << customercount << endl;
}

Customer CustomerController::getCustomerInfo() {
    string customerName;
    string dateofBirth;
    string mail;
    string phonenumber;

    cout << "Enter customer name: " << endl;
    cin.ignore();
    getline(std::cin, customerName);
    cout << "Enter customers date of birth: " << endl;
    cin >> dateofBirth;
    cout << "Enter customers mail: " << endl;
    cin >> mail;
    cout << "Enter customers phonenumber: " << endl;
    cin >> phonenumber;

    return Customer{-1, customerName, dateofBirth, mail, phonenumber};
}

void CustomerController::printCustomerInfo(Storage &storage) {
    auto customers = storage.get_all<Customer>();
    for (const auto& [customerId, customerName, dateofBirth, mail, phonenumber] : customers) {
        cout << "---------------------------\n";
        cout << "ID:           " << customerId    << '\n';
        cout << "Name:         " << customerName  << '\n';
        cout << "Birthdate:    " << dateofBirth   << '\n';
        cout << "Email:        " << mail          << '\n';
        cout << "Phone number: " << phonenumber   << '\n';
        cout << "---------------------------\n";
    }

}
