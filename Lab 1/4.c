#include <stdio.h>
#include<time.h>

int isPrime_Flag( int n)
{

    int i, flag = 0;

    for (i = 2; i <= n-1; i++)
    {


        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }

    if (n == 1)
    {
        return 0;
    }
    else
    {
        if (flag == 0)
            return 1;
        else
            return 0;
    }

}
int main()
{
    int n, i, count=0;
    printf("Enter: ");
    scanf("%d", &n);

    clock_t start = clock();

    for (i =1; i < n; i++)
    {

        if (isPrime_Flag(i)==1)
            count++;
    }

    printf("Number of prime %d .\n",count);

    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f",seconds);

    return 0;
}
