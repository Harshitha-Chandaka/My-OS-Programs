#include <stdio.h>

int main()
{
  int i,j,count[10],loc[10],b,block[30],p,process[30],min,l,diff,avail[10];
  printf("Enter the no. of blocks:\n");
  scanf("%d", &b);
  while (b<=0)
  {
    printf("Invalid input! Enter a positive integer for the no. of blocks:\n");
    scanf("%d", &b);
  }
  printf("Enter the block sizes:\n");
  for(i=0;i<b;i++)
  {
    scanf("%d",&block[i]);
    while (block[i]<0)
    {
      printf("Invalid input! Enter a non-negative integer for block %d size:\n", i + 1);
      scanf("%d", &block[i]);
    }
  }
  printf("Enter the no. of process:\n");
  scanf("%d",&p);
  while (p<=0)
  {
    printf("Invalid input! Enter a positive integer for the no. of processes:\n");
    scanf("%d", &p);
  }
  printf("Enter the process size\n");
  for (i=0;i<p;i++)
  {
    scanf("%d", &process[i]);
    while (process[i]<0)
    {
      printf("Invalid input! Enter a non-negative integer for process %d size:\n", i + 1);
      scanf("%d", &process[i]);
    }
  }
  for (i=0;i<b;i++)
  {
    avail[i]=0;
  }
   printf("P_id\t P_size\t Block_size\t Rmg_Blk_size\n");
  for (i=0;i<p;i++)
  {
    min=999999;
    l=-1;
    diff=0;
    for (j=0;j<b;j++)
    {
      if(process[i]<=block[j] &&avail[j]==0)
      {
         diff=block[j] - process[i];
         if(diff<min)
         {
            min=diff;
            l=j;
          }
      }
    }
    if(l!=-1)
    {
       printf("%d\t %d\t %d\t\t %d\t\n", i+1,process[i],block[l],diff);
       avail[l]=1;
    }
    else
    {
      printf("%d\t %d\t NA\t\t NA\t\n", i+1,process[i]);
    }
  }
}

  
