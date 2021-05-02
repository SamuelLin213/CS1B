#include "functions.h"

void reports(){
  int input;

  do{
    cout << "\033[2J\033[1;1H";

    cout << "  Serendipity Booksellers" << endl;
    cout << setw(10) << "" << "Reports" << endl << endl;
    cout << "1.  Inventory Listing" << endl;
    cout << "2.  Inventory Wholesale Value" << endl;
    cout << "3.  Inventory Retail Value" << endl;
    cout << "4.  Listing by Quantity" << endl;
    cout << "5.  Listing by Cost" << endl;
    cout << "6.  Listing by Age" << endl;
    cout << "7.  Return to Main Menu" << endl << endl;

    cout << "Enter Your Choice: ";

    cin.ignore();
    cin >> input;
  }while(!(input >= 1 && input <= 7));
}
