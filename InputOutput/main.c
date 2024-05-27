#include "char.h"
#include "charChallenge.h"
#include "stringLecture.h"
#include "stringChallenge.h"
#include "formatting.h"
#include "formattingChallenge.h"

int main(int argc, char **argv)
{
	//char class
    charClass();
    charChallengeFunc(argc, argv);

	//string class
    stringClass();
    stringChallengeFunc(argc,argv);
    
    //formatting class
    formattingClass();
    formattingChallengeFunc();
    /*
    int n = 0;
    scanf("%d",&n);
    ungetc(n,stdin);
    scanf("%d",&n);
    printf("%d\n",n);
    */
	return 0;
}
