#include <iostream>
#include "Car.h"
#include "Customer.h"
#include "menu.h"
#include "sqlite_orm.h"


int main()
{
    printMenu();
   // getUserInput();
    switch (getUserInput()) {
        case 1: Car::addCar();
        break;
       // case 2: Car::editCar();

        default:
            std::cout << "Invalid Choice" << std::endl;
        break;
    }

    return 0;
}

