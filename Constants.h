#ifndef CONSTANTS
#define CONSTANTS


// Constants for the different games, Bullseye, Over/Under, and Double or Nothing
namespace constants
{
	using gold = int;

	// General constants for player in all games
	constexpr gold startingGold{ 100 };
	constexpr gold minBet{ 5 };
	constexpr gold maxBet{ 50 };
	constexpr gold brokeThreshold{ 0 };

	// Use compile time evaluated asserts to validate
	static_assert(brokeThreshold == 0, "Player Broke Threshold inaccurate, not equal to zero");
	static_assert(maxBet <= startingGold, "Player needs enough gold to always wager the entirey");
	static_assert(minBet <= maxBet, "Minimum bet must be smaller than the maximum bet");
	static_assert(startingGold > 0, "Player must start with some amount of currency not equal to zero");
	static_assert(minBet > 0, "Player can not bet 0 of their currency");


	using amount = int;
	// Constants for different difficulty games of Bullseye
	constexpr amount easyLowRange{ 1 };
	constexpr amount easyHighRange{ 10 };
	constexpr amount easyGuesses{ 4 };
	static_assert(easyLowRange < easyHighRange, "low must be lower than high");
	static_assert(easyGuesses > 0, "Player must have a chance of guessing");

	constexpr amount mediumLowRange{ 1 };
	constexpr amount mediumHighRange{ 50 };
	constexpr amount mediumGuesses{ 6 };
	static_assert(mediumLowRange < mediumHighRange, "low must be lower than high");
	static_assert(mediumGuesses > 0, "Player must have a chance of guessing");

	constexpr amount hardLowRange{ 1 };
	constexpr amount hardHighRange{ 100 };
	constexpr amount hardGuesses{ 9 };
	static_assert(hardLowRange < hardHighRange, "low must be lower than high");
	static_assert(hardGuesses > 0, "Player must have a chance of guessin");

	// One constant for value of 7 used in Over/Under
	constexpr amount diceBasis{ 7 };
}


#endif 
