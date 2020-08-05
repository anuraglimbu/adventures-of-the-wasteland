#include "Engine.h"

Engine::Engine()
{
	//Loading the areas into vectors
	currentArea = &dumpyard;
	Item tempItem = Item("The Sword of the dead", ItemTypes::sword, 20, 1200);
	Item tempItem1 = Item("The Armour of the gods", ItemTypes::armour, 50, 1200);
	Item tempItem2 = Item("The Shield of the mighty", ItemTypes::shield , 50, 1200);
	Item tempItem3 = Item("Health Potion", ItemTypes::healthPotion, 20, 1200);
	inventory.add(tempItem);
	inventory.add(tempItem1);
	inventory.add(tempItem2);
	inventory.add(tempItem3);
}

bool Engine::Execute()
{
	if (gameState == GameStates::quit_game)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Engine::Process()
{
	parser.Read();
	switch (parser.Parse())
	{
		case 0:
			Quit();
			break;

		case 1:
			parser.Write("Go north command");
			moveNorth();
			break;

		case 2:
			parser.Write("Go south command");
			moveSouth();
			break;

		case 3:
			parser.Write("Go west command");
			moveWest();
			break;

		case 4:
			parser.Write("Go east command");
			moveEast();
			break;

		case 5:
			parser.Write("Go north-west command");
			moveNorthWest();
			break;

		case 6:
			parser.Write("Go north-east command");
			moveNorthEast();
			break;

		case 7:
			parser.Write("Go south-west command");
			moveSouthWest();
			break;

		case 8:
			parser.Write("Go south-east command");
			moveSouthEast();
			break;

		case 9:
			parser.showHelp();
			break;
		
		case 10:
			checkInventory();
			break;

		case 11:
			dropItem();
			break;

		case 12:
			equipItem();
			break;

		default:
			parser.Write("Excuse me, i dont get it");
	}
}

int Engine::randomNum(int max)
{
	/*Random number geberation taken reference from http://www.cplusplus.com/reference/cstdlib/rand/ */

	srand(time(NULL));// initializing random seed
	return rand() % max + 1; //gives a random number from 1 to max
}

void Engine::Quit()
{
	parser.Write("Do you really wish to quit the game?");
	if (parser.YesNo())
	{
		gameState = GameStates::quit_game;
		parser.Write("Closing the game");
	}
}

void Engine::onboardPlayer()
{
	while(true)
	{
		parser.ReadRaw();
		parser.Write("You will be called by this name from now on, are you sure?(y/n)");
		if(parser.YesNo())
		{
			player.setPlayerName(parser.getInput());
			std::cout << "Well nice to meet you, " << player.getPlayerName() <<".";
			parser.Write("You can ask for help by just typing 'help'");
			gameState = GameStates::playing;
			break;
		}
		parser.Write("State your name:");
	}
}

void Engine::refreshPlayerStats()
{
	player.setPlayerArmour(inventory.getItemCapacity(11));
	player.setPlayerShield(inventory.getItemCapacity(12));
}

//Player movement determination
void Engine::moveNorth()
{
	if(currentArea->checkDirection("n"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &valley;
				currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &wasteland;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouth()
{
	if (currentArea->checkDirection("s"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::wasteland:
				currentArea = &valley;
				currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &dumpyard;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveWest()
{
	parser.Write("There's only a dense forest in that direction! You can't go that way.");
}

void Engine::moveEast()
{		
	parser.Write("There's only a dense forest in that direction! You can't go that way.");
}

void Engine::moveNorthWest()
{
	if (currentArea->checkDirection("nw"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &plain;
				currentArea->welcomeMessage();
				break;

			case Areas::mountain:
				currentArea = &valley;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveNorthEast()
{
	if (currentArea->checkDirection("ne"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::dumpyard:
				currentArea = &mountain;
				currentArea->welcomeMessage();
				break;

			case Areas::plain:
				currentArea = &valley;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouthWest()
{
	if (currentArea->checkDirection("sw"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
			case Areas::mountain:
				currentArea = &dumpyard;
				currentArea->welcomeMessage();
				break;

			case Areas::valley:
				currentArea = &plain;
				currentArea->welcomeMessage();
				break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

void Engine::moveSouthEast()
{
	if (currentArea->checkDirection("se"))
	{
		randomEncounter();
		switch (currentArea->area)
		{
		case Areas::plain:
			currentArea = &dumpyard;
			currentArea->welcomeMessage();
			break;

		case Areas::valley:
			currentArea = &mountain;
			currentArea->welcomeMessage();
			break;
		}
	}
	else
	{
		parser.Write("There's only a dense forest in that direction! You can't go that way.");
	}
}

//inventory actions
void Engine::checkInventory()
{
	parser.Write("Inventory Stats:");
	std::cout << "\n\nTotal Inventory Space: " << inventory.totalCapacity();
	std::cout << "\tLeft Inventory Space: " << inventory.totalCapacity()-inventory.used();
	inventory.check();
}

void Engine::dropItem()
{
	checkInventory();
	parser.Write("Select the item you want to drop");
	parser.Choice();
	inventory.remove(parser.getChoice());
}

void Engine::equipItem()
{
	checkInventory();
	parser.Write("Select the item you want to equip");
	parser.Choice();
	inventory.equip(parser.getChoice());
}

void Engine::randomEncounter()
{
	switch (randomNum(3))
	{
		case 1:
			parser.Write("You encountered a zombie horde on your way!");
			randomEnemy.setType(enemyTypes::zombie);
			currentEnemy = &randomEnemy;
			initiateFight();
			break;

		case 2:
			parser.Write("You encountered a skeleton army on your way!");
			randomEnemy.setType(enemyTypes::skeleton);
			currentEnemy = &randomEnemy;
			//std::cout << "\nInitiated fight with: " << currentEnemy->getName();
			initiateFight();
			break;

		case 3:
		default:
			parser.Write("It's your lucky day! No enemies encountered on the way!!");
			break;
	}
}

void Engine::bossEncounter()
{
	initiateFight();
}

void Engine::initiateFight()
{
	parser.Write("You can stay and fight or choose to run away.");
	parser.Write("However if you run away, you might get hit in the back and recieve damage!");
	parser.Write("\nDo you want to stay and fight? (y/n)");
	if (parser.YesNo())
	{
		parser.Write("\nInitiated fight with: ");
		std::cout << currentEnemy->getName();

		bool playerTurn = true;

		while (!(player.isDead() || currentEnemy->isDead()))
		{
			fightStats();
			if (playerTurn)
			{
				parser.DashedLine();
				parser.Write("Your Turn:");
				parser.DashedLine();

				parser.Write("1. Attack");
				parser.Write("2. Block enemy's attack (Shield takes damage)");
				parser.Write("3. Use potion (Increases health)");
				
				parser.Choice();
				switch (parser.getChoice())
				{
					case 1:
						playerAttack();
						playerTurn = false;
						break;

					case 2:
						playerBlock();
						playerTurn = true;
						break;

					case 3:
						playerTurn = false;
						if (!usePotion()) playerTurn=true;
						break;

					default:
						parser.Write("Invalid Choice");
						playerTurn = true;
						break;
				}
			}
			else
			{
				parser.DashedLine();
				parser.Write("Enemy's Turn:");
				parser.DashedLine();

				enemyAttack();
				playerTurn = true;
			}
			parser.DashedLine();
			parser.Pause();
		}
		parser.EmptyLine();
		parser.DashedLine();

		if (currentEnemy->isDead()) parser.Write("The enemy is dead!");
		if (player.isDead()) 
		{ 
			parser.Write("You are dead!"); 
			gameState = GameStates::game_over;
		}

		parser.DashedLine();
	}
	else
	{
		parser.Write("You chose to run away...");
		switch(randomNum(3))
		{
			case 1:
				player.takesDamage(10);
				std::cout << std::endl << "You took 10 damage!" << std::endl;
				break;

			case 2:
				player.takesDamage(20);
				std::cout << std::endl << "You took 20 damage!" << std::endl;
				break;

			case 3:
			default:
				parser.Write("You luckily managed to escape unharmed!");
				break;
		}
	}
}

void Engine::fightStats()
{
	parser.EmptyLine();

	std::cout << "\nPlayer Stats: \t\t\t Enemy Stats:";
	std::cout << "\n============= \t\t\t ============";
	refreshPlayerStats();
	std::cout << "\n"<< player.getPlayerName() << "    \t\t\t" << currentEnemy->getName();
	std::cout << "\nLife:    " << player.getPlayerHealth() << "\t\t\t Life:   " << currentEnemy->getLife();
	std::cout << "\nPotions: " << inventory.getHealthPotionCount() << "\t\t\t Armour: " << currentEnemy->getArmour();
	std::cout << "\nArmour:  " << player.getPlayerArmour();
	std::cout << "\nShield:  " << player.getPlayerShield();
	std::cout << "\nSword Damage: " << inventory.getItemDamage(10);//Get damage of equipped sword

	parser.EmptyLine();
}

inline void Engine::playerAttack()
{
	parser.DashedLine();
	int damage = inventory.getItemDamage(10);
	switch (randomNum(3))
	{
		case 1:
			currentEnemy->takesDamage(damage);
			std::cout << std::endl << "You dealt " << damage << " damage to the enemy!!";
			break;

		case 2:
			currentEnemy->takesDamage((damage/2));
			std::cout << std::endl << "You dealt " << damage/2 << " damage to the enemy!!";
			break;
		
		default:
			parser.Write("Alas! The enemy did not take any damage!!");
			break;
	}
}

inline void Engine::playerBlock()
{
	parser.DashedLine();
	int dmg = enemyDamage();
	if (dmg != 0 )
	{

		int capacity; 
		capacity = player.getPlayerShield() - dmg;

		capacity = (capacity < 0) ? 0 : capacity; //if the shield or armour capacity is negative , make it zero

		player.shieldTakesHit(dmg);
		inventory.setItemCapacity(12, capacity);

		if (player.getPlayerShield() == 0) // If shield is zero, armour takes the damage
		{
			if (player.getPlayerArmour() < 0) // If armour is depleted and negative, then make it as 0 instead of a negative number
			{
				inventory.setItemCapacity(11, 0);
			}
			else
			{
				inventory.setItemCapacity(11, player.getPlayerArmour());
			}
		}
	}
}

inline bool Engine::usePotion()
{
	parser.DashedLine();
	if (inventory.getHealthPotionCount() == 0)
	{
		parser.Write("You don't have any potions to use!");
		return false;
	}
	else
	{
		if (player.getPlayerHealth() < 50)
		{
			int potion = inventory.useHealthPotion();

			int health = player.getPlayerHealth() + potion;
			player.setPlayerHealth(health);
			std::cout << "\nHealth Restored by " << potion;
		}
		else
		{
			parser.Write("Your Health is already full");
			return false;
		}
	}
	//parser.Pause();
	return true;
}

inline void Engine::enemyAttack()
{
	parser.DashedLine();
	int dmg = enemyDamage();
	if (dmg != 0)
	{
		int capacity;
		capacity = player.getPlayerArmour() - dmg;

		capacity = (capacity < 0) ? 0 : capacity; //if the shield or armour capacity is negative , make it zero

		player.armourTakesHit(dmg);
		inventory.setItemCapacity(11, capacity);
	}
}

int Engine::enemyDamage()
{
	int	damage = currentEnemy->getMaxDamage();

	switch (randomNum(3))
	{
		case 1:
			std::cout << std::endl << "You took " << damage << " damage from the enemy!!";
			break;

		case 2:
			damage = damage/2;
			std::cout << std::endl << "You took " << damage << " damage from the enemy!!";
			break;

		default:
			damage = 0;
			parser.Write("You did not take any damage!!");
			break;
	}

	return damage;
}

/// IMPLEMENT: game over if dead. coin system