#include <stdio.h>
#define max 32

void valid(float temp[], int index)
{
    if (temp !=temp || temp[index]<0)
    {
        printf("Error: Invalid input. Please enter an integer.\n");
    }
}

int main()
{
  int i,n;
  float at[max],bt[max],pt[max],ct[max],tat[max],wt[max],temp[max],pt_temp[max];
  int pid[max],ch=1;
  float awt=0.0,atat=0.0;
  printf("enter the no. of process:");
  scanf("%d",&n);
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
  printf("enter the processes id:");
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
  printf("\n enter the arrival time:");
  for (i=0;i<n;i++)
  {
    scanf("%f",&at[i]);
    valid(at,i);
  }
  printf("\n enter the burst time:");
  int count=0;
  for (i=0;i<n;i++)
  {
    scanf("%f",&bt[i]);
    valid(bt,i);
  }
  printf("\nenter the priority:");
  for (i=0;i<n;i++)
  {
    scanf("%f",&pt[i]);
    valid(pt,i);
  }
  printf("GANT CHART:");
  float time=0.0,c=0.0;
  for(i=0;i<n;i++)
  {
    temp[i]=0.0;
  }
  
  while(c!=n)
  {
    int hp=-1;
    float min=999.0;
    for (i=0;i<n;i++)
    {
      if(at[i]<=time && temp[i]==0.0 && pt[i]<min)
      {
        min=pt[i];
        hp=i;
      }
    }
    if(temp[(int)hp]!=-1.0)
    {
      time=time+bt[hp];
      ct[hp]=time;
      tat[hp]=ct[hp]-at[hp];
      wt[hp]=tat[hp]-bt[hp];
      temp[hp]=-1.0;
      c=c+1.0;
      printf("P%d ", pid[hp]);
    }
    else
    {
      time+time+1.0;
    }
  }
  
  printf("\n p_id\t a_t\t b_t\t p_t\t c_t\t t_at\t w_t");
  for (i=0.0;i<n;i++)
  {
    printf("\n %d\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\n", pid[i],at[i],bt[i],pt[i],ct[i],tat[i],wt[i]);
    awt=awt+wt[i];
    atat=atat+tat[i];
  }
  printf("average time of waiting time:%.2f",awt/n);
  printf("\n average time of turn around time:%.2f",atat/n);
}
