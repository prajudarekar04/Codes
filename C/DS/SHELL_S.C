//Shell Sort.
#include<stdio.h>
#include<conio.h>
#define M 10
void input(int *a)
{
	int i=0;
	printf("\nData:\n");
	while(i<M)
	{
		scanf("%d",a+i);
		i++;
	}
}
void display(int *a,int flg)
{
	int i=0;
	if(flg==0)
		printf("\nBefore Sorting:");
	else
		printf("\nAfter Sorting:");
	while(i<M)
		printf("%4d",a[i++]);
	return;
}
void shell(int *a)
{
	int i,h,w,curr;
	i=(M-1)/2;
	while(i)
	{
		for(curr=i;curr<M;curr++)
		{
			h=a[curr];
			w=curr-i;
			while(w>=0&&h<a[w])
			{
				a[w+i]=a[w];
				w-=i;
			}
			a[w+i]=h;
		}
		i/=2;
	}
}
void main()
{
	int x[M];
	clrscr();
	input(x);
	display(x,0);
	shell(x);
	display(x,1);
	getch();
	return;
}