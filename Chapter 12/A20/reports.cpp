#include "functions.h"

void reports(bookType books[]){
  int input = 10;

  while(input != 7)
  {
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

      if(!(input <= 7 && input >= 1)){
        cin.ignore();
        cout << endl << "Please enter a number in the range 1 - 7. Press any button to continue.";
        cin.get();
      }
    }while(!(input <= 7 && input >= 1));

    switch(input)
    {
      case 1:
        repListing(books);
        break;
      case 2:
        repWholesale(books);
        break;
      case 3:
        repRetail(books);
        break;
      case 4:
        repQty(books);
        break;
      case 5:
        repCost(books);
        break;
      case 6:
        repAge(books);
        break;
    }
  }
}

void repListing(bookType books[]){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  bool tenth = false;
  int bookNum = books->getBookCount();
  double pages = ceil(bookNum/10.0);

  if(bookType::getBookCount() > 0)
  {
    pageCnt = 1;
  }

  cout << "\033[2J\033[1;1H";

  cout << "Serendipity Booksellers" << endl;
  cout << " Report Listing" << endl;
  cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
  << '/'<<  1900 + ltm->tm_year;
  cout << "   Page: " << pageCnt << " of " << (int)pages;
  cout << "   Database size: " << DB_SIZE;
  cout << "   Current book count: " << bookNum << endl << endl;

  cout << left << setw(30) << "Title" << setw(10) << "ISBN" << setw(15) <<
  "Author" << setw(15) << "Publisher" << setw(11) << "Date added" << setw(8)
  << "Qty O/H" << setw(15) << "Wholesale cost" << setw(12) << "Retail price" << endl;

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    tenth = false;
    cout << left << setw(30) << books[i].getTitle() << setw(10) << books[i].getISBN()
    << setw(15) << books[i].getAuthor() << setw(15) << books[i].getPub()
    << setw(11) << books[i].getDateAdded() << right << setw(7) << books[i].getQtyOnHand()
    << setw(15) << books[i].getWholesale() << setw(13) << books[i].getRetail() << endl;
    if((i+1)%10 == 0)
    {
      tenth = true;
      if(i == 9)
      {
          cin.ignore();
      }
      cin.get();

      pageCnt++;

      cout << "\033[2J\033[1;1H";

      cout << "Serendipity Booksellers" << endl;
      cout << " Report Listing" << endl;
      cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
      << '/'<<  1900 + ltm->tm_year;
      cout << "   Page: " << pageCnt << " of " << (int)pages;
      cout << "   Database size: " << DB_SIZE;
      cout << "   Current book count: " << bookNum << endl << endl;

      cout << left << setw(30) << "Title" << setw(10) << "ISBN" << setw(15) <<
      "Author" << setw(15) << "Publisher" << setw(11) << "Date added" << setw(8)
      << "Qty O/H" << setw(15) << "Wholesale cost" << setw(12) << "Retail price" << endl;
    }

  }
  if(!tenth)
  {
    cin.get();
  }
}

void repWholesale(bookType books[]){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  bool tenth = false;
  int bookNum = books->getBookCount();
  double pages = ceil(bookNum/10.0);

  if(bookType::getBookCount() > 0)
  {
    pageCnt = 1;
  }

  cout << "\033[2J\033[1;1H";

  cout << "Serendipity Booksellers" << endl;
  cout << " Report Listing" << endl;
  cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
  << '/'<<  1900 + ltm->tm_year;
  cout << "   Page: " << pageCnt << " of " << (int)pages;
  cout << "   Database size: " << DB_SIZE;
  cout << "   Current book count: " << bookNum << endl << endl;

  cout << left << setw(50) << "Title" << setw(15) << "ISBN" << setw(12)
  << right << "Qty O/H" << setw(15) << "Wholesale cost" << endl;

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    tenth = false;
    cout << left << setw(50) << books[i].getTitle() << setw(15) << books[i].getISBN() << setw(12)
    << right << books[i].getQtyOnHand() << setw(15) << books[i].getWholesale() << endl;

    if((i+1)%10 == 0)
    {
      tenth = true;
      if(i == 9)
      {
          cin.ignore();
      }
      cin.get();

      pageCnt++;

      cout << "\033[2J\033[1;1H";

      cout << "Serendipity Booksellers" << endl;
      cout << " Report Listing" << endl;
      cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
      << '/'<<  1900 + ltm->tm_year;
      cout << "   Page: " << pageCnt << " of " << (int)pages;
      cout << "   Database size: " << DB_SIZE;
      cout << "   Current book count: " << bookNum << endl << endl;

      cout << left << setw(50) << "Title" << setw(15) << "ISBN" << setw(12)
      << right << "Qty O/H" << setw(15) << "Wholesale cost" << endl;
    }

  }
  if(!tenth)
  {
    cin.get();
  }
}

void repRetail(bookType books[]){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  bool tenth = false;
  int bookNum = books->getBookCount();
  double pages = ceil(bookNum/10.0);

  if(bookType::getBookCount() > 0)
  {
    pageCnt = 1;
  }

  cout << "\033[2J\033[1;1H";

  cout << "Serendipity Booksellers" << endl;
  cout << " Report Listing" << endl;
  cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
  << '/'<<  1900 + ltm->tm_year;
  cout << "   Page: " << pageCnt << " of " << (int)pages;
  cout << "   Database size: " << DB_SIZE;
  cout << "   Current book count: " << bookNum << endl << endl;

  cout << left << setw(50) << "Title" << setw(15) << "ISBN" << setw(12)
  << right << "Qty O/H" << setw(15) << "Retail cost" << endl;

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    tenth = false;
    cout << left << setw(50) << books[i].getTitle() << setw(15) << books[i].getISBN() << setw(12)
    << right << books[i].getQtyOnHand() << setw(15) << books[i].getRetail() << endl;

    if((i+1)%10 == 0)
    {
      tenth = true;
      if(i == 9)
      {
          cin.ignore();
      }
      cin.get();

      pageCnt++;

      cout << "\033[2J\033[1;1H";

      cout << "Serendipity Booksellers" << endl;
      cout << " Report Listing" << endl;
      cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
      << '/'<<  1900 + ltm->tm_year;
      cout << "   Page: " << pageCnt << " of " << (int)pages;
      cout << "   Database size: " << DB_SIZE;
      cout << "   Current book count: " << bookNum << endl << endl;

      cout << left << setw(50) << "Title" << setw(15) << "ISBN" << setw(12)
      << right << "Qty O/H" << setw(15) << "Retail cost" << endl;
    }

  }
  if(!tenth)
  {
    cin.get();
  }
}
void repQty(bookType books[]){
  cin.ignore();
  cout << endl << "You selected Listing by Quantity.";
  cin.get();
}
void repCost(bookType books[]){
  cin.ignore();
  cout << endl << "You selected Listing by Cost.";
  cin.get();
}
void repAge(bookType books[]){
  cin.ignore();
  cout << endl << "You selected Listing by Age.";
  cin.get();
}
