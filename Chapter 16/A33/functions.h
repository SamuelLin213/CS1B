#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "bookType.h"
#include "orderedLinkedList.h"
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

class bookType;

const int DB_SIZE = 125;

void loadBooks(orderedLinkedList<bookType> &books);
void saveBooks(orderedLinkedList<bookType> &books);

void cashier(orderedLinkedList<bookType> &books);
void invMenu(orderedLinkedList<bookType> &books);
void reports(orderedLinkedList<bookType> &books);

//invmenu signatures
nodeType<bookType>* lookUpBook(orderedLinkedList<bookType> &books, int code, string key);
void addBook(orderedLinkedList<bookType> &books, int code, nodeType<bookType>* index);
void editBook(orderedLinkedList<bookType> &books);
void deleteBook(orderedLinkedList<bookType> &books);

//reports signatures
void repListing(orderedLinkedList<bookType> &books);
void repWholesale(orderedLinkedList<bookType> &books);
void repRetail(orderedLinkedList<bookType> &books);
void repQty(orderedLinkedList<bookType> &books);
void repCost(orderedLinkedList<bookType> &books);
void repAge(orderedLinkedList<bookType> &books);

//misc functions
//void removeBook(orderedLinkedList<bookType> &books, int index);

// template <typename T>
// void sortQty(orderedLinkedList<T> &&&books);
//
// template <typename T>
// void sortCost(orderedLinkedList<T> &&books);
//
// template <typename T>
// void sortAge(orderedLinkedList<T> &books);

#endif
