#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
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
	deque<string> addresses2{make_move_iterator(begin(addresses)), make_move_iterator(end(addresses))};
	sort(begin(addresses2), end(addresses2));
	copy(begin(addresses2), end(addresses2), ostream_iterator<string>(cout, "\n"));
	system("pause");
}