#include <stdio.h>
#include<stdlib.h>

int Max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else return b;
}
int MaxArray(int arr[],int index, int n)
{
    if(index==n-1)
        return arr[index];

    return Max(arr[index],MaxArray(arr,index+1,n));
}
int main()
{

    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: \n");
    int i;
    for (i = 0; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
        printf("\n%d",MaxArray(arr,0,n));
        return 0;
}
