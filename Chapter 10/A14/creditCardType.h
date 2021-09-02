#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class creditCardType
{
  public:
    creditCardType();
    creditCardType(string num, string name, string date);

    static int getCount();
    static float getLimit();
    static float getBalance();

    void setCardNum(string num);
    void setName(string str);
    void setExpiration(string date);
    void setCard(string num, string str, string date);

    string getCardNum();
    string getName();
    string getExpiration();

    void print();
    bool equals(creditCardType other);
    void purchase(float amount);
  private:
    string cardNumber;
    string name;
    string expirationDate;

    static int count;
    static double creditLimit;
    static double balance;
};

#endif
