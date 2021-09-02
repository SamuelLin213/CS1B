#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class personType
{
  public:
    personType();

    //copy constructor
    personType(const personType& other);

    virtual void print();
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

    personType* getMother();
    personType* getFather();

    void setMother(personType mother_);
    void setFather(personType father_);

  private:
    string fName;
    string lName;
    string address;
    double height;
    string DOB;
    char gender;

    personType* mother {nullptr};
    personType* father {nullptr};
};

#endif
