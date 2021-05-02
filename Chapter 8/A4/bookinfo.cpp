#include "functions.h"

void bookInfo(){
  cout << "\033[2J\033[1;1H";

  cout << "  Serendipity Booksellers" << endl;
  cout << setw(6) << "" << "Book Information" << endl << endl;
  cout << "ISBN: " << endl;
  cout << "Title: " << endl;
  cout << "Author: " << endl;
  cout << "Publisher: " << endl;
  cout << "Date Added: " << endl;
  cout << "Quantity-On-Hand: " << endl;
  cout << "Wholesale Cost: " << endl;
  cout << "Retail Price: " << endl;

  cin.ignore();
  cin.get();
}
