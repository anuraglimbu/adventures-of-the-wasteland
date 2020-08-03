#include "Player.h"

Player::Player()
{
	SetPlayerHealth(50);
	SetPlayerShield(0);
}

void Player::SetPlayerName(std::string newName)
{
    PlayerName = newName;
}

void Player::SetPlayerHealth(int newHealth)
{
    PlayerHealth = newHealth;
}

void Player::SetPlayerShield(int newShield)
{
    PlayerShield = newShield;
}

/*void Player::SetPlayerProgress(int newProgress)
{
    PlayerProgress.emplace_back(newProgress);
}*/

std::string Player:: GetPlayerName()
{
    return PlayerName;
}

int Player::GetPlayerHealth()
{
    return PlayerHealth;
}

int Player::GetPlayerShield()
{
    return PlayerShield;
}

/*std::vector<std::string> Player::GetPlayerProgress()
{
    return PlayerProgress;
}*/

void Player::TakeHit(int damage)
{
    PlayerHealth -= damage;
}