#include "Player.h"

Player::Player()
{

}



void SetPlayerName(newName)
{
    PlayerName = newName;
    return;
}

void SetPlayerHealth(newHealth)
{
    PlayerHealth = newHealth;
    return;
}

void SetPlayerShield(newShield)
{
    PlayerShield = newShield;
    return;
}

void SetPlayerProgress(newProgress)
{
    PlayerProgress.push_back(newProgress);
    return;
}

std::string GetPlayerName()
{
    return PlayerName;
}

int GetPlayerHealth();
{
    return PlayerHealth;
}

int GetPlayerShield();
{
    return PlayerShield;
}

std::vector GetPlayerProgress();
{
    return PlayerProgress;
}

bool TakeHit(damage)
{
    PlayerHealth -= TakeHit
}

Player::~Player()
{

}