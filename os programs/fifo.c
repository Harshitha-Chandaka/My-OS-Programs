#include<stdio.h>
#define max 32


int main()
{
  int i,j,fal=0,pos=0,hit=0,frm[max],page[max],n,pf;
  printf("enter the no. page strings:\n");
  scanf("%d",&n);
  if(n<0 || n>max || n==(int)n)
  {
    printf("invalid input. Please enter an integer only.");
    return 0;
  }
  printf("enter the number of page frames:\n");
  scanf("%d",&pf);
  if(pf<0 || pf>max || pf==(int)pf)
  {
    printf("invalid input. Please enter an integer only.");
    return 0; 
  }
  printf("enter the page strings:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&page[i]);
    if(page[i]<0 || page[i]>max || page[i]== (int)page[i])
    {
      printf("invalid input. Please enter an integer only.");
      return 0;
    }
  }
  for (i=0;i<pf;i++)
  {
    frm[i]=-1;
  }
  
  int flag=0;
  for (i=0;i<n;i++)
  {
    for(j=0;j<pf;j++)
    {
      if(frm[j]==page[i])
      {
        flag=1;
        printf("Hit\t");
        hit=hit+1;
        break;
      }
      else
      {
        flag=0;
      }
    }
    if(flag==0)
    {
      frm[pos]=page[i]; // "pos" indicating the index of the page frame
      pos=pos+1;
      printf("Fault\t");
      fal=fal+1;
      if(pos>=pf)
      {
        pos=0;
      }
    }
    for(j=0;j<pf;j++)
    {
      printf("%d\t", frm[j]);
    }
    printf("\n");
  }
  printf("\n Number of faults occur in the page replacement:%d/%d",fal,n);
  printf("\n Number of hits occur in the page replacements:%d/%d",hit,n);
}
  
        
