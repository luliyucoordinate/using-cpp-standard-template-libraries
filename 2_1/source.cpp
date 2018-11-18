#include <iostream>                              // For standard streams
#include <iomanip>
#include <array>                                 // For array<T,N>

using namespace std;

int main()
{
	array<size_t, 50> data;
	size_t x1{};
	size_t x2{ 1 };
	size_t i{};
	size_t fib{};
	//不错的解法，但是与题意有一些不符，数列不是从0开始的
	//generate(begin(data), end(data),
	//	[a = 0, b = 1]() mutable {
	//	a = exchange(b, a + b);
	//	return a;
	//});

	generate(begin(data), end(data),
		[i, x1, x2, fib]() mutable {
		if (0 == i)
		{
			++i;
			return (size_t)0;
		}
		else if (1 == i)
		{
			++i;
			return (size_t)1;
		}
		else
		{
			fib = x1 + x2;
			x1 = x2;
			x2 = fib;
			return fib;
		}
	});
	for (int i = 0; i < 50; ++i)
	{
		cout << setw(12) << data.at(i) << " ";
		if ((i + 1) % 8 == 0)
		{
			cout << endl;
		}
	}
	system("pause");
}
