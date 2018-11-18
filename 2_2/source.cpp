#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
int main()
{
	vector<string> address;
	copy(istream_iterator<string>{cin},
		istream_iterator<string>{},
		back_inserter(address));
	sort(begin(address), end(address));
	for (auto& i : address)
	{
		cout << setw(12) << i << endl;
	}
	system("pause");
}