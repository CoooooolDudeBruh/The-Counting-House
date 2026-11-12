#include "Constants.h"
#include "Io.h"
#include "Games.h"
#include <iostream>
#include <cassert>
#include <string>
#define BROKE_FLAG 0

// TODO: Add Asserts, Static Asserts, Use more Auto for type deduction, Typedef (using) name aliases.


std::string getName()
{
	std::cout << "Enter Player name: ";
	std::string playerName;
	// Getline for player name to allow for spaces in name.
	std::getline(std::cin, playerName);
	std::cout << "Player Name is " << playerName << " is this correct?\n";
	return playerName;
}
std::string getNameAndCheck()
{
	while (true)
	{
		std::string playerName{ getName() };
		assert(playerName.empty() == false && "Player name must not be empty");
		while (true)
		{
			char decision{};
			std::cout << "(y/n) :";
			decision = io::inputChar();
			if (decision == 'y')
				return playerName;
			if (decision == 'n')
				break;
			else 
				continue;
			// This should never be reached if logic is right, but just in case, assert that decision is a single character
			assert(sizeof(decision) == 1 && "Expected single character input");
		}
		
	}
}

std::string getDifficulty()
{
	while (true)
	{
		// Lets make this easy for the user and us, using a char
		std::cout << "Select Difficulty: (1) Easy, (2) Medium, (3) Hard: ";
		char difficulty{ io::inputChar() };

		// Check to see if Difficulty matches expected text, if not re-prompt user for input
		// Use switch statement
		switch (difficulty)
		{
		case '1':
			return "Easy";
		case '2':
			return "Medium";
		case '3': 
			return "Hard";
		default:
			std	::cout << "Invalid Difficulty, Please enter a valid difficulty: (1) Easy, (2) Medium, (3) Hard\n";
		}
	}
}

// TODO: Fix ledger numbers and implement real values and calculations for net profit, games played, games won, games lost, current streak, best streak, and largest payout.

void ledgerView(std::string_view playerName, std::string_view difficulty, int gold, int gamesPlayed, int gamesWon, int gamesLost, int currentStreak, int bestStreak, int largestPayout)
{
	// Name, Difficulty, Gold, Net Profit (gold - starting gold), Games Played, Games Won, Games Lost, Current Streak, Best Streak, Largest Payout
	// Mention lack of Data if no games have been played yet, and that the ledger will be updated after each game played.

	std::cout << "Ledger View" << '\n';

	std::cout << "Player Name: " << playerName << '\n' << "Difficulty: " << difficulty << '\n' << "Gold: " << gold << '\n';
	// Placeholder values
	std::cout << "Net Profit: " << (gold - constants::startingGold) << '\n' << "Games Played: " << gamesPlayed << '\n';
	std::cout << "Games Won: " << gamesWon << '\n' << "Games Lost: " << gamesLost << '\n' << "Current Streak: " << currentStreak << '\n' << "Best Streak: " << bestStreak << '\n' << "Largest Payout: " << largestPayout << '\n';


	// Loop to ask whether to return to menu to prevent menu printout as no std::cin or other pause exists

	while (true)
	{
		std::cout << "Return to Menu? (y/n): ";
		char decision{ io::inputChar() };
		if (decision == 'y')
		{
			break;
		}
		if (decision == 'n')
		{
			continue;
		}
	}
	std::cout << "\nReturning to Menu...\n\n";
}

// Helper function that runs double or nothing game, returns gold, returns number of games played, number of games won, number of games lost, current streak, best streak, and largest payout.
// lets move this helper to game.cpp



int main()
{
	// Exit bool zero initialized to false.
	bool iWannaLeave{};
	// Went broke bool zero initialized to false.
	bool wentBroke{};
	// Beginning while loop.

	std::cout << "The Counting House" << '\n'
			<< "You are entering the counting house, a place where you can make millions. ";
	std::cout << "Every player starts with 100 gold,\nand the ability to wager up to 50 gold, startig from 5." << '\n';
	std::cout << "There are three games to play: Bullseye, Over/Under, and Double or Nothing.\n\n\n";


	// Starting values
	int gold = constants::startingGold;
	std::string difficulty{ "Easy" };
	std::string playerName{ getNameAndCheck() };
	// Assuming small number of games played
	int gamesPlayed{};
	int gamesWon{};
	int gamesLost{};
	int currentStreak{};
	int bestStreak{};
	int largestPayout{};


#if BROKE_FLAG		// Check if player has run out of gold, if so set wentBroke to true
	if (playerName == "Ada Lovelace")
	{
		gold = 0;
	}
#endif

	// Beginning while loop with exit condition of iWannaLeave being true and wentBroke being true, which is set to true when the player chooses to leave the counting house.
	while (!iWannaLeave && !wentBroke)
	{
		// somehow we need to trip the player back to this loop after finishing their game
		// Maybe outer loop not needed as inner will provide the concurrent menu and lead to gameplay and restart the loop after finish
		while (true)
		{
			// gamewon streak tallier post game exit and rerun of loop
			if (currentStreak > bestStreak)
			{
				bestStreak = currentStreak;
			}

			// Check if player has run out of gold, if so set wentBroke to true and break out of the loop at the beginning
			if (gold <= 0)
			{
				wentBroke = true;
				std::cout << "You have run out of gold, you are leaving the counting house." << '\n';
				break;
			}

			// Display Menu with given player name, gold, and difficulty.
			std::cout << "The Counting House" << '\n';
			std::cout << "Player: " << playerName << "\tGold: " << gold << "\tDifficulty: " << difficulty << '\n';
			std::cout << "1) Bullseye" << '\n' << "2) Over/Under" << '\n' << "3) Double or Nothing" << '\n';
			std::cout << "4) Show ledger" << '\n' << "5) Change difficulty" << '\n' << "6) Quit" << "\n\n";

			// Prompt for user input since I can't mask input marker or I dont know how to do it yet.
			std::cout << "Enter your choice: ";

			char choice{ io::inputChar() };
			switch (choice)
			{
			case '1':
				gamesPlayed++;
				//bullseye();
				break;
			case '2':
				gamesPlayed++;
				//overUnder();
				break;
			case '3':
				// Loop here for local gold +- wager outcome, game won, game lost, current streak, best streak, largest payout, and games played. Return to menu after game exit.
				// Impelementation for streak is not yet done
				while (true)
				{
					gamesPlayed++;
					int wager{ askBetDoubleOrNothing(gold) };
					
					int gameOutcomeUpdateGoldAmount	{ doubleOrNothing(gold, wager) };
					if (gameOutcomeUpdateGoldAmount > gold)
					{
						currentStreak += 1;
						++gamesWon;
					}
					else
					{
						currentStreak = 0;
						++gamesLost;
					}
					gold = gameOutcomeUpdateGoldAmount;
					if (!keepPlayingCheck())
					{

						break;
					}
				}
				break;
			case '4':
				ledgerView(playerName, difficulty, gold, gamesPlayed, gamesWon, gamesLost, currentStreak, bestStreak, largestPayout);
				break;
			case '5':
				
				difficulty = getDifficulty();
				break;
			case '6':
				iWannaLeave = true;
				break;
			default:
				continue;
			}
			// If the player has chosen to leave, break out of the loop and exit the program.
			if (iWannaLeave)
			{
				break;
			}
		}

	}

	std::cout << "Thank you for playing The Counting House, " << playerName << ". You are leaving with " << gold << " gold." << '\n';


	return 0;
}