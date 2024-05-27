#include "threadsIntro.h"
#include "threadFunc.h"
#include "conditionVariables.h"
#include "mutexes.h"
#include "threadChallenge.h"

int main(int argc, char **argv)
{
    //creating threads, passing arguments and returning values
    threadsIntroClass();

    //common functions
    threadFuncClass();

    //thread synchronization
        //mutexes
        mutexesClass();
    
        //condition variables
        conditionVariablesClass();

    //challenge
    threadChallenge();

    //will not cover: thread scheduling, thread-specific data, thread canceling,
    //      handling signals, and reader/writer locks
    
	return 0;
}