#include "Person.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using group_person = std::vector<Person>;
using std::string;


int main()
{
	group_person gp = { {"Ann", "golden"}, {"Jone", "gray"}, {"Dan", "brown"}, {"Ted", "black"} };
	std::partition(std::begin(gp), std::end(gp), [](Person& p) {return p.get_hair() == "black"; });
	auto& iter = std::next(std::begin(gp), 1);
	std::partition(iter, std::end(gp), [](Person& p) {return p.get_hair() == "gray"; });
	auto& iter2 = std::next(std::begin(gp), 2);
	std::partition(iter2, std::end(gp), [](Person& p) {return p.get_hair() == "brown"; });
	std::copy(std::begin(gp), std::end(gp), std::ostream_iterator<Person>(std::cout, ""));
	system("pause");
}