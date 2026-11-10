#include "Constants.h"
#include "Io.h"
#include <iostream>
#include <cassert>
#include <string>

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
		case 1:
			return "Easy";
		case 2:
			return "Medium";
		case 3: 
			return "Hard";
		default:
			std	::cout << "Invalid Difficulty, Please enter a valid difficulty: (1) Easy, (2) Medium, (3) Hard\n";
		}
	}
}

int main()
{
	// Exit bool zero initialized to false.
	bool iWannaLeave{};
	// Beginning while loop.

	std::cout << "The Counting House" << '\n'
			<< "You are entering the counting house, a place where you can make millions. ";
	std::cout << "Every player starts with 100 gold,\nand the ability to wager up to 50 gold, startig from 5." << '\n';
	std::cout << "There are three games to play: Bullseye, Over/Under, and Double or Nothing.\n\n\n";


	// Starting values
	int gold = constants::startingGold;
	std::string difficulty{ "Easy" };
	std::string playerName{ getNameAndCheck() };
	// Beginning while loop with exit condition of iWannaLeave being true, which is set to true when the player chooses to leave the counting house.
	while (!iWannaLeave)
	{
		// somehow we need to trip the player back to this loop after finishing their game

		while (true)
		{
			// Display Menu with given player name, gold, and difficulty.
			std::cout << "The Counting House" << '\n';
			std::cout << "Player: " << playerName << "\tGold: " << gold << "\tDifficulty: " << difficulty << '\n';
			std::cout << "1) Bullseye" << '\n' << "2) Over/Under" << '\n' << "3) Double or Nothing";
			std::cout << "4) Show ledger" << '\n' << "5) Change difficulty" << '\n' << "6) Quit" << "\n\n\n";

			// Prompt for user input since I can't mask input marker or I dont know how to do it yet.
			std::cout << "Enter your choice: ";

			char choice{ io::inputChar() };
			switch (choice)
			{
			case 1:
				//bullseye();
				break;
			case 2:
				//overUnder();
				break;
			case 3:
				//doubleOrNothing();
				break;
			case 4:
				//showLedger();
				break;
			case 5:
				//changeDifficulty();
				break;
			case 6:
				iWannaLeave = true;
				break;
			default:
				continue;
			}
		}

	}




	return 0;
}