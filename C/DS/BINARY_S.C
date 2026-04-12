//Binary Search
#include<stdio.h>
#include<conio.h>
void main()
{
	int x[5],i,l,r,mid,sv;
	i=0;
	while(i<5)
	{
		printf("\nEnter Data:");
		scanf("%d",&x[i]);
		if(i>0)
		{
			if(x[i]<x[i-1])
			{
				printf("\nInvalid Input.");
				continue;
			}
		}
		i++;
	}
	printf("\nEnter Search Value:");
	scanf("%d",&sv);
	l=0;r=4;
	do
	{
		mid=(l+r)/2;
		if(sv==x[mid])
			break;
		if(sv<x[mid])
			r=mid-1;
		else
			l=mid+1;
	}while(l<=r);
	if(l<=r)
		printf("\nFound.");
	else
		printf("\nNot found.");
	getch();
	return;
}