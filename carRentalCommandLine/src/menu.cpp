#include "menu.h"
#include <iostream>

void printMenu(){
    std::cout << "1. Add car" << std::endl;
    std::cout << "2. Edit car" << std::endl;
    std::cout << "3. Remove car" << std::endl;
    std::cout << std::endl;
    std::cout << "4. Add customer" << std::endl;
    std::cout << "5. Edit customer" << std::endl;
    std::cout << "6. Remove customer" << std::endl;
    std::cout << std::endl;
    std::cout << "7. Assign car to customer" << std::endl;
    std::cout << "8. Unassign car to customer" << std::endl;
    std::cout << "9. Show statistics" << std::endl;
    std::cout << "10. Export all information to a file" << std::endl;
    std::cout << "11. Import all information from a file" << std::endl;
    std::cout << std::endl;
    std::cout << "12. Exit" << std::endl;
    std::cout << std::endl;
  };

  int getUserInput(){
      std::cout << "Enter your choice: " << std::endl ;
      int userChoice = 0;
      std::cin >> userChoice;
      return userChoice;
  }