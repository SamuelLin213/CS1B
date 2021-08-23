#include "personType.h"
#include "professorType.h"
#include "studentType.h"
using namespace std;

int main()
{
  string mother;
  string father;

  personType person;
  studentType student("Bronny", "James", 3.5, "Junior", "123456");
  professorType prof("Lebron", "James", "456 LA Avenue", 80, "12/30/1984", 'M',
  "123456", "Athletics", "BS");

  person.setFName("Savannah");
  person.setLName("James");
  person.setAddress("456 LA Avenue");
  person.setHeight(70);
  person.setDOB("08/27/1986");
  person.setGender('F');

  student.setAddress("123 NBA Avenue");
  student.setHeight(74);
  student.setDOB("10/06/2003");
  student.setGender('M');
  student.setFather(prof);
  student.setMother(person);

  personType person2(person);

  cout << endl << "Printing info of each person: " << endl;
  person.print();
  cout << endl;
  person2.print();
  cout << endl;
  prof.print();
  cout << endl;
  student.print();

  return 0;
}
