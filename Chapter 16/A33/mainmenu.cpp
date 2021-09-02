#include "functions.h"

int bookType::bookCount = 0;

int main(){
  //book struct
  //bookType books[DB_SIZE];
  bookType **books = new bookType*[DB_SIZE];

  int choice = 0;

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
        cashier(books);
        break;
      case 2:
        invMenu(books);
        break;
      case 3:
        reports(books);
        break;
    }
  }

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    delete books[i];
  }
  delete [] books;

}
void loadBooks(bookType **books)
{
  ifstream input;
  int index = 0;
  string tempTitle;
  string tempIsbn;
  string tempAuthor;
  string tempPublisher;
  string tempDate;
  int tempQty;
  float tempWholesale;
  float tempRetail;

  input.open("database.txt");

  while(true)
  {
    getline(input, tempTitle);
    input >> tempIsbn;
    input.ignore();
    getline(input, tempAuthor);
    getline(input, tempPublisher);
    input >> tempDate;
    input >> tempQty;
    input >> tempWholesale;
    input >> tempRetail;

    if(input.eof())
      break;
  }

  input.close();
}
void saveBooks(bookType **books)
{
  ofstream output;

  output.open("database.txt");

  output.close();
}