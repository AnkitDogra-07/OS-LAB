#include<stdio.h>
void main(){
    int i, n, at[10], bt[10], rt[10], ct=0, tat=0, twt=0, smallest, time, fin=0;
    float awt=0, atat=0;

    printf("Enter number of processes:");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter Arrival time of P%d:", i);
        scanf("%d", &at[i]);
        printf("Enter Burst time of P%d:", i);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        printf("\n");
    }

    rt[9] = 9999;
    printf("\n Process\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for(time = 0;fin!=n; time++){
        smallest=9;
        for(i=0; i<n; i++){
            if((at[i]<=time && rt[i]<rt[smallest])&&rt[i]){
                smallest = i;
            }
        }

        rt[smallest]--;
        if(rt[smallest] == 0){
            fin++;
            ct = time+1;
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", smallest+1, bt[smallest], at[smallest], ct-at[smallest]-bt[smallest], ct-at[smallest]);
            tat = ct - at[smallest];
            twt = ct - at[smallest] - bt[smallest];
        }
    }

    awt = (float)twt/n;
	atat = (float)tat/n;
	
	printf("\nAverage Waiting Time: %f", awt);
	printf("\nAverage Turn Around Time: %f\n", atat);
}