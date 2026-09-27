#include "Io.h"
#include <iostream>

namespace io
{
	// Learncpp has not introduced error handling for std::string yet
	std::string inputString()
	{
		std::string statement{};
		std::cin >> statement;
		
		return statement;
	}
	// Will be implementing error handling soon
	int inputInt()
	{


		return int;
	}
	// Will be implementing error handling soon
	char inputChar()
	{


		return char;
	}

}
