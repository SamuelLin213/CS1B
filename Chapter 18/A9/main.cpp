#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <string.h>
using namespace std;

void insertionSort(int list[], int length, unsigned long long int &compares, unsigned long long int &swaps);
void selectionSort(int list[], int length, unsigned long long int &compares, unsigned long long int &swaps);
void bubbleSort(int list[], int length, unsigned long long int &compares, unsigned long long int &swaps);
const int SIZE = 200000;

int main()
{
  int numArr[SIZE];
  double duration;
  ifstream inFile;
  unsigned long long int numComp = 0;
  unsigned long long int numSwap = 0;
  clock_t start;
  clock_t end;

  // inFile.open("numbers.txt");
  //
  // cout << "Reading in the data..." << endl;
  // for(int i = 0; i < SIZE; i++)
  // {
  //   inFile >> numArr[i];
  // }
  //
  // //selection sort
  // cout << "Calling selection sort..." << endl;
  // start = clock();
  // selectionSort(numArr, SIZE, numComp, numSwap);
  // end = clock();
  // duration = (end - start) / (double) CLOCKS_PER_SEC;
  //
  // cout << "Selection sort - C: " << numComp << " W: " << numSwap << " Time: "
  // << static_cast<int>(duration) << " secs" << endl << endl;
  // inFile.close();
	// memset(numArr, 0, SIZE);
  //
  // numComp = 0;
  // numSwap = 0;
  //
  // //insertion sort
  // cout << "Reading in the data..." << endl;
  // inFile.open("numbers.txt");
  // for(int i = 0; i < SIZE; i++)
  // {
  //   inFile >> numArr[i];
  // }
  //
  // cout << "Calling insertion sort..." << endl;
  // start = clock();
  // insertionSort(numArr, SIZE, numComp, numSwap);
  // end = clock();
  // duration = (end - start) / (double) CLOCKS_PER_SEC;
  //
  // cout << "Insertion sort - C: " << numComp << " W: " << numSwap << " Time: "
  // << static_cast<int>(duration) << " secs" << endl << endl;
  // inFile.close();
	// memset(numArr, 0, SIZE);
  //
  // numComp = 0;
  // numSwap = 0;

  //bubble sort
  cout << "Reading in the data..." << endl;
  inFile.open("numbers.txt");
  for(int i = 0; i < SIZE; i++)
  {
    inFile >> numArr[i];
  }

  cout << "Calling bubble sort..." << endl;
  start = clock();
  bubbleSort(numArr, SIZE, numComp, numSwap);
  end = clock();
  duration = (end - start) / (double) CLOCKS_PER_SEC;

  cout << "Bubble sort - C: " << numComp << " W: " << numSwap << " Time: "
  << static_cast<int>(duration) << " secs" << endl;
  inFile.close();
	memset(numArr, 0, SIZE);

  return 0;
}

void selectionSort(int list[], int length, unsigned long long int &compares, unsigned long long int &swaps)
{
  int index;
  int smallestIndex;
  int location;
  int temp;

  for (index = 0; index < length - 1; index++)
  {
    //Step a
    smallestIndex = index;

    for (location = index + 1; location < length; location++)
    {
      if (list[location] < list[smallestIndex])
      {
          smallestIndex = location;
      }
      compares++;
    }


    //Step b
    temp = list[smallestIndex];
    list[smallestIndex] = list[index];
    list[index] = temp;
    swaps+=3;
  }
}
void insertionSort(int list[], int length, unsigned long long int &compares, unsigned long long int &swaps)
{
  int first;
  int index;

  for(int i = 1; i < length; i++)
  {
    compares++;
    first = list[i];
    index = i - 1;

    while (index >= 0 && list[index] > first)
    {
        list[index + 1] = list[index];
        index = index - 1;
        compares++;
        swaps++;
    }
    list[index + 1] = first;
  }
}
void bubbleSort(int list[], int length, unsigned long long int &compares, unsigned long long int &swaps)
{
  for(int i = 1; i < length; i++)
  {
    for(int j = 0; j < length-i; j++)
    {
      compares++;
      if(list[j] < list[j-1])
      {
        swaps+= 3;
        int temp = list[j];
        list[j] = list[j-1];
        list[j-1] = temp;
      }
    }
  }
}
