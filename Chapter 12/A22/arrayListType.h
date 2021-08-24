#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H

#include <iostream>
#include <iomanip>
using namespace std;

class arrayListType
{
  public:
    bool isEmpty() const
    {
      return (length == 0);
    }

    bool isFull() const
    {
      return (length == maxSize);
    }

    int listSize() const
    {
      return length;
    }
    int maxListSize() const
    {
      return maxSize;
    }
    void print() const
    {
      for (int i = 0; i < length; i++)
          cout << list[i] << " ";
      cout << endl;
    }
    bool isItemAtEqual(int location, int item) const
    {
      if (location < 0 || location >= length)
      {
        cout << "The location of the item to be removed "
          << "is out of range." << endl;
        return false;
      }
      else
        return (list[location] == item);
    }
    virtual void insertAt(int location, int insertItem) = 0;
    virtual void insertEnd(int insertItem) = 0;
    void removeAt(int location)
    {
      if (location < 0 || location >= length)
        cout << "The location of the item to be removed "
          << "is out of range." << endl;
      else
      {
        for (int i = location; i < length - 1; i++)
          list[i] = list[i+1];
        length--;
      }
    }
    void retrieveAt(int location, int& retItem) const
    {
      if (location < 0 || location >= length)
        cout << "The location of the item to be retrieved is "
          << "out of range" << endl;
      else
        retItem = list[location];
    }
    virtual void replaceAt(int location, int repItem) = 0;
    void clearList()
    {
      length = 0;
    }
    virtual int seqSearch(int searchItem) const = 0;
    virtual void remove(int removeItem) = 0;
    arrayListType(int size = 100)
    {
      if (size <= 0)
      {
        cout << "The array size must be positive. Creating "
        << "an array of the size 100." << endl;
        maxSize = 100;
      }
      else
        maxSize = size;
      length = 0;
      list = new int[maxSize];
    }
    arrayListType (const arrayListType& otherList)
    {
      maxSize = otherList.maxSize;
      length = otherList.length;
      list = new int[maxSize]; 
      for (int j = 0; j < length; j++)
        list[j] = otherList.list[j];
    }
    virtual ~arrayListType()
    {
      delete [] list;
    }

  protected:
    int *list;
    int length;
    int maxSize;
};

#endif
