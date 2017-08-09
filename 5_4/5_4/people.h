#pragma once
#include <string>
#include <iostream>
class people
{
private:
	std::string first_name{};
	std::string second_name{};
public:
	people(const std::string& name1, const std::string& name2):first_name(name1), second_name(name2){}
	//Move constructor
	people(people&& p) :first_name(std::move(p.first_name)), second_name(std::move(p.second_name)) {}
	people() = default;
	bool operator<(const people& p) const
	{
		return second_name < p.second_name || (second_name == p.second_name && first_name < p.first_name);
	}
	friend std::ostream& operator<<(std::ostream& out, const people& p);
};
inline std::ostream& operator<<(std::ostream& out, const people& p)
{
	out << p.first_name + " " + p.second_name;
	return out;
}