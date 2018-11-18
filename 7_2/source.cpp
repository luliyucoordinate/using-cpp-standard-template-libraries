#include <iostream>
#include <tuple>
#include <algorithm>
#include <iterator>
#include <vector>

using height = std::pair<int, float>;
using cHeight = std::tuple<int, int, int>;
int main()
{
	std::vector<height> h1{};
	std::vector<cHeight> h2{};
	int feet;
	float inch;
	std::cout << "Enter feet(int) and inch(float):\n" << std::endl;
	std::cin >> feet >> inch;
	//height h = std::make_pair(feet, inch);
	h1.emplace_back(std::make_pair(feet, inch));
	std::transform(std::begin(h1), std::end(h1), std::back_inserter(h2), [](height& h) {
		int temp = static_cast<int>( h.first * 304.8 + h.second * 304.8 / 12);
		cHeight ch{};
		std::get<2>(ch) = temp % 10;
		temp /= 10;
		std::get<1>(ch) = temp % 100;
		temp /= 100;
		std::get<0>(ch) = temp;
		return ch;
		//std::get<0>(ch) = h.first * 0.3048 + h.second * 0.3048 / 12;
	});
	std::for_each(std::begin(h2), std::end(h2), [](cHeight& h) {
		std::cout << std::get<0>(h) << "m " << std::get<1>(h) << "cm " << std::get<2>(h) << "mm " << std::endl;
	});
	system("pause");
}