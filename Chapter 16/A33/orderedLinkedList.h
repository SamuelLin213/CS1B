#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include "linkedList.h"
using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
  using linkedListType<Type>::first;
  using linkedListType<Type>::last;
  using linkedListType<Type>::count;

  public:
    bool search(const Type& searchItem) const
    {
      bool found = false;
      nodeType<Type> *current;

      current = first;

      while (current != nullptr && !found)
        if ((current->info.getTitle() >= searchItem.getTitle() && code == 1) ||
            (current->info.getISBN() >= searchItem.getISBN() && code == 2) )
          found = true;
        else
          current = current->link;

      if (found && code == 1)
        found = (current->info.getTitle() == searchItem.getTitle());
      else if(found && code == 2)
        found = (current->info.getISBN() == searchItem.getISBN());

      return found;
    }

    void insert(const Type& newItem, int code)
    {
      nodeType<Type> *current;
      nodeType<Type> *trailCurrent;
      nodeType<Type> *newNode;

      bool found;

      newNode = new nodeType<Type>;
      newNode->info = newItem;
      newNode->link = nullptr;

      if (first == nullptr)
      {
        first = newNode;
        last = newNode;
        count++;
      }
      else
      {
        current = first;
        found = false;

        while (current != nullptr && !found)
        {

          if ((current->info.getQtyOnHand() >= newItem.getQtyOnHand() && code == 1) ||
              (current->info.getWholesale() >= newItem.getWholesale() && code == 2) ||
              (current->info.getDateAdded() >= newItem.getDateAdded() && code == 3))
            found = true;
          else
          {
            trailCurrent = current;
            current = current->link;
          }
        }
        if (current == first)
        {
          newNode->link = first;
          first = newNode;
          count++;
        }
        else
        {
          trailCurrent->link = newNode;
          newNode->link = current;

          if (current == nullptr)
            last = newNode;

          count++;
        }
      }
    }

    void insertFirst(const Type& newItem)
    {
      insert(newItem);
    }

    void insertLast(const Type& newItem)
    {
      insert(newItem);
    }

    void deleteNode(const Type& deleteItem, int code)
    {
      nodeType<Type> *current;
      nodeType<Type> *trailCurrent;
      bool found;

      if (first == nullptr)
        cout << "Cannot delete from an empty list." << endl;
        else
        {
          current = first;
          found = false;

          while (current != nullptr && !found)
            if ( (current->info.getTitle() >= deleteItem.getTitle() && code == 1) ||
                (current->info.getISBN() >= deleteItem.getISBN() && code == 2))
              found = true;
            else
            {
              trailCurrent = current;
              current = current->link;
            }

          if (current == nullptr)
            cout << "The item to be deleted is not in the list" << endl;
          else
          {
            if ((current->info.getTitle() == deleteItem.getTitle() && code == 1) ||
                (current->info.getISBN() == deleteItem.getISBN() && code == 2))
            {
              if (first == current)
              {
                first = first->link;

                if (first == nullptr)
                  last = nullptr;

                delete current;
              }
              else
              {
                trailCurrent->link = current->link;

                if (current == last)
                  last = trailCurrent;

                delete current;
              }
              count--;
            }
          else
          cout << "The item to be deleted is not in the "
            << "list." << endl;
          }
      }
    }
};

#endif
