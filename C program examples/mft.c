#include<stdio.h>
main()
 {
   int T_mem_size, B_size, no_ofblocks, ext_frag,n, mp[10],int_frag=0;
   int i,p=0;
   printf("Enter the total memory available:");
   scanf("%d",&T_mem_size);
   printf("Enter the block size:"); 
   scanf("%d", &B_size); 
   no_ofblocks=T_mem_size/B_size; 
   ext_frag=T_mem_size - no_ofblocks*B_size; 
   printf("\nEnter the number of processes:"); 
   scanf("%d",&n); 
   for(i=0;i<n;i++)
    { 
      printf("Enter memory required for process %d:",i+1); 
      scanf("%d",&mp[i]); 
    } 
   printf("\nNo. of Blocks available in memory  %d:",no_ofblocks); 
   printf("\n\nPROCESS\tMEMORY REQUIRED\t ALLOCATED\tINTERNAL FRAGMENTATION");
   for(i=0;i<n && p<no_ofblocks;i++) 
    {
      printf("\n %d\t\t%d",i+1,mp[i]);
      if(mp[i] > B_size) 
         printf("\t\tNO\t\t");
      else
       { 
         printf("\t\tYES\t%d",B_size-mp[i]); 
         int_frag = int_frag + B_size-mp[i]; p++;
       } 
    } 
   if(i<n) 
     printf("\nMemory is Full, Remaining Processes cannot be accomodated"); 
     printf("\n\nTotal Internal Fragmentation is %d",int_frag);
     printf("\nTotal External Fragmentation is %d",ext_frag); 
 }