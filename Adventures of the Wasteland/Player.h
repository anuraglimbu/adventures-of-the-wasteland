#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class PlayerStates
{
	idle,
	fighting,
	shopping,
	travelling
};

class Player
{
	public:
		Player();

		void setPlayerName(std::string newName);
		void setPlayerHealth(int newHealth);
		void setPlayerArmour(int newArmour);
		void setPlayerShield(int newShield);

		std::string getPlayerName();
		int getPlayerHealth();
		int getPlayerArmour();
		int getPlayerShield();

		void takesDamage(int damage);
		void armourTakesHit(int damage);
		void shieldTakesHit(int damage);

		bool isDead();

	private:
		std::string name;
		int health;
		int armour;
		int shield;
		
};