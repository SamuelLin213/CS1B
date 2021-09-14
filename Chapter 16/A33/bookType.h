#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

class bookType
{
  public:
    bookType();
    bookType(string title, string isbn, string author, string publisher,
      string dateAdded, int qtyOnHand, float wholesale, float retail);

    void setTitle(string str);
    void setISBN(string str);
    void setAuthor(string str);
    void setPub(string str);
    void setDateAdded(string str);
    void setQtyOnHand(int amount);
    void setWholesale(float dbl);
    void setRetail(float dbl);

    const string getTitle() const;
    const string getISBN() const;
    const string getAuthor() const;
    const string getPub() const;
    const string getDateAdded() const;
    const int getQtyOnHand() const;
    const float getWholesale() const;
    const float getRetail() const;

    static int getBookCount();
    static void incBookCount();
    static void decBookCount();
    static void resetBookCount();

    void print();
    bool equals(bookType other);

    bool operator<(const bookType& otherBook) const;
    bool operator<=(const bookType& otherBook) const;
    bool operator>(const bookType& otherBook) const;
    bool operator>=(const bookType& otherBook) const;
    bool operator==(const bookType& otherBook) const;
    bool operator!=(const bookType& otherBook) const;
  private:
    string bookTitle;
    string isbn;
    string author;
    string publisher;
    string dateAdded;
    int qtyOnHand;
    float wholesale;
    float retail;
    static int bookCount;
};

#endif
