#include <iostream>
#include <deque>
#include <tuple>
#include <string>
#include <cctype>
#include <set>
#include <algorithm>
#include <iterator>
#include "ListDate.h"

using std::string;
using Date = std::tuple<string, int, int>;
using groupDate = std::deque<Date>;

void get_date(groupDate& gd)
{
	string month{};
	int day{};
	int year{};
	char answer{ 'Y' };
	while ( std::toupper(answer) == 'Y')
	{
		std::cout << "Enter date  month day year :";
		std::cin >> month >> day >> year;
		Date date{ month, day, year };
		gd.push_back(date);
		std::cout << "Do you want to enter another(Y or N):";
		std::cin >> answer;
	}
}

int main()
{
	groupDate gd{};
	get_date(gd);
	int gdSize = gd.size();
	int monthSize{1};
	groupDate difMonth{};
	
	for (int i = 0; i < gdSize; ++i)
	{
		for (int j = i + 1; j < gdSize; ++j)
		{
			if (std::get<0>(gd.at(i)) == std::get<0>(gd.at(j)))
			{
				++monthSize;
			}
		}
	}
	std::sort(std::begin(gd), std::end(gd), [](const Date& d1, const Date& d2)
	{ return std::get<1>(d1) > std::get<1>(d2); });
	std::for_each(std::begin(gd), std::end(gd), ListDate());

	auto end_iter = std::unique(std::begin(gd), std::end(gd), [](Date d1, Date d2)
															{return std::get<0>(d1) == std::get<0>(d2); });
	//gd.erase(end_iter, std::end(gd));
	std::copy(std::begin(gd), end_iter, std::back_inserter(difMonth));
	//std::copy(std::begin(difMonth), std::end(difMonth), std::ostream_iterator<Date>{std::cout, "\n"});	没有做相应的重载操作
	//对difMonth最排序操作，按照相同年相同月，日期按降序输出每个月份的数据


	system("pause");
}