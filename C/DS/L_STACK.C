//Linked List Implimentation of Stack.
#include<stdio.h>
typedef struct node
{
	int data;
	struct node*next;
}NODE;
typedef struct stack
{
	NODE* top;
}STK;
void init(STK*t)
{
	t->top=NULL;
}
NODE*createNode(int d)
{
	NODE*a;
	a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
void push(STK* t,int d)
{
	NODE*a=createNode(d);
	a->next=t->top;
	a->top=a;
}
void pop(STK*t)
{
	NODE*a=t->top;
	if(t->top==NULL)
	{
		printf("\nUnderflow");
		return;
	}
	t->top=a->next;
	free(a);
}
void display(STK*t)
{
	NODE*a=t->top;
	if(t->top==NULL)
		printf("\nEmpty List.");
	else
	{
		printf("\nStack Data:\n");
		while(a!=NULL)
		{
			printf("\n%4d",a->data);
			a=a->next;
		}
	}
}
void main()
{
	int opt,d;
	STK p;
	init(&p);
	while(1)
	{
		printf("\nStack Menu\n1.Push\n2.Pop\n3.Display\n4.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>3)
			break;
		switch(opt)
		{
			case 1:
				printf("\nData");
				scanf("%d",&d);
				push(&p,d);
				break;
			case 2:
				pop(&p);
				break;
			case 3:
				display(&p);
				break;
		}
	}
}