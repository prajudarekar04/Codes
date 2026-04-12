#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}NODE;
typedef struct doublelist
{
	NODE *st; //Points to first Node.
	NODE *ed; //Points to last Node.
}DLIST;
void init(DLIST *t)
{
	t->st=NULL;
	t->ed=NULL;
}
//fn. to create Node.
NODE *createNode(int d)
{
	NODE *a;
	a=(NODE *)malloc(sizeof(NODE));
	a->data=d;
	a->prev=a->next=NULL;
	return a;
}
//fn. to add at End.
void addEnd(DLIST *t,int d)
{
	NODE *a=createNode(d);
	NODE *b=t->ed;
	if(t->st==NULL)
		t->st=a;
	else
	{
		b->next=a;
		a->prev=b;
	}
	t->ed=a;
}
//fn. to add at Begin.
void addBeg(DLIST *t,int d)
{
	NODE *a=createNode(d);
	NODE *b=t->st;
	if(t->ed==NULL)
		t->ed=a;
	else
	{
		b->prev=a;
		a->next=b;
	}
	t->st=a;
}
//fn. to delete first node.
void delFirst(DLIST *t)
{
	NODE *a=t->st,*b;
	if(t->st==NULL)
		return;
	if(t->st==t->ed)
		t->st=t->ed=NULL;
	else
	{
		b=a->next;
		t->st=b;
		b->prev=NULL;
	}
	free(a);
}
//fn. to delete last node.
void delLast(DLIST *t)
{
	NODE *a=t->ed,*b;
	if(t->ed==NULL)   //Empty List.
		return;
	if(t->st==t->ed)  //only one Node.
		t->st=t->ed=NULL;
	else
	{
		b=a->prev;
		t->ed=b;
		b->next=NULL;
	}
	free(a);
}
//fn. to delete all Nodes from list.
void delAll(DLIST *t)
{
	while(t->st!=NULL)
		delFirst(t);
}
//fn. to ith Node from list.
void deliNode(DLIST *t,int pos)
{
	NODE *a=t->st,*b,*c;
	int i=1;
	if(t->st==NULL)
		return;
	if(pos==1)
		delFirst(t);
	else
	{
		while(i<pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(a==NULL)
			printf("\nNo such Node Exist.");
		else
		{
			c=a->next;
			b->next=c;
			c->prev=b;
			free(a);
		}
	}
}
//fn. to display DLIST from Start-End.
void disSE(DLIST *t)
{
	NODE *b=t->st;
	if(t->st==NULL)
		printf("\nEmpty List.");
	else
	{
		printf("\nData\n");
		while(b!=NULL)
		{
			printf("%4d",b->data);
			b=b->next;
		}
	}
}
//Fn. to Insert new node before ith pos.
void insertB(DLIST *t,int pos,int d)
{
	NODE *a=t->st,*b,*c;
	int i=1;
	if(t->st==NULL) //Empty list.
		return;
	if(pos<1)       //Invalid pos.
		return;
	if(pos==1)
		addBeg(t,d);
	else
	{
		while(i<pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(a==NULL)
			printf("\nNo such Node Exist.");
		else
		{
			c=createNode(d);
			b->next=c;
			c->prev=b;
			c->next=a;
			b->prev=c;
		}
	}
}
//Fn. to Insert new node after ith pos.
void insertA(DLIST *t,int pos,int d)
{
	NODE *a=t->st,*b,*c;
	int i=1;
	if(t->st==NULL)	  //Empty List.
		return;
	if(pos<1)
		return;
	while(i<=pos&&a!=NULL)
	{
		b=a;
		a=a->next;
		i++;
	}
	if(i<pos)         //Invalid pos.
		return;
	if(i>pos)
		addEnd(t,d);
	else
	{
		c=createNode(d);
		c->prev=b;
		b->next=c;
	}
}
//fn. to display DLIST from End-Start.
void disES(DLIST *t)
{
	NODE *b=t->ed;
	if(t->ed==NULL)
		printf("\nEmpty List.");
	else
	{
		printf("\nData\n");
		while(b!=NULL)
		{
			printf("%4d",b->data);
			b=b->prev;
		}
	}
}
void main()
{
	int opt,d,pos;
	DLIST p;
	init(&p);
	while(1)
	{
		printf("\nMenu\n1.Add at End\t\t\t2.Add at Begin\n3.Delete First\t\t\t4.Delete Last\n5.Display List Start-End\t6.Display List End-Start\n7.Insert Before Position\t8.Insert After Position\n9.Delete All Nodes\t\t10.Delete ith Pos Node\n11.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>10)
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
				disSE(&p);
				break;
			case 6:
				disES(&p);
				break;
			case 7: //insert b
				printf("Data:");
				scanf("%d",&d);
				printf("Pos:");
				scanf("%d",&pos);
				insertB(&p,d,pos);
				break;
			case 8://insert a
				printf("Data:");
				scanf("%d",&d);
				printf("Pos:");
				scanf("%d",&pos);
				insertA(&p,d,pos);
				break;
			case 9://delete all
				delAll(&p);
				break;
			case 10://delete ithpos
				printf("Pos:");
				scanf("%d",&pos);
				deliNode(&p,pos);
				break;
		}
	}
}