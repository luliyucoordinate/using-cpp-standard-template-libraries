#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>
using namespace std;
int main()
{
	priority_queue<string> words;
	string word;
	cout << "Enter words separated by spaces, enter Ctrl+Z on a separate" << endl;
	while (true)
	{
		if ((cin >> word).eof())
		{
			break;
		}
		words.push(word);
	}
	system("pause");
}