/*Program to maintain student list
1.Roll No. must be unique.
2.Mobile No. must be unique.
fn. add new record.
fn. to modify existing record.
fn. to delete existing record.
fn. to display student record.
fn. to
fn. to build list from file.*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct student
{
	int no;
	char nm[15];
	char mno[11];
}STU;
typedef struct node
{
	STU data;
	struct node*next;
}NODE;
typedef struct stulist
{
	NODE *st;
	int cnt;
}STLIST;
void init(STLIST *t)
{
	t->st=NULL;
	t->cnt=0;
}
void display(STU * a)
{
	printf("\n%5d %-15s %-11s",a->no,a->nm,a->mno);
}
//fn. to search student record rno wise (if found return address of node, otherwise return null)
NODE* searchNo(STLIST *t,int no)
{
	NODE *a=t->st;
	while(a!=NULL)
	{
		if(a->data.no==no)
			break;
		a=a->next;
	}
	return a;
}
//fn. to search by mno.
NODE *searchMno(STLIST *t,char*m)
{
	NODE *a=t->st;
	while(a!=NULL)
	{
		if(strcmp(a->data.mno,m)==0)
			break;
		a=a->next;
	}
	return a;
}
//fn. to add new student record.
void add(STLIST *t)
{
	NODE *a;
	int no;
	char mno[11];
	printf("\nRoll No.:");
	scanf("%d",&no);
	a=searchNo(t,no);
	if(a!=NULL)
	{
		printf("\nRecord Exists.");
		return;
	}
	a=(NODE*)malloc(sizeof(NODE));
	a->data.no=no;
	printf("\nName:");
	scanf("%s",a->data.nm);
	do
	{
		printf("\nMobile No:");
		scanf("%s",mno);
		if(searchMno(t,mno)==NULL)
			break;
		else
			printf("\nRecord Exists");
	}while(1);
	strcpy(a->data.mno,mno);
	a->next=t->st;
	t->st=a;
	t->cnt++;
	printf("\nAdd sucessfull");
	return;
}
//fn. to modify.
void mod(STLIST *t)
{
	NODE *a;
	int no;
	char mno[11];
	printf("\nRoll No.:");
	scanf("%d",&no);
	a=searchNo(t,no);
	if(a==NULL)
	{
		printf("\nRecord not Exists.");
		return;
	}
	a->data.no=no;
	printf("\nName:");
	scanf("%s",a->data.nm);
	do
	{
		printf("\nMobile No:");
		scanf("%s",mno);
		if(searchMno(t,mno)==NULL)
			break;
		else
			printf("\nRecord Exists");
	}while(1);
	strcpy(a->data.mno,mno);
	printf("\nMod sucessfull");
	return;
}
//fn. to delete student record.
void del(STLIST *t)
{
	NODE *a,*b,*c;
	int no;
	char mno[11];
	printf("\nRoll No.:");
	scanf("%d",&no);
	a=searchNo(t,no);
	if(a==NULL)
	{
		printf("\nRecord not Exists.");
		return;
	}
	if(a==t->st)
		t->st=a->next;
	else
	{
		b=t->st;
		while(b->next!=a)
			b=b->next;
		c=a->next;
		b->next=c;
	}
	t->cnt--;
	free(a);
	printf("\nDel sucessfull.");
}
//fn. to display all student record.
void displayAll(STLIST *t)
{
	NODE*a=t->st;
	if(t->st==NULL)
		printf("\nEmpty List.");
	else
	{
		printf("\nStudent data:\n");
		while(a!=NULL)
		{
			display(&a->data);
			a=a->next;
		}
	}
}
//fn. to store STU data to binary file.STU2021.dat
void save(STLIST *t)
{
	NODE *a=t->st;
	FILE *f1;
	if(t->st==NULL)
		return;
	f1=fopen("STU2021.dat","wb");
	while(a!=NULL)
	{
		fwrite(&a->data,sizeof(STU),1,f1);
		a=a->next;
	}
	fclose(f1);
}
//fn. to build STLIST from binary file STU2021.dat
void load(STLIST *t)
{
	NODE *a=t->st;
	STU d;
	FILE *f1=fopen("STU2021.dat","rb");
	if(f1==NULL)
	{
		printf("\nFile Not Found.");
		return;
	}
	while(t->st!=NULL)
	{
		t->st=a->next;
		free(a);
		a=t->st;
	}
	t->cnt=0;
	while(1)
	{
		fread(&d,sizeof(STU),1,f1);
		if(feof(f1))
			break;
		a=(NODE*)malloc(sizeof(NODE));
		a->data=d;
		a->next=t->st;
		t->st=a;
		t->cnt++;
	}
	fclose(f1);
}
void main()
{
	int opt,no;
	char mno[11];
	STLIST p;
	NODE *a;
	init(&p);
	while(1)
	{
		printf("\nMenu\n1.Add\n2.Mod\n3.Del\n4.DisplayAll\n5.Search by no.\n6.Search by Mno.\n7.save\n8.load\n9.exit\nOption:");
		scanf("%d",&opt);
		if(opt>8)
			break;
		switch(opt)
		{
			case 1:
				add(&p);
				break;
			case 2:
				mod(&p);
				break;
			case 3:
				del(&p);
				break;
			case 4:
				displayAll(&p);
				break;
			case 5:
				printf("\nRoll No To Search:");
				scanf("%d",&no);
				a=searchNo(&p,no);
				if(a==NULL)
					printf("\nNot Found.");
				else
					display(&a->data);
				break;
			case 6:
				printf("\nMno:");
				scanf("%s",mno);
				a=searchMno(&p,mno);
				if(a==NULL)
					printf("\nNot Found.");
				else
					display(&a->data);
				break;
			case 7:
				save(&p);
				break;
			case 8:
				load(&p);
				break;
		}
	}
}