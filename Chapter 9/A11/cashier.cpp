#include "functions.h"

void cashier(int &bookCount, bookType books[]){
  string date;
  int qty = 0;
  string isbn;
  string title;
  double price = 0.0;
  double total = 0.0;
  double tax = 0.0;
  char ch;
  int index = -1;

  do{
    cout << "\033[2J\033[1;1H";

    cout << "Serendipity Booksellers" << endl;
    cout << "  Cashier Module" << endl << endl;

    cout << "Date: ";
    cin >> date;
    cout << "Quantity of Book: ";
    cin >> qty;
    cout << "ISBN: ";
    cin >> isbn;
    cout << "Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Price: ";
    cin >> price;

    cout << endl;
    index = lookUpBook(bookCount, books, 4, isbn);

    if(index != -1)
    {
      books[index].qtyOnHand -= qty;

      cout << "\033[2J\033[1;1H";

      total = qty * price;
      tax = 0.06*total;

      cout << "Serendipity Book Sellers" << endl << endl;
      cout << "Date: " << date << endl << endl;
      cout << setw(4) << left << "Qty" << setw(14) << "ISBN" << setw(30) << "Title"
      << setw(15) << "Price" << setw(7) << "Total" << endl;
      cout << setw(70) << setfill('-') << "" << setfill(' ') << endl;

      cout << setw(4) << left << qty << setw(14) << books[index].isbn << setw(30) << books[index].title
      << "$" << right << setw(6) << price << " " << setw(8) << "$" << setw(6)
      << fixed << setprecision(2) << right << total << endl;

      cout << endl << endl;

      cout << left << setw(13) << "" << setw(8) << "Subtotal" << right << setw(42)
      << "" << "$" << setw(6) << fixed << setprecision(2) << total << endl;
      cout << left << setw(13) << "" << setw(8) << "Tax" << right << setw(42)
      << "" << "$" << setw(6) << fixed << setprecision(2) << tax << endl;
      cout << left << setw(13) << "" << setw(8) << "Total" << right << setw(42)
      << "" << "$" << setw(6) << fixed << setprecision(2) << (tax + total) << endl;

      cout << endl << "Thank you for Shopping at Serendipity!" << endl;

      cout << "Enter another transaction?(y/n) ";

      cin.ignore();
      cin >> ch;
    }
    else if(index == -1)
    {
      break;
  }while(ch != 'n' && ch != 'N');
}
