#pragma once
#include <iostream>

class game
{

public:

	int health = 100;
	int dmg = 3;		//when fighting with stick
	int xp = 0;
	std::string weapon = "stick";


	void enemy();
	void shop();
	void rest();
	void hat();
	void trophybag();

};
