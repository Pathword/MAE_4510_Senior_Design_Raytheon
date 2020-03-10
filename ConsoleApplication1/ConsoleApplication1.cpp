// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Alex Bufmack



#include <iostream>
#include "Uinterface.h"
#include "game.h"
#include "boss.h"



game mygame;
boss myboss;
Uinterface myint;


int hp = 100;
int coin = 0;
int hatty = 0;
int hpmax = 100;
int f = 1;				// level
int fightcounter = 0;


//init boss trophy vars here
int demonhorns = 0;

int main()
{


	std::cout << "Welcome to DUNGEON HUNTER! How much XP can you stack before you die?!\n\n\n";

	myint.gamerun();


}


