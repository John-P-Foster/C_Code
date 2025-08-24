
/*
    -  In C the pound key (#) when used as the first character on a line signals a preprocessor directive,
    like in the include statement.
    - Preprocesser Directive give the complier some instructions before it compiles the code.
    - Best practice is to have them at the start of the program but they can be written any where in code.


*/
#include <stdio.h>
/*
    - Header Files: Define information about some of the functions that are provided by that file.
    - stdio.h is a standard C header file that deals with getting and displaying info.
    - printf() requires stdio.h

    Two ways to define header files for a program.
    - Using angle brackets #inlude <SampleHeader.h>
        * Tells the compiler to look in the standard system dir
    - Using double quotes  #include "SampleHeader.h"
        * Tells the compiler to look in the current directory first.



*/

/* How to write multi line comments in C*/
// How to write single line comments in C.

int main()
{
    int myFavoriteNumber = 0;

    printf("Please enter your favorite number \n");
    scanf("%d", &myFavoriteNumber);
    printf("You entered number: %d\n", myFavoriteNumber);

    char str[100];
    int i;

    printf("Enter a value :");

    // When storing int you use & to give the address? But no need for str.
    // scanf looks for the first space to split the inputs into varible.
    scanf("%d %s", &i, str);

    printf("\nYou entered: %d::::%s\n", i, str);

    return 0;
}