#ifndef LINKEDLIST_H
#define LINKEDLIST_H
// #pragma once
#include <iomanip>
#include <iostream>
// #include "listIterator.h"
using namespace std;

template <class Type>
struct nodeType
{
  Type info;
  nodeType<Type> *link;
};

template <class Type>
class linkedListIterator
{
  public:
    linkedListIterator()
    {
    	current = nullptr;
    }

    linkedListIterator(nodeType<Type> *ptr)
    {
      current = ptr;
    }
    Type operator*()
    {
      return current->info;
    }
    linkedListIterator<Type> operator++()
    {
      current = current->link;
      return *this;
    }
    bool operator==(const linkedListIterator<Type>& right) const
    {
      return (current == right.current);
    }
    bool operator!=(const linkedListIterator<Type>& right) const
    {
      return (current != right.current);
    }
  private:
    nodeType<Type> *current;
};

template <class Type>
class linkedListType
{
  public:
    const linkedListType<Type>& operator=
    (const linkedListType<Type>& otherList)
    {
      if (this != &otherList)
      {
        copyList(otherList);
      }
      return *this;
    }

    void initializeList()
    {
      destroyList();
    }

    bool isEmptyList() const
    {
      return (first == nullptr);
    }

    void print() const
    {
      nodeType<Type> *current;

      current = first;

      while (current != nullptr)
      {
        cout << current->info << " ";
        current = current->link;
      }
    }

    int length() const
    {
      return count;
    }

    void destroyList()
    {
      nodeType<Type> *temp;

      while (first != nullptr) //while there are nodes in the list
      {
        temp = first;
        first = first->link;
        delete temp;
      }
      last = nullptr;
      count = 0;
    }

    Type front() const
    {
      assert(first != nullptr);
      return first->info;
    }

    Type back() const
    {
      assert(last != nullptr);
      return last->info;
    }

    virtual bool search(const Type& searchItem) const = 0;

    virtual void insertFirst(const Type& newItem) = 0;

    virtual void insertLast(const Type& newItem) = 0;

    virtual void deleteNode(const Type& deleteItem) = 0;

    linkedListIterator<Type> begin()
    {
      linkedListIterator<Type> temp(first);
      return temp;
    }

    linkedListIterator<Type> end()
    {
      linkedListIterator<Type> temp(nullptr);
      return temp;
    }

    linkedListType()
    {
      first = nullptr;
      last = nullptr;
      count = 0;
    }

    linkedListType(const linkedListType<Type>& otherList)
    {
      first = nullptr;
      copyList(otherList);
    }

    ~linkedListType()
    {
      destroyList();
    }
  protected:
      int count;
      nodeType<Type> *first;
      nodeType<Type> *last;
  private:
      void copyList(const linkedListType<Type>& otherList)
      {
        nodeType<Type> *newNode;
        nodeType<Type> *current;

        if (first != nullptr)
          destroyList();
        if (otherList.first == nullptr)
        {
          first = nullptr;
          last = nullptr;
          count = 0;
        }
        else
        {
          current = otherList.first;
          count = otherList.count;

          first = new nodeType<Type>;
          first->info = current->info;
          first->link = nullptr;

          last = first;

          current = current->link;

          while (current != nullptr)
          {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;

            last->link = newNode;
            last = newNode;

            current = current->link;
          }
        }
      }
};

#endif
