#include "clockType.h"
using namespace std;

int main()
{
  bool equals;
  bool notEquals;

  clockType myClock(0, 34, 10);
  clockType yourClock(0, 24, 50);
  clockType tempClock(1, 0, 25);

  clockType newClock;

  cout << "Checking clock equality:" << endl;
  equals = (myClock == yourClock);
  cout << "myClock == yourClock: " << boolalpha << equals << endl;
  equals = (myClock == tempClock);
  cout << "myClock == tempClock: " << equals << endl << endl;

  cout << "Checking clock inequality:" << endl;
  notEquals = (myClock != yourClock);
  cout << "myClock != yourClock: " << notEquals << endl;
  notEquals = (myClock != tempClock);
  cout << "myClock != tempClock: " << notEquals << endl << endl;

  cout << "Checking stream input:" << endl;
  cout << "Time(HH MM SS): ";
  cin >> myClock;

  cout << endl << "Checking addition operator:" << endl;
  newClock = myClock + yourClock;
  cout << newClock;
  cout << endl << endl;

  cout << "Checking subtraction operator:" << endl;
  newClock = yourClock - tempClock;
  cout << newClock;
  cout << endl;

  return 0;
}
