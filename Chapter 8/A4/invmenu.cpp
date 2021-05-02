#include "functions.h"

void invmenu(){
  int input;

  do{
    cout << "\033[2J\033[1;1H";

    cout << "  Serendipity Booksellers" << endl;
    cout << setw(5) << "" << "Inventory Database" << endl << endl;

    cout << "1.  Look Up a Book" << endl;
    cout << "2.  Add a Book" << endl;
    cout << "3.  Edit a Book's Record" << endl;
    cout << "4.  Delete a Book" << endl;
    cout << "5.  Return to the Main Menu" << endl << endl;

    cout << "Enter Your Choice: ";

    cin.ignore();
    cin >> input;
  }while(!(input >= 1 && input <= 5));
}
