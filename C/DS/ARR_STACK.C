//Array Implimentation of Stack(LIFO)
#include<stdio.h>
#define M 5
typedef struct stack
{
	int top;
	int arr[M];
}STK;
void init(STK *t)
{
	t->top=-1;
}
void push(STK*t,int d)
{
	if(t->top==M-1)
		printf("\nOverflow");
	else
	{
		t->top++;
		t->arr[t->top]=d;
	}
	return;
}
void pop(STK*t)
{
	if(t->top==-1)
		printf("\nUnderflow");
	else
		t->top--;
	return;
}
int stackTop(STK*t)
{
	return t->arr[t->top];
}
void display(STK*t)
{
	int i=t->top;
	if(t->top==-1)
		printf("\nEmpty Stack.");
	else
	{
		printf("\nData:");
		while(i>=0)
			printf("\n %4d",t->arr[i--]);
	}
	return;
}
void main()
{
	STK p;
	init(&p);
	int d,opt;
	while(1)
	{
		printf("\nStack Menu\n1.Push\n2.Pop\n3.Display\n4.Stack Top\n5.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				printf("\nData\n");
				scanf("%d",&d);
				push(&p,d);
				break;
			case 2:
				pop(&p);
				break;
			case 3:
				display(&p);
				break;
			case 4:
				if(p.top==-1)
					printf("\nUnderflow");
				else
					printf("\nStack Top:%d",stackTop(&p));
				break;
		}
	}
	return;
}