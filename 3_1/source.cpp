#include <iostream>
#include <deque>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
	deque<string> words;
	list<string> words2;
	string word;
	while (true)
	{
		if ((cin >> word).eof())
		{
			cin.clear();
			break;
		}
		words.push_back(word);
	}
	copy(begin(words), end(words), back_inserter(words2));
	words2.sort(greater<>());
	//sort(begin(words2), end(words2));
	system("pause");
}