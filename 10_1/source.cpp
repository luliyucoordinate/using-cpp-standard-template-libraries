#include <iostream>
#include <valarray>
#include <random>
#include <sstream>

int main()
{
	std::uniform_real_distribution<> values{ 1.0 ,100.0 };
	std::random_device rd;
	std::default_random_engine rng{ rd() };
	for (size_t i = 0; i < 100000; ++i)
	{

	}
	system("pause");
}