#define NDEBUG
#undef NDEBUG
#include "Constants.h"
#include "Io.h"
#include <iostream>
#include <cassert>

int main()
{

	int setDifficulty{};

	setDifficulty = io::inputInt();
	std::cout << setDifficulty;


	return 0;
}