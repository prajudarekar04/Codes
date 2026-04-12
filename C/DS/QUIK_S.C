//Quick Sort.
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
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void pivot(int *a,int l,int r)
{
	if(a[l]>a[r])
		swap(a+l,a+r);
}
int partition(int *a,int l,int r)
{
	int i=l,j=r,k;
	pivot(a,l,r);
	k=a[l];
	do
	{
		do ++i;while(a[i]<k);
		do --j;while(a[j]>k);
		if(i<j)
			swap(a+i,a+j);
	}while(i<j);
	swap(a+l,a+j);
	return j;
}
void Quick(int*a,int l,int r)
{
	int k;
	if(l<r)
	{
		k=partition(a,l,r);
		Quick(a,l,k-1);
		Quick(a,k+1,r);
	}
}
void main()
{
	int x[M];
	clrscr();
	input(x);
	display(x,0);
	Quick(x,0,M-1);
	display(x,1);
	getch();
	return;
}