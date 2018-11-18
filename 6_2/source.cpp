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
using Direction = std::vector<Card>;
using Group = std::map<string, Direction>;
using Distribution = std::uniform_int_distribution<size_t>;

static std::default_random_engine gen_value;

Cards create_card()
{
	Cards cards;
	string colours[]{ "heart", "club", "diamond", "spade" };
	string numbers[]{ "2", "3", "4", "5", "6", "7", "8", "9", "I", "J", "Q", "K", "A" };

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
		direction.push_back(card);
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

//合并所有牌
Cards create_all(Direction& d1, Direction& d2, Direction& d3, Direction& d4)
{
	Cards all;
	vector<Direction*> choose_all{ &d1, &d2, &d3, &d4 };
	while (d1.size() != 0 || d2.size() != 0 || d3.size() != 0 || d4.size() != 0)
	{		
		//选择合并牌的方向
		Distribution choose_direction{ 0, choose_all.size() - 1 };
		Direction *choose_d = choose_all[choose_direction(gen_value)];
		if (choose_d->size() == 0)
		{	//如果该方向的牌没有了，就重新循环，最好的做法是删除这个方向
			continue;
		}
		//选择合并方向的牌
		Distribution choose_card{ 0, choose_d->size() - 1 };
		Card card = (*choose_d)[choose_card(gen_value)];
		all.push_back(card);
		//从原来的方向中删除牌
		for (auto& iter = std::begin(*choose_d); iter != std::end(*choose_d); ++iter)
		{
			if (*iter == card)
			{
				choose_d->erase(iter);
				break;
			}
		}
	}
	return all;
}

int main()
{
	Cards cards = create_card();
	Direction east = create_direction(cards, 13);
	Direction west = create_direction(cards, 13);
	Direction south = create_direction(cards, 13);
	Direction north = create_direction(cards, 13);
	std::sort(std::begin(east), std::end(east));
	std::sort(std::begin(west), std::end(west));
	std::sort(std::begin(south), std::end(south));
	std::sort(std::begin(north), std::end(north));
	//合并手牌
	Cards all = create_all(west, east, south, north);
	std::for_each(std::begin(all), std::end(all), List_direction());
	std::cout << std::endl;
	system("pause");
}