#include "courseType.h"

class courseType;

courseType::courseType()
{
  open = true;
}
courseType::courseType(string sectionId_, string course_, string title_, string days_,
string time_, string room_, int cap_)
  :sectionId(sectionId_), course(course_), title(title_), days(days_),
  time(time_), room(room_), cap(cap_)
{
  students = new studentType[cap];
  open = true;
}
courseType::courseType(const courseType &other)
{
  delete [] students;

  students = new studentType[other.cap];
  for(int i = 0; i < other.enrolled; i++)
  {
    students[i] = other.students[i];
  }
  sectionId = other.sectionId;
  course = other.course;
  title = other.title;
  days = other.days;
  time = other.time;
  room = other.room;
  cap = other.cap;
  enrolled = other.enrolled;
  open = other.open;
}

void courseType::setSectionId(string sectionId_)
{
  sectionId = sectionId_;
}
void courseType::setCourse(string course_)
{
  course = course_;
}
void courseType::setTitle(string title_)
{
  title = title_;
}
void courseType::setDays(string days_)
{
  days = days_;
}
void courseType::setTime(string time_)
{
  time = time_;
}
void courseType::setRoom(string room_)
{
  room = room_;
}
string courseType::getSectionId()
{
  return sectionId;
}
string courseType::getCourse()
{
  return course;
}
string courseType::getTitle()
{
  return title;
}
string courseType::getDays()
{
  return days;
}
string courseType::getTime()
{
  return time;
}
string courseType::getRoom()
{
  return room;
}
int courseType::getCap()
{
  return cap;
}
int courseType::getEnrolled()
{
  return enrolled;
}
bool courseType::getOpen()
{
  return open;
}
void courseType::incEnrolled()
{
  enrolled++;
}
void courseType::print()
{

}
bool courseType::courseType::addStudent(studentType *other)
{
  if(enrolled < cap)
  {
    open = true;
    students[enrolled] = *other;
    incEnrolled();
    collegeType::incrementCensus();
    return true;
  }
  else{
    open = false;
    return false;
  }
}
void courseType::printStudents()
{
  for(int i = 0; i < enrolled; i++)
  {
    cout << students[i].getFName() << " " << students[i].getLName() << endl;
  }
}
string courseType::getStatus()
{
  if(getOpen())
  {
    return "Open";
  }
  return "Closed";
}
