#ifndef MENU_H
#define MENU_H
#include "storage.h"

void printMenu();
int getUserInput();
static void showStaticsMenu(Storage &storage);
static void showCarMenu(Storage &storage);
static void showCustomerMenu(Storage &storage);
static void showRentalMenu(Storage &storage);
static void ImportExportMenu(Storage &storage);


#endif //MENU_H
