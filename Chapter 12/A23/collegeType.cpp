#include "collegeType.h"

class collegeType;

void collegeType::incrementCensus()
{
  censusNumber++;
}
void collegeType::setName(string name_)
{
  name = name_;
}
string collegeType::getName()
{
  return name;
}
int collegeType::getCensusNumber()
{
  return censusNumber;
}
void collegeType::print()
{
  cout << "College name: " << name << endl;
  cout << "Census number: " << censusNumber << endl;
}
