#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
using std::string;
using people = std::pair<string, size_t>;

//这个问题处理的并不是很好，我对于这个题目的题意不是非常的理解
int main()
{
	string file_in{ "../People.txt" };
	std::ifstream in{ file_in };
	if (!in)
	{
		std::cerr << file_in << " not open." << std::endl;
		exit(1);
	}
	string file_out{ "../People_copy.txt" };
	std::ofstream out{ file_out, std::ios_base::out | std::ios_base::trunc };

	//这样做相当于复制
	//std::copy(std::istream_iterator<char>{in >> std::noskipws},
	//	std::istream_iterator<char>{},
	//	std::ostream_iterator<char>{out});
	in.clear();
	in.seekg(0);
	std::istream_iterator<string> in_str{ in };
	std::istream_iterator<size_t> in_size{ in };

	std::vector<people> People;
	while (true)
	{
		string word = *in_str;
		size_t number = *in_size;
		if (word == "*") break;
		++in_str;
		++in_size;
		People.push_back(std::make_pair(word, number));
	}
	std::ostream_iterator<string> out_str{ out };
	std::ostream_iterator<size_t> out_size{ out };
	for (auto& iter = std::rbegin(People); iter < std::rend(People); ++iter)
	{
		*out_str++ = iter->first;
		*out_size++ = iter->second;
		out << std::endl;
	}
	
	in.close();
	out.close();
	system("pause");

}