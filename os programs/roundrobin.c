#include <stdio.h>
#define max 32

void valid(float temp[], int index)
{
    if (temp != temp || temp<0)
    {
        printf("Error: Invalid input. Please enter an integer.\n");
    }
}

int main() 
{
    int i, n,ch=1,tq;
    int pid[max];
    float bt[max], at[max], ct[max], wt[max], tat[max];
    float a_wt = 0, a_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    while(ch)
    {
      if(n!=(int)n)
      {
          printf("Error: Invalid input. Please enter an integer.\n");
      }
      else
      {
         ch = 0;
      }
   }
    printf("enter the processes:");
    for(i=0;i<n;i++)
    {
      int result = scanf("%d", &pid[i]);
      if (result != 1) 
      {
         printf("Invalid input. Please enter an integer.\n");
         while (getchar() != '\n');
         i--; 
      }
    }
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &bt[i]);
        valid(bt,i);
    }
    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &at[i]);
        valid(at,i);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
      while(ch)
    {
      if(tq!=(int)tq)
      {
          printf("Error: Invalid input. Please enter an integer.\n");
      }
      else
      {
         ch = 0;
      }
   }

    printf("GANT CHART:");
    float c = 0, time = 0, rt[max];
    for (i = 0; i < n; i++) 
    {
        rt[i] = bt[i];
    }

    while (c != n) {
        for (i = 0; i < n; i++)
        {
            if (at[i]<=time && rt[i]>0) 
            {
                if (rt[i]<=tq) 
                {
                    time=time+rt[i];
                    ct[i]=time;
                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];
                    c++;
                    rt[i] = 0;
                    printf("P%d ",i+1);
                }
                else 
                {
                  time=time+tq;
                  rt[i]=rt[i]-tq;
                }
            }
        }
    }
    printf("\n p_id\t a_t\t b_t\t c_t\t t_at\t w_t \n");
    for (i = 0; i < n; i++) 
    {
        printf("\n %d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        a_wt += wt[i];
        a_tat += tat[i];
    }

    printf("\nAverage waiting time: %.2f\n", a_wt/n);
    printf("Average turnaround time: %.2f\n", a_tat/n);

    return 0;
}

