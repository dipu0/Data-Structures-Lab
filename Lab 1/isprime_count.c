#include <stdio.h>


int isPrime_count(int n)
{

    int i, c = 0;

    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            c++;
        }
    }

    if (c == 2)
    {
        printf("Prime number");
    }
    else
    {
        printf("not Prime number");
    }
}

main()
{

    int n;
    printf("Enter: ");
    scanf("%d", &n);
    isPrime_count(n);
}
