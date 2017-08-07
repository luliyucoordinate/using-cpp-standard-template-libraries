#include <iostream>
#include <vector>
#include <iterator>
#include <memory>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string word;
	vector<shared_ptr<string>> words;
	words.reserve(100);
	cout << "Enter words separated by spaces, enter Ctrl+Z on a separate" << endl;
	while (true)
	{
		if ((cin >> word).eof())
		{
			cin.clear();
			break;
		}
		words.push_back(make_shared<string>(word));
	}
	sort(begin(words), end(words), [](const shared_ptr<string>& s1, const shared_ptr<string>& s2) {
		return *s1 > *s2;
	});
	system("pause");
}