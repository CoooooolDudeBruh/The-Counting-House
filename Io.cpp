#include "Io.h"
#include <iostream>

namespace io
{
	// extraneous input error handling implementation for things that get stuck in the buffer that are not the same type as the input variable post first input
	void ignoreLine()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Learncpp has not introduced error handling for std::string yet
	std::string inputString()
	{
		std::string statement{};
		std::cin >> statement;
		
		return statement;
	}
	// Implementing error handling 
	int inputInt()
	{
		while (true)
		{
			// Three cases need to be handled: Normal, invalid, and boundary overflow
			// Defined input
			int input{};
			// Integrate while loop to handle invalid input and re-prompt user for input 
			// Use break to exit once valid input is received
			std::cin >> input;

			// Input validation
			if (!std::cin)
			{
				// clears the error fail bit
				std::cin.clear();
				// clears the buffer of any extraneous input
				ignoreLine();
				// "continue" to loop around the while loop
				continue;
			}


			// buffer clear in case of input like "1abc" not for "abc1"
			ignoreLine();

			std::cin >> input;
			return input;
		}
	}
	// Will be implementing error handling soon
	char inputChar()
	{
		char charVal{};

		return charVal;
	}

}
