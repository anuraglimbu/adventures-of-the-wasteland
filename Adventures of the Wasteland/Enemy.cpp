#include "Enemy.h"

Enemy::Enemy(std::string _EnemyName, enemyType _EnemyType, int _MaxDamage)
{
	EnemyName = _EnemyName;
	EnemyType = _EnemyType;
	MaxDamage = _MaxDamage;
}

std::string Enemy::GetEnemyName()
{
	return EnemyName;
}

enemyType Enemy::GetEnemyType()
{
	return EnemyType;
}

int Enemy::GetMaxDamage()
{
	return MaxDamage;
}