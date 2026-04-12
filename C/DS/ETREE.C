//Expression Tree.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *left;
	char ch;
	struct node *right;
}NODE;
NODE * createNode(char ch)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	a->ch=ch;
	a->left=a->right='\0';
	return a;
}
typedef struct stack
{
	int top;
	NODE *arr[10];
}STK;
NODE *rt='\0';//rt. node
STK s;
void init()
{
	rt='\0';
	s.top=-1;
}
void push(NODE*a)
{
	s.top++;
	s.arr[s.top]=a;
}
NODE * pop()
{
	return s.arr[s.top--];
}
int isEmpty()
{
	return s.top=-1;
}
void preorder(NODE*a)
{
	if(a!='\0')
	{
		printf("%c",a->ch);
		preorder(a->left);
		preorder(a->right);
	}
	else
		return;
}
void inorder(NODE*a)
{
	if(a!='\0')
	{
		inorder(a->left);
		printf("%c",a->ch);
		inorder(a->right);
	}
	else
		return;
}
void postorder(NODE*a)
{
	if(a!='\0')
	{
		postorder(a->left);
		postorder(a->right);
		printf("%c",a->ch);
	}
	else
		return;
}
void createEtree()
{
	char a[50];
	NODE *b,*c,*d;
	int i=0;
	printf("Enter Postfix Expression:");
	scanf("%s",a);
	while(a[i]!='\0')
	{
		if((a[i]>=65&&a[i]<=90)||(a[i]>=97&&a[i]<=122))
		{
			b=createNode(a[i]);
			push(b);
		}
		else
		{
			b=pop();
			c=pop();
			d=createNode(a[i]);
			//d->left=c;
			d->right=b;
			d->left=c;
			push(d);
		}
		i++;
	}
	rt=pop();
}
void display()
{
	printf("\nPreOrder:");
	preorder(rt);
	printf("\nInorder:");
	inorder(rt);
	printf("\nPostOrder:");
	postorder(rt);
}
void main()
{
	clrscr();
	createEtree();
	display();
	getch();
	return;
}