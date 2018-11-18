#pragma once
#include <iostream>
#include <algorithm>
#include "Card.h"

class List_direction
{
public:
	void operator()(const Card& card)
	{
		if (card.get_number() == "I")
			std::cout << card.get_colour() << " " << 10 << std::endl;
		else
			std::cout << card.get_colour() << " " << card.get_number() << std::endl;
	}
};