#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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

    Stack s;
    bool flag= true;
    int i,l=0;
    char c[100];
    gets(c);
    l=strlen(c);

    for(i=0; i<l; i++)
    {
        if(c[i]=='('|| c[i]=='{' || c[i]=='[')
        {
            s.push(c[i]);
        }

        else if(c[i]==')')
        {

            if(s.pop()=='(') {}

            else
            {
                flag= false;

                break;
            }

        }
        else if(c[i]=='}')
        {
            if(s.pop()=='{') {}
            else
            {
                flag= false;
                break;
            }
        }
        else if(c[i]==']')
        {
            if(s.pop()=='[') {}
            else
            {
                flag= false;
                break;
            }
        }

    }
    if(s.isEmpty()==true && flag==true)
    {
        printf(" balanced");
    }

    else
    {
        printf(" not balanced");
    }
}




