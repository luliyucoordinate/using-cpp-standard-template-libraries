#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <iomanip>
#include <sstream>	//istringstream
#include <set>
#include <vector>
using std::string;

int main()
{
	std::cout << "Enter some text and enter * to end:\n";
	string text_in{};
	std::getline(std::cin, text_in, '*');
	std::replace_if(std::begin(text_in), std::end(text_in),
		[](const char& ch) { return !isalpha(ch); }, ' ');	//非字母元素用space代替
	std::istringstream text(text_in);
	std::istream_iterator<string> begin(text);
	std::istream_iterator<string> end;

	std::vector<string> words;	//容纳单词
	std::for_each(begin, end, [&words](const string& word) {words.push_back(word); });

	auto words_copy = words;
	do
	{
		std::copy(std::begin(words), std::end(words), std::ostream_iterator<string>{std::cout, " "});
		std::cout << std::endl;
		std::next_permutation(std::begin(words), std::end(words));
	} while (words != words_copy);
	system("pause");
}