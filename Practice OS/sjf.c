#include<stdio.h>
#include<conio.h>
#define max 30
void main(){
    int i, j, n, t, p[max], bt[max], wt[max], tat[max];
    float awt=0, atat=0;
    printf("Enter the number of process:");
    scanf("%d", &n);

    printf("Enter the process number\n");
    for(i=0; i<n; i++){
        scanf("%d", &p[i]);
    }

    printf("Enter burst time for process\n");
    for(i=0; i<n; i++){
        scanf("%d", &bt[i]);
    }

    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(bt[j]>bt[j+1]){
                t = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = t;

                t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }

    printf("Process\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0; i<n; i++){
        wt[i] = 0;
        tat[i] = 0;
        for(j=0; j<i; j++){
            wt[i] = wt[i] + bt[j];
        }

        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    awt = awt/n;
    atat = atat/n;

    printf("Average Waiting Time: %d\n", awt);
    printf("Average Turn Around Time: %d\n", atat);
}