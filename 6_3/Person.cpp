#include "Person.h"

std::ostream & operator<<(std::ostream & out, const Person & person)
{
	// TODO: �ڴ˴����� return ���
	std::cout << "Person's name: " << person.name << " Person's hair color: " << person.hair << std::endl;
	return out;
}
