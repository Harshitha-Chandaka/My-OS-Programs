#include<stdio.h>
#include<stdlib.h>
#define max 50

int main()
{
  int i,n,rq[max],tm=0,init;
  
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
  printf("Enter the initial point of r/w head:\n");
  scanf("%d",&init);
  if (init < 0) 
  {
    printf("Invalid input. Initial point should be non-negative.\n");
    return 1;  
  }
  printf("Sequence:");
  for (i=0;i<n;i++)
  {
    tm=tm+abs(rq[i]-init);
    init=rq[i];
    printf("%d\n", rq[i]);
  }
  
  printf("Total movement:%d",tm);
}

