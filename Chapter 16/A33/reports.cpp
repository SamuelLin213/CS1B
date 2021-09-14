#include "functions.h"

void reports(orderedLinkedList<bookType> &books){
  // bookType** booksCost = books;
  // bookType** booksAge = books;
  orderedLinkedList<bookType> booksCost;
  orderedLinkedList<bookType> booksAge;

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
        {
          linkedListIterator<bookType> iterator = books.begin();
          for(int i = 0; i < bookType::getBookCount(); i++)
          {
            booksCost.insert(*iterator, 2);
            ++iterator;
          }
          repCost(booksCost);
        }
        break;
      case 6:
        {
          linkedListIterator<bookType> iterator = books.begin();
          for(int i = 0; i < bookType::getBookCount(); i++)
          {
            booksAge.insert(*iterator, 3);
            ++iterator;
          }
          repAge(booksAge);
        }
        break;
    }
  }
}

void repListing(orderedLinkedList<bookType> &books){
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

  cout << left << setw(30) << "Title" << setw(14) << "ISBN" << setw(15) <<
  "Author" << setw(15) << "Publisher" << setw(11) << "Date added" << setw(8)
  << "Qty O/H" << setw(15) << "Wholesale cost" << setw(12) << "Retail price" << endl;

  linkedListIterator<bookType> iterator = books.begin();

  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    string tempTitle = (*iterator).getTitle();
    string tempAuthor = (*iterator).getAuthor();
    string tempPub = (*iterator).getPub();

    if(tempTitle.length() > 29)
    {
      tempTitle = tempTitle.substr(0, 29);
    }
    if(tempAuthor.length() > 14)
    {
      tempAuthor = tempAuthor.substr(0, 14);
    }
    if(tempPub.length() > 14)
    {
      tempPub = tempPub.substr(0, 14);
    }

    tenth = false;
    cout << left << setw(30) << tempTitle << setw(14) << (*iterator).getISBN()
    << setw(15) << tempAuthor << setw(15) << tempPub
    << setw(11) << (*iterator).getDateAdded() << right << setw(7) << (*iterator).getQtyOnHand() << setw(6) << ""
    << "$" << setw(8) << setfill('.') << fixed << setprecision(2) << (*iterator).getWholesale() << setfill(' ') << setw(6)
    << "" << "$" << setfill('.') << setw(6) << fixed << setprecision(2) << (*iterator).getRetail() << endl << setfill(' ');
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

      cout << left << setw(30) << "Title" << setw(14) << "ISBN" << setw(15) <<
      "Author" << setw(15) << "Publisher" << setw(11) << "Date added" << setw(8)
      << "Qty O/H" << setw(15) << "Wholesale cost" << setw(12) << "Retail price" << endl;
    }
    ++iterator;
  }
  if(!tenth)
  {
    cin.get();
  }
}

void repWholesale(orderedLinkedList<bookType> &books){
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

  cout << left << setw(50) << "Title" << setw(18) << "ISBN" << setw(12)
  << right << "Qty O/H" << setw(15) << "Wholesale cost" << endl;

  linkedListIterator<bookType> iterator = books.begin();
  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    string tempTitle = (*iterator).getTitle();
    if(tempTitle.length() > 49)
    {
      tempTitle = tempTitle.substr(0, 49);
    }

    cout << left << setw(50) << tempTitle << setw(18) << (*iterator).getISBN() << setw(12)
    << right << (*iterator).getQtyOnHand() << setw(6) << "" << "$" << setw(8) << setfill('.')
    << fixed << setprecision(2) << (*iterator).getWholesale() << endl << setfill(' ');

    linkedListIterator<bookType> iterator2 = books.begin();
    if(i+1 == bookType::getBookCount())
    {
      double wholesaleTotal = 0.0;

      for(int x = 0; x < bookType::getBookCount(); x++)
      {
        wholesaleTotal += ((*iterator2).getQtyOnHand() * (*iterator2).getWholesale());
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

      cout << left << setw(50) << "Title" << setw(18) << "ISBN" << setw(12)
      << right << "Qty O/H" << setw(15) << "Wholesale cost" << endl;
    }
    ++iterator;
  }
}

