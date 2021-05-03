#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct playerType{
  string name;
  string position;
  int touchdowns;
  int catches;
  int yardsPass;
  int yardsRsh;
  int yardsRcv;
}

void readFile(ifstream, playerType);
void print(playerType);

int main(){
  ifstream inData;
  inData.open("data.txt");
  ofstream outData;
  ouData.open("output.txt");
  playerType players[10];

  readFile();
}

void readFile(ifstream inData, const playerType& players ){
  int count = 0;

  while(inData >> players[count].name){
    inData >> players[count].position >> players[count].touchdowns
    >> players[count].catches >> players[count].yardsPass >> players[count].yardsRsh
    >> players[count].yardsRcv;
  }
}
