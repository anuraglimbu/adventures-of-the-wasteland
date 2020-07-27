#pragma once

#include <iostream>
#include <string>
#include <vector>

class Player
{
private:
	std::string PlayerName;
	int PlayerHealth;
	int PlayerShield;
	std::vector<std::string> PlayerProgress;

public:
	void SetPlayerName(std::string newName);
	void SetPlayerHealth(int newHealth);
	void SetPlayerShield(int newShield);
	void SetPlayerProgress(int newProgress);
	std::string GetPlayerName();
	int GetPlayerHealth();
	int GetPlayerShield();
	std::vector<std::string> GetPlayerProgress();
	void TakeHit(int damage);
};