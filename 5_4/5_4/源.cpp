#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include "List_group.h"

using Distribution = std::uniform_int_distribution<size_t>;
static std::default_random_engine gen_value;

using std::string;
using std::vector;
using Book = string;
using Books = std::vector<Book>;
using people = string;
using Peoples = std::vector<people>;
using Group_books = std::set<Book>;
using group = std::pair<people, Group_books>;
using Group = std::multimap<people, Group_books>;

Group_books make_books(const Books& books, size_t group_size, const Distribution& choose_books)
{
	Group_books group_books;
	while (group_books.size() < group_size)
	{
		group_books.insert(books[choose_books(gen_value)]);
	}
	return group_books;
}

//Peoples create_people()
//{
//	Peoples p;
//	string first_names[]{ "Ann", "Jim", "Eve", "Dan", "Ted" };
//	string second_names[]{ "Smith", "Jones", "Howe", "Watt", "Beck" };
//	for (const auto& first : first_names)
//	{
//		for (const auto& second : second_names)
//		{
//			p.emplace_back(first, second);
//		}
//	}
//	return p;
//}

int main()
{
	Books books{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
	Peoples peoples{ "Ann", "Jim", "Eve", "Dan", "Ted" };
	Group people_book;
	Distribution book_size{ 4,6 };
	Distribution group_books{0, books.size()-1};

	for (const auto& people : peoples)
	{
		people_book.emplace(people, make_books(books, book_size(gen_value), group_books));
	}
	std::for_each(std::begin(people_book), std::end(people_book), List_group());

	Group inter;
	auto& iter = std::begin(people_book);
	while (iter != std::end(people_book))
	{
		auto& iptr = std::next(iter, 1);
		while (iptr != std::end(people_book))
		{	
			Group_books i;
			group it{ iter->first + iptr->first, i };
			std::set_intersection(std::begin(iter->second), std::end(iter->second),
				std::begin(iptr->second), std::end(iptr->second),
				std::inserter(it.second, std::begin(it.second)));
			inter.insert(it);
			++iptr;
		}
		++iter;
	}
	for (int i = books.size(); i >= 0; --i)
	{
		for (auto& iter = std::begin(inter); iter != std::end(inter); ++iter)
		{
			if (iter->second.size() == i)
			{
				List_group()(*iter);
			}
		}		
	}
	system("pause");
}