void repRetail(orderedLinkedList<bookType> &books){
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

  cout << left << setw(50) << "Title" << setw(18) << "ISBN" << setw(12)
  << right << "Qty O/H" << setw(15) << "Retail cost" << endl;

  linkedListIterator<bookType> iterator = books.begin();
  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    string tempTitle = (*iterator).getTitle();
    if(tempTitle.length() > 49)
    {
      tempTitle = tempTitle.substr(0, 49);
    }

    cout << left << setw(50) << tempTitle << setw(18) << (*iterator).getISBN() << setw(12)
    << right << (*iterator).getQtyOnHand() << setw(6) << "" << "$" << setw(8) << setfill('.')
    << fixed << setprecision(2) << (*iterator).getRetail() << endl << setfill(' ');

    if(i+1 == bookType::getBookCount())
    {
      double retailTotal = 0.0;

      linkedListIterator<bookType> iterator2 = books.begin();
      for(int x = 0; x < bookType::getBookCount(); x++)
      {
        retailTotal += ((*iterator2).getQtyOnHand() * (*iterator2).getRetail());
        ++iterator2;
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

      cout << left << setw(50) << "Title" << setw(18) << "ISBN" << setw(12)
      << right << "Qty O/H" << setw(15) << "Retail cost" << endl;
    }
    ++iterator;
  }
}

void repQty(orderedLinkedList<bookType> &books){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  int bookNum = bookType::getBookCount();
  double pages = ceil(bookNum/10.0);

  if(bookType::getBookCount() > 0)
  {
    pageCnt = 1;
  }

  // sortQty(books);

  cout << "\033[2J\033[1;1H";

  cout << "Serendipity Booksellers" << endl;
  cout << " Report By Quantity On Hand" << endl;
  cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
  << '/'<<  1900 + ltm->tm_year;
  cout << "   Page: " << pageCnt << " of " << (int)pages;
  cout << "   Database size: " << DB_SIZE;
  cout << "   Current book count: " << bookNum << endl << endl;

  cout << left << setw(55) << "Title" << setw(18) << "ISBN" << setw(12)
  << right << "Qty O/H" << endl;

  linkedListIterator<bookType> iterator = books.begin();
  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    string tempTitle = (*iterator).getTitle();
    if(tempTitle.length() > 49)
    {
      tempTitle = tempTitle.substr(0, 49);
    }

    cout << left << setw(55) << tempTitle << setw(18) << (*iterator).getISBN() << setw(12)
    << right << (*iterator).getQtyOnHand() << endl;

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
      cout << " Report By Quantity On Hand" << endl;
      cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
      << '/'<<  1900 + ltm->tm_year;
      cout << "   Page: " << pageCnt << " of " << (int)pages;
      cout << "   Database size: " << DB_SIZE;
      cout << "   Current book count: " << bookNum << endl << endl;

      cout << left << setw(55) << "Title" << setw(18) << "ISBN" << setw(12)
      << right << "Qty O/H" << endl;
    }
    ++iterator;
  }
}

void repCost(orderedLinkedList<bookType> &books){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  int bookNum = bookType::getBookCount();
  double pages = ceil(bookNum/10.0);

  if(bookType::getBookCount() > 0)
  {
    pageCnt = 1;
  }

  // sortCost(books);
  orderedLinkedList<bookType> booksCost;
  linkedListIterator<bookType> iteratorBook = books.begin();
  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    booksCost.insert(*iteratorBook, 2);
    ++iteratorBook;
  }

  cout << "\033[2J\033[1;1H";

  cout << "Serendipity Booksellers" << endl;
  cout << " Report Wholesale Cost Hi-Lo" << endl;
  cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
  << '/'<<  1900 + ltm->tm_year;
  cout << "   Page: " << pageCnt << " of " << (int)pages;
  cout << "   Database size: " << DB_SIZE;
  cout << "   Current book count: " << bookNum << endl << endl;

  cout << left << setw(55) << "Title" << setw(18) << "ISBN" << setw(16)
  << right << "Wholesale Cost" << endl;

  linkedListIterator<bookType> iterator = booksCost.begin();
  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    string tempTitle = (*iterator).getTitle();
    if(tempTitle.length() > 49)
    {
      tempTitle = tempTitle.substr(0, 49);
    }

    cout << left << setw(50) << tempTitle << setw(18) << (*iterator).getISBN()
    << right << setw(12) << "" << "$" << setw(8) << setfill('.')
    << fixed << setprecision(2) << (*iterator).getWholesale() << endl << setfill(' ');

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
      cout << " Report Wholesale Cost Hi-Lo" << endl;
      cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
      << '/'<<  1900 + ltm->tm_year;
      cout << "   Page: " << pageCnt << " of " << (int)pages;
      cout << "   Database size: " << DB_SIZE;
      cout << "   Current book count: " << bookNum << endl << endl;

      cout << left << setw(55) << "Title" << setw(18) << "ISBN" << setw(16)
      << right << "Wholesale Cost" << endl;
    }
    ++iterator;
  }
}

