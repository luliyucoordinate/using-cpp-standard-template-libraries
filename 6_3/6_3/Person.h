#pragma once
#include <string>
#include <iostream>
using std::string;
class Person
{
public:
	Person(const string& Name, const string& Hair) : name(Name), hair(Hair){}
	Person() = default;
	const string& get_hair() const { return hair; }
	const string& get_name() const { return name; }
	friend std::ostream& operator<<(std::ostream& out, const Person& person);
private: 
	string name;
	string hair;
};