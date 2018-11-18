#pragma once
#include <iostream>                              // For standard streams
#include <cctype>                                 // For toupper()
#include <string>                                // For string class
#include <unordered_map>                         // For unordered_map container
#include <vector>									// Students
#include <iterator>
#include <memory>

using std::string;
using std::unordered_multimap;
using Name = string;
using Address = string;
using Phone = string;


class Person
{
public:
	Person(const Name& name, const Address& address, const Phone& phone) :
		name(name), address(address), phone(phone) {}
	Person() = default;
	Person(const Person& person) : name(person.name), address(person.address), phone(person.phone) {}
	Person& operator=(const Person& person);
	
	Person(Person&& person) : name(person.name), address(person.address), phone(person.phone) {}
	Person& operator=(Person&& person);
	bool operator>(const Person& person)const { return name > person.name; }
	friend std::istream& operator>>(std::istream& in, Person& person);
	friend std::ostream& operator<<(std::ostream& out, const Person& person);
public:
	Name name{};
private:
	Address address{};
	Phone phone{};
};