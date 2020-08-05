#include <iostream>
#include <string>

enum class enemyTypes
{
	dead,
	skeleton,
	zombie,
	miniBoss,
	boss
};

class Enemy
{
	public:
		Enemy();
		Enemy(enemyTypes _type);
		Enemy(enemyTypes _type, std::string _name);

		void setType(enemyTypes _type);
		void setName(std::string _name);

		std::string getName();
		enemyTypes getType();
		int getLife();
		int getArmour();
		int getMaxDamage();

		void takesDamage(int num);

		bool isDead();


	private:
		std::string name;
		enemyTypes type;
		int maxDamage;
		int life;
		int armour;
};