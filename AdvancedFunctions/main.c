#include "variadic.h"
#include "variadicChallenge.h"
#include "recursion.h"
#include "recursionChallenge.h"
#include "inline_noreturn.h"

int main(int argc, char **argv)
{
	//variadic class
    variadicClass();
    variadicChallengeFunc();

	//recursion class
    recursionClass();
    recursionChallengeFunc();
    
    //inline_noreturn class
    inline_noreturnClass();

	return 0;
}