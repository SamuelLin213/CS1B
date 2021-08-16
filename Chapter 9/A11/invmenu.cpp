#include "functions.h"

void invMenu(int &bookCount, bookType books[]){
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
        lookUpBook(bookCount, books, 1);
        break;
      case 2:
        addBook(bookCount, books, 1, 0);
        break;
      case 3:
        editBook(bookCount, books);
        break;
      case 4:
        deleteBook(bookCount, books);
        break;
    }
  }
}

void lookUpBook(int &bookCount, bookType books[], int code)
{
  string search = "";
  vector<int> indexes;
  char ch = 'z';
  char ch2 = 'y';
  char ch3 = 'x';
  bool done = false;
  int index = 0;

  INFO:cin.ignore();
  cout << endl << "Search for a book: ";
  getline(cin, search);

  for(int i = 0; i < bookCount; i++)
  {
    if(books[i].bookTitle.find(search) != string::npos || books[i].isbn.find(search) != string::npos
    || books[i].publisher.find(search) != string::npos || books[i].author.find(search) != string::npos)
    {
      indexes.push_back(i);
    }
  }

  if(indexes.size() > 0)
  {
    for(int x = 0; x < int(indexes.size()); x++)
    {
      do{
        cout << endl << "Result: " << books[indexes[x]].bookTitle << ", " << books[indexes[x]].isbn << endl;
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
        bookInfo(books[indexes[index]].isbn, books[indexes[index]].bookTitle, books[indexes[index]].author
          , books[indexes[index]].publisher, books[indexes[index]].dateAdded, books[indexes[index]].qtyOnHand,
           books[indexes[index]].wholesale, books[indexes[index]].retail);
        if(code == 1)
        {
          cin.ignore();
          cin.get();
        }
        else if(code == 2)
        {
          do{
            cout << endl << "Is this the book you want to edit? <Y/N>: ";
            cin >> ch2;
          }while(toupper(ch2) != 'Y' && toupper(ch2) != 'N');
          if(toupper(ch2) == 'Y')
          {
            addBook(bookCount, books, 2, indexes[index]);
          }
        }
        else if(code == 3)
        {
          do{
            cout << endl << "Is this the book you want to delete? <Y/N>: ";
            cin >> ch3;
          }while(toupper(ch3) != 'Y' && toupper(ch3) != 'N');
          if(toupper(ch3) == 'Y')
          {
            ch3 = 'n';
            cout << "Book deleted." << endl;
            bookCount--;
            
            for(int i = indexes[index]; i < bookCount; i++)
            {
              books[i].bookTitle = books[i+1].bookTitle;
              books[i].isbn = books[i+1].isbn;
              books[i].author = books[i+1].author;
              books[i].publisher = books[i+1].publisher;
              books[i].dateAdded = books[i+1].dateAdded;
              books[i].qtyOnHand = books[i+1].qtyOnHand;
              books[i].wholesale = books[i+1].wholesale;
              books[i].retail = books[i+1].retail;
            }

            if(bookCount != 0)
            {
              cout << "Delete another? <Y/N>: ";
              cin >> ch3;
            }
            if(toupper(ch3) == 'Y')
            {
              cout << "\033[2J\033[1;1H";
              cout << "Serendipity Booksellers" << endl;
              cout << " Delete Book" << endl << endl;
              cout << " Database size: " << DB_SIZE << " Current book count: " << bookCount
              << endl;
              goto INFO;
            }
          }
        }
        break;
      }
    }
    if(!done)
    {
      cin.ignore();
      cout << endl << "Sorry. No match found.";
      cin.get();
    }
  }
  else{
    cout << "Sorry. No match found.";
    cin.get();
  }
  indexes.clear();
}
void addBook(int &bookCount, bookType books[], int code, int index){
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
    string action;
    bool changed = false;
    bool saved = false;
    bool exit = false;

    if(code == 1)
    {
      action = "Enter";
    }
    else{
      action = "Edit";
      tempTitle = books[index].bookTitle;
      tempISBN = books[index].isbn;
      tempAuthor = books[index].author;
      tempPublisher = books[index].publisher;
      tempDate = books[index].dateAdded;
      tempQty = books[index].qtyOnHand;
      tempWholesale = books[index].wholesale;
      tempRetail = books[index].retail;
    }

    while(choice != 0 && !exit)
    {
      do
      {
        cout << "\033[2J\033[1;1H";
        cout << "Serendipity Booksellers" << endl;
        cout << " Add Book" << endl << endl;
        cout << "Database size: " << DB_SIZE << " Current book count: "
        << bookCount << endl;
        cout << setw(36) << " " << "--Pending values" << endl;

        cout << setw(4) << left << "<1>" << setw(5) << action << setw(25) << " book title"
        << "> --" << tempTitle << endl;
        cout << setw(4) << left << "<2>" << setw(5) << action << setw(25) <<" ISBN"
        << "> --" << tempISBN << endl;
        cout << setw(4) << left << "<3>" << setw(5) << action << setw(25) <<" author"
        << "> --" << tempAuthor << endl;
        cout << setw(4) << left << "<4>" << setw(5) << action << setw(25) <<" publisher"
        << "> --" << tempPublisher << endl;
        cout << setw(4) << left << "<5>" << setw(5) << action << setw(25) <<" date added <mm/dd/yyyy>"
        << "> --" << tempDate << endl;
        cout << setw(4) << left << "<6>" << setw(5) << action << setw(25) <<" quantity on hand"
        << "> --" << tempQty << endl;
        cout << setw(4) << left << "<7>" << setw(5) << action << setw(25) <<" wholesale cost"
        << "> --" << tempWholesale << endl;
        cout << setw(4) << left << "<8>" << setw(5) << action << setw(25) <<" retail price"
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
      }while((choice > 9 || choice < 0));

      switch(choice)
      {
        case 1:
          cout << "Enter book title: ";
          getline(cin, tempTitle);
          changed = true;
          break;
        case 2:
          cout << "Enter ISBN: ";
          getline(cin, tempISBN);
          changed = true;
          break;
        case 3:
          cout << "Enter author: ";
          getline(cin, tempAuthor);
          changed = true;
          break;
        case 4:
          cout << "Enter publisher: ";
          getline(cin, tempPublisher);
          changed = true;
          break;
        case 5:
          cout << "Enter date <mm/dd/yyyy>: ";
          getline(cin, tempDate);
          changed = true;
          break;
        case 6:
          cout << "Enter quantity: ";
          cin >> tempQty;
          changed = true;
          break;
        case 7:
          cout << "Enter wholesale cost: ";
          cin >> tempWholesale;
          changed = true;
          break;
        case 8:
          cout << "Enter retail price: ";
          cin >> tempRetail;
          changed = true;
          break;
        case 9:
          if(bookCount < 20)
          {
            if(code == 1)
            {
              books[bookCount].bookTitle = tempTitle;
              books[bookCount].isbn = tempISBN;
              books[bookCount].author = tempAuthor;
              books[bookCount].publisher = tempPublisher;
              books[bookCount].dateAdded = tempDate;
              books[bookCount].qtyOnHand = tempQty;
              books[bookCount].wholesale = tempWholesale;
              books[bookCount].retail = tempRetail;

              cout << "Book added!";
              cin.get();

              bookCount++;
            }
            else if(code == 2)
            {
              books[index].bookTitle = tempTitle;
              books[index].isbn = tempISBN;
              books[index].author = tempAuthor;
              books[index].publisher = tempPublisher;
              books[index].dateAdded = tempDate;
              books[index].qtyOnHand = tempQty;
              books[index].wholesale = tempWholesale;
              books[index].retail = tempRetail;

              cout << "Book saved!";
              cin.get();

              saved = true;
            }
          }
          else
          {
            cout << "Error: database full.";
            cin.get();
          }
          break;
        case 0:
          if(code == 2 && !saved && changed)
          {
            char save;

            cout << "Book not saved! Are you sure you want to exit? <Y/N> ";
            cin >> save;

            if(toupper(save) == 'Y')
            {
              exit = true;
            }
            else
            {
              exit = false;
              choice = 10;
            }
          }
          break;
      }
    }
  }
  else{
    cout << "Error: database full.";
    cin.ignore();
    cin.get();
  }
}
void editBook(int &bookCount, bookType books[]){
  cout << "\033[2J\033[1;1H";
  cout << "Serendipity Booksellers" << endl;
  cout << " Edit Book" << endl << endl;
  cout << " Database size: " << DB_SIZE << " Current book count: " << bookCount
  << endl;

  lookUpBook(bookCount, books, 2);
}
void deleteBook(int &bookCount, bookType books[]){
  cout << "\033[2J\033[1;1H";
  cout << "Serendipity Booksellers" << endl;
  cout << " Delete Book" << endl << endl;
  cout << " Database size: " << DB_SIZE << " Current book count: " << bookCount
  << endl;

  lookUpBook(bookCount, books, 3);
}
