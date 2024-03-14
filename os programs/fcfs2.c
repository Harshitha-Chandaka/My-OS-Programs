#include<stdio.h>
#define max 32

void valid(float temp[],int index)
{
    if (temp != temp || temp<0)
    {
        printf("Error: Invalid input. Please enter an integer.\n");
    }
}

int main()
{
    int i,n,ch = 1;
    float bt[max],at[max],tat[max],wt[max],ct[max];
    int pid[max];
    float awt=0, atat=0;
    while(ch)
    {
      printf("enter the no. of processes:");
      scanf("%d",&n);
      if(n!=(int)n)
      {
          printf("Error: Invalid input. Please enter an integer.\n");
      }
      else
      {
        ch = 0;
      }
    }
    printf("enter the process id:");
    for (i=0;i<n;i++)
    {
        int result = scanf("%d", &pid[i]);
        if (result != 1) 
        {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
            i--; 
        }
    }
    printf("enter the Araival Time:");
    for (i=1;i<=n;i++)
    {
        scanf("%f",&at[i]);
        valid(at,i);
    }
    printf("enter the Burst Time:");
    for(i=1;i<=n;i++)
    {
        scanf("%f",&bt[i] );
        valid(bt,i);
    }
    float temp=at[1];
    printf("P_id\t B_t\t A_t\t C_t\t W_t\t TA_t\n");
    for (i=1;i<=n;i++)
    {
       temp=bt[i]+temp;
       ct[i]=temp;
       tat[i]=ct[i]-at[i];
       wt[i]=tat[i]-bt[i];
       printf("%d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\n", pid[i],bt[i],at[i],ct[i],wt[i],tat[i]);
       atat=atat+tat[i];
       awt=awt+wt[i];
    }
    printf("\nAverage of waiting time:%.2f\n",awt/n);
    printf("\nAverage of waiting time:%.2f",atat/n);
}
