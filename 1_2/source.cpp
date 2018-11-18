#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
	string data[]{ "and", "fhds", "wer", "pifop" };
	transform(begin(data), end(data), 
		ostream_iterator<string>(cout , "\n"),
		[](string i) {
		for (auto iter = begin(i); iter != end(i); ++iter)
		{
			if (*iter == 'a' || *iter == 'e' || *iter == 'i' || *iter == 'o' || *iter == 'u')
			{
				*iter = '*';
			}
		}
		return i;
		}
	);
	system("pause");
}