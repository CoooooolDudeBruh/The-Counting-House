#include "Io.h"
#include <iostream>
#include <limits>

namespace io
{
	// extraneous input error handling implementation for things that get stuck in the buffer that are not the same type as the input variable post first input
	void ignoreLine()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	// Additional function for if EOF value has been entered and incorporate failed extraction due to type mismatch
	bool clearFailedExtraction()
	{
		// checked for failed extraction
		if (!std::cin)
		{
			// check eof first in order to prioritize program termination
			if (std::cin.eof())
			{
				std::exit(0);
			}
			// clears error fail bit
			std::cin.clear();
			ignoreLine();
			// True for failure in extraction
			return true;
		}

		return false;
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


			// clears the error fail bit, eof input, and buffer clear all in one function call
			if (clearFailedExtraction());
			{
				std::cout << "Enter a valid integer" << '\n';
				continue;
			}
			// buffer clear in case of input like "1abc" not for "abc1"
			ignoreLine();

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
