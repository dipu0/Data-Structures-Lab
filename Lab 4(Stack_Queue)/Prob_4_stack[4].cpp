#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
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


int priority_of_Operator(char c)
{
     if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    if(c == '(')
        return 0;
}

int main()
{
    Stack s;
    bool flag= true;
    int i,temp=0,l=0;
    char c[100];
    gets(c);
    l=strlen(c);
    for(i=0; i<l; i++)
    {

        if(isalnum(c[i]))
            printf("%c",c[i]);

        else if(c[i] == '(')
            s.push(c[i]);
        else if(c[i] == ')')
        {
            while((temp=s.pop()) != '(')
                printf("%c", temp);
        }
        else
        {
            while(priority_of_Operator(s.getTop()) >= priority_of_Operator(c[i])){
                printf("%c",s.pop());
            }

            s.push(c[i]);
        }

    }
    while(s.getLength()!= 0)
    {
        printf("%c",s.pop());
    }
}
