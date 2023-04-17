#include<stdio.h>
int main()
{
    int n,i,j,temp,p[10],pri[10],a_time[10],b_time[10],temp1,c_time[10],w_time[10],taround_time[10],total=0,loc;
    float avg_w_time,avg_taround_time;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\nEnter arrival time, burst time and priority for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time:");
        scanf("%d",&a_time[i]);
        printf("Burst Time:");
        scanf("%d",&b_time[i]);
        printf("Priority:");
        scanf("%d",&pri[i]);
        p[i]=i+1;           
    }
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(pri[j]<pri[loc]){
                loc=j;
            }
        }
        temp=pri[i];
        pri[i]=pri[loc];
        pri[loc]=temp;
        temp1=b_time[i];
        b_time[i]=b_time[loc];
        b_time[loc]=temp1;
        temp1=p[i];
        p[i]=p[loc];
        p[loc]=temp1;
    }
    for(i=0;i<n;i++)
    {
        if(i==0){
            c_time[i]=a_time[i]+b_time[i];
        }
        else
        {
            if(a_time[i]>c_time[i-1]){
                c_time[i]=a_time[i]+b_time[i];
            }
            else
                c_time[i]=c_time[i-1]+b_time[i];
        }
        total=total + c_time[i];
    }
    avg_taround_time=(float)total/n;     
    total=0;
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurn Around Time\tWaiting Time");
    for(i=0;i<n;i++)
    {
        taround_time[i]=c_time[i]-a_time[i];      
        w_time[i]=taround_time[i]-b_time[i];     
        total=total + w_time[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d",p[i],a_time[i],b_time[i],pri[i],c_time[i],taround_time[i],w_time[i]);
    }
    avg_w_time=(float)total/n; 
    printf("\n\nAverage Waiting Time=%f",avg_w_time);
    printf("\nAverage Turn Around Time=%f\n",avg_taround_time);
    return 0;
}
