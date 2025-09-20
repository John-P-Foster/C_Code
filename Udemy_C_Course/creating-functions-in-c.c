#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);
float absoluteValue(float n, int test);
float squareRoot(float n);

int main()
{
    // GCD test cases.
    gcd(150, 35);
    gcd(1026, 405);
    gcd(83, 240);

    printf("\n");

    // ABS test cases
    float f1 = -15.5, f2 = 20.0, f3 = -5.0;
    absoluteValue(f1, 1);
    absoluteValue(f2, 1);
    absoluteValue(f3, 1);

    printf("\n");

    // SQR test cases;
    f1 = -15.0, f2 = 25.0, f3 = 36.0;
    squareRoot(f1);
    squareRoot(f2);
    squareRoot(f3);

    return 0;
}

int gcd(int x, int y)
{
    int a = x;
    int b = y;
    int temp;

    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    printf("The GCD of %d and %d is %d \n", x, y, a);

    return a;
}

float absoluteValue(float x, int test)
{
    float n = x;

    if (n < 0)
    {
        n = -n;
    }

    if (test == 1)
    {
        printf("The abs of %.2f is %.2f \n", x, n);
    }
    return n;
}

float squareRoot(float x)
{
    float n = x;
    const float epsilon = .00001;
    float guess = 1.0;

    if (n < 0)
    {
        printf("Can not square negative number. \n");
        return -1;
    }

    while (absoluteValue((guess * guess - n), 0) >= epsilon)
    {
        guess = (n / guess + guess) / 2.0;
    }

    printf("The square root of %.2f is : %.2f \n", x, guess);

    return guess;
}