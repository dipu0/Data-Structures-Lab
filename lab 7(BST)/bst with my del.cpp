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


struct treeNode * searchItem(struct treeNode * node, int item)
{
    // Solve using recursion
     if(node==0)
        return 0;

    if(node->item==item)
        return node;
    else
    {
        if(item < node->item)
            searchItem(node->left,item);

        else
            searchItem(node->right,item);
    }

};

struct treeNode * searchPrev(struct treeNode * node,int item)
{
    // Return the parent node of the item using recursion
     if(node!=0)
        {
        if(node->left!=0 && node->left->item==item)

            return node;

        else if(node->right!=0 && node->right->item==item)
            return node;

        else{
            if(item < node->item)

                searchPrev(node->left,item);

            else if(item > node->item)

                searchPrev(node->right,item);

            else if(item==root->item)
                return 0;

        }
    }
    else
        return 0;

};

struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    // Insert item in the tree using recursion
    if (root==0)
    {
      root=makeTreeNode(item);
      return root;
    }

    if (node == 0)

        return makeTreeNode(item);

    else {
        if (item < node->item)
            node->left = insertItem(node->left, item);
        if(item>node->item)
            node->right = insertItem(node->right, item);

    return(node);
  }
}


int calcNodeHeight(struct treeNode * node)
{
    // return height (maximum distance from node to leaf + 1) using recursion
    if (node==0)
       return 0;
   else
   {

       int leftH = calcNodeHeight(node->left);
       int rightH = calcNodeHeight(node->right);

       if (leftH > rightH)

           return(leftH+1);

       else return(rightH+1);
   }
}


int calcHeight(int item) //return height of an item in the tree
{
    // return height of an item using calcNodeHeight function
    return calcNodeHeight(searchItem(root,item));
}

int getSize(struct treeNode * node)
{
    // return size of the tree with node(argument) as root using recursion
    if(node!=0)

        return(getSize(node->left) + 1 + getSize(node->right));

    else return 0;
}

int calcNodeDepth(struct treeNode * node,struct treeNode * root)
{
    //calculate depth of level of a node using recursion
    int count=0;
     if(root==node)
        return count;

    else{
        if(node->item < root->item)

           count= 1+ calcNodeDepth(node,root->left);

        else
            count= 1+ calcNodeDepth(node,root->right);
        }
}

int findLCA(struct treeNode *node,int item1,int item2)
{
    //Find lowest common ancestors of item1 and item2 using recursion
    if(item1 <= node->item && node->item  <= item2)

        return node->item;

    if(item1 > node->item)
        findLCA(node->right,item1,item2);

    if(item2 < node->item)
        findLCA(node->left,item1,item2);

}

int calcDepth(int item)
{
    //Return depth or level of an item using calcNodeDepth function
    return calcNodeDepth(searchItem(root,item),root);
}


struct treeNode* getMinItem(struct treeNode * node)
{
    //return the minimum item in the tree using recursion
    if(node->left==0)
        return node;

    else
        getMinItem(node->left);

}

int getMaxItem(struct treeNode * node)
{
    //return the maximum item in the tree using recursion
    if(node->right==NULL)
        return node->item;

    else
        getMaxItem(node->right);

}

int deleteItem(struct treeNode * node, int item)
{
    //write your code from previous assignment here, you do not need to implement using recursion
   treeNode* curr = root;
    treeNode* prev = NULL;

    // Check if the item is actually
    // present in the BST.
    // the variable prev points to
    // the parent of the item to be deleted.
    while (curr != NULL && curr->item != item) {
        prev = curr;
        if (item < curr->item)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL) {
             printf("item not founf");

    }

    // Check if the node to be
    // deleted has atmost one child.
    if (curr->left == NULL
        || curr->right == NULL) {

        // newCurr will replace
        // the node to be deleted.
        treeNode* newCurr;

        // if the left child does not exist.
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;

        // check if the node to
        // be deleted is the root.
        if (prev == NULL)


        // check if the node to be deleted
        // is prev's left or right child
        // and then replace this with newCurr
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;

        // free memory of the
        // node to be deleted.
        free(curr);
    }

    // node to be deleted has
    // two children.
    else {
        treeNode* p = NULL;
        treeNode* temp;

        // Compute the inorder successor
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }

        // check if the parent of the inorder
        // successor is the root or not.
        // if it isn't, then make the
        // left child of its parent equal to the
        // inorder successor's right child.
        if (p != NULL)
            p->left = temp->right;

        // if the inorder successor was the
        // root, then make the right child
        // of the node to be deleted equal
        // to the right child of the inorder
        // successor.
        else
            curr->right = temp->right;

        curr->item = temp->item;
        free(temp);
    }

}

