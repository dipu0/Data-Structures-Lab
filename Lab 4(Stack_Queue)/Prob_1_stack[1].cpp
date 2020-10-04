#include<stdio.h>
#include<stdlib.h>
#define Stack_MAX_Size 300
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

int SOD(int digits)//sum of digits of each number i.e.(2+3+1=6, 5+0+1=6, 4+6=10, 5+7=12, 5+3=8)
{
    int sum=0,temp;
    while(digits!=0)
    {
        temp=digits%10;
        sum+=temp;
        digits=digits/10;
    }
    return sum;
}
int main()
{
    Stack s;
    int i,n,a[100];
    printf("Enter the size: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);

    }

    for(i=0; i<n; i++)
    {

        s.push(SOD(a[i]));
    }
    for(i=0; i<n; i++)
    {

        printf("%d ",s.pop());
    }

}

