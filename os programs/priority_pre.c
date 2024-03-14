#include <stdio.h>
#define max 32

void valid(float temp)
{
    if (temp != (int)temp)
    {
        printf("Error: Invalid input. Please enter an integer.\n");
    }
}

int main() 
{
    int i, n;
    float bt[max], at[max], ct[max], wt[max], tat[max], temp[max];
    float a_wt = 0, a_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("entert e process id:");
    for (i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
        valid(pid[i]);
    }    
    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%f", &at[i]);
        valid(at[i]);
    }
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f",&bt[i] );
        valid(bt[i]);
        temp[i]=bt[i];
    }
  }
