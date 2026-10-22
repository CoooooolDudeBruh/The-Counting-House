#ifndef IO
#define IO
// We need to forward declare all the functions in IO.cpp 

// My guess is we need to include <string> for std::string
#include <string>
// My guess was correct

// Forward declarations must be in the same namespace (namespace all in lowercase like learncpp suggests)
namespace io
{
	std::string inputString();
	int inputInt();
	char inputChar();
}




#endif
