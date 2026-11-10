#include "Random.h"
#include "Io.h"
#include <iostream>


// ==============================================================================
// Multiple Function for games as well as helped functions to facilitate the games 
// and their logic, as well as the ledger view function to display the player's stats 
// and progress in the counting house.
// ==============================================================================

int returnGold(int gold)
{
	return gold;
}

int gamesWon(int gamesWon)
{
	return gamesWon + 1;
}

int gamesLost(int gamesLost)
{
	return gamesLost + 1;
}






// First game development Cycle, Double or Nothing
// Not dependent on difficulty, but will be dependent on wager amount and current gold amount
void doubleOrNothing(int gold)
{
	
	bool keepPlaying{ true };
	while (keepPlaying)
	{
		// Prompt user for wager amount, check if wager is valid, if not re-prompt the user for input
		std::cout << "Enter your wager amount: ";
		int wager{ io::inputInt() };
		if (wager <= 0)
		{
			std::cout << "Wager must be greater than 0, please enter a valid wager amount." << '\n';
			continue;
		}
		if (wager > gold)
		{
			std::cout << "Wager must be less than or equal to your current gold, please enter a valid wager amount." << '\n';
			continue;
		}
		if (wager > 50)
		{
			std::cout << "Wager must be less than or equal to 50, please enter a valid wager amount." << '\n';
			continue;
		}

		std::cout << "Your wager is: " << wager << " gold." << '\n';

		// Generated number on the spot, if the number is even, the player wins and their gold is doubled, if the number is odd, the player loses and their gold is halved.
		int randomNumber{ random::get(1, 100) };
		// Even check else for odd check
		if (randomNumber % 2 == 0)
		{
			gold += (wager+wager);
			returnGold(gold);
			std::cout << "You won! Your gold has been doubled" << '\n';
		}
		else
		{
			gold -= wager;
			returnGold(gold);
			std::cout << "You lost! Your gold has been halved" << '\n';
		}

		std::cout << "Your gold amount is: " << gold << '\n';
		std::cout << "Do you want to play again? (y/n): ";

		char choice{ io::inputChar() };
		switch (choice)
		{
		case 'y':
			break;
		case 'n':
			keepPlaying = false;
			break;
		default:
			std::cout << "Invalid input, please enter y or n." << '\n';
			continue;
		}
	}
	



}