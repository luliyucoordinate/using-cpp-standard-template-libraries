#include "Card.h"

inline std::ostream & operator<<(std::ostream & out, const Card & card)
{
	// TODO: �ڴ˴����� return ���
	out << card.colours + " " + card.numbers;
	return out;
}

inline std::istream & operator >> (std::istream & in, Card & card)
{
	// TODO: �ڴ˴����� return ���
	in >> card.colours >> card.numbers;
	return in;
}
