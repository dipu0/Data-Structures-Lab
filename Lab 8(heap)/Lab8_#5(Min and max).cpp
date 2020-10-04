#include<stdio.h>
#include <iostream>
using namespace std;
void Min_heapify(int arr[], int n, int i)
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
       Min_heapify(arr, n, smallest);
    }
}

void Max_heapify(int arr[], int n, int i)
{
	int largest = i;
	int l=2*i;
	int r = 2*i + 1;


	if (l < n && arr[l] > arr[largest])
		largest = l;


	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		Max_heapify(arr, n, largest);
	}
}

void Min_BuildHeap(int arr[],int n)
{
    for (int i = n/2 ; i >=1; i--)
        Min_heapify(arr, n+1, i);

}

void Max_BuildHeap(int arr[],int n)
{
    for (int i = n/2 ; i >=1; i--)
        Max_heapify(arr, n+1, i);

}
int main()
{

	int arr[50], i, n;
     printf("Enter number of elements: ");
     scanf("%d", &n);

     for(i=1; i<=n; i++)
     {
           printf("Enter elements %d : ",i);
          scanf("%d", &arr[i]);

     }

    Min_BuildHeap(arr,n);
        printf("Min: %d \n",arr[1]);

   Max_BuildHeap(arr,n);
    printf("Max: %d \n",arr[1]);

}

