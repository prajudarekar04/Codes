//Ordered Search
#include<stdio.h>
void main()
{
	int x[11],i=0;
	clrscr();
	printf("\nEnter Data:");
	while(i<10)
	{
		scanf("%d",&x[i]);
		if(i)
		{
			if(x[i]<x[i-1])
			{
				printf("\nInvalid.");
				continue;
			}
		}
		i++;
	}
	printf("\nSearch Value:");
	scanf("%d",&x[10]);
	for(i=0;x[i]<x[10];i++)
		;
	if((i==10)||(x[i]>x[10]))
		printf("\nNot Found");
	else
		printf("\nFound");
	return;
}