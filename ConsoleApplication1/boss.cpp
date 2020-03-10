#include "boss.h"
#include <iostream>
#include "game.h"
#include "monster.h"
#include "bossmonsters.h"
#include "Uinterface.h"

extern int hp;
extern int hpmax;
extern int coin;
extern int atk;
extern std::string name;
extern int bad_health;
extern int xp_drop;
extern game mygame;
extern int demonhorns;

int tb;
bossmonsters theboss;

void boss::bossfight()
{
	std::cout << "\nYOU ARE ENTERING A BOSS FIGHT! IF YOU SURVIVE YOU WILL REGAIN 50 HP AND YOUR MAX HP WILL RISE BY 15!\n\n";

	int bosspick = rand() % 1;

	switch (bosspick)
	{
	case 0 :
		theboss.cavedemon();
	}
}


void boss::bosscash()
{
	int boss_add = rand() % 30 + 15;
	coin = coin + boss_add;
}

void boss::bossheal()
{
	if (hp > 0)
	{
		hp = hp + 50;
		hpmax = hpmax + 15;
		if (hp > hpmax)
		{
			hp = hpmax;
		}
	}
}