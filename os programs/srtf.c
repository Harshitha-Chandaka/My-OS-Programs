#include <stdio.h>
#define max 32

void valid(float temp[], int index)
{
    int temp1=1;
    if (temp != temp1 || temp[index]<0)
    {
        printf("Error: Invalid input. Please enter an integer.\n");
      
    }
}

int main()
{
  int i,n;
  int pid[max],ch=1;
  float bt[max],at[max],ct[max],wt[max],tat[max],pt[max];
  float a_wt=0,a_tat=0;
  printf("enter the no. processes:");
  scanf("%d",&n);
  while(ch)
  {
    if(n!=(int)n)
    {
        printf("Error: Invalid input. Please enter an integer.\n");
        break;
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
    break;
  }
  printf("enter the burst time:");
  for (i=0;i<n;i++)
  {
   scanf("%f",&bt[i] );
   valid(bt,i);
   break;
  }
  printf("GANT CHART:");
  float c=0,time=0,temp[max];
  int min;
  for (i=0;i<n;i++)
  {
    temp[i]=bt[i];
  }
  while(c!=n)
  {
      min=-1;
      for (i=0;i<n;i++)
      {
        if(at[i]<=time && temp[i]>0)
        {
          if(min==-1|| temp[i]<temp[min])
          {
              min=i;
          }
        }
      }
      temp[min]--;
      if(temp[min]==0)
      {
        c++;
        time++;
        ct[min]=time;
        tat[min]=ct[min]-at[min];
        wt[min]=tat[min]-bt[min];
        printf(" P%d ||",pid[min]);
      }
      else
      {
        time++;
      }
    }
  
  printf("\n p_id\t a_t\t b_t\t c_t\t t_at\t w_t \n");
  for(i=0;i<n;i++)
  {
    printf("\n%d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t\n", pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    a_wt=a_wt+wt[i];
    a_tat=a_tat+tat[i];
  }
  printf("Average time of waiting:%.2f", a_wt/n);
  printf("\nAverage time of Turn Around time:%.2f",a_tat/n);
}
