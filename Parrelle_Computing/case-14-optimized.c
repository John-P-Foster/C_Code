#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long long sum1;
long long sum2;
int *a;

#define Size 100000000 * 8

void case_14(void)
{
    int i;
    for (i = 0; i < Size / 2; i++)
    {
        sum1 += a[2 * i];
        sum2 += a[(2 * i) + 1];
    }
}

void case_14_Optimized1()
{
    int i;
    for (i = 0; i < Size; i += 4)
    {
        sum1 += a[i] + a[i + 2] + a[i + 4] + a[i + 6];
    }

    for (i = 1; i < Size; i += 8)
    {
        sum2 += a[i] + a[i + 2] + a[i + 4] + a[i + 6];
    }
}

void case_14_Optimized2()
{
    int i;
    long long localSum1;
    long long localSum2;

    for (i = 0; i < Size; i += 16)
    {
        localSum1 += a[i] + a[i + 2] + a[i + 4] + a[i + 6] + a[i + 8] + a[i + 10] + a[i + 12] + a[i + 14];
        localSum2 += a[i + 1] + a[i + 3] + a[i + 5] + a[i + 7] + a[i + 9] + a[i + 11] + a[i + 13] + a[i + 15];
    }

    sum1 = localSum1;
    sum2 = localSum2;
}

int main()
{

    // Create large memory space for the array
    a = malloc(Size * sizeof(int));
    if (!a)
    {
        printf("Failed to allocate memory in RAM!(Reduce Size)\n");
        return 1;
    }

    // fill the array with values 0 - 9.
    for (int i = 0; i < Size; i++)
    {
        a[i] = i % 10;
    }

    clock_t start = clock();

    case_14();

    clock_t end = clock();

    int totalTime1 = (end - start);

    printf("Case 14 un optimized results: \n");
    printf("Sum 1: %lld  Sum 2: %lld \n", sum1, sum2);
    printf("Total time: %d cylces. \n \n", totalTime1);

    sum1 = 0;
    sum2 = 0;
    clock_t start2 = clock();

    case_14_Optimized2();

    clock_t end2 = clock();

    int totalTime2 = (end2 - start2);

    printf("Case 14 optimized results: \n");
    printf("Sum 1: %lld  Sum 2: %lld \n", sum1, sum2);
    printf("Total time: %d cycles. \n \n", totalTime2);

    int reduction = totalTime1 - totalTime2;
    double percentReduction = ((double)reduction / (double)totalTime1) * 100;

    printf("Optimized function was %%%.2f faster.", percentReduction);

    return 0;
}