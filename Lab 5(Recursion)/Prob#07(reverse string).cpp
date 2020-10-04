#include<stdio.h>
#include<string.h>
int swp(char *a, char *b)
{
    char t = *a;
    *a=*b;
    *b=t;
}
void rev(char str[],int start,int end)
{
    if(start==end)
    {
        return;
    }
    else if(start<end)
    {
        swp(str+start,str+end);
        rev(str,start+1,end-1);
    }
}
int main()
{
    int l;
    char str[100];
    gets(str);
    l=strlen(str);
    rev(str,0,l-1);
    puts(str);
    return 0;
}
