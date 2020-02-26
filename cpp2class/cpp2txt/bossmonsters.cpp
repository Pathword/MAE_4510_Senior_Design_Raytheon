#include "bossmonsters.h"
#include <iostream>
#include "game.h"

extern int hp;
extern int hpmax;
extern int coin;
extern int atk;
extern std::string name;
extern int bad_health;
extern int xp_drop;
extern game mygame;
extern int demonhorns;
extern int tb;

void bossmonsters::cavedemon()
{
	name = "CAVE DEMON";
	bad_health = 45;
	xp_drop = 75;

	//intro the enemy
	std::cout << name << "\n\n";
	std::cout << "You enter a large cavern in the dungeon. It seems to peaceful. Then suddenly the rocks collapse from the ceiling above you. In front of you you see a massive, horned creature materialize out of the darkness. He brandishes an obsidian blade in one black, clawed fist.\n\n";
	while (bad_health > 0)
	{
		atk = rand() % 2 + 5;

		std::cout << "The cave demon swings the obsidian blade toward you. You can briefly feel the air tremble before the impact nearly slices cleanly through your armor and knocks you off your feet. It deals " << atk << " ";
		std::cout << "points of damage.\n\n";
		hp = hp - atk;

		if (hp <= 0)
		{
			std::cout << "YOU DIED\nNEXT TIME DO BETTER\n\n";
			std::cout << "But at least you died with " << mygame.xp << " XP! That's not entirely subpar.\n\n\n";
			break;

		}
		else
		{
			std::cout << "You regain your footing and fight back, swinging your " << mygame.weapon << ". It seems to pass through the Cave Demon like it were cutting through mist. However, the Cave Demon lets out a sickening shriek and takes " << mygame.dmg;
			std::cout << " points of damage.\n\n";
			bad_health = bad_health - mygame.dmg;
		}
	}
	if (hp > 0)
	{
		std::cout << "\n\nWith one last swing, you sever the Cave Demon's hand, forcing him to drop the obsidian blade and fall to his knees. In one sweep, you remove the pitch-black head from his shoulders. You sever the Cave Demon's curled horns from his head and add them to your trophy bag. You feel ";
		std::cout << "more experienced. About " << xp_drop << " points more experienced.\n\n";
		mygame.xp = mygame.xp + xp_drop;
		demonhorns = demonhorns++;
		tb++;			//adds to trophy bag counter
	}
}