#include "functions.h"

void invMenu(int &bookCount, string titles[], string isbns[], string authors[],
string publishers[], string dates[], int quantities[], double wholesales[], double retails[]){
  int input = 0;

  while(input != 5)
  {
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

      if(!(input <= 5 && input >= 1)){
        cin.ignore();
        cout << endl << "Please enter a number in the range 1 - 5. Press any button to continue.";
        cin.get();
      }
    }while(!(input <= 5 && input >= 1));

    switch(input)
    {
      case 1:
        lookUpBook(bookCount, titles, isbns, authors, publishers, dates, quantities,
        wholesales, retails);
        break;
      case 2:
        addBook(bookCount, titles, isbns, authors, publishers, dates, quantities,
        wholesales, retails);
        break;
      case 3:
        editBook();
        break;
      case 4:
        deleteBook();
        break;
    }
  }
}

void lookUpBook(int &bookCount, string titles[], string isbns[], string authors[],
string publishers[], string dates[], int quantities[], double wholesales[], double retails[])
{
  string search = "";
  vector<int> indexes;
  char ch = 'z';
  bool done = false;
  int index = 0;

  cin.ignore();
  cout << endl << "Search for a book: ";
  getline(cin, search);

  for(int i = 0; i < bookCount; i++)
  {
    if(titles[i].find(search) != string::npos || isbns[i].find(search) != string::npos
    || publishers[i].find(search) != string::npos || authors[i].find(search) != string::npos)
    {
      indexes.push_back(i);
    }
  }

  if(indexes.size() > 0)
  {
    for(int x = 0; x < int(indexes.size()); x++)
    {
      do{
        cout << endl << "Result: " << titles[indexes[x]] << ", " << isbns[indexes[x]] << endl;
        cout << "View this book record? <Y/N>: ";
        cin >> ch;

        if(toupper(ch) == 'Y')
        {
          done = true;
          index = x;
          break;
        }
      }while(toupper(ch) != 'Y' && toupper(ch) != 'N');
      if(done)
      {
        bookInfo(isbns[indexes[index]], titles[indexes[index]], authors[indexes[index]]
          , publishers[indexes[index]], dates[indexes[index]], quantities[indexes[index]],
           wholesales[indexes[index]], retails[indexes[index]]);
        break;
      }
    }
  }
  else{
    cout << "Sorry. No match found.";
    cin.get();
  }
  indexes.clear();
}
void addBook(int &bookCount, string titles[], string isbns[], string authors[],
string publishers[], string dates[], int quantities[], double wholesales[], double retails[]){
  if(bookCount < 20)
  {
    string tempTitle = "EMPTY";
    string tempISBN = "EMPTY";
    string tempAuthor = "EMPTY";
    string tempPublisher = "EMPTY";
    string tempDate = "EMPTY";
    int tempQty = 0;
    double tempWholesale = 0.0;
    double tempRetail = 0.0;
    int choice = 10;

    while(choice != 0)
    {
      do
      {
        cout << "\033[2J\033[1;1H";
        cout << "Serendipity Booksellers" << endl;
        cout << " Add Book" << endl << endl;
        cout << "Database size: " << DB_SIZE << " Current book count: "
        << bookCount << endl;
        cout << setw(36) << " " << "--Pending values" << endl;

        cout << setw(4) << left << "<1>" << setw(30) << "Enter book title"
        << "> --" << tempTitle << endl;
        cout << setw(4) << left << "<2>" << setw(30) << "Enter ISBN"
        << "> --" << tempISBN << endl;
        cout << setw(4) << left << "<3>" << setw(30) << "Enter author"
        << "> --" << tempAuthor << endl;
        cout << setw(4) << left << "<4>" << setw(30) << "Enter publisher"
        << "> --" << tempPublisher << endl;
        cout << setw(4) << left << "<5>" << setw(30) << "Enter date added <mm/dd/yyyy>"
        << "> --" << tempDate << endl;
        cout << setw(4) << left << "<6>" << setw(30) << "Enter quantity on hand"
        << "> --" << tempQty << endl;
        cout << setw(4) << left << "<7>" << setw(30) << "Enter wholesale cost"
        << "> --" << tempWholesale << endl;
        cout << setw(4) << left << "<8>" << setw(30) << "Enter retail price"
        << "> --" << tempRetail << endl;
        cout << setw(4) << left << "<9>" << setw(30) << "Save book to database"
        << endl;
        cout << setw(4) << left << "<0>" << setw(30) << "Return to Inventory menu"
        << endl << endl;

        cout << "Choice <0-9>: ";

        cin >> choice;
        //cin.clear();
  			cin.ignore(50, '\n');

        if(choice > 9 || choice < 0)
        {
          cout << endl << "Please enter a number in the range 0 - 9 . Press any button to continue.";
          cin.get();
        }
      }while(choice > 9 || choice < 0);

      switch(choice)
      {
        case 1:
          cout << "Enter book title: ";
          getline(cin, tempTitle);
          break;
        case 2:
          cout << "Enter ISBN: ";
          getline(cin, tempISBN);
          break;
        case 3:
          cout << "Enter author: ";
          getline(cin, tempAuthor);
          break;
        case 4:
          cout << "Enter publisher: ";
          getline(cin, tempPublisher);
          break;
        case 5:
          cout << "Enter date <mm/dd/yyyy>: ";
          getline(cin, tempDate);
          break;
        case 6:
          cout << "Enter quantity: ";
          cin >> tempQty;
          break;
        case 7:
          cout << "Enter wholesale cost: ";
          cin >> tempWholesale;
          break;
        case 8:
          cout << "Enter retail price: ";
          cin >> tempRetail;
          break;
        case 9:
          titles[bookCount] = tempTitle;
          isbns[bookCount] = tempISBN;
          authors[bookCount] = tempAuthor;
          publishers[bookCount] = tempPublisher;
          dates[bookCount] = tempDate;
          quantities[bookCount] = tempQty;
          wholesales[bookCount] = tempWholesale;
          retails[bookCount] = tempRetail;

          cout << "Book added!";
          cin.get();

          bookCount++;
          break;
        case 0:
          break;
      }
    }
  }
}
void editBook(){
  cin.ignore();
  cout << "\033[2J\033[1;1H";
  cout << endl << "You selected Edit Book.";
  cin.get();
}
void deleteBook(){
  cin.ignore();
  cout << endl << "You selected Delete Book.";
  cin.get();
}
