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


int main()
{
    Stack w1,w2;
    int i,l=0;
    char str[100];
    gets(str);
    for(i=0; str[i]!='\0'; i++)
    {
        w1.push(str[i]);
        l++;
    }

    for(i=l-1; i>=0; i--)
    {
        w2.push(str[i]);

    }

   /* for(i=0; i<l; i++)
    {
        w2.push(w1.pop());
    }

    for(i=0; str[i]!='\0'; i++)
    {
        w1.push(str[i]);
    }
    */

    bool flag= false;


    while(!w1.isEmpty() && !w2.isEmpty())
    {


        if(w1.pop()!=w2.pop())
        {

            flag= false;
            break;
        }
        else
        {
            flag= true;

        }
    }


    if(flag==true)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }

    return 0;
}



