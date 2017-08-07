#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>
using namespace std;
int main()
{
	string data[]{ "and", "fhds", "wer", "pifop" };
	transform(begin(data), end(data),
		ostream_iterator<string>(cout, "\n"),
		[](string i) {
		transform(begin(i), end(i), begin(i), toupper);
		return i;
	}
	);
	system("pause");
}