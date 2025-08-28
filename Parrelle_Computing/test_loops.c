#include <stdio.h>

typedef int aint; // remove alignment from type
int a[256], b[256], c[256];

void foo(int n, aint *__restrict__ p, aint *__restrict__ q)
{
    int i;
    int MAX = 1000;
    int orig_n = n; // store original n for loops

    while (n--)
    {
        *p++ = *q++ + 5;
    }

    for (i = 0; i < orig_n; i++)
    {
        a[i] = b[i + 1] + c[i + 3];
    }

    for (i = 0; i < orig_n; i++)
    {
        int j = a[i];
        b[i] = (j > MAX ? MAX : 0);
    }
}

int main()
{
    int n = 5;

    // align the arrays themselves
    aint p[5] __attribute__((aligned(16)));
    aint q[5] __attribute__((aligned(16)));

    // initialize q
    for (int i = 0; i < n; i++)
    {
        q[i] = i * 2; // q = {0, 2, 4, 6, 8}
        p[i] = 0;     // initialize p
    }

    // initialize b and c for later loops
    for (int i = 0; i < 10; i++)
    {
        b[i] = i * 10; // b = {0,10,20,...}
        c[i] = i * 3;  // c = {0,3,6,...}
    }

    foo(n, p, q);

    // print results
    printf("p array after foo:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    printf("a array after foo:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("b array after foo:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}