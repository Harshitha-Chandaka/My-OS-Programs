#include<stdio.h>
#define max 100

int lru(int temp[],int n)
{
    int i,pos=0,min=temp[0];
    for (i=1;i<n;i++)
    {
        if(temp[i]<min)
    {
        min=temp[i];
        pos=i;
    }
    return pos;
}

    
}

int main()
{
    int i,j,n,pf,page[max],frm[max],fal=0,hit=0;
    
    printf("enter the number of pages strings:\n");
    scanf("%d",&n);
    printf("enter the page strings:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&page[i]);
    }
    
    printf("Enter the number of page frames:\n");
    scanf("%d",&pf);
    for (i=0;i<pf;i++)
    {
        frm[i]=-1;
    }

    int time[max],count=0;
    int c_h=0,c_f=0; //count hit and fault for the desired page string
    for (i=0;i<n;i++)
    {
        int flag1=0;
        int flag2=0;
        for (j=0;j<pf;j++)
        {
            if(frm[j]==page[i])
            {
                printf("Hit    --> \t");
                hit++;
                count++;
                time[j]=count;
                flag1=1;
                flag2=1;
                if(page[i]==156);
                {
                    c_h++;
                }
                break;
            }
        }
        if(flag1==0)
        {
            for (j=0;j<pf;j++)
            {
                if(frm[j]==-1)
                {
                    frm[j]=page[i];
                    printf("Fault --> \t");
                    fal++;
                    count++;
                    time[j]=count;
                    flag2=1;
                    if(page[i]==156)
                    {
                        c_f++;
                    }
                    break;
                }
              }
          }
          int pos;
          if(flag2==0)
          {
             pos=lru(time,pf);
             frm[pos]=page[i];
             printf("Fault  --> \t");
             fal++;
             count++;
             time[pos]=count;
             if(page[i]==156)
             {
                c_f++;
             }
          }
          for( j=0;j<pf;j++)
          {
            printf("%d\t",frm[j]);
           }
           printf("\n");
    }
    printf("\n Total number of faults occurred: %d", fal);
    printf("\n Total number of hits occurred: %d", hit);
    printf("\n Total number of faults occurred in 156 page string: %d", c_f);
    printf("\n Total number of faults occurred in 156 page string: %d", c_h);
}








