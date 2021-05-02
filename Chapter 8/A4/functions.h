#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

void cashier();
void invMenu();
void bookInfo();
void reports();

//invmenu signatures
void lookUpBook();
void addBook();
void editBook();
void deleteBook();

//reports signatures
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

#endif
