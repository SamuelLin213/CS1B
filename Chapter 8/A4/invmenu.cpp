#include "functions.h"

void invMenu(){
  int input = 0;

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
    cin >> input;

    while(!(input <= 5 && input >= 1)){
      cin.ignore();
      cout << endl << "Please enter a number in the range 1 - 5. ";
      cin >> input;
    }

    switch(input)
    {
      case 1:
        lookUpBook();
        break;
      case 2:
        addBook();
        break;
      case 3:
        editBook();
        break;
      case 4:
        deleteBook();
        break;
    }

  }while(input != 5);
}

void lookUpBook(){
  cin.ignore();
  cout << endl << "You selected Look Up Book.";
  cin.get();
}
void addBook(){
  cin.ignore();
  cout << endl << "You selected Add Book.";
  cin.get();
}
void editBook(){
  cin.ignore();
  cout << endl << "You selected Edit Book.";
  cin.get();
}
void deleteBook(){
  cin.ignore();
  cout << endl << "You selected Delete Book.";
  cin.get();
}
