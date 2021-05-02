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
    double score = 0;
    int numCorrect = 0;
    int i = 0;

    ifstream inData;
    inData.open("data.txt");

    //store answer key
    inData >> ansKey;
    cout << ansKey << endl;

    while(inData.peek()!=EOF)
    {
      if(inData.fail()){
        break;
      }
      inData >> ids;
      cout << ids.length();
      numCorrect = 0;
      inData.get(ch);
      getline(inData, responses, '\n');

      for(int x = 0; x < responses.length()-1; x++)
      {
        if(responses.at(x) == ' ')
        {
          numCorrect += 0;
        }
        else if(responses.at(x) == ansKey.at(x))
        {
          numCorrect += 2;
        }
        else
        {
          numCorrect -= 1;
        }
      }
      cout << ids.length() << " " << responses.length() << " " << numCorrect << endl;

      cout << setw(8) << ids << " " << left << setw(20) << responses << endl;

      i++;
    }

    inData.close();
    return 0;
}
