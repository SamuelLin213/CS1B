#ifndef COURSETYPE_H
#define COURSETYPE_H
#include "studentType.h"
#include "professorType.h"

class studentType;

class courseType
{
  friend class studentType;
  friend class professorType;

  public:
    courseType();
    courseType(string sectionId_, string course_, string title_, string days_,
    string time_, string room_, int cap_);
    courseType(const courseType &other);

    void setSectionId(string sectionId_);
    void setCourse(string course_);
    void setTitle(string title_);
    void setDays(string days_);
    void setTime(string time_);
    void setRoom(string room_);
    string getSectionId();
    string getCourse();
    string getTitle();
    string getDays();
    string getTime();
    string getRoom();
    int getCap();
    int getEnrolled();
    bool getOpen();
    void incEnrolled();
    void print();
  private:
    string sectionId;
    string course;
    string title;
    string days;
    string time;
    string room;
    int cap;
    int enrolled {0};
    bool open;

    studentType *students;

    bool addStudent(studentType *other);
    void printStudents();
};

#endif
