#include "Person.h"

std::ostream & operator<<(std::ostream & out, const Person & person)
{
	// TODO: 在此处插入 return 语句
	std::cout << "Person's name: " << person.name << " Person's hair color: " << person.hair << std::endl;
	return out;
}
