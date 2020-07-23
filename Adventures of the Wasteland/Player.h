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
		//std::vector PlayerProgress;

public:
	void SetPlayerName(newName);
	void SetPlayerHealth(newHealth);
	void SetPlayerShield(newShield);
	void SetPlayerProgress(newProgress);
	void GetPlayerName();
	void GetPlayerHealth();
	void GetPlayerShield();
	void GetPlayerProgress();