#include "personType.h"
using namespace std;

int main()
{
  personType person1;
  person1.setFName("Sam");
  person1.setLName("Lin");
  person1.setAddress("123 Sesame Street");
  person1.setHeight(70);
  person1.setDOB("04-20-1969");
  person1.setGender('M');

  person1.print();

  return 0;
}
