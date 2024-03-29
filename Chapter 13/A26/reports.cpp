#include "functions.h"

void reports(bookType **books){
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

void repListing(bookType **books){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  bool tenth = false;
  int bookNum = bookType::getBookCount();
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

  cout << left << setw(30) << "Title" << setw(11) << "ISBN" << setw(15) <<
  "Author" << setw(15) << "Publisher" << setw(11) << "Date added" << setw(8)
  << "Qty O/H" << setw(15) << "Wholesale cost" << setw(12) << "Retail price" << endl;

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    string tempTitle = books[i]->getTitle();
    string tempAuthor = books[i]->getAuthor();
    string tempPub = books[i]->getPub();

    if(books[i]->getTitle().length() > 29)
    {
      tempTitle = tempTitle.substr(0, 29);
    }
    if(books[i]->getAuthor().length() > 14)
    {
      tempAuthor = tempAuthor.substr(0, 14);
    }
    if(books[i]->getPub().length() > 14)
    {
      tempPub = tempPub.substr(0, 14);
    }

    tenth = false;
    cout << left << setw(30) << tempTitle << setw(11) << books[i]->getISBN()
    << setw(15) << tempAuthor << setw(15) << tempPub
    << setw(11) << books[i]->getDateAdded() << right << setw(7) << books[i]->getQtyOnHand() << setw(6) << ""
    << "$" << setw(8) << setfill('.') << fixed << setprecision(2) << books[i]->getWholesale() << setfill(' ') << setw(6) 
    << "" << "$" << setfill('.') << setw(6) << fixed << setprecision(2) << books[i]->getRetail() << endl << setfill(' ');
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

      cout << left << setw(30) << "Title" << setw(11) << "ISBN" << setw(15) <<
      "Author" << setw(15) << "Publisher" << setw(11) << "Date added" << setw(8)
      << "Qty O/H" << setw(15) << "Wholesale cost" << setw(12) << "Retail price" << endl;
    }

  }
  if(!tenth)
  {
    cin.get();
  }
}

void repWholesale(bookType **books){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  int bookNum = bookType::getBookCount();
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
    string tempTitle = books[i]->getTitle();
    if(books[i]->getTitle().length() > 49)
    {
      tempTitle = tempTitle.substr(0, 49);
    }

    cout << left << setw(50) << tempTitle << setw(15) << books[i]->getISBN() << setw(12)
    << right << books[i]->getQtyOnHand() << setw(6) << "" << "$" << setw(8) << setfill('.')
    << fixed << setprecision(2) << books[i]->getWholesale() << endl << setfill(' ');

    if(i+1 == bookType::getBookCount())
    {
      double wholesaleTotal = 0.0;

      for(int x = 0; x < bookType::getBookCount(); x++)
      {
        wholesaleTotal += (books[x]->getQtyOnHand() * books[x]->getWholesale());
      }

      cout << endl << "Total wholesale value: $" << fixed << setprecision(2) << wholesaleTotal;
      cin.get();
      break;
    }

    if((i+1)%10 == 0)
    {

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
}

void repRetail(bookType **books){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  int bookNum = bookType::getBookCount();
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
    string tempTitle = books[i]->getTitle();
    if(books[i]->getTitle().length() > 49)
    {
      tempTitle = tempTitle.substr(0, 49);
    }

    cout << left << setw(50) << tempTitle << setw(15) << books[i]->getISBN() << setw(12)
    << right << books[i]->getQtyOnHand() << setw(6) << "" << "$" << setw(8) << setfill('.')
    << fixed << setprecision(2) << books[i]->getRetail() << endl << setfill(' ');

    if(i+1 == bookType::getBookCount())
    {
      double retailTotal = 0.0;

      for(int x = 0; x < bookType::getBookCount(); x++)
      {
        retailTotal += (books[x]->getQtyOnHand() * books[x]->getRetail());
      }

      cout << endl << "Total retail value: $" << fixed << setprecision(2) << retailTotal;
      cin.get();
      break;
    }


    if((i+1)%10 == 0)
    {
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
}
void repQty(bookType **books){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  int bookNum = bookType::getBookCount();
  double pages = ceil(bookNum/10.0);

  if(bookType::getBookCount() > 0)
  {
    pageCnt = 1;
  } 

  sortBooks(books);

  cout << "\033[2J\033[1;1H";

  cout << "Serendipity Booksellers" << endl;
  cout << " Report Listing" << endl;
  cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
  << '/'<<  1900 + ltm->tm_year;
  cout << "   Page: " << pageCnt << " of " << (int)pages;
  cout << "   Database size: " << DB_SIZE;
  cout << "   Current book count: " << bookNum << endl << endl;

  cout << left << setw(55) << "Title" << setw(15) << "ISBN" << setw(12)
  << right << "Qty O/H" << endl;

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    string tempTitle = books[i]->getTitle();
    if(books[i]->getTitle().length() > 49)
    {
      tempTitle = tempTitle.substr(0, 49);
    }

    cout << left << setw(55) << tempTitle << setw(15) << books[i]->getISBN() << setw(12)
    << right << books[i]->getQtyOnHand() << endl;

    if((i+1)%10 == 0)
    {
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

      cout << left << setw(55) << "Title" << setw(15) << "ISBN" << setw(12)
      << right << "Qty O/H" << endl;
    }

  }
}
void repCost(bookType **books){
  cin.ignore();
  cout << endl << "You selected Listing by Cost.";
  cin.get();
}
void repAge(bookType **books){
  cin.ignore();
  cout << endl << "You selected Listing by Age.";
  cin.get();
}
template <typename T>
void sortBooks(T** books)
{
  for(int i = 0; i < T::getBookCount()-1; i++)
  {
    int largestIndex = i;
    for(int x = i+1; x < T::getBookCount(); x++)
    {
      if(*books[x] > *books[largestIndex])
      {
        largestIndex = x;
      }
    }
    if(largestIndex != i)
      swap(*books[i], *books[largestIndex]);
  }
}