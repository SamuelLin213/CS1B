#include "studentType.h"

class studentType;

studentType::studentType()
{
  id = "";
  gpa = 0.0;
  classification = "";
  courses = new courseType[2];
  numCourses = 0;
}
studentType::studentType(string fName, string lName)
{
  setFName(fName);
  setLName(lName);
  studentType();
  courses = new courseType[2];
  numCourses = 0;
}
studentType::studentType(string fName, string lName, double GPA, string classification, string id)
  :studentType(fName, lName)
{
  gpa = GPA;
  this->classification = classification;
  this->id = id;
  courses = new courseType[2];
  numCourses = 0;
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
int studentType::getNumCourses()
{
  return numCourses;
}

//overridden methods
void studentType::print()
{
  cout << setw(90) << "" << left << setw(9) << "ID" << setw(15) << "Classification" << setw(7) << "GPA" << setw(11) << "Course Load" << endl;

  personType::print();
  
  cout << left << setw(9) << id << setw(15) << classification << setw(7) << gpa << setw(11) << getNumCourses() << endl;

  if(numCourses > 0)
  {
    cout << endl << setw(90) << "" << setw(6) << "ID" << setw(12) << "Course Name" << setw(21) << "Title" << setw(5) << "Days"
    << setw(20) << "Time" << setw(4) << "Cap" << setw(5) << "Size" << setw(6) << "Status" << endl;
    for(int i = 0; i < numCourses; i++)
    {
      cout << setw(90) << "" << setw(6) << courses[i].getSectionId() << setw(12) << courses[i].getCourse() << setw(21) << courses[i].getTitle() 
      << setw(5) << courses[i].getDays() << setw(20) << courses[i].getTime() << setw(4) << courses[i].getCap() << setw(5) << courses[i].getEnrolled()
      << setw(6) << courses[i].getStatus() << endl;

    }
    cout << endl;
  }
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
