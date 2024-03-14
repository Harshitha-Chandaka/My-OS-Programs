v#include <stdio.h>
#define max 32

void valid(float temp)
{
    if (temp != (int)temp)
    {
        printf("Error: Invalid input. Please enter an integer.\n");
        exit(1);
    }
}

int main()
{
    int i, n;
    float pid[max], bt[max], at[max], ct[max], wt[max], tat[max], pt[max],temp[max];
    float a_wt = 0, a_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    valid(n);

    printf("Enter the process IDs:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &pid[i]);
        valid(pid[i]);
    }

    printf("Enter the Arrival times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &at[i]);
        valid(at[i]);
    }

    printf("Enter the Burst times:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &bt[i]);
        valid(bt[i]);
        temp[i]=bt[i];
    }

    printf("Enter the Priorities:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &pt[i]);
        valid(pt[i]);
    }

    printf("\n p_id\t a_t\t b_t\t c_t\t t_at\t w_t \n");
    float c = 0, time = 0,min;
    float hp = -1;

    while (c != n)
    {
        min = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && temp[i] > 0)
            {
                if (min == -1 || pt[i] < pt[(int)hp])
                {
                    min = i;
                    hp = i;
                }
            }
        }

        temp[(int)hp]--;

        if (temp[(int)hp] == 0)
        {
            c++;
            time++;
            ct[(int)hp] = time;
            tat[(int)hp] = ct[(int)hp] - at[(int)hp];
            wt[(int)hp] = tat[(int)hp] - bt[(int)hp];
            hp = -1;
        }
        else
        {
            time++;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("\n%.2f\t %.2f\t %.2f\t %.2f\t %.2f\t %.2f\t\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        a_wt += wt[i];
        a_tat += tat[i];
    }

    printf("Average time of waiting: %.2f", a_wt / n);
    printf("\nAverage time of Turn Around time: %.2f", a_tat / n);

    return 0;
}

