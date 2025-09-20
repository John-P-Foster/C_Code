#include <stdio.h>

int add();

int main()
{
    int a = 1;
    int b = 2;
    int sum = add(a, b);

    printf("The sum of %d and %d is %d", a, b, sum);
    return 0;
}

int add(int a, int b)
{
    int sum = a + b;
    return sum;
}