#include <iostream>
using namespace std;

void drawShape(int n)
{
  int lineCnt = 0;
	int charCnt;
	for (charCnt = 0; charCnt<n; charCnt++)
	{
		cout << "*";
	}
	if(lineCnt != n)
	{
		cout << endl;
		drawShape(n-1);
		lineCnt++;
	}

	charCnt = n;
	lineCnt = n;
	for (charCnt = n; charCnt>0; charCnt--)
	{
		cout << "*";
	}
	if(lineCnt != 0)
	{
		--lineCnt;
		cout << endl;
	}
}

int main()
{
  int lines;

  cout << "Enter number of lines: ";
  cin >> lines;

  drawShape(lines);

  return 0;
}
