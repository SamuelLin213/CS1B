#include "studentType.h"

class studentType;

studentType::studentType()
{
  id = "";
  gpa = 0.0;
  classification = "";
  courses = new courseType[2];
}
studentType::studentType(string fName, string lName)
{
  setFName(fName);
  setLName(lName);
  studentType();
  courses = new courseType[2];
}
studentType::studentType(string fName, string lName, double GPA, string classification, string id)
  :studentType(fName, lName)
{
  gpa = GPA;
  this->classification = classification;
  this->id = id;
  courses = new courseType[2];
}

//setters
void studentType::setGPA(double GPA)
{
  gpa = GPA;
}
void studentType::setID(string id)
{
  this->id = id;
}
void studentType::setClassification(string classification)
{
  this->classification = classification;
}

//getters
double studentType::getGPA()
{
  return gpa;
}
string studentType::getID()
{
  return id;
}
string studentType::getClassification()
{
  return classification;
}

//overridden methods
void studentType::print()
{
  personType::print();
  cout << "Id: " << id << endl;
  cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
  cout << "Classification: " << classification << endl;
}
bool studentType::equals(studentType other)
{
  if(this->id == other.id)
  {
    return true;
  }
  return false;
}
bool studentType::addCourse(courseType *other)
{
  if(numCourses < 2 && other->addStudent(this))
  {
    courses[numCourses] = *other;
    numCourses++;
    return true;
  }
  else
    return false;
}
