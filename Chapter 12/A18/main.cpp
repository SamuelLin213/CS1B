#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
  int x = 50;
  char y = 'h';

  int *xPtr = &x;
  char *yPtr = &y;

  cout << "x value: " << x << "    Address of x: " << &x << endl;
  cout << "y value: " << y << "    Address of y: " << &y << endl;
  cout << "x pointer value: " << xPtr << "    Dereferenced x pointer: " << *xPtr
  << "    Address of xPtr: " << &xPtr << endl;
  cout << "y pointer value: " << yPtr << "    Dereferenced y pointer: " << *yPtr
  << "    Address of yPtr: " << &yPtr << endl;

  cout << endl;

  *xPtr = 25;
  *yPtr = 'i';

  cout << "x value: " << x << "    Address of x: " << &x << endl;
  cout << "y value: " << y << "    Address of y: " << &y << endl;
  cout << "x pointer value: " << xPtr << "    Dereferenced x pointer: " << *xPtr
  << "    Address of xPtr: " << &xPtr << endl;
  cout << "y pointer value: " << yPtr << "    Dereferenced y pointer: " << *yPtr
  << "    Address of yPtr: " << &yPtr << endl;

  return 0;
}
