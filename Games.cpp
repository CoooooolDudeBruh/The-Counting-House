#include "Random.h"
#include "Io.h"
#include <iostream>


// ==============================================================================
// Multiple Function for games as well as helped functions to facilitate the games 
// and their logic, as well as the ledger view function to display the player's stats 
// and progress in the counting house.
// ==============================================================================






// First game development Cycle, Double or Nothing
// Not dependent on difficulty, but will be dependent on wager amount and current gold amount
// splitting this funciton up to many to grab the specific values for gold, games played, games won, games lost, current streak, best streak, and largest payout.

int askBetDoubleOrNothing(int gold)
{
	while(true)
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
		return wager;
	}
}




	int doubleOrNothing(int gold, int wager)
	{
		// function gold var used for in function calculations to be returned at loop end

			// Generated number on the spot, if the number is even, the player wins and their gold is doubled, if the number is odd, the player loses and their gold is halved.
		int randomNumber{ random::get(1, 100) };
		// Even check else for odd check
		if (randomNumber % 2 == 0)
		{
			gold += wager;
			std::cout << "You won! Your gold has been doubled" << '\n';
		}
		else
		{
			gold -= wager;
			std::cout << "You lost! Your gold has been halved" << '\n';
		}

		std::cout << "Your gold amount is: " << gold << '\n';
		return gold;
	}

	bool keepPlayingCheck()
	{
		while(true)
		{
			std::cout << "Do you want to play again? (y/n): ";
			char choice{ io::inputChar() };
			switch (choice)
			{
			case 'y':
				return true;
			case 'n':
				return false;
			default:
				std::cout << "Invalid input, please enter y or n." << '\n';
				continue;
			}
		}
	}