#include "Constants.h"
#include "Io.h"
#include <iostream>
#include <cassert>
#include <string>

std::string getName()
{
	std::cout << "Enter Player name: ";
	std::string playerName;
	// Getline 
	std::getline(std::cin, playerName);
	std::cout << "Player Name is " << playerName << " is this correct?\n";
	return playerName;
}
std::string getNameAndCheck()
{
	std::string playerName{ getName() };
	char decision{};
	while (true)
	{
		std::cout << "(y/n) :";
		decision = io::inputChar();
		if (decision == 'y')
			break;
		if (decision == 'n')
			break;
	}
	return playerName;
}



int main()
{
	// Exit bool zero initialized to false
	bool iWannaLeave{};
	// Beginning while loop

	std::cout << "The Counting House" << '\n'
			<< "You are entering the counting house, a place where you can make millions. ";
	std::cout << "Every player starts with 100 gold,\nand the ability to wager up to 50 gold, startig from 5." << '\n';
	std::cout << "There are three games to play: Bullseye, Over/Under, and Double or Nothing.\n\n\n";

	// Ask for player name (not sure if its worth implementing a call for std::getline in io.cpp)
	// definition/default-initialization
#if 0
	std::cout << "Enter Player name: ";
	std::string playerName;
	// Getline 
	std::getline(std::cin, playerName);
	std::cout << "Player Name is " << playerName << " is this correct?\n";
	
	// Decision is zero initialized so it can be used later
	char decision{};
	while (true)
	{
		std::cout << "(y/n) :";
		decision = io::inputChar();
		if (decision == 'y' || decision == 'n')
			break;
		std::cout << '\n';
	}
#endif
	// Starting values
	int gold = constants::startingGold;
	std::string difficulty{ "Easy" };
	std::string playerName{ getNameAndCheck() };
	// Beginning while loop
	while (true)
	{


		while (true)
		{
			std::cout << "The Counting House" << '\n';
			std::cout << "Player: " << playerName << "\tGold: " << gold << "\tDifficulty: " << difficulty << '\n';
			std::cout << "1) Bullseye" << '\n' << "2) Over/Under" << '\n' << "3) Double or Nothing";
			std::cout << "4) Show ledger" << '\n' << "5) Change difficulty" << '\n' << "6) Quit";

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