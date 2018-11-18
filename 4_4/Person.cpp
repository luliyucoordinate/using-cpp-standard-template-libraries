#include "Person.h"

std::istream & operator >> (std::istream & in, Person & person)
{
	// TODO: �ڴ˴����� return ���
	in >> person.name >> person.address >> person.phone;
	return in;
}

std::ostream & operator<<(std::ostream & out, const Person & person)
{
	// TODO: �ڴ˴����� return ���
	out << person.name << " " << person.address << " " << person.phone;
	return out;
}

Person & Person::operator=(const Person & person)
{
	// TODO: �ڴ˴����� return ���
	name = person.name;
	address = person.address;
	phone = person.phone;
	return *this;
}

Person & Person::operator=(Person && person)
{
	// TODO: �ڴ˴����� return ���
	if (this != &person)
	{
		name = person.name;
		address = person.address;
		phone = person.phone;
	}
	return *this;
}
