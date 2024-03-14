#include<stdio.h>
#define max 32

int findOptimal(int page[], int n, int frm[], int pf, int index) 
{
    int pos=-1,count= index;
    for(int i=0;i<pf;i++) 
    {
        int j;
        for(j=index+1;j<n;j++) 
        {
            if(frm[i]==page[j]) 
            {
                if(j>count) 
                {
                  count=j;
                  pos=i;
                }
                break;
            }
        }
        if(j==n) 
        {
            return i;
        }
    }
    if(pos!=-1)
    {
      return pos;
    }
    else
    {
      return 0;
    }
}
      


int main()
{
  int i,j,fal=0,pos=0,hit=0,frm[max],page[max],n,pf,next=1,count=0;
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
    
   int time[10];
   for (i=0;i<n;i++)
   {
      int flag1=0,flag2=0;
      for(j=0;j<pf;j++)
      {
        if(frm[j]==page[i])
        {
          count++;
          time[j]=count;
          flag1=1;
          flag2=1;
          printf("Hit\t");
          hit=hit+1;
          break;
        }
        else
        {
          flag1=0;
          flag2=0;
        }
      }
      if(flag1==0)
      {
        for(j=0;j<pf;j++)
        {
          if(frm[j]==-1)
          {
            count++;
            fal++;
            frm[j]=page[i];
            time[j]=count;
            flag2=1;
            printf("Faults\t");
            break;
          }
        }
      }
      if (flag2==0)
      {
        pos=findOptimal(page,n,frm,pf,i) ;
        count++;
        fal++;
        frm[pos]=page[i];
        time[pos]=count;
        printf("Faults\t");
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
