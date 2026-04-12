//Implimentation of Radix Sort.
#include<stdio.h>
#include<conio.h>
#define M 10
struct queue
{
	int fr,rr;
	int arr[M];
}Q[10];//array of struct queue
void init()
{
	int i=0;
	while(i<M)
	{
		Q[i].fr=0;
		Q[i].rr=-1;
		i++;
	}
}
void input(int*a)
{
	int i=0;
	while(i<M)
	{
		printf("\nNo:");
		scanf("%d",a+i);
		if(a[i]<100||a[i]>999)
			continue;
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
}
//to get digit from  no.
int getIndex(int val,int pos)
{
	int index;
	switch(pos)
	{
		case 1://right most
			index=val%10;
			break;
		case 2://middle
			index=(val/10)%10;
			break;
		case 3://left most
			index=(val/100);
			break;
	}
	return index;
}
void insert(int*a,int pos)
{
	int i=0,j,k;
	while(i<10)
	{
		j=getIndex(a[i],pos);
		k=++Q[j].rr;
		Q[j].arr[k]=a[i];
		i++;
	}
}
void remque(int*a)
{
	int i=0,j=0,k=0;
	while(i<M)
	{
		j=0;
		while(j<=Q[i].rr)
		{
			a[k]=Q[i].arr[j];
			j++;
			k++;
		}
		i++;
	}
}
void radix(int*a)
{
	int pos=1;
	while(pos<=3)
	{
		init();
		insert(a,pos);
		remque(a);
		pos++;
	}
}
void main()
{
	int x[10];
	input(x);
	display(x,0);
	radix(x);
	display(x,1);
}