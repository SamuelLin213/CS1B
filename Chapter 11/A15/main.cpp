#include "studentType.h"
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

  studentType student1("Jeremy", "Lin", 4.0, "Senior", "123ABC");
  student1.setAddress("456 NBA Lane");
  student1.setHeight(75);
  student1.setDOB("08-23-1988");
  student1.setGender('M');

  cout << endl;
  student1.print();

  return 0;
}
