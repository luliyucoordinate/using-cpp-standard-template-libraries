#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iterator>
using namespace std;
int fun(int low, int high, string str, int index)
{
	if (index == 0 || index == 1)
	{
		return 1;
	}
	if (str.at(low) != str.at(high))
	{
		return 0;
	}
	return fun(low + 1, high - 1, str, index - 2);
}
int main()
{
	stack<char> words;
	bool flag{};
	string exp;
	try
	{
		while (true)
		{
			size_t index{};
			getline(cin, exp, '\n');
			if (exp.empty()) break;
			while (index != exp.length())
			{
				words.push(exp.at(index++));
			}
			exp.erase(remove(begin(exp), end(exp), ' '), end(exp));
			exp.erase(remove(begin(exp), end(exp), '?'), end(exp));
			exp.erase(remove(begin(exp), end(exp), ','), end(exp));
			exp.erase(remove(begin(exp), end(exp), '.'), end(exp));
			
			while (!words.empty())
			{
				cout << words.top();
				words.pop();
			}
			index = exp.length();
			if (fun(0, index - 1, exp, index))
			{
				cout << "  OK" << endl;
			}
			else
			{
				cout << "  NO" << endl;
			}
		}
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
	system("pause");
}