#include<stdio.h>
#include <iostream>
using namespace std;
int data[100];
int count=1;

void Max_ReheapUp(int position)
{
    int parent;

    if(position>1)
    {
        parent = (position/2);
        if (data[ position] > data[parent])
        swap( data[position], data[parent]);
        Max_ReheapUp(parent);
    }

}
void Min_ReheapUp(int position)
{
    int parent;

    if(position>1)
    {
        parent = (position/2);
        if (data[ position] < data[parent])
        swap( data[position], data[parent]);
       Min_ReheapUp(parent);
    }

}
void Max_ReheapDown(int n, int i)
{
	int largest = i;
	int l=2*i;
	int r = 2*i + 1;


	if (l < n && data[l] > data[largest])
		largest = l;


	if (r < n && data[r] > data[largest])
		largest = r;

	if (largest != i)
	{
		swap(data[i], data[largest]);
		Max_ReheapDown(n, largest);
	}
}
void Max_BuildHeap( int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        Max_ReheapUp(i);
    }
}
void Min_BuildHeap( int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        Min_ReheapUp(i);
    }
}
void InsertHeap(int DataIn)
{
    data[count]=DataIn;
    Min_ReheapUp(count);
    count++;
}
int Delete_Root()
    {
    int start=data[1];

    int end = data[count-1];

    data[1] = end;
    count--;
    Min_ReheapUp(count-1);
    return start;
}

void heapSort(int n)
{
	for (int i=n-1; i>=1; i--)
	{
		swap(data[1], data[i]);
		Max_ReheapUp(i);
	}
}
int main()
{
 while(1)
    {
        printf(" 1.Insert Operation. 2.Deletion Operation. 3. Smallest and Largest Element \n 4. Heap Sort. 5. print heap. 6. Exit \n");


        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int x;
            scanf("%d", &x);
            InsertHeap(x);
        }
        if(ch==2)
        {
        printf("Data Deleted: %d",Delete_Root());
        printf("\n");
            printf("S:\n");
            for (int i = 1; i <count; i++)
                printf("%d ",data[i]);
                printf("\n");
        }

        else if(ch==3)
        {
            printf("Min Data: %d ",data[1]);
            printf("\n");
            Max_BuildHeap(count);
            printf("Mxn Data: %d ",data[1]);
            printf("\n");

        }
        else if(ch==4)
        {
            heapSort(count);
        printf("S:\n");
        for (int i = 1; i <count; i++)
            printf("%d ",data[i]);
            printf("\n");

        }

        else if(ch==5)
        {
        printf("S:\n");
        for (int i = 1; i <count; i++)
            printf("%d ",data[i]);
            printf("\n");

        }
        else if(ch==6)
        {
            break;
        }
    }
}
