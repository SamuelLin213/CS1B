#include "functions.h"

int bookType::bookCount = 0;

int main(){
  //book struct
  //bookType books[DB_SIZE];
  bookType **books = new bookType*[DB_SIZE];

  int choice = 0;

  loadBooks(books);

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
  string tempTitle;
  string tempIsbn;
  string tempAuthor;
  string tempPublisher;
  string tempDate;
  int tempQty;
  float tempWholesale;
  float tempRetail;

  input.open("database.txt");

  if(input.fail())
  {
    cout << "Error: file not opened." << endl;
    cin.ignore();
    cin.get();
  }

  // books[bookType::getBookCount()] = new bookType;
  // books[bookType::getBookCount()]->setTitle(tempTitle);
  // books[bookType::getBookCount()]->setISBN(tempIsbn);
  // books[bookType::getBookCount()]->setAuthor(tempAuthor);
  // books[bookType::getBookCount()]->setPub(tempPublisher);
  // books[bookType::getBookCount()]->setDateAdded(tempDate);
  // books[bookType::getBookCount()]->setQtyOnHand(tempQty);
  // books[bookType::getBookCount()]->setWholesale(tempWholesale);
  // books[bookType::getBookCount()]->setRetail(tempRetail);

  // bookType::incBookCount();

  // int i = bookType::getBookCount() - 1;

  // if(books[i]->getTitle().length() > 29)
  // {
  //   tempTitle = tempTitle.substr(0, 29);
  // }
  // if(books[i]->getAuthor().length() > 14)
  // {
  //   tempAuthor = tempAuthor.substr(0, 14);
  // }
  // if(books[i]->getPub().length() > 14)
  // {
  //   tempPublisher = tempPublisher.substr(0, 14);
  // }
  // cout << left << setw(30) << tempTitle << setw(11) << books[i]->getISBN()
  //   << setw(15) << tempAuthor << setw(15) << tempPublisher
  //   << setw(11) << books[i]->getDateAdded() << right << setw(7) << books[i]->getQtyOnHand() << setw(6) << ""
  //   << "$" << setw(8) << setfill('.') << fixed << setprecision(2) << books[i]->getWholesale() << setfill(' ') << setw(6) 
  //   << "" << "$" << setfill('.') << setw(6) << fixed << setprecision(2) << books[i]->getRetail() << endl << setfill(' ');

  // cin.ignore();
  // cin.get();






  while(true && !input.eof())
  {
    getline(input, tempTitle);
    getline(input, tempIsbn);
    getline(input, tempAuthor);
    getline(input, tempPublisher);
    input >> tempDate;
    input >> tempQty;
    input >> tempWholesale;
    input >> tempRetail;

    books[bookType::getBookCount()] = new bookType;
    books[bookType::getBookCount()]->setTitle(tempTitle);
    books[bookType::getBookCount()]->setISBN(tempIsbn);
    books[bookType::getBookCount()]->setAuthor(tempAuthor);
    books[bookType::getBookCount()]->setPub(tempPublisher);
    books[bookType::getBookCount()]->setDateAdded(tempDate);
    books[bookType::getBookCount()]->setQtyOnHand(tempQty);
    books[bookType::getBookCount()]->setWholesale(tempWholesale);
    books[bookType::getBookCount()]->setRetail(tempRetail);

    bookType::incBookCount();

    if(input.eof())
      break;  
  }

  input.close();
}
void saveBooks(bookType **books)
{
  ofstream output;

  output.open("database.txt");

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    
  }

  output.close();
}