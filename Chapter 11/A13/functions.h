#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
using namespace std;

const int DB_SIZE = 20;

struct bookType
{
  string bookTitle;
  string isbn;
  string author;
  string publisher;
  string dateAdded;
  int qtyOnHand;
  double wholesale;
  double retail;
};

void cashier(int &bookCount, bookType books[]);
void invMenu(int &bookCount, bookType books[]);
void bookInfo(string isbn, string title, string author, string publisher,
string date, int qty, double wholesale, double retail);
void reports();

//invmenu signatures
int lookUpBook(int &bookCount, bookType books[], int code, string key);
void addBook(int &bookCount, bookType books[], int code, int index);
void editBook(int &bookCount, bookType books[]);
void deleteBook(int &bookCount, bookType books[]);

//reports signatures
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

//set functions
void setTitle(bookType books[], string str, int index);
void setISBN(bookType books[], string str, int index);
void setAuthor(bookType books[], string str, int index);
void setPub(bookType books[], string str, int index);
void setDateAdded(bookType books[], string str, int index);
void setQty(bookType books[], int amount, int index);
void setWholesale(bookType books[], double dbl, int index);
void setRetail(bookType books[], double dbl, int index);
int isEmpty(bookType books[], int index);
void removeBook(bookType books[], int index, int count);

#endif
