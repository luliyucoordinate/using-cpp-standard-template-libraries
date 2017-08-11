#include "Card.h"

inline std::ostream & operator<<(std::ostream & out, const Card & card)
{
	// TODO: 在此处插入 return 语句
	out << card.colours + " " + card.numbers;
	return out;
}

inline std::istream & operator >> (std::istream & in, Card & card)
{
	// TODO: 在此处插入 return 语句
	in >> card.colours >> card.numbers;
	return in;
}
