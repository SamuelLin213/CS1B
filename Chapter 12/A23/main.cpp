#include "studentType.h"
#include "professorType.h"
#include "personType.h"
#include "courseType.h"
#include "collegeType.h"
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

string collegeType::name = "Saddleback College";
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

    switch(choice)
    {
      case 1:
        {
          string tempSectionId;
          string tempCourse;
          string tempTitle;
          string tempDays;
          string tempTime;
          string tempRoom;
          int tempCap;
        
          cout << "\033[2J\033[1;1H";
          cout << "Creating new course" << endl << endl;

          cout << "Enter section id: ";
          cin >> tempSectionId;
          cout << "Enter course: ";
          cin.ignore();
          getline(cin, tempCourse);
          cout << "Enter title: ";
          getline(cin, tempTitle);
          cout << "Enter days: ";
          cin >> tempDays;
          cout << "Enter time: ";
          cin.ignore();
          getline(cin, tempTime);
          cout << "Enter room: ";
          // cin.ignore();
          getline(cin, tempRoom);
          cout << "Enter enrollment cap: ";
          cin >> tempCap;

          courses.push_back(new courseType(tempSectionId, tempCourse, tempTitle,
            tempDays, tempTime, tempRoom, tempCap));
          numCourses++;

        }
        break;
      case 2:
        {
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
        
          int personChoice = 0;

          while(personChoice < 1 || personChoice > 3)
          {
            cout << "\033[2J\033[1;1H";
            cout << "Creating new person" << endl << endl;

            cout << "<1> Person" << endl;
            cout << "<2> Student" << endl;
            cout << "<3> Professor" << endl << endl;

            cout << "Choice (1-3): ";
            cin >> personChoice;
          }

          switch(personChoice)
          {
            case 1:
              cout << "\033[2J\033[1;1H";
              cout << "Creating new person" << endl << endl;

              cout << "Enter first name: ";
              cin >> tempFirst;
              cout << "Enter last name: ";
              cin.ignore();
              getline(cin, tempLast);
              cout << "Enter address: ";
              // cin.ignore();
              getline(cin, tempAddr);
              cout << "Enter date of birth(dd/mm/yyyy): ";
              cin >> tempDate;
              cout << "Enter height: ";
              cin >> tempHeight;
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
              cin.ignore();
              getline(cin, tempLast);
              cout << "Enter address: ";
              // cin.ignore();
              getline(cin, tempAddr);
              cout << "Enter date of birth(dd/mm/yyyy): ";
              cin >> tempDate;
              cout << "Enter height: ";
              cin >> tempHeight;              
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
              cin.ignore();
              getline(cin, tempLast);
              cout << "Enter address: ";
              // cin.ignore();
              getline(cin, tempAddr);
              cout << "Enter date of birth(dd/mm/yyyy): ";
              cin >> tempDate;
              cout << "Enter height: ";
              cin >> tempHeight;
              cout << "Enter gender(m/f): ";
              cin >> tempGender;
              cout << "Enter employee ID: ";
              cin >> tempEmployeeId;
              cout << "Enter department: ";
              cin.ignore(); 
              getline(cin, tempDepart);
              cout << "Enter degree: ";
              //cin.ignore();
              getline(cin, tempDegree);
              
              
              people.push_back(new professorType(tempFirst, tempLast, tempAddr,
                tempHeight, tempDate, tempGender, tempEmployeeId, tempDepart, tempDegree));
              numPpl++;
              numProf++;

              break;
          }
        }
        break;
      case 3:
        {
          ENROLL:bool found1 = false;
          bool found2 = false;
          int courseIndex;
          int studentIndex;
          char again = 'n';
          string tempId;
          string tempCourse;

          cout << "\033[2J\033[1;1H";
          cout << "Enrolling student in course: " << endl << endl;
          cout << "Enter student id: ";
          cin >> tempId;
          cout << "Enter course id: ";
          cin >> tempCourse;

          for(int i = 0; i < (int)courses.size(); i++)
          {
            if(courses[i]->getSectionId() == tempCourse)
            {
              courseIndex = i;
              found1 = true;
              break;
            }
          }
          for(int i = 0; i < (int)people.size(); i++)
          {
            studentType* tempStudent = dynamic_cast<studentType*>(people[i]);
            if(tempStudent != nullptr)
            {
              if(tempStudent->getID() == tempId)
              {
                studentIndex = i;
                found2 = true;
                break;
              }
            }            
          }
          if(!found1)
          {
            cout << endl << "Course not found. Try again? ";
            cin >> again;
            if(toupper(again) == 'Y')
            {
              goto ENROLL;
            }
            else
            {
              break;
            }
          }
          else if(!found2)
          {
            cout << endl << "Student not found. Try again? ";
            cin >> again;
            if(toupper(again) == 'Y')
            {
              goto ENROLL;
            }
            else
            {
              break;
            }
          }
          else
          {
            if(!courses[courseIndex]->getOpen())
            {
              cout << endl << "Error: class full.";
              cin.ignore();
              cin.get();
            }
            else
            {
              dynamic_cast<studentType*>(people[studentIndex])->addCourse(courses[courseIndex]);
              cout << endl << "Success: student enrolled in course.";

              cin.ignore();
              cin.get();
            }
          }
        }
        break;
      case 4:
        {
          ASSIGN:bool found1 = false;
          bool found2 = false;
          int courseIndex;
          int profIndex;
          char again = 'n';
          string tempId;
          string tempCourse;

          cout << "\033[2J\033[1;1H";
          cout << "Assigning professor to course: " << endl << endl;
          cout << "Enter professor id: ";
          cin >> tempId;
          cout << "Enter course id: ";
          cin >> tempCourse;

          for(int i = 0; i < (int)courses.size(); i++)
          {
            if(courses[i]->getSectionId() == tempCourse)
            {
              courseIndex = i;
              found1 = true;
              break;
            }
          }
          for(int i = 0; i < (int)people.size(); i++)
          {
            professorType* tempProf = dynamic_cast<professorType*>(people[i]);
            if(tempProf != nullptr)
            {
              if(tempProf->getEmployeeID() == tempId)
              {
                profIndex = i;
                found2 = true;
                break;
              }
            }            
          }
          if(!found1)
          {
            cout << endl << "Course not found. Try again? ";
            cin >> again;
            if(toupper(again) == 'Y')
            {
              goto ASSIGN;
            }
            else
            {
              break;
            }
          }
          else if(!found2)
          {
            cout << endl << "Professor not found. Try again? ";
            cin >> again;
            if(toupper(again) == 'Y')
            {
              goto ASSIGN;
            }
            else
            {
              break;
            }
          }
          else
          {            
            if(dynamic_cast<professorType*>(people[profIndex])->assignCourse(courses[courseIndex]))
            {
              cout << endl << "Success: professor assigned to course.";

              cin.ignore();
              cin.get();
            }
            else
            {
              cout << endl << "Error: course limit exceeded for professor.";

              cin.ignore();
              cin.get();
            }            
          }
        }
        break;
      case 5:
        cout << "\033[2J\033[1;1H";
        
        cout << collegeType::getName() << " list of people" << endl << endl;

        cout << left << setw(25) << "Name" << setw(40) << "Address" << setw(7) << "Height" << setw(11) << "DOB" << setw(7) << "Gender" << endl;

        for(int x = 0; x < (int)people.size(); x++)
        {
          people[x]->print();

          cout << endl;
        }

        cin.ignore();
        cin.get();

        break;
      case 6:
        cout << "\033[2J\033[1;1H";
        cout << collegeType::getName() << "list of courses" << endl << endl;

        cout << left << setw(11) << "Section ID" << setw(12) << "Course Name" << setw(25) << "Title" 
        << setw(5) << "Days" << setw(20) << "Time" << setw(4) << "Cap" << setw(9) << "Enrolled"
        << setw(6) << "Status" << endl;

        for(int x = 0; x < (int)courses.size(); x++)
        {
          cout << left << setw(11) << courses[x]->getSectionId() << setw(12) << courses[x]->getCourse()
          << setw(25) << courses[x]->getTitle() << setw(5) << courses[x]->getDays() << setw(20) 
          << courses[x]->getTime() << setw(4) << courses[x]->getCap() << setw(9) << courses[x]->getEnrolled()
          << setw(6) << courses[x]->getStatus() << endl;
        }

        cin.ignore();
        cin.get();

        break;
      case 7:
        cout << "\033[2J\033[1;1H";
        cout << collegeType::getName() << " 2021 census" << endl;
        cout << "Enrollments: " << collegeType::getCensusNumber();
        cin.ignore();
        cin.get();
        break;
    }
  }

  return 0;
}
