#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#define Stack_MAX_Size 300
#define Queue_MAX_Size 300
#define FAILURE_VALUE -99999
#define SUCCESS_VALUE 99999
class Stack
{
private:
    int stack[Stack_MAX_Size];
    int top;

public:
    Stack()
    {
        top = 0 ;
    }

    int push(int item)
    {
        if(top==Stack_MAX_Size) return FAILURE_VALUE;
        stack[top]=item;
        top++;
        return SUCCESS_VALUE;
    }
    int pop()
    {
        if(top==0) return FAILURE_VALUE;
        top--;
        return stack[top];
    }
    int getTop()
    {
        return stack[top-1];
    }

    int getLength()
    {
        return top;
    }

    bool isEmpty()
    {
        if(top==0) return true;
        else return false;
    }
    bool isFull()
    {
        if(top==Stack_MAX_Size) return true;
        else return false;
    }


};

class Queue
{
private:
    int queue[Queue_MAX_Size];
    int length,front,rear;
public:
    Queue()
    {
        length=0;
        front=0;
        rear=0;
    }
    int enqueue(int item)
    {
        if(length == Queue_MAX_Size) return FAILURE_VALUE;
        queue[front] = item ;
        front++ ;
        length++ ;
        return SUCCESS_VALUE;
    }
    int dequeue()
    {
        if(length == 0) return 0;
        int item = queue[rear] ;
        rear++ ;
        length-- ;
        return item ;
    }
    int getLength()
    {
        return length;
    }
    bool isEmpty()
    {
        if(length==0) return true;
        else return false;
    }
    bool isFull()
    {
        if(length==Queue_MAX_Size) return true;
        else return false;
    }
};

int main()
{
    Queue q;
    Stack s;

    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int num;
    for(int i=0; i<n; i++)
    {
        printf("Item %d: ",i+1);
        scanf("%d",&num);
        q.enqueue(num);
    }
    while(!q.isEmpty())
    {
        s.push(q.dequeue());
    }
    while(!s.isEmpty())
    {
        q.enqueue(s.pop());
    }
    printf("\nReversed items: ");
    while(!q.isEmpty())
    {
        printf("%d  ",q.dequeue());
    }
}
