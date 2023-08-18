#include<stdio.h>
int main()
{
int demandStream[] = {4, 1, 2, 4, 5, 9, 10};
int pageFaults = 0;
int frames = 3;
int m, n, s, pages;
pages = sizeof(demandStream)/sizeof(demandStream[0]);
printf("DemandPageNo \t\t Frame 1 \t\t Frame 2 \t\t Frame 3");
int temp[frames];
for(m = 0; m < frames; m++)
{
temp[m] = -1;
}
for(m = 0; m < pages; m++)
{
s = 0;
for(n = 0; n < frames; n++)
{
if(demandStream[m] == temp[n])
{
s++;
pageFaults--;
}
}
pageFaults++;
if((pageFaults <= frames) && (s == 0))
{
temp[m] = demandStream[m];
}
else if(s == 0)
{
temp[(pageFaults - 1) % frames] = demandStream[m];
}
printf("\n");
printf("%d\t\t\t",demandStream[m]);
for(n = 0; n < frames; n++)
{
if(temp[n] != -1)
printf(" %d\t\t\t", temp[n]);
else
printf(" - \t\t\t");
}
}
printf("\nTotal Page Faults:\t%d\n", pageFaults);
return 0;
}
