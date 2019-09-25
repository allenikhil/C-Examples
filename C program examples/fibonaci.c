#include<stdio.h>
main()
{
int i=1,f1=0,f2=1,f3=0,n;
printf("\n enter range");
scanf("%d",&n);
printf("\n the fibonacci series start with %d\t%d",f1,f2);
while(i<n)
{
f3=f1+f2;
f1=f2;
f2=f3;
i++;
printf("\t %d",f3);
}
}