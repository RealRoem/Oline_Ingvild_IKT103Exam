//
// Created by oline on 03.05.2025.
//
#include <iostream>
#include "Rental.h"
#include "storage.h"

void showStatisticsMenu() {
    int statisticsMenu;;
    std::cout << "\n Statistics menu: \n";
    std::cout << "1. Total number of customers\n";
    std::cout << "2. Total number of cars\n";
    std::cout << "3. Number of assigned cars\n";
    std::cout << "4. Number of available cars\n";
    std::cout << "Enter your choice: ";
    std::cin >> statisticsMenu;

    switch (statisticsMenu) {
        case 1:
            std::cout << "Total number of customers: ";
            break;
        case 2:
            std::cout << "Total number of cars: ";
            break;
        case 3:
            std::cout << "Number of assigned cars: ";
            break;
        case 4:
            std::cout << "Number of available cars: ";
            break;
        default:
            std::cout << "Invalid choice. Returning to main menu.\n";
    }
}


