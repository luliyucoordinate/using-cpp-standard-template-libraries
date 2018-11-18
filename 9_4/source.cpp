#include <iostream>
#include <random>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
using std::string;

int main()
{
	string file_out{ "../People.txt" };
	std::ofstream out{ file_out, std::ios_base::out | std::ios_base::trunc };
	std::random_device rd;
	std::default_random_engine rng{ rd() };
	std::uniform_int_distribution<long long> dist{ 0L, 10000000000L };
	const size_t n{ 100 };
	std::generate_n(std::ostream_iterator<long long>{out, " "}, n, [&rng, &dist]() {
		return dist(rng);
	});
	out.close();
	system("pause");
}