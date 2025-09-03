#include <stdio.h>
#include <time.h>
#include <stdlib.h>

long long sum1 = 0;        // To be the sum of the even indexed values.
long long sum2 = 0;        // To be the sum of the odd indexed values.
int unOptimizedTime = 0;   // Base line time.
int *a;                    // Pointer to a very large array in memory.
#define Size 100000000 * 8 // The size of the array in memory, time 8 to simplify loops.

// Case 14 as given in home work.
void case_14(void)
{
    int i;
    for (i = 0; i < Size / 2; i++)
    {
        sum1 += a[2 * i];
        sum2 += a[(2 * i) + 1];
    }
}

// First attempt, optimized by 8 and spliting loop.
void case_14_Optimized1()
{
    int i;
    for (i = 0; i < Size; i += 8)
    {
        sum1 += a[i] + a[i + 2] + a[i + 4] + a[i + 6];
    }

    for (i = 1; i < Size; i += 8)
    {
        sum2 += a[i] + a[i + 2] + a[i + 4] + a[i + 6];
    }
}

// Second optimization unrolling by 16 ints for better use of cache.
void case_14_Optimized2()
{
    int i;
    long long localSum1 = 0;
    long long localSum2 = 0;

    for (i = 0; i < Size; i += 16)
    {
        localSum1 += a[i] + a[i + 2] + a[i + 4] + a[i + 6] + a[i + 8] + a[i + 10] + a[i + 12] + a[i + 14];
        localSum2 += a[i + 1] + a[i + 3] + a[i + 5] + a[i + 7] + a[i + 9] + a[i + 11] + a[i + 13] + a[i + 15];
    }

    sum1 = localSum1;
    sum2 = localSum2;
}

// Tracks clock ticks of each function passed.
void runFunction(void (*function)(), char *functionOpt)
{

    clock_t start = clock();

    function();

    clock_t end = clock();

    int totalTime = (end - start);

    printf("\n........ %s ........ \n", functionOpt);
    printf("Sum 1: %lld  Sum 2: %lld \n", sum1, sum2);
    printf("Total time: %d ticks. \n", totalTime);

    // Set base line time if not set, run comparison if it is.
    if (unOptimizedTime == 0)
    {
        unOptimizedTime = totalTime;
    }
    else
    {
        int reduction = unOptimizedTime - totalTime;
        double percentReduction = ((double)reduction / (double)unOptimizedTime) * 100;

        printf("Optimized function was %%%.2f faster. \n", percentReduction);
    }

    sum1 = 0;
    sum2 = 0;
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

    // Run base line function as given.
    char unOptimized[] = "Case-14 Unoptimized";
    runFunction(&case_14, unOptimized);

    // First optimization Splitting loops and unrolling.
    char optimized1[] = "Case-14 first Optimization";
    runFunction(&case_14_Optimized1, optimized1);

    // Second optimization unrolling by 16 for better use of cache.
    char optimized2[] = "Case-14 Second Optimization";
    runFunction(&case_14_Optimized2, optimized2);

    return 0;
}
