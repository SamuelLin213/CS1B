#include "personType.h"
#include "studentType.h"
#include "professorType.h"
using namespace std;

int main()
{
  int number;
  string type;
  string tempFirst;
  string tempLast;
  string tempAddr;
  double tempHgt;
  string tempDate;
  char tempGen;

  cout << "Enter the number of people to create: ";
  cin >> number;
  cout << endl;

  personType **people = new personType*[number];

  for(int i = 0; i < number; i++)
  {
    cout << "What type of person to create?(person/student/professor) ";
    cin >> type;

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

    if(type == "person")
    {
      cout << endl;

      people[i] = new personType;
      people[i]->setFName(tempFirst);
      people[i]->setLName(tempLast);
      people[i]->setAddress(tempAddr);
      people[i]->setHeight(tempHgt);
      people[i]->setDOB(tempDate);
      people[i]->setGender(tempGen);
    }
    else if(type == "student")
    {
      string tempId;
      double tempGpa;
      string tempClass;

      cout << "Enter student id: ";
      cin >> tempId;
      cout << "Enter student gpa: ";
      cin >> tempGpa;
      cout << "Enter student class: ";
      cin >> tempClass;

      cout << endl;

      people[i] = new studentType(tempFirst, tempLast, tempGpa, tempClass, tempId);
      people[i]->setAddress(tempAddr);
      people[i]->setHeight(tempHgt);
      people[i]->setDOB(tempDate);
      people[i]->setGender(tempGen);
    }
    else if(type == "professor")
    {
      string tempId;
      string tempDepart;
      string tempDegree;

      cout << "Enter professor id: ";
      cin >> tempId;
      cout << "Enter professor department: ";
      cin >> tempDepart;
      cout << "Enter professor degree: ";
      cin >> tempDegree;

      cout << endl;

      people[i] = new professorType(tempFirst, tempLast, tempAddr, tempHgt, tempDate,
      tempGen, tempId, tempDepart, tempDegree);
    }
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
