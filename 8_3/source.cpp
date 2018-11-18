#include <iostream>
#include <random>
#include <algorithm>
#include <iomanip>

std::default_random_engine& rng()
{
	static std::default_random_engine engine{ std::random_device()() };
	return engine;
}

int main()
{
	std::discrete_distribution<size_t> throw_die{ 1, 1, 1, 1, 1, 1 };
	system("pause");
}