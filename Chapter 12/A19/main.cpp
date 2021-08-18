#include "personType.h"
using namespace std;

int main()
{
  int number = 5;
  string tempFirst;
  string tempLast;
  string tempAddr;
  double tempHgt;
  string tempDate;
  char tempGen;

  personType **people = new personType*[number];

  for(int i = 0; i < number; i++)
  {
    cout << "Enter first name of person " << i+1 << ": ";
    cin >> tempFirst;
    cout << "Enter last name of person " << i+1 << ": ";
    cin >> tempLast;
    cout << "Enter address of person " << i+1 << ": ";
    cin.ignore();
    getline(cin, tempAddr);
    cout << "Enter height of person " << i+1 << ": ";
    cin >> tempHgt;
    cout << "Enter date of birth of person " << i+1 << ": ";
    cin >> tempDate;
    cout << "Enter gender of person " << i+1 << ": ";
    cin >> tempGen;

    cout << endl;

    people[i] = new personType;
    people[i]->setFName(tempFirst);
    people[i]->setLName(tempLast);
    people[i]->setAddress(tempAddr);
    people[i]->setHeight(tempHgt);
    people[i]->setDOB(tempDate);
    people[i]->setGender(tempGen);
  }

  cout << endl << "Printing info of each person: " << endl;
  for(int x = 0; x < number; x++)
  {
    cout << "Person " << x+1 << endl;
    people[x]->print();
    cout << endl;
  }

  for(int x = 0; x < number; x++)
  {
    delete people[x];
  }
  delete [] people;
  return 0;
}
