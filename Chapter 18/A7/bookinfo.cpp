#include "functions.h"

void bookInfo(string isbn, string title, string author, string publisher,
string date, int qty, double wholesale, double retail){
  cout << "\033[2J\033[1;1H";

  cout << "  Serendipity Booksellers" << endl;
  cout << setw(6) << "" << "Book Information" << endl << endl;
  cout << "ISBN: " << isbn << endl;
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Date Added: " << date << endl;
  cout << "Quantity-On-Hand: " << qty << endl;
  cout << "Wholesale Cost: " << wholesale << endl;
  cout << "Retail Price: " << retail << endl;
}
