#include<stdio.h>
#define max 32

int main()
{
    int i,n,bt[max],at[max],tat[max],wt[max],ct[max];
    float awt=0, atat=0;
    printf("enter the no. of processes:");
    scanf("%d",&n);
    printf("enter the Burst Time:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&bt[i]);
    }
    printf("enter the Arraival Time:");
    for (i=1;i<=n;i++)
    {
        scanf("%d",&at[i]);
    }
    int temp=0;
    printf("Completion time:");
    for (i=1;i<=n;i++)
    {
       temp=bt[i]+temp;
       ct[i]=temp;
       printf("%d ",ct[i]);
    }
    printf("\nTurn around time:");
    for (i=1;i<=n;i++)
    {
        int temp1=ct[i]-at[i];
        tat[i]=temp1;
        printf("%d ", tat[i]);
    }
    printf("\nWaiting time:");
    for (i=1;i<=n;i++)
    {
        wt[i]=tat[i]-bt[i];
        printf("%d ", wt[i]);
    }
   
    for (i=1;i<=n;i++)
    {
      awt=awt+wt[i];
    }
    printf("\nAverage of waiting time:%f\n",awt);
    for (i=1;i<=n;i++)
    {
      atat=atat+tat[i];
    }
    printf("\nAverage of waiting time:%f",atat);
}
