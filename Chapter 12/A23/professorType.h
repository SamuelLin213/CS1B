#ifndef PROFESSORTYPE_H
#define PROFESSORTYPE_H

#include "personType.h"
#include "courseType.h"
#include <string>
using namespace std;

class courseType;

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

    bool assignCourse(courseType *course_);
  private:
    string employeeID;
    string department;
    string degree;
    int numCrsTaught {0};
    int maxCourse {5};

    courseType *courses;
};

#endif
