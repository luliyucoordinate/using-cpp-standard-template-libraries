#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <random>
#include <algorithm>
#include "Card.h"
#include "List_direction.h"

using std::string;
using std::vector;
using Cards = std::vector<Card>;
using Direction = std::set<Card>;
using Group = std::map<string, Direction>;
using Distribution = std::uniform_int_distribution<size_t>;

static std::default_random_engine gen_value;

Cards create_card()
{
	Cards cards;
	string colours[]{"heart", "club", "diamond", "spade"};
	string numbers[]{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	
	for (const auto& first : colours)
	{
		for (const auto& second : numbers)
		{
			cards.emplace_back(first, second);
		}
	}
	return cards;
}

Direction create_direction(Cards& cards, size_t directin_size)
{
	Direction direction;
	size_t i{};
	while (i < directin_size)
	{
		Distribution choose_card{ 0, cards.size() - 1 };
		Card card = cards[choose_card(gen_value)];
		direction.insert(card);
		for (auto& iter = std::begin(cards); iter != std::end(cards); ++iter)
		{
			if (*iter == card)
			{
				cards.erase(iter);
				
				break;
			}
		}		
		++i;
	}
	return direction;
}

int main()
{	
	Cards cards = create_card();
	Direction east = create_direction(cards, 13 );
	Direction west = create_direction(cards, 13 );
	Direction south = create_direction(cards, 13 );
	Direction north = create_direction(cards, 13 );
	std::cout << "direction: east" << std::endl;
	std::for_each(std::begin(east), std::end(east), List_direction());
	std::cout << std::endl;
	std::cout << "direction: west" << std::endl;
	std::for_each(std::begin(west), std::end(west), List_direction());
	std::cout << std::endl;
	std::cout << "direction: south" << std::endl;
	std::for_each(std::begin(south), std::end(south), List_direction());
	std::cout << std::endl;
	std::cout << "direction: north" << std::endl;
	std::for_each(std::begin(north), std::end(north), List_direction());
	std::cout << std::endl;
	system("pause");
}