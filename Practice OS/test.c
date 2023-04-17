#include<stdio.h>
#include<stdlib.h>

void main(){
    int n, ct=0, count=0, at[10], bt[10], rt[10], tq, y, twt=0, tat=0, i;
    float awt=0, atat=0;

    printf("Enter number of processes:");
    scanf("%d", &n);

    count = n;

    for(i =0; i<n; i++){
        printf("Enter Arrival time of P%d:", i);
        scanf("%d", &at[i]);
        printf("Enter Burst time of P%d:", i);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        printf("\n");
    }

    printf("Enter Time Quantum:");
    scanf("%d", &tq);

    printf("\n Process\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for(ct=0, i=0; count != 0;){
        if((rt[i] <= tq) && (rt[i] > 0)){
            ct+=rt[i];
            rt[i] = 0;
            count--;
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], at[i], ct-at[i]-bt[i], ct-at[i]);
            twt = twt + ct - at[i] - bt[i];
            tat = tat + ct - at[i];
        }

        else if(rt[i]>0){
            rt[i]=rt[i] - tq;
            ct=ct + tq;
        }

        if(i == n-1){
            i = 0;
        }

        else if(at[i+1] <= ct){
            i++;
        }

        else{
            i=0;
        }
    }
}