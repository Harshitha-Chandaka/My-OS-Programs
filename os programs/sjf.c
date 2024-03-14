#include <stdio.h>
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
  int i,n,ch=1;
  int pid[max];
  float bt[max],at[max],ct[max],wt[max],tat[max],pt[max],temp1[max];
  float a_wt=0,a_tat=0;
  printf("enter the no. processes:");
  scanf("%d",&n);
  while(ch)
  {
    if(n!= n)
    {
        printf("Error: Invalid input. Please enter an integer.\n");
    }
    else
    {
       ch = 0;
    }
  }
  printf("enter the processes id:");
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
  printf("enter the Arrival time:");
  for (i=0;i<n;i++)
  {
    scanf("%f",&at[i]);
    valid(at,i);
  }
  printf("enter the burst time:");
  for (i=0;i<n;i++)
  {
   scanf("%f",&bt[i]);
   valid(bt,i);
  }
  float c=0,time=0,temp[max];
  for (i=0;i<n;i++)
  {
    temp[i]=999.0;
  }
  printf("\nGant Chat of the processes:\n");
  while(c!=n)
  {
      for (i=0;i<n;i++)
      {
        if(at[i]<=time)
        {
          temp[i]=bt[i];
        }
      }
      int min=0;
      for(i=0;i<n;i++)
      {
        if(temp[ min]>temp[i])
        {
          min=i;
        }
      }
      if(temp[ min]!=999)
      {
        temp[min]=999;
        time=time+bt[min];
        ct[min]=time;
        tat[min]=time-at[ min];
        wt[min]=tat[ min]-bt[ min];
        pt[min]=at[ min];
        at[min]=999;
        c=c+1;
        printf(" P%d ||",pid[min]);
      }
      else
      {
        time=time+1;
      }
  }
  printf("\n p_id\t a_t\t b_t\t c_t\t t_at\t w_t \n");
  for(i=0;i<n;i++)
  {
    printf("\n%d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t\n", pid[i],pt[i],bt[i],ct[i],tat[i],wt[i]);
    a_wt=a_wt+wt[i];
    a_tat=a_tat+tat[i];
  }
   printf("Average time of waiting:%.2f", a_wt/n);
  printf("\nAverage time of Turn Around time:%.2f",a_tat/n);
}

