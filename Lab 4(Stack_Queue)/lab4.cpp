#include<stdio.h>
#include<iostream>
#define STACK_MAX_SIZE 100
#define QUEUE_MAX_SIZE 100
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0
class Stack{
private:
    int data[STACK_MAX_SIZE];
    int top;
public:
    Stack()
    {
    top=0;
    }
   int push (int item)
    {
    data[top] = item ;
    top++ ;
    return SUCCESS_VALUE ;
    }
    int pop()
    {
    if(top == 0) return NULL_VALUE ;
    printf("pop kam kore");
    top-- ;
    return data[top] ;
    }
    int isEmpty()
    {
    if(top == 0) return TRUE_VALUE;
    else return FALSE_VALUE ;
    }
    int isFull()
    {
    if(top == STACK_MAX_SIZE) return TRUE_VALUE;
    else return FALSE_VALUE;
    }
    int getLength(){
        return top;
    }
};
class Queue{
    private:
    int data[QUEUE_MAX_SIZE];
    int length,front,rear;
public:
    Queue()
    {
        length=0;
        front=0;
        rear=0;
    }
    int enqueue(int item){
      if(length == QUEUE_MAX_SIZE) return FALSE_VALUE;
        data[front] = item ;
        front++ ;
        length++ ;
        return TRUE_VALUE;
    }
    int dequeue(){
        if(length == 0) return NULL_VALUE;
        int item = data[rear] ;
        rear++ ;
        length-- ;
        return item ;
    }
    int getLength(){
        return length;
    }
    int isEmpty(){
        if(length==0) return TRUE_VALUE;
        else return FALSE_VALUE;
    }
    int isFull(){
        if(length==QUEUE_MAX_SIZE) return TRUE_VALUE;
        else return FALSE_VALUE;
    }
};
void Prb1(){
Stack st;
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter numbers: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        int m=arr[i];
        int sum=0;
        while(m>0){
            sum=sum+(m%10);
            m=m/10;
        }
        st.push(sum);
    }
    while(!st.isEmpty()){
        printf("%d\n",st.pop());
    }
}
void Prb2(){
    Stack st;
    Stack temp;
    Stack rev;
    char str[50];
    printf("Enter string: ");
    scanf("%s",&str);
    for(int i=0;str[i]!='\0';i++){
        st.push(str[i]);
        temp.push(str[i]);
    }
    while(!temp.isEmpty()){
        rev.push(temp.pop());
    }
    bool flag=true;
    while(!st.isEmpty() && !rev.isEmpty()){
        if(st.pop()!=rev.pop()){
            flag=false;
            break;
        }
    }
    if(flag){
        printf("palindrome\n");
    }
    else{
        printf("not palindrome\n");
    }
}
void Prb3(){
    Stack st1,st2,st3;
    bool flag=true;
    char str[50];
    printf("Enter expression: ");
    scanf("%s",&str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            st1.push(str[i]);
        }
        else if(str[i]=='{'){
            st2.push(str[i]);
        }
        else if(str[i]=='['){
            st3.push(str[i]);
        }
        else if(str[i]==')'){
            if(!st1.pop()) flag=false;
        }
        else if(str[i]=='}'){
            if(!st2.pop()) flag=false;
        }
        else if(str[i]==']'){
            if(!st3.pop()) flag=false;
        }
    }
    if(st1.isEmpty() && st2.isEmpty() && st3.isEmpty() && flag){
        printf("valid");
    }
    else{
        printf("Invalid");
    }
}
void Prb4(){
    Stack st;
    char arr[50];
    printf("Enter expression: ");
    scanf("%s",&arr);
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]!='(' && arr[i]!=')' && arr[i]!='{' && arr[i]!='}' && arr[i]!='[' && arr[i]!=']' && arr[i]!='+' && arr[i]!='-' && arr[i]!='*' && arr[i]!='/'){
             printf("%c",arr[i]);
        }
        else if(arr[i]=='+' || arr[i]=='-'){
            int t=st.pop();
            if(t!=0){
                st.push(t);
            }
            if(t=='*' || t=='/'){
                while(!st.isEmpty() && t!='('){
                    printf("%c",st.pop());
                    t=st.pop();
                    if(t!=0){
                        st.push(t);
                    }
                }
            }
            st.push(arr[i]);
        }
        else if(arr[i]=='('){
            st.push(arr[i]);
        }
        else if(arr[i]=='*' || arr[i]=='/'){
            int t=st.pop();
            if(t!=0){
                st.push(t);
            }
            if(t=='*' || t=='/'){
                printf("%c",st.pop());
            }
            st.push(arr[i]);
        }
        else if(arr[i]==')'){
            int t=st.pop();
            if(t!=0){
                st.push(t);
            }
            while(t!='('){
                printf("%c",st.pop());
                t=st.pop();
                if(t!=0){
                    st.push(t);
                }
            }
            st.pop();
        }
    }
    while(!st.isEmpty()){
        printf("%c",st.pop());
    }
}
class StackQueue{
private:
    Stack s1,s2;
    int length;
public:
    StackQueue(){
        length=0;
    }
        int enqueue(int item){
        if(length == QUEUE_MAX_SIZE) return FALSE_VALUE;
        while(!s1.isEmpty()){
            s2.push(s1.pop());
        }
        s1.push(item);
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
        length++ ;
        return TRUE_VALUE;
    }
    int dequeue(){
        if(length == 0) return NULL_VALUE;
        int item = s1.pop() ;
        length-- ;
        return item ;
    }
    int getLength(){
        return length;
    }
    int isEmpty(){
        if(length==0) return TRUE_VALUE;
        else return FALSE_VALUE;
    }
    int isFull(){
        if(length==QUEUE_MAX_SIZE) return TRUE_VALUE;
        else return FALSE_VALUE;
    }
};
void Prb6(){
    Stack st;
    Queue q;
    int N;
    printf("Enter Integer Number: ");
    scanf("%d",&N);
    int num;
    printf("Queue Before: \n");
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        q.enqueue(num);
    }
    while(!q.isEmpty()){
        st.push(q.dequeue());
    }
    while(!st.isEmpty()){
        q.enqueue(st.pop());
    }
    printf("Queue After: ");
    while(!q.isEmpty()){
        printf("\n%d",q.dequeue());
    }
}
void Prb7(){
    Queue q,temp;
    Stack st;
    int n,k,num;
    printf("Enter size of the Queue: ");
    scanf("%d",&n);;
    printf("Enter elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&num);;
        temp.enqueue(num);
    }
    printf("Enter integer k: ");
    scanf("%d",&k);;
    for(int i=0;i<k;i++){
        st.push(temp.dequeue());
    }
    while(!st.isEmpty()){
        q.enqueue(st.pop());
    }
    while(!temp .isEmpty()){
        q.enqueue(temp.dequeue());
    }
    while(!q.isEmpty()){
        printf("%d",q.dequeue());
    }
}
int main(){
    int num;
    printf("Enter Problem no: ");
    scanf("%d",&num);
    if(num==1){
        Prb1();
    }
    else if(num==2){
        Prb2();
    }
    else if(num==3){
        Prb3();
    }
    else if(num==4){
        Prb4();
    }
    else if (num==5){
        StackQueue sq;
        int chn;
        while(1){
            printf("1.Enqueue  2.Dequeue  3.Check Empty  4.Check Full  5.Get Length  6.Exit\n");
            scanf("%d",&chn);
            if(chn==1){
              int num;
              scanf("%d",&num);
              sq.enqueue(num);
            }
            else if(chn==2){
                printf("%d\n",sq.dequeue());
            }
            else if(chn==3){
                if(sq.isEmpty()){
                    printf("Queue is Empty.\n");
                }
                else{
                    printf("Queue is not Empty.\n");
                }
            }
            else if(chn==4){
                if(sq.isFull()){
                    printf("Queue is Full.\n");
                }
                else{
                    printf("Queue is not Full.\n");
                }
            }
            else if(chn==5)
            printf("Length of Queue: %d\n",sq.getLength());
            else if(chn==6)
            break;
            else
            printf("Invalid command");
        }
    }
    else if(num==6){
        Prb6();
    }
    else if(num==7){
        Prb7();
    }
    else{
        printf("Invalid Problem!\n");
    }
    return 0;
}
