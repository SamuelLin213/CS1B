#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H

#include "personType.h"
#include "courseType.h"
#include <string>
using namespace std;

class courseType;

class studentType: public personType{
    public:
        //constructors
        studentType();
        studentType(string fName, string lName);
        studentType(string fName, string lName, double GPA, string classification, string id);

        //setters
        void setGPA(double GPA);
        void setID(string id);
        void setClassification(string classification);

        //getters
        double getGPA();
        string getID();
        string getClassification();

        //overridden methods
        void print() ; //override the parents' print method
        bool equals(studentType other);

        bool addCourse(courseType *other);
    private:
        string id; //added every id 'should' be unique
        double gpa;
        string classification;

        int numCourses {0};
        courseType *courses;
};

#endif
