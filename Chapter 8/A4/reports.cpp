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
    cin >> input;

    while(!(input <= 7 && input >= 1)){
      cin.ignore();
      cout << endl << "Please enter a number in the range 1 - 7. ";
      cin >> input;
    }

    switch(input)
    {
      case 1:
        repListing();
        break;
      case 2:
        repWholesale();
        break;
      case 3:
        repRetail();
        break;
      case 4:
        repQty();
        break;
      case 5:
        repCost();
        break;
      case 6:
        repAge();
        break;
    }

  }while(input != 7);
}

void repListing(){
  cin.ignore();
  cout << endl << "You selected Inventory List.";
  cin.get();
}
void repWholesale(){
  cin.ignore();
  cout << endl << "You selected Inventory Wholesale Value.";
  cin.get();
}
void repRetail(){
  cin.ignore();
  cout << endl << "You selected Inventory Retail Value.";
  cin.get();
}
void repQty(){
  cin.ignore();
  cout << endl << "You selected Listing by Quantity.";
  cin.get();
}
void repCost(){
  cin.ignore();
  cout << endl << "You selected Listing by Cost.";
  cin.get();
}
void repAge(){
  cin.ignore();
  cout << endl << "You selected Listing by Age.";
  cin.get();
}
