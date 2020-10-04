#include<stdio.h>
#include <iostream>
using namespace std;
int arr[100];
int l=0;

class Priority_Queue
{
    public:

    void Max_heapify(int arr[], int n, int i){
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


    void BuildHeap(int arr[],int n)
    {
        for (int i = n/2 ; i >=1; i--)
            Max_heapify(arr, n+1, i);

    }

    void Insert( int x )
    {


         l++;
        arr[l]=x;
       BuildHeap(arr,l);
    }

    int Extract_Max(int arr[], int n)
    {

    int start=arr[1];

    int end = arr[n];

    arr[1] = end;
    Max_heapify(arr, n, 1);
    l--;
    return start;
}
    void Increase_Key(int a, int b)
    {
        int i;
        for(i=1;i<=l;i++)
        {
            if(a==arr[i])
                {
                arr[i]=b;
                 break;
                }
        }

        BuildHeap(arr,l);
    }

};
int main()
{
    Priority_Queue pq;
 while(1)
    {
        printf(" 1. Insert item. 2.Print Max heap. 3. Maximum Item.\n 4. Extract-Max item. 5. Increase-Key( x, k ). 6. Exit \n");


        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int x;
            scanf("%d", &x);
            pq.Insert(x);
        }
        else if(ch==2)
        {

        //printf("Size of arr %d \n",l);
         //BuildHeap(arr,l);
        printf("S:\n");
        for (int i = 1; i <=l; i++)
            printf("%d ",arr[i]);
            printf("\n");

        }

        else if(ch==3)
        {
            printf("Max: %d ",arr[1]);
            printf("\n");

        }
        else if(ch==4)
        {
            printf("return: %d",pq.Extract_Max(arr,l));
            printf("\n");
            printf("S:\n");
            for (int i = 1; i <=l; i++)
                printf("%d ",arr[i]);
                printf("\n");


        }
        else if(ch==5)
        {
            int x,k;
            scanf("%d", &x);
            scanf("%d", &k);
            pq.Increase_Key(x,k);
            printf("S:\n");
            for (int i = 1; i <=l; i++)
                printf("%d ",arr[i]);
                printf("\n");

        }

        else if(ch==6)
        {
            break;
        }
    }
}

