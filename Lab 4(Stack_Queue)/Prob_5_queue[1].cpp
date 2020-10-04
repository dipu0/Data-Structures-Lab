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
    Stack s1,s2;
    int length;
public:
    Queue()
    {
        length=0;
    }
    int enqueue(int item)
    {
        s1.push(item);
        length++;
    }
    int dequeue()
    {
        if (s2.isEmpty())
        {

            while(!s1.isEmpty())
            {
                s2.push(s1.pop());

            }
        }

        length--;
        return s2.pop();

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
    int c;
    while(1)
    {
        printf("1.Enqueue  2.Dequeue  3.Get Length 4.Check Empty  5.Check Full 6.Dequeue All(print) 7.Exit\n");
        scanf("%d",&c);
        if(c==1)
        {
            int num,n,i;
            printf("Enter item number: ");
            scanf("%d",&n);
            for(i=0; i<n; i++)
            {
                printf("Item %d: ",i+1);
                scanf("%d",&num);
                q.enqueue(num);
            }


        }
        else if(c==2)
        {
            printf("%d\n",q.dequeue());
        }
        else if(c==3){
            printf("Length: %d\n",q.getLength());
        }
        else if(c==4)
        {
            if(q.isEmpty())
            {
                printf("Empty.\n");
            }
            else
            {
                printf("Not Empty.\n");
            }
        }
        else if(c==5)
        {
            if(q.isFull())
            {
                printf("Full.\n");
            }
            else
            {
                printf("Not Full.\n");
            }
        }

        else if(c==6)

        {
            int i;

            while(!q.isEmpty())
            {
                printf(" %d ",q.dequeue());

            }
            printf("\n");
        }
        else if(c==7)
            break;
        else
            printf("Invalid");
    }
}


