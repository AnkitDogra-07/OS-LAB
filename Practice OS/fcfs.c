#include<stdio.h>

void main(){
    int i, j, bt[10], wt[10], tat[10], n;
    float awt=0, atat=0;

    printf("Enter number of processes:");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter Burst time of process%d:", i+1);
        scanf("%d", &bt[i]);
    }

    printf("Process\t Burst Time\t Wait Time\t Turn Around Time\n");
    for(i=0; i<n; i++){
        wt[i] = 0;
        tat[i] = 0; 
        for(j=0; j<i; j++){
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("| %d\t| %d\t\t| %d\t\t| %d\n", i+1, bt[i], wt[i], tat[i]);
    }
    awt = awt/n;
    atat = atat/n;
    printf("Average waiting time = %.2f\n", awt);
    printf("Average Turn Around Time = %.2f", atat);
}