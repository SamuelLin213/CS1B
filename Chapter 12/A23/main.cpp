#include "studentType.h"
#include "professorType.h"
#include "personType.h"
#include "courseType.h"
#include "collegeType.h"
#include <vector>
#include <string>
using namespace std;

string collegeType::name = "";
int collegeType::censusNumber = 0;

int main()
{
  int numCourses = 0;
  int numPpl = 0;
  int numProf = 0;
  int numStudent = 0;
  int choice = 0;
  vector<courseType*> courses;
  vector<personType*> people;

  while(choice != 8)
  {
    cout << "\033[2J\033[1;1H";

    cout << "Number of courses: " << numCourses << endl;
    cout << "Number of people: " << numPpl << endl;
    cout << "---Professors: " << numProf << endl;
    cout << "---Students: " << numStudent << endl;
    cout << endl << "<1> Create new course" << endl;
    cout << "<2> Create new person" << endl;
    cout << "<3> Enroll student" << endl;
    cout << "<4> Assign instructor" << endl;
    cout << "<5> Print all people" << endl;
    cout << "<6> Print all courses" << endl;
    cout << "<7> Print census" << endl;
    cout << "<8> Quit" << endl << endl;

    cout << "Choice (1-8): ";
    cin >> choice;

    if(choice < 1 || choice > 8)
    {
      continue;
    }

    string tempSectionId;
    string tempCourse;
    string tempTitle;
    string tempDays;
    string tempTime;
    string tempRoom;
    int tempCap;

    switch(choice)
    {
      case 1:
        cout << "\033[2J\033[1;1H";
        cout << "Creating new course" << endl << endl;

        cout << "Enter section id: ";
        cin >> tempSectionId;
        cout << "Enter course: ";
        cin.ignore();
        getline(cin, tempCourse);
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, tempTitle);
        cout << "Enter days: ";
        cin >> tempDays;
        cout << "Enter time: ";
        cin.ignore();
        getline(cin, tempTime);
        cout << "Enter room: ";
        cin.ignore();
        getline(cin, tempRoom);
        cout << "Enter enrollment cap: ";
        cin >> tempCap;

        courses.push_back(new courseType(tempSectionId, tempCourse, tempTitle,
          tempDays, tempTime, tempRoom, tempCap));
        numCourses++;
        break;
      case 2:
        int choice = 0;

        while(choice < 1 || choice > 3)
        {
          cout << "\033[2J\033[1;1H";
          cout << "Creating new person" << endl << endl;

          cout << "<1> Person" << endl;
          cout << "<2> Student" << endl;
          cout << "<3> Professor" << endl << endl;

          cout << "Choice (1-3): ";
          cin >> choice;
        }

        string tempFirst;
        string tempLast;
        string tempAddr;
        double tempHeight;
        string tempDate;
        char tempGender;
        string tempEmployeeId;
        string tempDepart;
        string tempDegree;
        string tempId;
        double tempGpa;
        string tempClass;

        switch(choice)
        {
          case 1:
            cout << "\033[2J\033[1;1H";
            cout << "Creating new person" << endl << endl;

            cout << "Enter first name: ";
            cin >> tempFirst;
            cout << "Enter last name: ";
            cin >> tempLast;
            cout << "Enter address: ";
            cin.ignore();
            getline(cin, tempAddr);
            cout << "Enter height: ";
            cin >> tempHeight;
            cout << "Enter date of birth(mm/dd/yyyy): ";
            cin >> tempDate;
            cout << "Enter gender(m/f): ";
            cin >> tempGender;

            people.push_back(new personType);
            people[numPpl]->setFName(tempFirst);
            people[numPpl]->setLName(tempLast);
            people[numPpl]->setAddress(tempAddr);
            people[numPpl]->setHeight(tempHeight);
            people[numPpl]->setDOB(tempDate);
            people[numPpl]->setGender(tempGender);
            numPpl++;
            break;
          case 2:
            cout << "\033[2J\033[1;1H";
            cout << "Creating new student" << endl << endl;

            cout << "Enter first name: ";
            cin >> tempFirst;
            cout << "Enter last name: ";
            cin >> tempLast;
            cout << "Enter address: ";
            cin.ignore();
            getline(cin, tempAddr);
            cout << "Enter height: ";
            cin >> tempHeight;
            cout << "Enter date of birth(mm/dd/yyyy): ";
            cin >> tempDate;
            cout << "Enter gender(m/f): ";
            cin >> tempGender;
            cout << "Enter student ID: ";
            cin >> tempId;
            cout << "Enter GPA: ";
            cin >> tempGpa;
            cout << "Enter class: ";
            cin >> tempClass;

            people.push_back(new studentType(tempFirst, tempLast, tempGpa, tempClass, tempId));
            people[numPpl]->setAddress(tempAddr);
            people[numPpl]->setHeight(tempHeight);
            people[numPpl]->setDOB(tempDate);
            people[numPpl]->setGender(tempGender);
            numPpl++;
            numStudent++;

            break;
          case 3:
            cout << "\033[2J\033[1;1H";
            cout << "Creating new professor" << endl << endl;

            cout << "Enter first name: ";
            cin >> tempFirst;
            cout << "Enter last name: ";
            cin >> tempLast;
            cout << "Enter address: ";
            cin.ignore();
            getline(cin, tempAddr);
            cout << "Enter height: ";
            cin >> tempHeight;
            cout << "Enter date of birth(mm/dd/yyyy): ";
            cin >> tempDate;
            cout << "Enter gender(m/f): ";
            cin >> tempGender;
            cout << "Enter employee ID: ";
            cin >> tempEmployeeId;
            cout << "Enter department: ";
            cin >> tempDepart;
            cout << "Enter degree: ";
            cin >> tempDegree;

            people.push_back(new professorType(tempFirst, tempLast, tempAddr,
              tempHeight, tempDate, tempGender, tempEmployeeId, tempDepart, tempDegree));
            numPpl++;
            numProf++;

            break;
        }
        break;
    }
  }

  return 0;
}
