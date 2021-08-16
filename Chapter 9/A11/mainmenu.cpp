#include "functions.h"

int main(){
  //book struct
  bookType books[DB_SIZE];

  int choice = 0;
  int count = 0;

  while(choice != 4){
    do{
      cout << "\033[2J\033[1;1H";

      cout << "  Serendipity Booksellers" << endl;
      cout << setw(8) << "" << "Main Menu" << endl;
      cout << endl << "1. Cashier Module" << endl;
      cout << "2. Inventory Database Module" << endl;
      cout << "3. Report Module" << endl;
      cout << "4. Exit" << endl << endl << "Enter Your Choice: ";

      cin >> choice;

      if(!(choice <= 4 && choice >= 1)){
        cin.ignore();
        cout << endl << "Please enter a number in the range 1 - 4. ";
        cin.get();
      }

    }while(!(choice <= 4 && choice >= 1));


    if(choice == 4){
      break;
    }

    switch(choice)
    {
      case 1:
        cashier();
        break;
      case 2:
        invMenu(count, books);
        break;
      case 3:
        reports();
        break;
    }
  }

}
