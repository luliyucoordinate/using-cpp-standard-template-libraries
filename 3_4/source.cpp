#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <memory>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;
int main()
{
	deque<shared_ptr<string>>  words;
	list<shared_ptr<string>> words2;
	string word;
	cout << "Enter words swparated by spaces, enter Ctrl+Z on a separate line to end:\n" << endl;
	while (true)
	{
		if ((cin >> word).eof())
		{
			cin.clear();
			break;
		}
		words.push_back(make_shared<string>(word));
	}
	//words2.insert(begin(words2), begin(words), end(words));
	copy(begin(words), end(words), back_inserter(words2));
	words2.sort([](const shared_ptr<string>& s1, const shared_ptr<string>& s2) {
		return *s1 > *s2;
	});
	system("pause");
}