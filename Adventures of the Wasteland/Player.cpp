#include "Player.h"

Player::Player()
{

}

void Player::SetPlayerName(std::string newName)
{
    PlayerName = newName;
    return;
}

void Player::SetPlayerHealth(int newHealth)
{
    PlayerHealth = newHealth;
    return;
}

void Player::SetPlayerShield(int newShield)
{
    PlayerShield = newShield;
    return;
}

void Player::SetPlayerProgress(int newProgress)
{
    PlayerProgress.emplace_back(newProgress);
    return;
}

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

std::vector<std::string> Player::GetPlayerProgress()
{
    return PlayerProgress;
}

void Player::TakeHit(int damage)
{
    PlayerHealth -= damage;
    return;
}

Player::~Player()
{

}