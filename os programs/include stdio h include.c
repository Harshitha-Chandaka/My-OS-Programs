#include<stdio.h>
#include<stdlib.h>
#define max 50


int main()
{
  int i,n,rq[max],tm=0,init,seq[max],k,index,size,move;
  printf("enter the no. of value in request queue:\n");
  scanf("%d", &n);
  printf("Enter the Request queue:\n");
  for (i=0;i<n;i++)
  {
    scanf("%d",&rq[i]);
  }
  printf("Enter the disk size:");
  scanf("%d",&size);
  printf("Enter the initial point of r/w head:\n");
  scanf("%d",&init);
  printf("Enter the movement of the track [ left=0 and right= ]:");
  scanf("%d",&move);
  
  //sorting request queue
  for (i=0;i<n-1;i++)
  {
    for (int j=i+1;j<n;j++)
    {
      if(rq[i]>rq[j])
      {
        int temp=rq[i];
        rq[i]=rq[j];
        rq[j]=temp;
      }
    }
  }
  
  for(i=0;i<n;i++)
  {
    if(init<rq[i])
    {
      index=i;
      break;
    }
  }
  
  if(move==1)
  {
    for (i=index;i<n;i++)
    {
      tm=tm+abs(rq[i]-init);
      init=rq[i];
      seq[k]=rq[i];
      k++;
    }
    tm=tm+abs((size-1)-init);
    init=size-1;
    seq[k]=init;
    k++;
    for(i=index-1;i>=0;i--)
    {
      tm=tm+abs(rq[i]-init);
      init=rq[i];
      seq[k]=init;
      k++;
    }
  }
  else
  {
    for(i=index-1;i>=0;i--)
    {
      tm=tm+abs(rq[i]-init);
      init=rq[i];
      seq[k]=rq[i];
      k++;
    }
    tm=tm+abs(rq[i+1]-0);
    init=0;
    seq[k]=0;
    k++;
    for (i=index;i<n;i++)
    {
      tm=tm+abs(rq[i]-init);
      init=rq[i];
      seq[k]=rq[i];
      k++;
    }

  }
  printf("Sequence of request queue:\n");
  for(i=0;i<n+1;i++)
  {
    printf("%d\n",seq[i]);
  }
  printf("Total movement:\t%d\n", tm);
}
    
  
