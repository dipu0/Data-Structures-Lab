#include <stdio.h>
#include <math.h>

int rev(int n)
{
    int digit=(int)log10(n);// log10(121)=2.08
    if(n==0)
    {
        return 0;
    }
    return ((n%10 * pow(10, digit))+rev(n/10));

}
int Palindrome(int n)
{
    if(n==rev(n))
        printf("Palindrome");
    else
     printf("Not palindrome");
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    Palindrome(n);
}
