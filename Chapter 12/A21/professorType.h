#ifndef PROFESSORTYPE_H
#define PROFESSORTYPE_H

#include "personType.h"
#include <string>
using namespace std;

class professorType: public personType{
  public:
    professorType();
    professorType(string fName, string lName);
    professorType (string fName, string lName, string address, double height,
      string dob, char gender, string employeeID, string department, string degree);

    bool equals(professorType other);
    void print();

    void setEmployeeID(string id);
    void setDepartment(string depart);
    void setDegree(string deg);

    string getEmployeeID();
    string getDepartment();
    string getDegree();
  private:
    string employeeID;
    string department;
    string degree;
};

#endif
