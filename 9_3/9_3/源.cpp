
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iterator>

using std::string;
using people = std::pair<string, size_t>;

int main()
{
	string file_in{ "../People.txt" };
	std::ifstream in{ file_in };
	if (!in)
	{
		std::cerr << file_in << " not open." << std::endl;
		exit(1);
	}
	std::stringstream instr;
	//std::copy(std::istreambuf_iterator<char>{in},
	//	std::istreambuf_iterator<char>(),
	//	std::ostreambuf_iterator<char>{instr});
	instr << in.rdbuf();			//这是一种更加简洁的方法
	in.close();


	instr.clear();
	instr.seekg(0);
	std::istream_iterator<string> in_str{ instr };
	std::istream_iterator<size_t> in_size{ instr };

	std::map<string, size_t> People;
	while (true)
	{
		string word = *in_str;
		size_t number = *in_size;
		if (word == "*") break;
		++in_str;
		++in_size;
		People.insert({ word, number });
	}
	//使用输出流迭代器输出到标准输出流
	std::ostream_iterator<string> out_str{ std::cout };
	std::ostream_iterator<size_t> out_size{ std::cout };
	for (const auto& p : People)
	{
		*out_str++ = p.first;
		*out_size++ = p.second;
	}
	system("pause");
}