#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iomanip>

using std::string;
using People = std::pair<string, size_t>;

int main()
{
	string word;
	std::cout << "Enter some people information name and old, Enter * to end:" << std::endl;
	std::getline(std::cin, word, '*');


	string file_out{ "../People.txt" };
	std::ofstream out{ file_out, std::ios_base::out | std::ios_base::trunc };
	std::copy(std::begin(word), std::end(word), std::ostream_iterator<char>(out, ""));
	out.close();
	string file_in{ "../People.txt" };
	std::ifstream in{file_in};
	if (!in)
	{
		std::cerr << file_in << " not open. " << std::endl;
		exit(1);
	}
	std::copy(std::istream_iterator<char>{in >> std::noskipws}, std::istream_iterator<char>{},
		std::ostream_iterator<char>{std::cout});
	in.close();
	system("pause");
}