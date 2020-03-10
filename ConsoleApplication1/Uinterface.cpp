#include <iostream>
#include "Uinterface.h"

#include "game.h"
#include "monster.h"
#include "boss.h"



extern game mygame;
extern boss myboss;

extern int hp;
extern int coin;
extern int hatty;
extern int hpmax;
extern int f;				// level
extern int fightcounter;

void Uinterface::gamerun()
{


	int choice;
	

	while (hp > 0)
	{
		if (hatty == 1)
		{
			mygame.hat();
		}

		std::cout << "----------------\n";
		std::cout << "HP: " << hp << "   C$: " << coin << "   XP: " << mygame.xp << "  LVL: " << f << "\n";
		//basic game choices
		std::cout << "1) Shop\n";
		std::cout << "2) Fight\n";
		std::cout << "3) Rest\n";
		std::cout << "4) Trophy Bag\n";
		std::cout << "5) Inventory\n";
		std::cout << "----------------\n";
		std::cin >> choice;
		if (choice == 1)
		{
			mygame.shop();
		}
		else if (choice == 2)
		{
			myboss.countdown--;
			if (myboss.countdown > 0)
			{
				mygame.enemy();
			}
			else
			{
				myboss.countdown = rand() % 6 + 3;
				myboss.bossfight();
				myboss.bosscash();
				myboss.bossheal();
			}

		}
		else if (choice == 3)
		{
			mygame.rest();
		}
		else if (choice == 4)
		{
			mygame.trophybag();
		}
		else if (choice == 5)
		{
			mygame.inventory();
		}
		else if (choice == 1337)		//dev option for working on features
		{
			hp = hpmax;
			coin = 999;
			mygame.xp = 999;
		}

	}

	mygame.goodbye();
}