#include "game.h"
#include <iostream>
#include <time.h>
#include "monster.h"
#include "invent.h"

monster mymonster;	 //init new vars
invent myinv;
bool rested;
extern game mygame;
extern int fightcounter;

extern bool over;    //get vars from other files
extern int hp;
extern int coin;
extern std::string name;
extern int hatty;
extern int hpmax;
extern int demonhorns;
extern int tb;
int potions;

void game::enemy()
{
	fightcounter++;

	rested = false;

	int rando = rand() % 4;		// gens # btwn 0-3

	switch (rando)		//determines enemy from rando
	{
	case 0:
		mymonster.skeleton();
		break;

	case 1:
		mymonster.slime();
		break;

	case 2:
		mymonster.rat();
		break;

	case 3:
		mymonster.mimic();
	}
	if (hp > 0)
	{
		int coin_add = rand() % 20 + 5;
		coin = coin + coin_add;
		std::cout << "\n\nThe " << name << " drops " << coin_add << " coins! You now have " << coin << " coins \n";
		std::cout << "Your health is currently " << hp << " and you have " << mygame.xp << " XP \n\n";
	}

}


void game::shop()
{ 				//for now, keeping shop mega simple

	int choice;
	std::cout << "\n1) Potion [heal 5-10 health]  -  10 coins\n";
	std::cout << "2) Weapon Upgrade [+2 attack]  -  15 coins\n";
	std::cout << "3) Hat [you wear a hat]  -  100 coins\n";
	std::cout << "4) Leave [you leave the shop] \n\n";

	std::cin >> choice;
	
	std::cout << "\n";

	switch (choice)
	{
	case 1:
		if (coin < 10)
		{
			std::cout << "\nYou don't have enough for that! \n\n";
			break;
		}
				
		potions++;
		

		std::cout << "You take a bottle filled with strange looking liquid from the shop keeper and add it to your inventory. ";

		break;


	case 2:
		if (coin < 15)
		{
			std::cout << "\nYou don't have enough for that! \n\n";
			break;
		}

		if (mygame.dmg < 15)
		{
			mygame.dmg = mygame.dmg + 2;
			coin = coin - 15;

			std::cout << "\nA glance at your trusty " << mygame.weapon << " and you realize it may not be good ";

			switch (mygame.dmg)
			{
			case 5:
				mygame.weapon = "knife";
				break;

			case 7:
				mygame.weapon = "rusty sword";
				break;

			case 9:
				mygame.weapon = "sword";
				break;

			case 11:
				mygame.weapon = "great sword";
				break;

			case 13:
				mygame.weapon = "enchanted sword";
				break;

			case 15:
				mygame.weapon = "large fish by the tail";

			}


			std::cout << "for the rest of this journey. Reluctantly you toss it aside and grab the " << mygame.weapon;
			std::cout << " from the old man.\n\n";
		}
		else
		{
			std::cout << "\n The old shop keeper has no more weapons to sell.\n\n";
		}
		break;


	case 3:
		if (coin < 100)
		{
			std::cout << "\nYou don't have enough for that! \n\n";
			break;
		}
		coin = coin - 100;
		hatty = 1;
		std::cout << "The hat sitting on the shop keep's stand catches your eye. You can't resist.";
		std::cout << " You spend 100 XP for it. It may be useless, but you feel good wearing it.\n\n";

	}
	std::cout << "\n\nYour health is currently " << hp << "\n\n";


}


void game::rest()
{
	if (rested == false)
	{
		rested = true;

		int rest_add = rand() % 2 + 2;		//generates the strength of the rest btwn 2-4 hp

		std::cout << "\n\nYou find a small, safe-feeling corner in the dungeon, light a fire, and curl up ";
		std::cout << "for an uneasy nap. You wake up, honestly surprised that you're alive, and feel somewhat rested.";
		std::cout << "You regain " << rest_add << " health.\n\n";

		hp = hp + 3;

		if (hp > hpmax)
		{
			hp = hpmax;
		}

	}
	else
	{
		std::cout << "You try to lay down for another nap, but since you just slept you're restless. You get no benefit from resting too long.\n\n";
	}
	std::cout << "\n\nYour health is currently " << hp << "\n\n";
}


void game::hat()
{
	std::cout << "         .' |     /`.\n";
	std::cout << "         |   |   /   |\n";
	std::cout << "        |     |_/     |\n";
	std::cout << "        |             |\n";
	std::cout << "        |             |\n";
	std::cout << "        |             |\n";
	std::cout << "        |             |\n";
	std::cout << "        |             |\n";
	std::cout << "        |             |\n";
	std::cout << "        |             |\n";
	std::cout << "        |_ _ _ _ _ _ _|\n";
	std::cout << "        |             |\n";
	std::cout << " | = = = = = = = = = = = = = /\n\n";
}


void game::trophybag()
{
	if (tb > 0)
	{
		std::cout << "TROPHY BAG\n";
			if (demonhorns)
			{
				std::cout << demonhorns << "x   Horns of the Cave Demon - |^|_|^|\n";
			}
	}
	else
	{
		std::cout << "You don't have any trophies yet!\n";
	}
	std::cout << "\n";
}

void game::inventory()
{
	int invchoice;

	std::cout << "\nCurrent weapon:  " << mygame.weapon << "\n";
	std::cout << "1) Drink potion (" << potions << ")\n";

	std::cout << "\n";
	std::cin >> invchoice;

	std::cout <<  "\n";

	switch (invchoice)
	{
	case 1:
		myinv.potion();

	}
	
}