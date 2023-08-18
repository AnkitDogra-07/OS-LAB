#include<stdio.h>
#include<stdlib.h>

int x=0, mutex=1, full=0, empty, n=0, buffer;
int wait(int s){
    return(--s);
}

int signal(int s){
    return(++s);
}

void producer(){
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nItem no.%d has been produced and added to buffer", x);
    mutex = signal(mutex);
}

void consumer(){
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    x--;
    printf("\nItem no.%d has been consumed from the buffer", x);
    mutex = signal(mutex);
}

void main(){
    printf("Enter size of buffer:");
    scanf("%d", &buffer);
    empty = buffer;

    while(1){
        printf("\n\nPress 1 to produce an Item.\nPress 2 to consume an Item\nPress 3 to exit the critical section\nEnter your choice here:");
        scanf("%d", &n);
        switch(n){
            case 1:{
                if((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("\nBuffer is full!!");
            }break;

            case 2:{
                if((mutex == 1) && (full != 0))
                    consumer();
                else    
                    printf("\nBuffer is empty!!");
            }break;
	    case 3:exit(0);}}}
