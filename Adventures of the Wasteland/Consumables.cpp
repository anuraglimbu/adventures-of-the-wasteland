#include "Consumables.h"
#include "Player.h"

Consumables::Consumables()
{

}

void HealthBoost()
{
	int currentHealth = Player::GetPlayerHealth();
	Player::SetPlayerHealth(currentHealth + 10);
	return;
}

void ShieldBoost()
{
	int currentShield = Player::GetPlayerShield();
	Player::SetPlayerShield(currentShield + 10);
	return;
}

void FullHealth();
void FullShield();