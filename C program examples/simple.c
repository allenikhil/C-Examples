#include<stdio.h>
 int main(void)
{
 int a=1,b=2;
 static int c=a*b;
 printf("%d",c);
 return 0;
}
