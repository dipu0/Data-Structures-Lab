#include<stdio.h>
#include<stdlib.h>

#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}

/****** Complete the following functions using Loop ******/
struct treeNode * searchItem(struct treeNode * node, int item)
{
    // return the treeNode holding the item
   while(node!=0){
        if(node->item == item){
            return node;
          //  break;
        }
        else if(node->item<item){
            node=node->right;
        }
        else{
            node=node->left;
        }
       // printf("loop end.....");//
    }
    printf("Invalid\n");
    return node;
};

int insertItem(struct treeNode * node, int item)
{
    //If success return TRUE_VALUE, else return FALSE_VALUE

   if(root==0)

    {
        struct treeNode* newTree=(struct treeNode*)malloc(sizeof(struct treeNode));

        newTree->item=item;
        newTree->left=NULL;
        newTree->right=NULL;
        root=newTree;

        return TRUE_VALUE;
    }
    else
    {
        struct treeNode * node,*parent;
        node=root;

        while(node!=0)
        {
            if (node->item== item)
                return FALSE_VALUE;

            if(node->item > item)
            {
                parent=node;
                node=node->left;
            }
           if(node->item < item)
            {
                parent=node;
                node=node->right;
            }
        }

        struct treeNode* newtree=(struct treeNode*)malloc(sizeof(struct treeNode));

        newtree->item=item;
        newtree->left=0;
        newtree->right=0;

        if(item < parent->item)
        {
            parent->left=newtree;
        }
        else
        {
            parent->right=newtree;
        }
        return TRUE_VALUE;
    }
}

void deleteItem(struct treeNode * node, int item)
{
    //If success return TRUE_VALUE, else return FALSE_VALUE

    struct treeNode * temp, *parent=searchItem(root,item);

    if(parent->left==0 && parent->right==0)
        {
            free(parent);
        }

    else if(parent->right==0)
        {
            temp=parent->left;

            while(temp->right!=0)
            {
                temp=temp->right;
            }

            parent->item=temp->item;

            free(temp);
        }

    else
        {
            struct treeNode * temp;

            temp=parent->right;

            while(temp->left!=0)
            {
                temp=temp->left;
            }

            parent->item=temp->item;

            free(temp);
        }
}

int calcLevel(int item)
{
    //return level/depth of an item in the tree
    struct treeNode *node= root;

     int c=0;

     while(node!=0){

        if(node->item == item){
            return c;
        }
        if(node->item< item){
            node=node->right;
        }
        else{
            node=node->left;
        }
        c++;
    }
    printf("Not found.\n");
    return FALSE_VALUE;
}

int getMinItem() // return the minimum item in the tree
{

    struct treeNode * node= root;
    while(node->left!=0)
    {
        node=node->left;
    }
    return node->item;

}

int getMaxItem() // return the maximum item in the tree
{
    struct treeNode * node= root;

    while(node->right!=0)
    {
        node=node->right;
    }
    return node->item;

}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print level of an item. \n");
        printf("5.Get Minimum  6.Get Maximum \n");
        printf("7.Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(root, item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            int level = calcLevel(item);
            printf("Level of %d = %d\n", item, level);
        }
        else if(ch==5)
        {
            printf("%d\n",getMinItem());
        }
        else if(ch==6)
        {
            printf("%d\n",getMaxItem());
        }
        else if(ch==7)
        {
            break;
        }
    }

}

