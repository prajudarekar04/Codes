#include<stdio.h>
#include<conio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *st=NULL;
//fn. to create new NODE
NODE *createNode(int d)
{
	NODE *a;
	a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
//fn. to retive last NODE adddress
NODE *getlastnode()
{
	NODE *a=st;
	while(a->next!=NULL)
		a=a->next;
	return a;
}
//fn. to display list data
void display()
{
	NODE *a=st;
	if(st==NULL)
		printf("\nEmpty List");
	else
	{
		printf("\n Data:");
		while(a!=NULL)
		{
			printf("\n%4d",a->data);
			a=a->next;
		}
		printf("\n");
	}
}
//fn. to add new NODE at End
void addEnd(int d)
{
	NODE *a,*b;
	a=createNode(d);
	if(st==NULL)
		st=a;
	else
	{
		b=getlastnode();
		b->next=a;
	}
}
//fn. to add new NODE at Begin
void addBeg(int d)
{
	NODE *a;
	a=createNode(d);
	a->next=st;
	st=a;
}
void main()
{
	int opt,d;
	clrscr();
	while(1)
	{
		printf("\nSingle Linked List\n1.Add End\n2.Add Begin\n3.Display\n4.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>3)
			break;
		switch(opt)
		{
			case 1:
				printf("\nData at End:");
				scanf("%d",&d);
				addEnd(d); break;
			case 2:
				printf("\nData at Begin:");
				scanf("%d",&d);
				addBeg(d); break;
			case 3:
				display();
		}
	}
}