#pragma once
#include <iostream>
#include <deque>
#include <tuple>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>
#include <iterator>

using std::string;
using Date = std::tuple<string, int, int>;
using groupDate = std::deque<Date>;

class ListDate
{
public:
	void operator()(const Date& date)
	{
		std::cout << std::get<0>(date) << " " << std::get<1>(date) << " " << std::get<2>(date) << std::endl;
	}
};