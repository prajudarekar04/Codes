//Queue using Array.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define M 5
typedef struct queue
{
	int arr[M];
	int fr,rr;
}Q;
void init(Q*t)
{
	t->rr=-1;
	t->fr=0;
}
void insert(Q*t,int d)
{
	if(t->rr==M-1)
		printf("\nOverflow");
	else
	{
		t->rr++;
		t->arr[t->rr]=d;
	}
	return;
}
void remque(Q*t)
{
	if(t->rr<t->fr)
		printf("\nUnderflow");
	else
		t->fr++;
	return;
}
int isFull(Q*t)
{
	return(t->rr==M-1);
}
int isEmpty(Q*t)
{
	return(t->rr<t->fr);
}
void display(Q*t)
{
	int i=t->fr;
	if(isEmpty(t))
		printf("\nEmpty.");
	else
	{
		printf("\nData:\n");
		while(i<=t->rr)
		{
			printf("\n%4d",t->arr[i]);
			i++;
		}
	}
	return;
}
void main()
{
	int opt,d;
	Q p;
	init(&p);
	while(1)
	{
		printf("\nMenu\n1.Insert\n2.Remove\n3.Display\n4.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>3)
			break;
		switch(opt)
		{
			case 1:
				printf("\nData:\n");
				scanf("%d",&d);
				insert(&p,d);
				break;
			case 2:
				remque(&p);
				break;
			case 3:
				display(&p);
				break;
		}
	}
	getch();
	return;
}