#ifndef MENU_H
#define MENU_H
#include "storage.h"

void printMenu();
int getUserInput();
void showAllStatistics(Storage &storage);
void showCarMenu(Storage &storage);
void showCustomerMenu(Storage &storage);
void showRentalMenu(Storage &storage);
void ImportExportMenu(Storage &storage);


#endif //MENU_H
