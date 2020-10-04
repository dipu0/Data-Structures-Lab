#include <stdio.h>

int isPrime_flag( int n)
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
        printf("Prime number");
    }
    else
    {
        if (flag == 0)
            printf("prime number.");
        else
            printf("Not prime number.");
    }

}

int main()
{

    int n;
    printf("Enter: ");
    scanf("%d", &n);
    isPrime_flag(n);

}
