#include<stdio.h>
int GCD(int x, int y){

if (x==0)return y;
if (y==0)return x;
else
    return GCD(y,x%y);
}
int main(){
int a,b;
printf("Enter X and Y: ");
scanf("%d%d",&a,&b);
printf("GCD: %d",GCD(a,b));
}
