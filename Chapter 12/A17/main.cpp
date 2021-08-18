#include "personType.h"
using namespace std;

int main()
{
  int number = 0;
  string tempFirst;
  string tempLast;
  string tempAddr;
  double tempHgt;
  string tempDate;
  char tempGen;

  cout << "Enter number of people to create: ";
  cin >> number;

  personType *people = new personType[number];

  cout << endl;
  for(int i = 0; i < number; i++)
  {
    cout << "Enter first name of person " << i+1 << ": ";
    cin >> tempFirst;
    cout << "Enter last name of person " << i+1 << ": ";
    cin >> tempLast;
    cout << "Enter address of person " << i+1 << ": ";
    cin >> tempAddr;
    cout << "Enter height of person " << i+1 << ": ";
    cin >> tempHgt;
    cout << "Enter date of birth of person " << i+1 << ": ";
    cin >> tempDate;
    cout << "Enter gender of person " << i+1 << ": ";
    cin >> tempGen;

    cout << endl;

    people[i].setFName(tempFirst);
    people[i].setLName(tempLast);
    people[i].setAddress(tempAddr);
    people[i].setHeight(tempHgt);
    people[i].setDOB(tempDate);
    people[i].setGender(tempGen);
  }

  cout << endl << "Printing info of each person: " << endl;
  for(int x = 0; x < number; x++)
  {
    cout << "Person " << x+1 << endl;
    people[x].print();
    cout << endl;
  }

  delete [] people;
  return 0;
}
