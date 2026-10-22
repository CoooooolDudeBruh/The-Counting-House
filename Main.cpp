#include "Constants.h"
#include "Io.h"
#include <iostream>
#include <cassert>
#include <string>

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
	std::cout << "Enter Player name: ";
	std::string playerName;
	// Getline 
	std::getline(std::cin, playerName);
	std::cout << "Player Name is " << playerName << " is this correct?\n" << "(y/n) :";
	char decision{};
	while (true)
	{
		decision = io::inputChar();
		if (decision != 'y' || decision != 'n')
			continue;
		break;
	}
	// Beginning while loop
	while (true)
	{






	}




	return 0;
}