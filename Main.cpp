#define NDEBUG

#include "Constants.h"
#include "Io.h"
#include <iostream>
#include <cassert>

bool cassertCheckInputInt(auto x)
{
	switch (sizeof(x))
	{
	case 2:
		std::cout << "char";
			break;
	case 4:
		std::cout << "int";
		break;
	case 8:
		std::cout << "double";
			break;
	default:
		return false;
	}
	return true;
}

int main()
{

	int setDifficulty{};

	setDifficulty = io::inputInt();
	assert(cassertCheckInputInt(setDifficulty));


	return 0;
}