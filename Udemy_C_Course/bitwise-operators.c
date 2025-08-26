#include <stdio.h>

void printBinary(int n)
{
    for (int i = (sizeof(n) * 2) - 1; i >= 0; i--)
    {
        if ((n >> i) & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{

    unsigned int a = 60; // 0011 1100
    unsigned int b = 13; // 0000 1101
    int result = 0;

    printf("The binary value of a = 60 is: ");
    printBinary(a);

    printf("The binary value of b = 13 is: ");
    printBinary(b);

    result = a & b; // 0000 1100 = 12
    printf("result of a & b is %d:         ", result);
    printBinary(result);

    result = a | b; // 0011 1101 = 61
    printf("result of a | b is %d:         ", result);
    printBinary(result);

    result = a << 2; // 1111 0000 = 240
    printf("result of  a << 2 is %d:      ", result);
    printBinary(result);

    result = a >> 4; // 0011 = 3
    printf("result of a >> 4 is %d:         ", result);
    printBinary(result);

    int sizeOfInt = sizeof(a);
    printf("The size of an int is: %d  bytes or %d bits", sizeOfInt, sizeOfInt * 8);

    return 0;
}