#include <iostream>
#include <string>
using namespace std;
int main()
{
	string data[]{ "123", "321", "456", "654" };
	for (auto iter = begin(data); iter != end(data); ++iter)
	{
		cout << *iter << endl;
	}
	system("pause");
}