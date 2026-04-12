//Single Linked List
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
//fn. to create new NODE
NODE * createNode(int d)
{
	NODE *a;
	a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
//fn. to retrieve last NODE address
NODE *getLastNode(NODE* *p)
{
	NODE *a=*p;
	while(a->next!=NULL)
		a=a->next;
	return a;
}
//fn. to add new NODE at End
void addEnd(NODE* *p,int d)
{
	NODE*a=createNode(d),*b;
	if(*p==NULL)
		*p=a;
	else
	{
		b=getLastNode(p);
		b->next=a;
	}
}
//fn. to add new NODE at Begin
void addBeg(NODE* *p,int d)
{
	NODE*a=createNode(d);
	a->next=*p;
	*p=a;
}
//fn. to display list data
void display(NODE* *p)
{
	NODE *a=*p;
	if(*p==NULL)
		printf("\nEmpty List");
	else
	{
		printf("\nData:\n");
		while(a!=NULL)
		{
			printf("%4d\n",a->data);
			a=a->next;
		}
	}
}
/*
void main()
{
	NODE *st=NULL;
	addEnd(&st,10);
	addEnd(&st,20);
	addEnd(&st,30);
	addBeg(&st,40);
	display(&st);
	//getch();
}
*/
//OR
/*
void main()
{
	int opt,d;
	NODE *st=NULL;
	while(1)
	{
		printf("\nSingle Linked List\nMenu\n1.Add End\n2.Add Begin\n3.Display\n4.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>3)
			break;
		switch(opt)
		{
			case 1:
				printf("\nEnter Data to add at End:");
				scanf("%d",&d);
				addEnd(&st,d);
				break;
			case 2:
				printf("\nEnter Data to add at Begin:");
				scanf("%d",&d);
				addBeg(&st,d);
				break;
			case 3:
				display(&st);
				break;
		}
	}
}*/