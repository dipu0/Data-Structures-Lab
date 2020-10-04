#include <stdio.h>
int binary(int d)
{
    if(d == 0)
        return 0;
    else
    {

    int r=d%2;
    return (r+10*binary(d/2));

    }

}
int main()
{
    int n;
     printf("Enter decimal number: ");
    scanf("%d",&n);
    printf("Binary number: %d",binary(n));
}

