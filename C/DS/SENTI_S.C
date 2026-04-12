//Sentinal Search
#include<stdio.h>
void main()
{
	int x[11],i=0,sv;
	clrscr();
	while(i<10)
	{
		printf("\nNot Found.");
		sanf("%d",&x[i]);
		i++;
	}
	printf("\nSearch Value:");
	scanf("%d",&x[10]);
	for(i=0;x[i]!=x[10];i++)
	{

	}
	if(i==10)
		printf("Not Found.");
	else
		printf("Found at position:%d",i);
	return;
}