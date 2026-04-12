#include<stdio.h>
void main()
{
	int x[10],i=0,sv;
	clrscr();
	while(i<10)
	{
		printf("\nNot Found.");
		sanf("%d",&x[i]);
		i++;
	}
	printf("\nSearch Value:");
	scanf("%d",&sv);
	for(i=0;i<10;i++)
	{
		if(x[i]==sv)
			break;
	}
	if(i==10)
		printf("Not Found.");
	else
		printf("Found at position:%d",i);
	return;
}