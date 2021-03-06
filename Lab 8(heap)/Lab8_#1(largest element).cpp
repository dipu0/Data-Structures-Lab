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
void BuildHeap(int arr[],int n)
{
    for (int i = n/2 ; i >= 1; i--){

        heapify(arr, n+1, i);
	}
}

int Extract_Max(int arr[], int n)
{

    int start=arr[1];

    int end = arr[n];

    arr[1] = end;
    heapify(arr, n, 1);
    return start;
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

    printf("Enter k: ");
    scanf("%d", &k);
	//n = sizeof(arr)/sizeof(arr[0]);

	BuildHeap(arr,n);

    //for (int i = 1; i <=n; i++)
    //    printf("%d ",arr[i]);
    //    printf("\n");

    for(i=0;i<k;i++)
        {
            printf("%d\n",Extract_Max(arr, n-i));
        }
}
