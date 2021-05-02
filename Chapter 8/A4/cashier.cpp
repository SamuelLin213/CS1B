#include "functions.h"

void cashier(){
  string date;
  int qty = 0;
  string isbn;
  string title;
  double price = 0.0;
  double total = 0.0;
  double tax = 0.0;
  char ch;

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

    cout << "\033[2J\033[1;1H";

    total = qty * price;
    tax = 0.06*total;

    cout << "Serendipity Book Sellers" << endl << endl;
    cout << "Date: " << date << endl << endl;
    cout << setw(4) << left << "Qty" << setw(14) << "ISBN" << setw(30) << "Title"
    << setw(15) << "Price" << setw(7) << "Total" << endl;
    cout << setw(70) << setfill('-') << "" << setfill(' ') << endl;

    cout << setw(4) << left << qty << setw(14) << isbn << setw(30) << title
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
  }while(ch != 'n' && ch != 'N');
}
