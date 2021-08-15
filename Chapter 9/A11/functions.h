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

void cashier();
void invMenu(int &bookCount, bookType books[]);
void bookInfo(string isbn, string title, string author, string publisher,
string date, int qty, double wholesale, double retail);
void reports();

//invmenu signatures
void lookUpBook(int &bookCount, bookType books[], int code);
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

#endif
