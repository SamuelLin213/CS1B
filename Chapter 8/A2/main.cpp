#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void getData(int, string[], int[][2]);
double averageHigh(int, int);
double averageLow(int, int);
int indexHighTemp(int[][2]);
int indexLowTemp(int[][2]);

int main(){
  const int MONTHS = 12;
  int temps[MONTHS][2];
  int sumH = 0;
  int sumL = 0;
  double avgH = 0.0;
  double avgL = 0.0;
  string months[12] = {"January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"};

  getData(MONTHS, months, temps);

  //calculate sums of highs and lows
  for(int i = 0; i < MONTHS; i++){
    sumL += temps[i][1];
    sumH += temps[i][0];
  }

  //prints summary
  cout << setprecision(4) << "Average Hi: " << averageHigh(sumH, MONTHS) << "\370" << endl;
  cout << "Average Low: " << averageLow(sumL, MONTHS) << "\370" << endl;
  cout << "Highest Temperature: " << fixed << setprecision(2) <<
  1.0*temps[indexHighTemp(temps)][0] << "\370" << " Month: "
  << months[indexHighTemp(temps)] << endl;
  cout << "Lowest Temperature: " << fixed << setprecision(2)
  << 1.0*temps[indexLowTemp(temps)][1] << "\370" << " Month: "
  << months[indexLowTemp(temps)] << endl;
}

void getData(int MONTHS, string months[], int temps[][2]){

  //read data
  for(int i = 0; i < MONTHS; i++)
  {
    cout << months[i] << ":" << endl;
    for(int x = 0; x < 2; x++){
      if(x == 0){
        cout << "-- Enter High: ";
        cin >> temps[i][x];
      }
      else{
        cout << "-- Enter Low: ";
        cin >> temps[i][x];
      }
    }
  }

  cout << endl << "Yearly Statistics:" << endl;
}

double averageHigh(int sumH, int MONTHS){
    return (1.0*sumH/MONTHS);
}

double averageLow(int sumL, int MONTHS){
    return (1.0*sumL/MONTHS);
}

int indexHighTemp(int temps[][2]){
  int indexH = 0;
  for(int i = 0; i < 12; i++){
    if(temps[indexH][0] < temps[i][0])
    {
      indexH = i;
    }
  }
  return indexH;
}

int indexLowTemp(int temps[][2]){
  int indexL = 0;
  for(int i = 0; i < 12; i++){
    if(temps[indexL][1] > temps[i][1]){
      indexL = i;
    }
  }
  return indexL;
}
