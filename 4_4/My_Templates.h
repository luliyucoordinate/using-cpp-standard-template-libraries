#pragma once
// Templates for Ex4_07
#include <functional>
#include <vector>
#include <algorithm>

// List all elements
template<typename Container>
void list_elements(Container& container)
{
	std::vector<Person> temp;
	for (const auto& element : container)
		temp.push_back(element.second);
	std::sort(temp.begin(), temp.end(), std::greater<Person>());
	for (const auto& element : temp)
		std::cout << element << std::endl;
}

// List range of elements
template<typename T>
void list_range(const T& pr)
{
	if (pr.first != pr.second)
	{
		for (auto iter = pr.first; iter != pr.second; ++iter)
			std::cout << "  " << iter->first << "  " << iter->second << std::endl;
	}
	else
		std::cout << "No records found.\n";
}

// Find elements for a key entered from the keyboard - C++ 14 version
template<typename Container>
auto find_elements(const Container& container)
{
	typename Container::key_type key {};
	std::cin >> key;
	auto pr = container.equal_range(key);
	return pr;
}


//// Find elements for a key entered from the keyboard - C++ 11 version
//template<typename Container>
//auto find_elements(const Container& container) -> std::pair<typename Container::const_iterator, typename Container::const_iterator>
//{
//	typename Container::key_type key{};
//	std::cin >> key;
//	auto pr = container.equal_range(key);
//	return pr;
//}