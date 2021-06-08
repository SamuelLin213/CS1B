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
};

void readFile(playerType players[], ifstream&);
void printTeam(playerType players[]);
void menu(playerType players[]);
int lookUpPlayer(playerType players[]);
void editPlayer(playerType players[]);
void printPlayer(playerType players[], int);
void writeFile(playerType players[], ofstream&);

int main(){
  ifstream inData;
  inData.open("data.txt");
  ofstream outData;
  outData.open("output.txt");
  playerType players[10];

  readFile(players, inData);
  menu(players);
  writeFile(players, outData);
}


//functions
void menu(playerType players[])
{
  int choice = 0;
  int num = 0;
  while(choice != 4){
    cout << "\033[2J\033[1;1H";
    cout << "<1> Look up a player" << endl;
    cout << "<2> Edit a player" << endl;
    cout << "<3> Print team roster" << endl;
    cout << "<4> To quit" << endl;

    cout << endl << "Choice(1-4): ";
    cin >> choice;

    switch(choice){
      case 1:
        num = lookUpPlayer(players);
        break;
      case 2:
        editPlayer(players);
        break;
      case 3:
        printTeam(players);
        break;
    }
  }
}

int lookUpPlayer(playerType players[])
{ 
  string searchStr;
  cout << endl << "Search: ";
  cin >> searchStr;

  for(int i = 0; i < 10; i++){
    if(players[i].name.find(searchStr) != std::string::npos)
    {
      cout << endl << "found player " << players[i].name;
      cin.ignore();
      cin.get();
      return i;
    }
  }
  cout << endl << "not found";
  cin.ignore();
  cin.get();
  return -1;
}

void editPlayer(playerType players[])
{
  int choice = 0;
  int index = 0;
  int fnd = lookUpPlayer(players);
  if(fnd != -1){
    while(choice != 8){
      cout << "\033[2J\033[1;1H";
      cout << left << "Edit player" << endl;
      cout << setw(36) << "" << "CURRENT VALUES" << endl;
      cout << setw(36) << "<1> Edit name " << players[fnd].name << endl;
      cout << setw(36) << "<2> Edit position " << players[fnd].position << endl;
      cout << setw(36) << "<3> Edit touch downs " << players[fnd].touchdowns << endl;
      cout << setw(36) << "<4> Edit catches " << players[fnd].catches << endl;
      cout << setw(36) << "<5> Edit passing yards " << players[fnd].yardsPass << endl;
      cout << setw(36) << "<6> Edit receiving yards " << players[fnd].yardsRcv << endl;
      cout << setw(36) << "<7> Edit rushing yards " << players[fnd].yardsRsh << endl;
      cout << setw(36) << "<8> Return to main menu " << endl;

      cout << endl << "Choice(1-8): ";
      cin >> choice;

      switch(choice){
        case 1:
          cout << endl << "Name: ";
          cin >> players[fnd].name;
          break;
        case 2:
          cout << endl << "Position: ";
          cin >> players[fnd].position;
          break;
        case 3:
          cout << endl << "Touchdowns: ";
          cin >> players[fnd].touchdowns;
          break;
        case 4:
          cout << endl << "Catches: ";
          cin >> players[fnd].catches;
          break;
        case 5:
          cout << endl << "Passing yards: ";
          cin >> players[fnd].yardsPass;
          break;
        case 6:
          cout << endl << "Receiving yards: ";
          cin >> players[fnd].yardsRcv;
          break;
        case 7:
          cout << endl << "Rushing yards: ";
          cin >> players[fnd].yardsRsh;
          break;
      }
    }
  }
}

void printTeam(playerType players[]){
  cout << "\033[2J\033[1;1H";
  cout << left << setw(20) << "Name" << setw(6) << "Pos" << setw(6) << "TDs" << setw(10)
  << "Catches" << setw(7) << "Pass" << setw(7) << "Recv" << setw(7) << "Rush" << endl;
  for(int i = 0; i < 10; i++)
  {
    printPlayer(players, i);
  }
  cin.ignore();
  cin.get();
}

void printPlayer(playerType players[], int index)
{
  cout << left << setw(20) << players[index].name << setw(6) << players[index].position << setw(6) << players[index].touchdowns << setw(10)
  << players[index].catches << setw(7) << players[index].yardsPass << setw(7) << players[index].yardsRcv << setw(7) << players[index].yardsRsh << endl;
}

void readFile(playerType players[], ifstream &inData)
{
  int x = 0;
  while(inData.peek()!=EOF)
    {
      if(inData.fail()){
        break;
      }
      getline(inData >> ws, players[x].name, '\n');
      inData.clear();
      inData >> players[x].position;
      inData >> players[x].touchdowns;
      inData >> players[x].catches;
      inData >> players[x].yardsPass;
      inData >> players[x].yardsRsh;
      inData >> players[x].yardsRcv;
      x++;
    }
}

void writeFile(playerType players[], ofstream& outData)
{
  for(int x = 0; x < 10; x++){
      outData << players[x].name << endl;
      outData << players[x].position << endl;
      outData << players[x].touchdowns << endl;
      outData << players[x].catches << endl;
      outData << players[x].yardsPass << endl;
      outData << players[x].yardsRsh << endl;
      outData << players[x].yardsRcv << endl;
  }
}