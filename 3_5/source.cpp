#include <iostream>
#include <queue>
#include <iterator>
#include <string>
#include <memory>
using namespace std;
int main()
{
	//priority_queue<string> words;
	string word;	
	auto comp = [](const shared_ptr<string>& cp1, const shared_ptr<string>& cp2) {
		return *cp1 < *cp2;
	};
	priority_queue<shared_ptr<string>, vector<shared_ptr<string>>, decltype(comp)> words{ comp };
	cout << "Enter words separated by spaces, enter Ctrl+Z on a separate" << endl;
	while (true)
	{
		if ((cin >> word).eof())
		{
			cin.clear();
			break;
		}
		words.push(make_shared<string>(word));
	}
	while (!words.empty())
	{
		cout << *words.top() << endl;
		words.pop();
	}
	system("pause");
}