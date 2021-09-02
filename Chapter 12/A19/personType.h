#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class personType
{
  public:
    void print();
    bool equals(personType other);

    void setFName(string name);
    void setLName(string name);
    void setAddress(string addr);
    void setHeight(double height);
    void setDOB(string date);
    void setGender(char gen);

    string getFName();
    string getLName();
    string getAddress();
    double getHeight();
    string getDOB();
    char getGender();

  private:
    string fName;
    string lName;
    string address;
    double height;
    string DOB;
    char gender;
};

#endif
