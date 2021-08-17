#include "creditCardType.h"

class creditCardType;

creditCardType::creditCardType()
{
  count++;
  cardNumber = "0000 0000 0000 0000";
  name = "Unknown";
  expirationDate = "Unavaliable";
  creditLimit = 10000;
}
creditCardType::creditCardType(string num, string name, string date)
{
  creditLimit = 10000;
  count++;
  cardNumber = num;
  this->name = name;
  expirationDate = date;
}

int creditCardType::getCount()
{
  return count;
}
float creditCardType::getLimit()
{
  return creditLimit;
}
float creditCardType::getBalance()
{
  return balance;
}

void creditCardType::setCardNum(string num)
{
  cardNumber = num;
}
void creditCardType::setName(string str)
{
  name = str;
}
void creditCardType::setExpiration(string date)
{
  expirationDate = date;
}
void creditCardType::setCard(string num, string str, string date)
{
  cardNumber = num;
  name = str;
  expirationDate = date;
}

string creditCardType::getCardNum()
{
  return cardNumber;
}
string creditCardType::getName()
{
  return name;
}
string creditCardType::getExpiration()
{
  return expirationDate;
}

void creditCardType::print()
{
  cout << "Card number: " << cardNumber << endl;
  cout << "Name: " << name << endl;
  cout << "Expiration date: " << expirationDate << endl;
}
bool creditCardType::equals(creditCardType other)
{
  if(this->cardNumber == other.cardNumber && this->name == other.name
    && this->expirationDate == other.expirationDate)
    {
      return true;
    }
  return false;
}
void creditCardType::purchase(float amount)
{
  if(amount + balance <= creditLimit)
  {
    balance += amount;
  }
}
