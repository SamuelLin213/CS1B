#ifndef UNORDEREDLISTTYPE_H
#define UNORDEREDLISTTYPE_H

class unorderedArrayListType: public arrayListType
{
public:
  void insertAt(int location, int insertItem)
  {
    if (location < 0 || location >= maxSize)
      cout << "The position of the item to be inserted "
        << "is out of range." << endl;
    else if (length >= maxSize)
      cout << "Cannot insert in a full list" << endl;
    else
    {
      for (int i = length; i > location; i--)
        list[i] = list[i - 1];
      list[location] = insertItem;
      length++;
    }
  }
  void insertEnd(int insertItem)
  {
    if (length >= maxSize) //the list is full
      cout << "Cannot insert in a full list." << endl;
    else
    {
      list[length] = insertItem;
      length++;
    }
  }
  void replaceAt(int location, int repItem)
  {
    if (location < 0 || location >= length)
      cout << "The location of the item to be "
        << "replaced is out of range." << endl;
    else
      list[location] = repItem;
  }
  int seqSearch(int searchItem) const
  {
    int loc;
    bool found = false;
    loc = 0;
    while (loc < length && !found)
    {
      if (list[loc] == searchItem)
        found = true;
      else
        loc++;
    }
    if (found)
      return loc;
    else
      return -1;
  }
  void remove(int removeItem)
  {
    int loc;
    if (length == 0)
      cout << "Cannot delete from an empty list." << endl;
    else
    {
      loc = seqSearch(removeItem);
      if (loc != -1)
        removeAt(loc);
      else
        cout << "The item to be deleted is not in the list."
          << endl;
    }
  }
  unorderedArrayListType(int size = 100)
    :arrayListType(size)
  {
  }

};

#endif
