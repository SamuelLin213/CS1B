#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void readFile(ifstream&, int[], int);
void binary(int numbers[], int &, int, int);
void linear(int numbers[], int &, int, int);
void sort(int numbers[], int size);

int main()
{
  const int ARRAY_SIZE = 200000;
  ifstream inData;
  inData.open("numbers.txt");
  int target = -1;
  int comp1 = 0;
  int comp2 = 0;
  int choice = -1;
  int numbers[ARRAY_SIZE];

  readFile(inData, numbers, ARRAY_SIZE);
  cout << "Numbers read!";
  cin.get();
  cout << "Sorting numbers...";
  cin.get();
  sort(numbers, ARRAY_SIZE);
  cout << "Numbers sorted!";
  cin.get();

  while(choice != 4){
    cout << "\033[2J\033[1;1H";
    cout << "Current target: " << target << endl;

    cout << setw(8) << left << "Linear:" << setw(7) << comp1 << "comparisons" << endl;
    cout << setw(8) << left << "Binary:" << setw(7) << comp2 << "comparisons" << endl;

    cout << "<1> Enter integer to search" << endl;
    cout << "<2> Linear search" << endl;
    cout << "<3> Binary search" << endl;
    cout << "<4> Quit" << endl;

    cout << endl << "Choose from the menu (1-4): ";
    cin >> choice;

    switch(choice){
      case 1:
        cout << endl << "New target integer: ";
        cin >> target;
        break;
      case 2:
        linear(numbers, comp1, target, ARRAY_SIZE);
        break;
      case 3:
        binary(numbers, comp2, target, ARRAY_SIZE);
        break;
    }
  }
  return 0;
}
void sort(int numbers[], int size)
{
  int index, smallestIndex, location, temp;
  for(index = 0; index < size - 1; index++)
	{
		smallestIndex = index;

		for(location = index + 1; location < size; location++)
		{
			if(numbers[location] < numbers[smallestIndex])
			{
				smallestIndex = location;
			}
		}

		temp = numbers[smallestIndex];
		numbers[smallestIndex] = numbers[index];
		numbers[index] = temp;
	}
}
void readFile(ifstream &inData, int numbers[], int size){
  // int x = 0;
  // while(inData.peek()!=EOF)
  // {
  //     if(inData.fail()){
  //       break;
  //     }
  //     inData >> numbers[x];
  //     x++;
  // }
  for(int i = 0; i < size; i++)
	{
		inData >> numbers[i];
	}
}
void binary(int numbers[], int &comp2, int target, int size)
{
  int first = 0;
  int last = size - 1;
  int mid;
  comp2 = 0;

  bool found = false;

  while (first <= last && !found)
  {
    mid = (first + last) / 2;
    if (numbers[mid] == target)
    {
      comp2++;
      found = true;
    }
    else if (numbers[mid] > target)
    {
      comp2 += 2;
      last = mid - 1;
    }
    else
    {
      comp2 += 2;
      first = mid + 1;
    }
  }
}
void linear(int numbers[], int &comp1, int target, int size)
{
  comp1 = 0;
  bool found = false;
  int i = 0;
  while(i < size && !found)
  {
    comp1++;
    if(numbers[i] == target)
    {
      found = true;
      break;
    }
    i++;
  }
}
