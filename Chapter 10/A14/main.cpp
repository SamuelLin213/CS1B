#include "creditCardType.h"
using namespace std;

int creditCardType::count;
double creditCardType::balance;
double creditCardType::creditLimit;

int main()
{
  creditCardType card1("1234 5678 9012 3456", "Ray Allen", "06/25");
  cout << "Count after creating first card: " << creditCardType::getCount() << endl << endl;

  creditCardType card2("1212 1212 3434 3434", "Steph Curry", "01/25");
  cout << "Count after creating second card: " << creditCardType::getCount() << endl << endl;

  creditCardType card3("1313 2424 5757 6868", "Reggie Miller", "03/25");
  cout << "Count after creating third card: " << creditCardType::getCount() << endl << endl;

  cout << "Calling getLimit(), getBalance() and getCount(): " << endl;
  cout << "Limit: " << creditCardType::getLimit() << " Balance: " << creditCardType::getBalance()
  << " Count: " << creditCardType::getCount() << endl << endl;

  card1.purchase(500);
  card1.print();
  cout << "Balance after first purchase: " << creditCardType::getBalance() << endl << endl;

  card2.purchase(5000);
  card2.print();
  cout << "Balance after second purchase: " << creditCardType::getBalance() << endl << endl;

  card3.purchase(20000);
  card3.print();
  cout << "Balance after third purchase: " << creditCardType::getBalance() << endl;


  return 0;
}
