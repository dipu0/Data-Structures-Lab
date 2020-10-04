#include <stdio.h>
int fib(int n)
{
    if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    else
    {
        return(fib(n-1)+fib(n-2));
    }
}

int main()
{
    int n;
    printf("Order fibonacci sequence: ");
    scanf("%d", &n);
    printf("summation of %dth fibonacci sequence %d",n,fib(n));
    return 0;
}
