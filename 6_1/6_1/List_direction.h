#pragma once
#include <iostream>
#include <algorithm>
#include "Card.h"

class List_direction
{
public:
	void operator()(const Card& card)
	{
		std::cout << card.get_colour() << " " << card.get_number() << std::endl;
	}
};