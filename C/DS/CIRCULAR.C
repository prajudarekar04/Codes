#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}NODE;
typedef struct circularlist
{
	NODE *st;
}CLIST;
void init(CLIST *t)
{
	t->st=NULL;
}
NODE *createNode(int d)
{
	NODE*a=(NODE *)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
//fn. to add at End.
void addEnd(CLIST *t,int d)
{
	NODE *a=createNode(d),*b;
	if(t->st==NULL)
		a->next=a;
	else
	{
		b=t->st;
		a->next=b->next;
		b->next=a;
	}
	t->st=a;
}
//fn. to add at Begin.
void addBeg(CLIST *t,int d)
{
	NODE *a=createNode(d),*b;
	if(t->st==NULL)
	{
		a->next=a;
		t->st=a;
	}
	else
	{
		b=t->st;
		a->next=b->next;
		b->next=a;
	}
}
//fn. to Delete First.
void delFirst(CLIST *t)
{
	NODE *a=t->st,*b=t->st;
	if(t->st==NULL) //Empty List.
		return;
	else
	{
		if(a->next==a)       //Only 1 Node.
			t->st=NULL;
		else                 //MultiNodes
		{
			b=a->next;
			a->next=b->next;
		}
		free(b);
	}
}
//fn. to Delete Last.
void delLast(CLIST *t)
{
	NODE *a=t->st,*b=t->st;
	if(t->st==NULL) //Empty List.
		return;
	else
	{
		if(a->next==a)       //Only 1 Node.
			t->st=NULL;
		else                 //MultiNodes
		{
			b=a->next;
			while(b->next!=a)
				b=b->next;
			b->next=a->next;
			t->st=b;
		}
		free(a);
	}
}
//fn. to Display List.
void display(CLIST *t)
{
	NODE *a=t->st;
	if(t->st==NULL)
		printf("\nEmpty List.");
	else
	{
		printf("\nData:\n");
		a=a->next;
		do
		{
			printf("%4d",a->data);
			if(a==t->st)
				break;
			a=a->next;
		}while(1);
	}
}
void main()
{
	int opt,d;
	CLIST p;
	init(&p);
	while(1)
	{
		printf("\nMenu\n1.Add at End\n2.Add at Begin\n3.Delete First\n4.Delete Last\n5.Display\n6.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>5)
			break;
		switch(opt)
		{
			case 1:
				printf("\nData at End:");
				scanf("%d",&d);
				addEnd(&p,d);
				break;
			case 2:
				printf("\nData at Begin:");
				scanf("%d",&d);
				addBeg(&p,d);
				break;
			case 3:
				delFirst(&p);
				break;
			case 4:
				delLast(&p);
				break;
			case 5:
				display(&p);
				break;
		}
	}
}
