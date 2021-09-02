#include "personType.h"

class personType;

personType::personType()
{
  
}

personType::personType(const personType& other)
{
  fName = other.fName;
  lName = other.lName;
  address = other.address;
  height = other.height;
  DOB = other.DOB;
  gender = other.gender;

  mother = other.mother;
  father = other.father;
}

void personType::print()
{
  cout << left << setw(10) << fName << setw(15) << lName << setw(40) << address << setw(7) << height 
  << setw(11) << DOB << setw(7) << gender;
}
bool personType::equals(personType other)
{
  if( (this->fName == other.fName) &&
      (this->lName == other.lName) &&
      (this->address == other.address) &&
      (this->height == other.height) &&
      (this->DOB == other.DOB) &&
      (this->gender == other.gender))
      {
        return true;
      }
  return false;
}
void personType::setFName(string name)
{
  fName = name;
}
void personType::setLName(string name)
{
  lName = name;
}
void personType::setAddress(string addr)
{
  address = addr;
}
void personType::setHeight(double height)
{
  this->height = height;
}
void personType::setDOB(string date)
{
  DOB = date;
}
void personType::setGender(char gen)
{
  gender = gen;
}

string personType::getFName()
{
  return fName;
}
string personType::getLName()
{
  return lName;
}
string personType::getAddress()
{
  return address;
}
double personType::getHeight()
{
  return height;
}
string personType::getDOB()
{
  return DOB;
}
char personType::getGender()
{
  return gender;
}
personType* personType::getMother()
{
  return mother;
}
personType* personType::getFather()
{
  return father;
}

void personType::setMother(personType mother_)
{
  this->mother = &mother_;
}
void personType::setFather(personType father_)
{
  this->father = &father_;
}
