#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
using namespace std;

const int DB_SIZE = 20;

void cashier();
void invMenu(int &bookCount, string titles[], string isbns[], string authors[],
string publishers[], string dates[], int quantities[], double wholesales[], double retails[]);
void bookInfo(string isbn, string title, string author, string publisher,
string date, int qty, double wholesale, double retail);
void reports();

//invmenu signatures
void lookUpBook(int &bookCount, string titles[], string isbns[], string authors[],
string publishers[], string dates[], int quantities[], double wholesales[], double retails[]);
void addBook(int &bookCount, string titles[], string isbns[], string authors[],
string publishers[], string dates[], int quantities[], double wholesales[], double retails[]);
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
