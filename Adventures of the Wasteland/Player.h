
#include <iostream>
#include <string>

class Player
{
private:
	std::string PlayerName;
	int PlayerHealth;
	int PlayerShield;
	std::vector PlayerProgress;

public:
	void SetPlayerName();
	void SetPlayerHealth();
	void SetPlayerShield();
	void SetPlayerProgress();
	void GetPlayerName();
	void GetPlayerHealth();
	void GetPlayerShield();
	void GetPlayerProgress();
};