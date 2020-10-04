#include<stdio.h>
#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int smallest=i;
    int l= 2*i;
    int r= 2*i+1;
    if (l<n && arr[l] < arr[smallest])
    {
        smallest = l;
    }
    if (r < n && arr[r] < arr[smallest])
    {
        smallest = r;
    }
    if (smallest!= i) {
            swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void BuildHeap(int arr[],int n)
{
    for (int i = n/2 ; i >=1; i--){

        heapify(arr, n+1, i);
	}
}

int main()
{

	int arr[50], i, n, k;
     printf("Enter number of elements: ");
     scanf("%d", &n);

     for(i=1; i<=n; i++)
     {
           printf("Enter elements %d : ",i);
          scanf("%d", &arr[i]);

     }

    BuildHeap(arr,n);
    for (int i = 1; i <=n; i++)
        printf("%d ",arr[i]);
        printf("\n");
}
