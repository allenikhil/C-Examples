#include<stdio.h>
void main()
{
int a=1,b=1,c=a||--b;
int d=a-- && --b;
printf("%d\t%d\t%d\t%d",a,b,c,d);
}
