#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "bookType.h"
using namespace std;

class bookType;

const int DB_SIZE = 20;

void cashier(bookType books[]);
void invMenu(bookType books[]);
void reports();

//invmenu signatures
int lookUpBook(bookType books[], int code, string key);
void addBook(bookType books[], int code, int index);
void editBook(bookType books[]);
void deleteBook(bookType books[]);

//reports signatures
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

//misc functions
int isEmpty(bookType books[], int index);
void removeBook(bookType books[], int index);

#endif
