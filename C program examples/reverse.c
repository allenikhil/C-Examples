#include<stdio.h>
main(){
int r,n;
printf("enter number");
scanf("%d",&n);
while(n>0)
{
r=n%10;
n=n/10;
printf("%d",r);
}
}
