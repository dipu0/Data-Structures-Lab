#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
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
		heapify(arr, n, largest);
	}
}
BuildHeap(int arr[],int n)
{
    for (int i = n/2 ; i >= 1; i--){

        heapify(arr, n+1, i);
	}
}

void heapSort(int arr[], int n)
{
	for (int i=n; i>1; i--)
	{

		swap(arr[1], arr[i]);
		heapify(arr, i, 1);
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


	//n = sizeof(arr)/sizeof(arr[0]);

	BuildHeap(arr,n);
	heapSort(arr,n);

    for (int i = 1; i <=n; i++)
        printf("%d ",arr[i]);
        printf("\n");

}
