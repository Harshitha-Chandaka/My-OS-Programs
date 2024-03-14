#includve<stdio.h>
#include<stdlib.h>
#define max 100
int main()
{
   int i,n,rq[max],tm=0,init,seq[max],k=0,index,size,move;
  printf("enter the no. of value in request queue:\n");
  scanf("%d", &n);
  if (n<=0 || n>max)
  {
      printf("Invalid input. Number of values should be between 1 and %d.\n", max);
      return 1; 
  }
  printf("Enter the Request queue:\n");
  for (i=0;i<n;i++)
  {
    scanf("%d",&rq[i]);
     if (rq[i]<0)
    {
        printf("Invalid input. Values should be non-negative.\n");
        return 1;  
    }
  }
  printf("Enter the disk size:");
  scanf("%d",&size);
  if (size<0) 
  {
    printf("Invalid input. size should be non-negative.\n");
    return 1;  
  }
  printf("Enter the init point of r/w head:\n");
  scanf("%d",&init);
  if (init<0) 
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
    
	
	for (i=0;i<n-1;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if(rq[i]>rq[j])
			{
				temp=rq[i];
				rq[i]=rq[j];
				rq[j]=temp;
			}
		}
	}
	
	for (i=0;i<n;i++)
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
			seq[k]=rq[i];
			k++;
		}
		for(i=index-1;i>=0;i--)
		{
			tm=tm+abs(rq[i]-init);
			init=rq[i];
			seq[k]=rq[i]; 
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
		for(i=index;i<n;i++)
		{
			tm=tm+abs(rq[i]-init);
			init=rq[i];
			seq[k]=rq[i];
			k++;
		}
	}
	printf(" Sequence of track:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",seq[i]);
	}
	printf("Total Head Movement: %d\n",tm);
	return 0;
}	
		
		
	 
