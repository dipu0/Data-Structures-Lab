#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * head;

void initializeList()
{
    head = 0;//initially set to NULL
}

int insertItem(int item) //insert at the beginning
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = head; //point to previous first node
	head = newNode ; //set list to point to newnode as this is now the first node
	return SUCCESS_VALUE ;
}

void printList()
{
    struct listNode * temp;
    temp = head;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void rev(struct listNode *newNode)
{
    if(newNode->next==NULL)
    {
        head=newNode;
        return;
    }
    rev(newNode->next);
    struct listNode* pre = newNode->next;
    pre->next=newNode;
    newNode->next=NULL;
}
int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Reverse node. 3. Print. 4. Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            printf("After Reversing node ");
            rev(head);
            printList();

        }
        else if(ch==3)
        {
            printList();
        }
        else if(ch==4)
        {
            break;
        }
    }
}


