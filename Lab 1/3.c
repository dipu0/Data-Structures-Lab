#include <stdio.h>
#include<time.h>

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
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, i, count=0;
    printf("Enter: ");
    scanf("%d", &n);

    clock_t start = clock();
    for (i =1; i < n; ++i)
    {

        if (isPrime_count(i)==1)
            count++;

    }
    printf("Number of prime %d .\n",count);
    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f",seconds);

    return 0;
}
