#include <stdio.h>
#include <stdlib.h>
#define max 100

int mini(int queue[], int n, int head) {
    int min=999999;
    int index=-1;
    for (int i=0;i<n;i++) 
    {
        int diff=abs(queue[i]-head);
        if (diff<min) 
        {
            min=diff;
            index=i;
        }
    }
    return index;
}

int main()
{
    int rq[max],init,tm=0,diff=0,curr_init=0,min_index=0,seq[max];
    int n;
    printf("Enter the number of values in Request Queue:\n");
    scanf("%d",&n);
    if (n <= 0 || n > max)
    {
      printf("Invalid input. Number of values should be between 1 and %d.\n", max);
      return 1; 
    }
    printf("Enter the values of Request Queue:\n");
    for (int i=0;i<n;i++) 
    {
        scanf("%d",&rq[i]);
        if (rq[i] < 0)
        {
            printf("Invalid input. Values should be non-negative.\n");
            return 1;  
        }
    }
    printf("Enter the initial point: ");
    scanf("%d", &init);
    if (init < 0) 
    {
       printf("Invalid input. Initial point should be non-negative.\n");
       return 1;  
    }
    
    for (int i=0;i<n;i++) 
    {
        min_index=mini(rq,n,init);
        curr_init=rq[min_index];
        diff=abs(rq[min_index]-init);
        tm=tm+diff;
        init=curr_init;
        seq[i]=rq[min_index];
        // Removing the element at min_index
        for (int j=min_index;j<n-1;j++)
        {
            rq[j]=rq[j+1];
        }
    }

    printf("The SSTF Disk Scheduling sequence is:\n");
    for (int i=0;i<n;i++) 
    {
        printf("%d\n",seq[i]);
    }

    printf("Total Movement: %d\n", tm);

    return 0;
}

