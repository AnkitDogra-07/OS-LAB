#include<stdio.h>
int max[10][10],allocation[10][10], need[10][10];
int avail[10];
int np, nr;
void readmatrix(int matrix[10][10]){
	for(int i=0; i<np; i++){
		for(int j=0; j<nr; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
}

void displaymatrix(int matrix[10][10]){
	for(int i=0; i<np; i++){
		for(int j=0; j<nr; j++){
			printf("  %d", matrix[i][j]);
		}
		printf("\n");
	}
}

void calc_need(){
	for(int i=0; i<np; i++){
		for(int j=0; j<nr; j++){
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
}

void banker(){
	int k=0,i,j,flag;
	int finish[10], safe_seq[10];

	for(i=0; i<np; i++){
		finish[i] = 0;
	}

	for(i=0; i<np; i++){
		flag = 0;
		if(finish[i] == 0){
			for(j=0; j<nr; j++){
				if(need[i][j]>avail[j]){
					flag = 1;
					break;
				}
			}

			if(flag == 0){
				finish[i] = 1;
				safe_seq[k] = i;
				printf("Process %d has entered the safe sequence\n", i);
				k++;

				for(j=0; j<nr; j++){
					avail[j]+=allocation[i][j];
				}
				i=-1;
			}
		}
	}

	flag = 0;
	for(i=0; i<np; i++){
		if(finish[i] == 0){
			flag = 1;
			break;
		}
	}

	if(flag == 1){
		printf("System is in deadlock");
	}

	else{
		printf("\nSystem is in safe state.\n");
		for(i = 0; i<np; i++){
			if(i == np-1){
				printf("P%d", safe_seq[i]);
			}

			else{
				printf("P%d->", safe_seq[i]);
			}
		}
	}
}

void main(){
	printf("Enter number of processes:");
	scanf("%d", &np);
	
	printf("Enter number of resources:");
	scanf("%d", &nr);
	
	printf("Enter allocation matrix\n");
	readmatrix(allocation);
	
	printf("Enter Maximum matrix\n");
	readmatrix(max);
	
	printf("Enter available resources:");
	for(int i=0; i<nr; i++){
		scanf("%d", &avail[i]);
	}
	
	printf("\n******Entered Data is *******\n\n");
	printf("\nInitial Allocation \n");
	displaymatrix(allocation);
	printf("\n\n\nMaximum Requirement\n");
	displaymatrix(max);
	printf("\nAvailable Resources:");
	for(int i=0; i<nr; i++)
		printf(" %d", avail[i]);

	calc_need();
	printf("\n\n\nNeed is\n");
	displaymatrix(need);

	banker();
	printf("\n\n\n\n");
}

