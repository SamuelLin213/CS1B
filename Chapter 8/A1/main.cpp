#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    const int MAX_STUDENTS = 150;
    const int NUM_QUESTIONS = 21;
    string ansKey;
    string responses;
    string ids;
    char ch;
    int points = 0;
    double percent = 0.0;
    char grade;

    ifstream inData;
    inData.open("data.txt");

    //store answer key
    inData >> ansKey;
    cout << setw(9) << left << "Key: " << ansKey << endl;

    while(inData.peek()!=EOF)
    {
      if(inData.fail()){
        break;
      }
      inData >> ids;
      //cout << ids.length();
      points = 0;
      inData.get(ch);
      getline(inData, responses, '\n');

      for(int x = 0; x < responses.length(); x++)
      {
        if(responses.at(x) == ansKey.at(x))
        {
          points += 2;
        }
        else if(responses.at(x) != ' ')
        {
          points -= 1;
        }
      }
      percent = points/40.0*100;

      if(percent < 60.0) grade = 'F';
      else if(percent < 70) grade = 'D';
      else if (percent < 80) grade = 'C';
      else if (percent < 90) grade = 'B';
      else grade = 'A';

      cout << setw(8) << ids << " " << left << setw(20) << responses << " " << points << " " << grade << endl;
    }

    inData.close();
    return 0;
}
