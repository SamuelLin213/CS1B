//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999 

#include "unorderedLinkedList.h"
using namespace std;

int main()
{
    unorderedLinkedList<int> list1, list2;
    int num;

    cout << "Line 3: Enter integers ending "
         << "with -999" << endl;
    cin >> num;

    while (num != -999)
    {
        list1.insertLast(num);
        cin >> num;
    }

	  cout << endl;

    cout << "Line 9: list1: ";
    list1.print();
    cout << endl;
    cout << "Line 12: Length of list1: "
         << list1.length() << endl;

    list2 = list1;

    cout << "Line 16: list2: ";
    list2.print();
    cout << endl;
    cout << "Line 17: Length of list2: "
         << list2.length() << endl;

    cout << "Line 18: Enter the number to be "
         << "deleted: ";
    cin >> num;
    cout << endl;

    list2.deleteNode(num);

    cout << "Line 22: After deleting " << num
         << " list2: " << endl;
    list2.print();
    cout << endl;

    cout << "Line 25: Length of list2: "
         << list2.length() << endl;

    cout << endl << "Line 26: Output list1 "
         << "using an iterator" << endl;

    linkedListIterator<int> it;

    for (it = list1.begin(); it != list1.end();
                             ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
