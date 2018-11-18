#pragma once
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>


using Book = std::string;
using people = std::string;
using Group_books = std::set<Book>;
using group = std::pair<people, Group_books>;

class List_group
{
public:
	void operator() (const group& g)
	{
		std::cout << "\n\n" << g.first << " " << g.second.size() << " books:\n";
		std::copy(std::begin(g.second), std::end(g.second), 
			std::ostream_iterator<Book>(std::cout, " "));
	}
};