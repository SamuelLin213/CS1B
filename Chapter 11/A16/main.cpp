#include "studentType.h"
#include "professorType.h"
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

  studentType student2("James", "Harden", 3.5, "Junior", "456DEF");
  student2.setAddress("789 Stepback road");
  student2.setHeight(77);
  student2.setDOB("08-26-1989");
  student2.setGender('M');

  cout << endl;
  student2.print();

  professorType professor("Bill", "Nye", "123 Science street", 70, "11-27-1955",
  'M', "789HIJ", "Natural Sciences", "MS");

  cout << endl;
  professor.print();

  cout << endl << "Are student1 and student2 equal? " << std::boolalpha
  << student1.equals(student2) << endl;

  return 0;
}
