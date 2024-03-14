#include <stdio.h>

int main()
{
  int i,j,count[10],loc[10],b=6,p=5,min,l,diff,avail[10];
  int block[]= {300,600,350,200,750,125};
  int process[]={115,500,358,200,375};
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

  
