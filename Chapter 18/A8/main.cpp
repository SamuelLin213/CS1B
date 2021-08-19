#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct playerType{
  string id;
  string name;
  int games;
  int completions;
  int attempts;
  double compPercent;
  int yards;
  int touchdowns;
  int interceptions;
  int fumbles;
  string team;
};
const int SIZE = 100;
int playerNum = 0;

void readFile(playerType players[], ifstream&);
void printTeam(playerType players[]);
void menu(playerType players[]);
int lookUpPlayer(playerType players[]);
void editPlayer(playerType players[]);
void printPlayer(playerType players[], int);
void sortArray(playerType players[]);

int main(){
  ifstream inData;
  inData.open("players.txt");
  playerType players[SIZE];

  readFile(players, inData);
  menu(players);
}


//functions
void menu(playerType players[])
{
  int choice = 0;
  int index = 0;

  while(choice != 4){
    cout << "\033[2J\033[1;1H";
    cout << "<1> Look up a player" << endl;
    cout << "<2> Edit a player" << endl;
    cout << "<3> Print league QB statistics" << endl;
    cout << "<4> To quit" << endl;

    cout << endl << "Choice(1-4): ";
    cin >> choice;

    switch(choice){
      case 1:
        index = lookUpPlayer(players);

        if(index >= 0)
        {
          cout << "\033[2J\033[1;1H";

          cout << left << setw(7) << "ID" << setw(20) << "Name" << setw(13) << "Games Played"
          << setw(12) << "Completions" << setw(9) << "Attempts" << setw(7) << "Pass %"
          << setw(9) << "Pass Yds" << setw(10) << "TD Passes" << setw(5) << "Ints"
          << setw(8) << "Fumbles" << setw(4) << "Team" << endl;

          printPlayer(players, index);

          cin.ignore();
          cin.get();
        }

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
  vector<int> indexes;
  char choice = 'n';

  for(int i = 0; i < playerNum; i++){
    if(players[i].name.find(searchStr) != std::string::npos)
    {
      indexes.push_back(i);
    }
  }

  if((int)indexes.size() > 0)
  {
    for(int i = 0; i < (int)indexes.size(); i++)
    {
      cout << endl << "Found player " << players[indexes[i]].name << endl;
      cout << "View this player? <Y/N> ";
      cin >> choice;

      if(toupper(choice) == 'Y')
      {
        return indexes[i];
      }
      cout << endl;
    }
    cout << endl << "Error: player not found.";
    cin.ignore();
    cin.get();
  }
  else
  {
    cout << endl << "Error: player not found.";
    cin.ignore();
    cin.get();
    return -1;
  }
  return -1;
}

void editPlayer(playerType players[])
{
  int choice = 0;
  //int index = 0;
  int fnd = lookUpPlayer(players);

  if(fnd != -1){
    while(choice != 11){
      cout << "\033[2J\033[1;1H";
      cout << left << "Edit player" << endl;
      cout << setw(36) << "" << "CURRENT VALUES" << endl;
      cout << setw(36) << "<1> Edit id: " << players[fnd].id << endl;
      cout << setw(36) << "<2> Edit name: " << players[fnd].name << endl;
      cout << setw(36) << "<3> Edit games: " << players[fnd].games << endl;
      cout << setw(36) << "<4> Edit completions: " << players[fnd].completions << endl;
      cout << setw(36) << "<5> Edit attempts: " << players[fnd].attempts << endl;
      cout << setw(36) << "<6> Edit yards: " << players[fnd].yards << endl;
      cout << setw(36) << "<7> Edit touchdowns: " << players[fnd].touchdowns << endl;
      cout << setw(36) << "<8> Edit interceptions: " << players[fnd].interceptions << endl;
      cout << setw(36) << "<9> Edit fumbles: " << players[fnd].fumbles << endl;
      cout << setw(36) << "<10> Edit team: " << players[fnd].team << endl;
      cout << setw(36) << "<11> Return to main menu " << endl;

      cout << endl << "Choice(1-11): ";
      cin >> choice;

      switch(choice){
        case 1:
          cout << endl << "Id: ";
          cin >> players[fnd].id;
          break;
        case 2:
          cout << endl << "Name: ";
          cin >> players[fnd].name;
          break;
        case 3:
          cout << endl << "Games: ";
          cin >> players[fnd].games;
          break;
        case 4:
          cout << endl << "Completions: ";
          cin >> players[fnd].completions;
          break;
        case 5:
          cout << endl << "Attempts: ";
          cin >> players[fnd].attempts;
          break;
        case 6:
          cout << endl << "Yards: ";
          cin >> players[fnd].yards;
          break;
        case 7:
          cout << endl << "Touchdowns: ";
          cin >> players[fnd].touchdowns;
          break;
        case 8:
          cout << endl << "Interceptions: ";
          cin >> players[fnd].interceptions;
          break;
        case 9:
          cout << endl << "Fumbles: ";
          cin >> players[fnd].fumbles;
          break;
        case 10:
          cout << endl << "Team: ";
          cin >> players[fnd].team;
          break;
      }
    }
  }
}

void printTeam(playerType players[]){
  sortArray(players);
  bool tenth = false;

  cout << "\033[2J\033[1;1H";

  cout << left << setw(7) << "ID" << setw(20) << "Name" << setw(13) << "Games Played"
  << setw(12) << "Completions" << setw(9) << "Attempts" << setw(7) << "Pass %"
  << setw(9) << "Pass Yds" << setw(10) << "TD Passes" << setw(5) << "Ints"
  << setw(8) << "Fumbles" << setw(4) << "Team" << endl;

  sortArray(players);

  for(int i = 0; i < playerNum; i++)
  {
    tenth = false;

    printPlayer(players, i);
    if((i+1) % 10 == 0)
    {
      if(i == 9)
      {
          cin.ignore();
      }
      tenth = true;
      cin.get();

      cout << "\033[2J\033[1;1H";

      cout << left << setw(7) << "ID" << setw(20) << "Name" << setw(13) << "Games Played"
      << setw(12) << "Completions" << setw(9) << "Attempts" << setw(7) << "Pass %"
      << setw(9) << "Pass Yds" << setw(10) << "TD Passes" << setw(5) << "Ints"
      << setw(8) << "Fumbles" << setw(4) << "Team" << endl;
    }
  }
  if(!tenth)
  {
    cin.get();
  }
}

void printPlayer(playerType players[], int index)
{
  cout << left << setw(7) << players[index].id << setw(20) << players[index].name
  << setw(12) << right << players[index].games << setw(12) << players[index].completions
  << setw(9) << players[index].attempts << setw(7) << fixed
  << setprecision(2) << players[index].compPercent
  << setw(9) << players[index].yards << setw(10) << players[index].touchdowns
  << setw(5) << players[index].interceptions << setw(8) << players[index].fumbles
  << setw(5) << players[index].team << endl;
}

void readFile(playerType players[], ifstream &inData)
{
  string tempFirst;
  string tempLast;
  int x = 0;
  while(inData >> players[x].id)
    {
      inData >> tempFirst;
      inData >> tempLast;
      players[x].name = tempFirst + " " + tempLast;
      inData >> players[x].games;
      inData >> players[x].completions;
      inData >> players[x].attempts;
      inData >> players[x].yards;
      inData >> players[x].touchdowns;
      inData >> players[x].interceptions;
      inData >> players[x].fumbles;
      players[x].compPercent = 100.00*players[x].completions/players[x].attempts;

      inData >> players[x].team;

      playerNum++;
      x++;

      if(inData.eof()){
        break;
      }
    }
}
void sortArray(playerType players[])
{
  int largestIndex = 0;

  for(int x = 0; x < playerNum; x++)
  {
    largestIndex = x;
    for(int i = 1+x; i < playerNum; i++)
    {
      if(players[largestIndex].touchdowns < players[i].touchdowns)
      {
        largestIndex = i;
      }
    }
    playerType temp = players[x];
    players[x] = players[largestIndex];
    players[largestIndex] = temp;
  }
}
