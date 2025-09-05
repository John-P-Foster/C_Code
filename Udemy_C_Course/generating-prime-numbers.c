#include <stdio.h>

int main()
{
    int primeNums = 50;
    int primes[primeNums];
    int maxNumber = 100;

    int i;
    for (i = 0; i < primeNums; i++)
    {
        primes[i] = 0;
    }

    for (i = 1; i < maxNumber + 1; i = i + 2)
    {
        int j = 0;
        while (primes[j] != 0)
        {
            if (i % primes[j] != 0 || primes[j] == 1)
            {

                j++;
            }
            else
            {
                break;
            }
        }
        if (primes[j] == 0)
        {
            primes[j] = i;
        }
    }

    i = 0;
    while (primes[i] != 0)
    {
        printf(" %d", primes[i]);
        i++;
    }

    return 0;
}