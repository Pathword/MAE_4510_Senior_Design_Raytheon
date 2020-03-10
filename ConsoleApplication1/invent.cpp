#include "invent.h"
#include <iostream>
#include "Uinterface.h"

extern int potions;
extern int hp, hpmax, coin;

void invent::potion()
{
	if (potions > 0)
	{
		int potion_add = rand() % 5 + 5;     //generates the strength of the potion btwn 5-10 hp

		std::cout << "\nAfter a moment of trepedation, you down the potion. At first you nearly wretch, ";
		std::cout << "but then you begin to feel oddly refreshed.\n\n";

		hp = hp + potion_add;
		coin = coin - 10;

		if (hp > hpmax)
		{
			hp = hpmax;
		}

		potions--;

		std::cout << "\n";
	}
	else
	{
		std::cout << "\nYou're out of potions!\n\n";
	}
}