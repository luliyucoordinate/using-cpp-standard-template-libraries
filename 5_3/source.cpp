#include <set>
#include <iostream>
#include <random>

using Distribution = std::uniform_int_distribution<size_t>;
static std::default_random_engine gen_value;
int main()
{
	Distribution choose_data{1,6};
	size_t number[13]{};
	for (int i = 0; i < 1000; ++i)
	{
		size_t data1 = choose_data(gen_value);
		size_t data2 = choose_data(gen_value);
		size_t data = data1 + data2;
		number[data]++;
	}
	for (int i = 2; i <= 12; ++i)
	{
		std::cout << "number[" << i << "] " << number[i] << std::endl;
	}
	system("pause");
}