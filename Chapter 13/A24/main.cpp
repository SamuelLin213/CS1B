#include <iomanip>
#include <iostream>
using namespace std;

template <class bucky>
bucky addCrap(bucky a, bucky b)
{
  return a+b;
}

int main()
{
  int x = 7, y = 43, z;
  z = addCrap(x, y);
  cout << x << " + " << y << " = " << z << endl;

  double a = 2.0, b = 3.0, c;
  c = addCrap(a, b);
  cout << fixed << setprecision(2) << a << " + " << b << " = " << c << endl;

  char ch1 = 'h', ch2 = 'i', ch3;
  ch3 = addCrap(ch1, ch2);
  cout << ch1 << " + " << ch2 << " = " << ch3 << endl;

  string s1 = "Hello", s2 = "world", s3;
  s3 = addCrap(s1, s2);
  cout << s1 << " + " << s2 << " = " << s3 << endl;

  return 0;
}
