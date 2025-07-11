#include <iostream>
#include "Car.h"
#include "Customer.h"
#include "menu.h"
#include "sqlite_orm.h"
#include "storage.h"
#include <filesystem>

#include "CarController.h"
#include "CustomerController.h"
#include "RentalController.h"

namespace fs = std::filesystem;

int main()
{
   fs::remove("carRental.sqlite");

  auto storage = init_storage("carRental.sqlite");
  storage.sync_schema();

  while (true) {
    printMenu();

    switch (getUserInput()) {
        case 1: showCarMenu(storage);
       break;
        case 2: showCustomerMenu(storage);
       break;
      case 3: showRentalMenu(storage);
        break;
      case 4: showAllStatistics(storage);
          break;
      case 5: ImportExportMenu(storage);
          break;
        case 6: return 0;
        default: std::cout << "Invalid choice";
    }
  }
    return 0;
}
