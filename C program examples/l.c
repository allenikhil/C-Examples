#include<stdio.h>
int main()
{
 int file[100],i,fileno=1,length,block,ch,filename,start;
 
 for(i=0;i<=100;i++)
 {
 file[i]=0;
 }
 
do
{

printf("\t\tMENU\n");
printf("\t1.allocate\n");
printf("\t2.display\n");
printf("\t3.exit\n");
printf("\t enter the choice\n");
scanf("%d",&ch);
switch (ch){

case 1 : here:printf("enter the start block\n");
         scanf("%d",&start);
	   
       if(file[start]==0)
	   {
	   printf("enter the no of blocks\n");
	   scanf("%d",&length);
	   file[start]=fileno;
	   length--;
	   if(length>=1)
	   {
	   do
	   {
	   printf("enter the block\n");
	   scanf("%d",&block);
	   if(file[block]==0)
	   {
	   file[block]=fileno;
	   length--;
	   }
	   else
	   {
	   printf("block is not empty choose another block\n");
	   }
	   }while(length!=0);
	   }
	   fileno++;
	   
       }
	   else
	   {
		   printf("block is not empty choose another block");
		   goto here;
	   }
	    break;
case 2:printf("enter the file name");
       scanf("%d",&filename);
	   if(filename<=fileno)
	   {
	   for(i=0;i<=100;i++)
	   {
	   if(file[i]==filename)
	   {
	   printf("->%d",i);
	   }
	   }
	   }
	   else
	   {
	   printf("file does not exist");
	   }
	   break;

case 3:break;

default:printf("invalid option");
        break;
}
}while(ch!=3);
return 0;
}