void repAge(orderedLinkedList<bookType> &books){
  time_t now = time(0);
  tm *ltm = localtime(&now);
  int pageCnt = 0;
  int bookNum = bookType::getBookCount();
  double pages = ceil(bookNum/10.0);

  if(bookType::getBookCount() > 0)
  {
    pageCnt = 1;
  }

  // sortAge(books);
  orderedLinkedList<bookType> booksAge;
  linkedListIterator<bookType> iteratorBook = books.begin();
  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    booksAge.insert(*iteratorBook, 2);
    ++iteratorBook;
  }

  cout << "\033[2J\033[1;1H";

  cout << "Serendipity Booksellers" << endl;
  cout << " Report By Age(Oldest First)" << endl;
  cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
  << '/'<<  1900 + ltm->tm_year;
  cout << "   Page: " << pageCnt << " of " << (int)pages;
  cout << "   Database size: " << DB_SIZE;
  cout << "   Current book count: " << bookNum << endl << endl;

  cout << left << setw(50) << "Title" << setw(18) << "ISBN" << setw(9)
  << right << "Qty O/H" << setw(14) << "Date Added" << endl;

  linkedListIterator<bookType> iterator = booksAge.begin();
  for(int i = 0; i < bookType::getBookCount(); i++)
  {
    string tempTitle = (*iteratorBook).getTitle();
    if(tempTitle.length() > 49)
    {
      tempTitle = tempTitle.substr(0, 49);
    }

    cout << left << setw(50) << tempTitle << setw(18) << (*iteratorBook).getISBN() << setw(6)
    << right << (*iteratorBook).getQtyOnHand() << setw(17) << (*iteratorBook).getDateAdded() << endl;

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
      cout << " Report By Age(Oldest First)" << endl;
      cout << "Date: " << 1 + ltm->tm_mon << '/' << ltm->tm_mday
      << '/'<<  1900 + ltm->tm_year;
      cout << "   Page: " << pageCnt << " of " << (int)pages;
      cout << "   Database size: " << DB_SIZE;
      cout << "   Current book count: " << bookNum << endl << endl;

      cout << left << setw(50) << "Title" << setw(18) << "ISBN" << setw(9)
      << right << "Qty O/H" << setw(14) << "Date Added" << endl;
    }
    ++iterator;
  }
}

// template <typename T>
// void sortQty(T** books)
// {
//   for(int i = 0; i < T::getBookCount()-1; i++)
//   {
//     int largestIndex = i;
//     for(int x = i+1; x < T::getBookCount(); x++)
//     {
//       if(*books[x] > *books[largestIndex])
//       {
//         largestIndex = x;
//       }
//     }
//     if(largestIndex != i)
//       swap(*books[i], *books[largestIndex]);
//   }
// }
// template <typename T>
// void sortCost(T** books)
// {
//   for(int i = 0; i < T::getBookCount()-1; i++)
//   {
//     int largestIndex = i;
//     for(int x = i+1; x < T::getBookCount(); x++)
//     {
//       if(books[x]->getWholesale() > books[largestIndex]->getWholesale())
//       {
//         largestIndex = x;
//       }
//     }
//     if(largestIndex != i)
//       swap(*books[i], *books[largestIndex]);
//   }
// }
// template <typename T>
// void sortAge(T** books)
// {
//   for(int i = 0; i < T::getBookCount()-1; i++)
//   {
//     int smallestIndex = i;
//     for(int x = i+1; x < T::getBookCount(); x++)
//     {
//       int monthX = stoi(books[x]->getDateAdded().substr(0, 2));
//       int monthS = stoi(books[smallestIndex]->getDateAdded().substr(0, 2));
//       int dayX = stoi(books[x]->getDateAdded().substr(3, 2));
//       int dayS = stoi(books[smallestIndex]->getDateAdded().substr(3, 2));
//       int yearX = stoi(books[x]->getDateAdded().substr(6, 4));
//       int yearS = stoi(books[smallestIndex]->getDateAdded().substr(6, 4));
//
//       if(yearX < yearS)
//       {
//         smallestIndex = x;
//       }
//       else if(yearX == yearS && monthX < monthS)
//       {
//         smallestIndex = x;
//       }
//       else if(yearX == yearS && monthX == monthS && dayX < dayS)
//       {
//         smallestIndex = x;
//       }
//     }
//     if(smallestIndex != i)
//       swap(*books[i], *books[smallestIndex]);
//   }
// }
