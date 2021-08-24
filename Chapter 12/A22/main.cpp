#include "arrayListType.h"
#include "unorderedListType.h"
using namespace std;

int main()
{
  unorderedArrayListType intList(25);
  int number;
  cout << "List 3: Enter 8 integers: ";
  for (int count = 0; count < 8; count++)
  {
    cin >> number;
    intList.insertEnd(number);
  }
  cout << endl;
  cout << "Line 8: intList: ";
  intList.print();
  cout << endl;

  cout << "Line 11: Enter the number to be "
  << "deleted: ";
  cin >> number;
  cout << endl;

  intList.remove(number);

  cout << "Line 15: After removing " << number
  << " intList: ";
  intList.print();
  cout << endl;

  cout << "Line 18: Enter the search item: ";

  cin >> number;
  cout << endl;

  if (intList.seqSearch(number) != -1)
    cout << "Line 22: " << number
      << " found in intList." << endl;
  else
    cout << "Line 24: " << number
      << " is not in intList." << endl;

  return 0;
}
