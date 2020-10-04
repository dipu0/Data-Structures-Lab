#include<stdio.h>
int fac(int n)
{
    if (n==1)
        return 1;
    else
        return n*fac(n-1);
}
int main()
{
    int n;
    printf("Enter n!: ");
    scanf("%d",&n);
    printf("Factorial of %d = %d ",n,fac(n));
    return 0;
}

