#include "professorType.h"

class professorType;

professorType::professorType()
{
  employeeID = "";
  department = "";
  degree = "";
  courses = new courseType[5];
}
professorType::professorType(string fName, string lName)
{
  this->setFName(fName);
  this->setLName(lName);
  professorType();
  courses = new courseType[5];
}
professorType::professorType (string fName, string lName, string address, double height,
  string dob, char gender, string employeeID, string department, string degree)
{
    this->setFName(fName);
    this->setLName(lName);
    this->setAddress(address);
    this->setHeight(height);
    this->setDOB(dob);
    this->setGender(gender);
    this->employeeID = employeeID;
    this->department = department;
    this->degree = degree;
    courses = new courseType[5];
}

bool professorType::equals(professorType other)
{
  if(this->employeeID == other.employeeID)
    return true;
  return false;
}
void professorType::print()
{
  personType::print();
  cout << "Employee ID: " << employeeID << endl;
  cout << "Department: " << department << endl;
  cout << "Degree: " << degree << endl;
}

void professorType::setEmployeeID(string id)
{
  employeeID = id;
}
void professorType::setDepartment(string depart)
{
  department = depart;
}
void professorType::setDegree(string deg)
{
  degree = deg;
}

string professorType::getEmployeeID()
{
  return employeeID;
}
string professorType::getDepartment()
{
  return department;
}
string professorType::getDegree()
{
  return degree;
}
void professorType::assignCourse(courseType *course_)
{
  if(numCrsTaught < 5)
  {
    courses[numCrsTaught] = *course_;
    numCrsTaught++;
  }
}
