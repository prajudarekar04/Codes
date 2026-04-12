//Linked List Implimentation of Queue.
#include<stdio.h>
typedef struct node
{
	int data;
	struct node*next;
}NODE;
typedef struct Queue
{
	NODE *fr;//Points to 1st node.
	NODE *rr;//Points to last node.
}Q;
void init(Q*t)
{
	t->fr=NULL;
	t->rr=NULL;
}
NODE*createNode(int d)
{
	NODE*a;
	a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
void insert(Q*t,int d)
{
	NODE*a=createNode(d),*b=t->rr;
	if(t->fr==NULL)
		t->fr=a;
	else
		b->next=a;
	t->rr=a;
}
void remque(Q*t)
{
	NODE*a=t->fr;
	if(t->fr==NULL)
		printf("\nUnderflow");
	else
	{
		t->fr=a->next;
		if(t->fr==NULL)
			t->rr=NULL;
		free(a);
	}
}
void display(Q*t)
{
	NODE*a=t->fr;
	if(t->fr==NULL)
		printf("\nEmpty Queue");
	else
	{
		printf("\nData");
		while(a!=NULL)
		{
			printf("%4d",a->data);
			a=a->next;
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
}