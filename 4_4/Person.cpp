#include "Person.h"

std::istream & operator >> (std::istream & in, Person & person)
{
	// TODO: 在此处插入 return 语句
	in >> person.name >> person.address >> person.phone;
	return in;
}

std::ostream & operator<<(std::ostream & out, const Person & person)
{
	// TODO: 在此处插入 return 语句
	out << person.name << " " << person.address << " " << person.phone;
	return out;
}

Person & Person::operator=(const Person & person)
{
	// TODO: 在此处插入 return 语句
	name = person.name;
	address = person.address;
	phone = person.phone;
	return *this;
}

Person & Person::operator=(Person && person)
{
	// TODO: 在此处插入 return 语句
	if (this != &person)
	{
		name = person.name;
		address = person.address;
		phone = person.phone;
	}
	return *this;
}