int rangeSearch(struct treeNode * node, int leftB, int rightB)
{
    //returns number of items in the range of leftB and rightB using recursion
    if(node==0)
        return 0;

    if(leftB <= node->item && node->item <= rightB)
        return 1+rangeSearch(node->left,leftB,rightB)+rangeSearch(node->right,leftB,rightB);

    if(leftB > node->item)
        rangeSearch(node->right,leftB,rightB);

    if(rightB < node->item)
        rangeSearch(node->left,leftB,rightB);

}

int findInOrderSuccessor(int item)
{
    //return In order successor of the item in the tree (You need not use recursion)

struct treeNode *node=searchItem(root,item);
    struct treeNode *tmp,*parent;
    if(node->right!=0)
    {
        tmp=node->right;
        while(tmp->left!=0)
        {
            tmp=tmp->left;
        }
        return tmp->item;
    }
    else{
        tmp=node;
        parent=searchPrev(root,tmp->item);
        while(tmp->item > parent->item && parent!=0)
        {
            tmp=parent;
            parent=searchPrev(root,parent->item);
        }
        if(parent!=0)
        {
            return parent->item;
        }
            return FALSE_VALUE;
    }
}

void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}

void printPreOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in pre-order
    if(node==0) return;

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print left sub-tree
    printPreOrder(node->left, height-1);

    //print right sub-tree
    printPreOrder(node->right, height-1);
}

void printPostOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in post-order
    if(node==0) return;

    //print left sub-tree
    printPostOrder(node->left, height-1);

    //print right sub-tree
    printPostOrder(node->right, height-1);
       //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);
}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf(" 1. Insert item. 2. Item parent. 3. Search item. \n");
        printf(" 4. Print height of tree. 5. Print height of an item. \n");
        printf(" 6. PrintInOrder. 7. PrintPreOrder 8. PrintPostOrder\n");
        printf(" 9. Print depth of an item. 10.Print size 11.Get Minimum 12.Get Maximum \n");
        printf("13.Delete item 14.RangeSearch 15.findLCA  16.findInorderSuccessor 17.Exit\n");

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
            struct treeNode * res = searchPrev(root, item);
            if(res==0) printf("No parent found.\n");
            else printf("Parent of %d is %d \n",item,res->item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found(%d).\n",res->item);
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==7)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printPreOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==8)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printPostOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==9)
        {
            int item;
            scanf("%d", &item);
            int depth = calcDepth(item);
            printf("Depth of %d = %d\n", item, depth);
        }
        else if(ch==10)
        {
            printf("Size of tree is %d\n",getSize(root));
        }
        else if(ch==11)
        {
            printf("%d\n",getMinItem(root));
        }
        else if(ch==12)
        {
            printf("%d\n",getMaxItem(root));
        }
        else if(ch==13)
        {
            int item;
            scanf("%d",&item);
            int func = deleteItem(root,item);
            if(func==-1) printf("Item not present\n");
            else printf("Deleted item: %d\n",func);
        }
        else if(ch==14)
        {
            int leftB,rightB;
            scanf("%d %d",&leftB,&rightB);
            int num = rangeSearch(root,leftB,rightB);
            printf("%d\n",num);
        }
        else if(ch==15)
        {
            int item1,item2;
            scanf("%d %d",&item1,&item2);
            printf("LCA is: %d\n",findLCA(root,item1,item2));
        }
        else if(ch==16)
        {
            int item;
            scanf("%d",&item);
            printf("In order successor of %d is: %d\n",item,findInOrderSuccessor(item));
        }
        else if(ch==17)
        {
            break;
        }
    }

}

