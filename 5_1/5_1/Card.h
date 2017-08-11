#pragma once
#include <string>

using std::string;
using Colours = string;
using Numbers = string;
class Card
{
public:
	Card(const string& colour, const string& number) :colours(colour), numbers(number) {}
	Card() = default;
	const string& get_colour() const { return colours; }
	const string& get_number() const { return numbers; }
	bool operator==(const Card& card) const { return (colours == card.colours) && (numbers == card.numbers); }
	bool operator<(const Card& card) const { return (colours < card.colours) || (colours == card.colours && numbers < card.numbers); }
	friend std::ostream& operator<<(std::ostream& out, const Card& card);
	friend std::istream& operator>>(std::istream& in, Card& card);
private:
	Colours colours;
	Numbers numbers;
};
