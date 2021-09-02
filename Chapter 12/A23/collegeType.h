#ifndef COLLEGETYPE_H
#define COLLEGETYPE_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class collegeType
{
  friend class courseType;

  public:
    static void setName(string name_);
    static string getName();
    static int getCensusNumber();
    static void print();

  private:
    static string name;
    static int censusNumber;

    static void incrementCensus();
};

#endif
