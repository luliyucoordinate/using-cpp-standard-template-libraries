#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
int main()
{
	list<string> addresses;
	string address;
	while (getline(cin, address, '\n'), !address.empty())
	{
		addresses.push_front(address);
	}
	addresses.sort();
	for (auto& i : addresses)
	{
		cout << setw(12) << i << endl;
	}
	system("pause");
}