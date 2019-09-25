#include<stdio.h>
#define m 5
void add(int val);
int del();
void bfs(int);
int vis[m];
int g[][m]={{0,1,1,0,0},{1,0,1,1,1},{1,1,0,1,0},{0,1,1,0,0},{0,1,0,0,0}};
int q[4],f,r;
main()
{
int i;
f=r=-1;
for(i=0;i<m;i++)
vis[i]=0;
bfs(0);
}
void bfs(int i)
{
int j;
vis[i]=1;
add(i);
while(f!=r)
{
i=del();
printf("%3c",i+65);
for(j=0;j<m;j++)
if((vis[j]==0&&g[i][j]==1))
{
add(j);
vis[j]=1;
}
}
}
void add(int val)
{
if(r==m-1)
 printf("\n queue");
 else
 q[++r]=val;
}
int del()
{
if(r==f)
{
printf("queue");
return -1;
}
return q[++f];
}


