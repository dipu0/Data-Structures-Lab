#include <stdio.h>
void subSet(int arr[],int check[],int start,int n,int index, int j)
{
    if (index==j)
    {
        printf("\n");

        for (int k=0; k<j; k++)

            printf("%d ", check[k]);

        printf("\n");

        return;
    }

    for (int i=start; i< n && n-i >= j-index; i++)
    {
        check[index] = arr[i];
        subSet(arr, check, i+1, n, index+1,j);
    }
}

int main()
{
    int i,j,n,arr[100];
    printf("Enter the number of element: ");
	scanf("%d",&n);
	 printf("Enter elements: \n");
	for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(j=1;j<=n;j++)
    {
    int check[j];
    subSet(arr,check,0, n, 0, j);
    }
	return 0;
}


