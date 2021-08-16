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

//set functions
void setTitle(bookType books[], string str, int index)
{
  books[index].bookTitle = str;
}
void setISBN(bookType books[], string str, int index)
{
  books[index].isbn = str;
}
void setAuthor(bookType books[], string str, int index)
{
  books[index].author = str;
}
void setPub(bookType books[], string str, int index)
{
  books[index].publisher = str;
}
void setDateAdded(bookType books[], string str, int index)
{
  books[index].dateAdded = str;
}
void setQty(bookType books[], string str, int index)
{
  books[index].qtyOnHand = str;
}
void setWholesale(bookType books[], double dbl, int index)
{
  books[index].wholesale = dbl;
}
void setRetail(bookType books[], double dbl, int index)
{
  books[index].retail = dbl;
}
int isEmpty(bookType books[], int index)
{
  if(books[index].bookTitle.at(0) == '\0')
  {
    return 1;
  }
  return 0;
}
void removeBook(bookType books[], int index)
{
  books[index].bookTitle = '\0';
}

#endif
