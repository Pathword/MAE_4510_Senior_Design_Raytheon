#include "monster.h"
#include <iostream>
#include "game.h"

std::string name;
int atk, bad_health, xp_drop;

extern game mygame;
extern bool over;
extern int hp;

void monster::skeleton()
{
	name = "Undead Skeleton Warrior";
	bad_health = 25;
	xp_drop = 10;

	//intro the enemy
	std::cout << name << "\n\n";
	std::cout << "An undead soldier rises up in front of you, his bleached";
	std::cout << " skeleton peering out beneath rusted armor. He holds a ";
	std::cout << "chipped sword in his hand\n\n";

	while (bad_health > 0)
	{
		atk = rand() % 3 + 2;

		std::cout << "He swings the age-old blade at you. You take " << atk << " ";
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
			std::cout << "You fight back, swinging your " << mygame.weapon << ". He takes " << mygame.dmg;
			std::cout << " points of damage.\n\n";
			bad_health = bad_health - mygame.dmg;
		}

	}
	if (hp > 0)
	{
		std::cout << "\n\nWith one last swing, the bones and armor clatter to the floor.";
		std::cout << " A moment later, you're sure the creature is dead. You feel ";
		std::cout << "more experienced. About " << xp_drop << " points more experienced.\n\n";
		mygame.xp = mygame.xp + xp_drop;
	}
}

void monster::slime()
{
	name = "Cave Slime";
	bad_health = 30;
	xp_drop = 12;

	//intro the enemy
	std::cout << name << "\n\n";
	std::cout << "You hear a sickening gurgle further down the coridore. You struggle to maintain your balance, as the floor becomes slick. Finally, you round a corner and are suddenly faced with a hulking blob in front of you. This must be one of the cave slimes you heard about!\n\n";
	while (bad_health > 0)
	{
		atk = rand() % 3 + 1;

		std::cout << "The slime lunges at you, coating you in an acidic goo. It deals " << atk << " ";
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
			std::cout << "You fight back, swinging your " << mygame.weapon << ". The slime takes " << mygame.dmg;
			std::cout << " points of damage.\n\n";
			bad_health = bad_health - mygame.dmg;
		}
	}
	if (hp > 0)
	{
		std::cout << "\n\nWith one last swing, the slime shudders then deflates. Leaving a pool of goo in front of you. You carefully move across it and continue forward. You feel ";
		std::cout << "more experienced. About " << xp_drop << " points more experienced.\n\n";
		mygame.xp = mygame.xp + xp_drop;
	}
}

void monster::rat()
{
	name = "Giant Rat";
	bad_health = 20;
	xp_drop = 5;

	//intro the enemy
	std::cout << name << "\n\n";
	std::cout << "As you push deeper into the dungeon, you hear the skittering of claws echoing off the stone tunnels. You prepare your " << mygame.weapon << " and inch further into the darkness. A dark silhouette appears to be running toward you, low to the ground. Suddenly, a giant rat appears out of the darkness, blood and saliva dripping from his fangs.\n\n";
	while (bad_health > 0)
	{
		atk = rand() % 2 + 2;

		std::cout << "The giant rat jumps forward and closes it's jaws around your leg, slicing you with its razor-sharp teeth. It deals " << atk << " ";
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
			std::cout << "You fight back, swinging your " << mygame.weapon << ". The giant rat takes " << mygame.dmg;
			std::cout << " points of damage.\n\n";
			bad_health = bad_health - mygame.dmg;
		}
	}
	if (hp > 0)
	{
		std::cout << "\n\nWith one last swing, you plunge your weapon into the rat's neck. It falls to the ground motionless. You step over it and move on. You feel ";
		std::cout << "more experienced. About " << xp_drop << " points more experienced.\n\n";
		mygame.xp = mygame.xp + xp_drop;
	}
}

void monster::mimic()
{
	name = "'Treasure Chest'";
	bad_health = 25;
	xp_drop = 20;

	//intro the enemy
	std::cout << name << "\n\n";
	std::cout << "You come across a treasure chest deep in the dungeon. It looks fully intact, which seems odd, but you can't control your curiosity. You go to open the chest. As you grab the lock, you notice that this chest has...eyes? And teeth?! But you notice too late! The treasure chest comes to life and opens to show a fang-lined maw.\n\n";
	while (bad_health > 0)
	{
		atk = rand() % 3 + 3;

		std::cout << "The mimic snaps its jaws, digging its fangs into your flesh. It deals " << atk << " ";
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
			std::cout << "You fight back, swinging your " << mygame.weapon << ". The mimic takes " << mygame.dmg;
			std::cout << " points of damage.\n\n";
			bad_health = bad_health - mygame.dmg;
		}
	}
	if (hp > 0)
	{
		std::cout << "\n\nWith one last swing, you send splinters of wood and purple blood flying across the dungeon. You feel ";
		std::cout << "more experienced. About " << xp_drop << " points more experienced.\n\n";
		mygame.xp = mygame.xp + xp_drop;
	}
}

