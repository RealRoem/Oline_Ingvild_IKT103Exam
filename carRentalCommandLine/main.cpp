#include <iostream>
#include "Car.h"
#include "Customer.h"
#include "menu.h"




int main()
{
    printMenu();
   // getUserInput();
    switch (getUserInput()) {
        case 1: Car::addCar();
       // case 2: Car::editCar();
    }

    return 0;
}

