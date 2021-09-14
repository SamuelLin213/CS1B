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
    vector<nodeType<Type>*> search(const Type& searchItem) const
    {
      bool found = false;
      nodeType<Type> *current;
      vector<nodeType<Type>*> indexes;

      current = first;

      while (current != nullptr)
        if ((current->info.getTitle() >= searchItem.getTitle()) ||
            (current->info.getISBN() >= searchItem.getISBN()) )
        {
          indexes.push_back(current);
          found = true;
        }
        else
          current = current->link;

      // if (found && code == 1)
      //   found = (current->info.getTitle() == searchItem.getTitle());
      // else if(found && code == 2)
      //   found = (current->info.getISBN() == searchItem.getISBN());

      if(found)
        return indexes;
      else
      {
        return indexes;
      }
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
          if(code == 3)
          {
            int monthX = stoi(current->info.getDateAdded().substr(0, 2));
            int monthS = stoi(newItem.getDateAdded().substr(0, 2));
            int dayX = stoi(current->info.getDateAdded().substr(3, 2));
            int dayS = stoi(newItem.getDateAdded().substr(3, 2));
            int yearX = stoi(current->info.getDateAdded().substr(6, 4));
            int yearS = stoi(newItem.getDateAdded().substr(6, 4));

            if(yearX >= yearS)
            {
              found = true;
            }
            else if(yearX == yearS && monthX >= monthS)
            {
              found = true;
            }
            else if(yearX == yearS && monthX == monthS && dayX >= dayS)
            {
              found = true;
            }
          }

          //(current->info.getDateAdded() >= newItem.getDateAdded() && code == 3)

          if ((current->info.getQtyOnHand() >= newItem.getQtyOnHand() && code == 1) ||
              (current->info.getWholesale() >= newItem.getWholesale() && code == 2))
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
      insert(newItem, 1);
    }

    void insertLast(const Type& newItem)
    {
      insert(newItem, 1);
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
          if ( (current->info.getQtyOnHand() >= deleteItem.getQtyOnHand() && code == 1) ||
              (current->info.getWholesale() >= deleteItem.getWholesale() && code == 2) ||
              (current->info.getDateAdded() >= deleteItem.getDateAdded() && code == 3))
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
          if ((current->info.getQtyOnHand() >= deleteItem.getQtyOnHand() && code == 1) ||
              (current->info.getWholesale() >= deleteItem.getWholesale() && code == 2) ||
              (current->info.getDateAdded() >= deleteItem.getDateAdded() && code == 3))
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
