#include "professorType.h"

class professorType;

professorType::professorType()
{
  employeeID = "";
  department = "";
  degree = "";
  courses = new courseType[maxCourse];
}
professorType::professorType(string fName, string lName)
{
  this->setFName(fName);
  this->setLName(lName);
  professorType();
  courses = new courseType[maxCourse];
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
    courses = new courseType[maxCourse];
}

bool professorType::equals(professorType other)
{
  if(this->employeeID == other.employeeID)
    return true;
  return false;
}
void professorType::print()
{

  cout << setw(90) << "" << left << setw(9) << "ID" << setw(20) << "Department" << setw(25) << "Degree" << setw(11) << "Course Load" << endl;

  personType::print();

  cout << setw(9) << employeeID << setw(20) << department << setw(25) << degree << setw(11) << numCrsTaught << endl;

  if(numCrsTaught > 0)
  {
    cout << endl << setw(90) << "" << setw(6) << "ID" << setw(12) << "Course Name" << setw(21) << "Title" << setw(5) << "Days"
    << setw(20) << "Time" << setw(4) << "Cap" << setw(5) << "Size" << setw(6) << "Status" << endl;
    for(int i = 0; i < numCrsTaught; i++)
    {
      cout << setw(90) << "" << setw(6) << courses[i].getSectionId() << setw(12) << courses[i].getCourse() << setw(21) << courses[i].getTitle() 
      << setw(5) << courses[i].getDays() << setw(20) << courses[i].getTime() << setw(4) << courses[i].getCap() << setw(5) << courses[i].getEnrolled()
      << setw(6) << courses[i].getStatus() << endl;

    }
    cout << endl;
  }
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
bool professorType::assignCourse(courseType *course_)
{
  if(numCrsTaught < maxCourse)
  {
    courses[numCrsTaught] = *course_;
    numCrsTaught++;
    return true;
  }
  return false;
}
