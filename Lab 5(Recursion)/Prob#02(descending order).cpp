#include<stdio.h>
int Ascending(int n){
if(n==1){

    printf(" %d ",n);
    return n;

}

else{
    printf(" %d ",n);
    return Ascending(n-1);
}

}

int main(){
int n;
printf("Give n number: ");
scanf("%d",&n);
Ascending(n);
return 0;
}
