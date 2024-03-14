#include<stdio.h>
#include<stdlib.h>
#define max 100
int main()
{
   int i,n,rq[max],tm=0,init,seq[max],k=0,index,size,move;
  printf("enter the no. of value in request queue:\n");
  scanf("%d", &n);
  if (n <= 0 || n > max)
  {
      printf("Invalid input. Number of values should be between 1 and %d.\n", max);
      return 1; 
  }
  printf("Enter the Request queue:\n");
  for (i=0;i<n;i++)
  {
    scanf("%d",&rq[i]);
     if (rq[i] < 0)
    {
        printf("Invalid input. Values should be non-negative.\n");
        return 1;  
    }
  }
  printf("Enter the disk size:");
  scanf("%d",&size);
  if (size < 0) 
  {
    printf("Invalid input. size should be non-negative.\n");
    return 1;  
  }
  printf("Enter the init point of r/w head:\n");
  scanf("%d",&init);
  if (init < 0) 
  {
    printf("Invalid input. Initial point should be non-negative.\n");
    return 1;  
  }
  printf("Enter the movement of the track [ left=0 and right= ]:");
  scanf("%d",&move);
  if (move!=0 && move!=1)
  { 
     printf("Invalid input. Values should be only 0 or 1.\n");
     return 1;  
  }
    
  
  for(i=0;i<n;i++)
  {
      for( int j=0;j<n-i-1;j++)
      {
         if(rq[j]>rq[j+1])
         {
              int temp;
              temp=rq[j];
              rq[j]=rq[j+1];
              rq[j+1]=temp;
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
      for(i=index;i<n;i++)
      {
          tm=tm+abs(rq[i]-init);
          init=rq[i];
          seq[k]=init;
          k++;
      }
      tm=tm+abs(size-rq[i-1]-1);
      seq[k]=size-1;
      k++;
      tm=tm+abs(size-1-0);
      init=0;
      seq[k]=init;
      k++;
      for( i=0;i<index;i++)
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
          seq[k]=init;
          k++;
      }
      tm=tm+abs(rq[i+1]-0);
      seq[k]=0;
      k++;
      tm=tm+abs(size-1-0);
      init =size-1;
      seq[k]=init;
      k++;
      for(i=n-1;i>=index;i--)
      {
          tm=tm+abs(rq[i]-init);
          init=rq[i];
          seq[k]=init;
          k++;
      }
  }
  for(i=0;i<=n+1;i++)
  {
      printf("%d\n",seq[i]);
  }
  printf("Total head movement is %d",tm);
  return 0;
  }
