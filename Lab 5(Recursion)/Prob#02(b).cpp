#include<stdio.h>
int Descending(int n){
if(n==1){

    printf(" %d ",n);
    return n;

}

else{

    Descending(n-1);
    printf(" %d ", n);
    //printf(" %d ",Descending(n-1));
    //return 0;

}
return 0;



}

int main(){
int n;
printf("Give n number: ");
scanf("%d",&n);
Descending(n);
return 0;
}

