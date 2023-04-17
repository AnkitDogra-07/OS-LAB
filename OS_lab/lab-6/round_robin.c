#include<stdio.h>
void main(){
	int NOP, sum=0, count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10], x;
	float avg_wt, avg_tat;
	printf("Enter number of processes:");
	scanf("%d", &NOP);
	y=NOP;
	
	for(int i=0; i<y; i++){
		printf("Enter arrival time and burst time of process[%d]\n", i+1);
		printf("Arrival Time:");
		scanf("%d", &at[i]);
		printf("Burst Time:");
		scanf("%d", &bt[i]);
		temp[i]=bt[i];
		printf("\n");
	}
	
	printf("Enter time quantum:");
	scanf("%d", &quant);
	printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
	for(sum=0, x = 0; y!=0;)  
	{  
		if(temp[x] <= quant && temp[x] > 0) 
		{	  
		    	sum = sum + temp[x];  
		    	temp[x] = 0;  
		    	count=1;  
    		}     
    		else if(temp[x] > 0)  
    		{  
        		temp[x] = temp[x] - quant;  
        		sum = sum + quant;    
    		}  
    		if(temp[x]==0 && count==1)  
    		{  
        		y--;   
        		printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", x+1, bt[x], sum-at[x], sum-at[x]-bt[x]);  
        		wt = wt+sum-at[x]-bt[x];  
        		tat = tat+sum-at[x];  
        		count =0;     
    		}  
    		if(x==NOP-1)  
    		{  
        		x=0;  
    		}  
    		else if(at[x+1]<=sum)  
    		{  
        		x++;  
    		}  
    		else {
        		x=0;  
    		}  	
	}  
	avg_wt = wt * 1.0/NOP;  
	avg_tat = tat * 1.0/NOP;  
	printf("\n Average Turn Around Time:%f", avg_wt);  
	printf("\n Average Waiting Time:%f", avg_tat);   
	printf("\n");
}
