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
  cout << endl;

  personType person2("Bill", "Nye");
  person2.setAddress("456 Science Avenue");
  person2.setHeight(72);
  person2.setDOB("11-27-1955");
  person2.setGender('M');

  person2.print();
  cout << endl;

  personType person3("Edith", "Clarke", "789 MIT road", 63, "02-10-1883", 'F');

  person3.print();

  return 0;
}
