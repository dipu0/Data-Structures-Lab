#include <stdio.h>
#include<string.h>
int size(char str[], int index)
{

    if (str[index]==NULL)
        return 0;

    else
    return (1+size(str,index + 1));
}

int main()
{
    char str[100];
    gets(str);
    int c;
    c = size(str,0);
    printf("%d",c);
    return 0;
}
