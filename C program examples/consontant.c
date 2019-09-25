#include<stdio.h>
#include<string.h>
main()
{
char w[100];
int j,x;
printf("\n enter a word");
scanf("%d",&w);
x=strlen(w);
int n=0;
for( j=0;j<x;j++)
{
    if(w[j]=='a'||w[j]=='e'|| w[j]=='i'|| w[j]=='o'|| w[j]=='u')
    {
        n++;
    }
}
if(n==0)
{
    printf("\n con");
}
else{
    printf("\n v");
}
}
