#include <iostream>
#include <string>
#include <vector>

enum class enemyType
{
	skeleton,
	zombie,
	boss
};

class Enemy
{
private:
	std::string EnemyName;
	enemyType EnemyType;
	int MaxDamage;
	Enemy(std::string _EnemyName, enemyType _EnemyType, int _MaxDamage)
	{}

	std::string GetEnemyName();
	enemyType GetEnemyType();
	int GetMaxDamage();
};