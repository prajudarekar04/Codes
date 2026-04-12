//Bubble Sort
#include<stdio.h>
#include<conio.h>
void main()
{
	int x[5],i,j,flg,tmp;
	clrscr();
	printf("\nArray Data:");
	for(i=0;i<5;i++)
		scanf("%d",&x[i]);
	printf("\nBefore Sorting:");
	for(i=0;i<5;i++)
		printf("%4d",x[i]);
	for(i=0;i<4;i++)
	{
		flg=0;
		for(j=0;j<4-i;j++)
		{
			if(x[j]>x[j+1])
			{
				flg=1;
				tmp=x[j];
				x[j]=x[j+1];
				x[j+1]=tmp;
			}
		}
		if(flg==0)
			break;
	}
	printf("\nOrdered Data:\n");
	for(i=0;i<5;i++)
		printf("%4d",x[i]);
	getch();
	return;
}