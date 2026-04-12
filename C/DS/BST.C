#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node*left;
	int data;
	struct node*right;
}NODE;

typedef struct bst
{
	NODE *rt;
	NODE *prnt;
	NODE *curr;
}BST;

NODE *createNode(int d)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	a->left=a->right=NULL;
	a->data=d;
	return a;
}
//preorder
void preorder(NODE *a)
{
	if(a!=NULL)
	{
		printf("%4d",a->data);
		preorder(a->left);
		preorder(a->right);
	}
	else
	return;
}
//inorder
void inorder(NODE *a)
{
	if(a!=NULL)
	{
		inorder(a->left);
		printf("%4d",a->data);
		inorder(a->right);
	}
	else
	return;
}
//post order
void postorder(NODE *a)
{
	if(a!=NULL)
	{
		postorder(a->left);
		postorder(a->right);
		printf("%4d",a->data);
	}
	else
	return;
}
//insert
void insert(BST *t)
{
	NODE *a,*b;
	int d;
	while(1)
	{
		printf("\nData:\n");
		scanf("%d",&d);
		if(d==0)
			break;
		if(t->rt==NULL)
			t->rt=createNode(d);
		else
		{
			a=t->rt;
			while(1)
			{
				if(d<a->data)
				{
					if(a->left==NULL)
					{
						a->left=createNode(d);
						break;
					}
					else
					a=a->left;
				}
				else
				{
					if(a->right==NULL)
					{
						a->right=createNode(d);
						break;
					}
					else
					a=a->right;
				}
			}
		}
	}
}
//fn to serach data
int search(BST *t,int d)
{
	NODE *a=t->rt;
	int flg=0;
	while(1)
	{
		if(a->data==d)
		{
			t->curr=a;
			flg=1;
			break;
		}
		if(d<a->data)
		{
			if(a->left==NULL)
				break;
			else
			{
				t->prnt=a;
				a=a->left;
			}
		}
		else
		{
			if(a->right==NULL)
				break;
			else
			{
				t->prnt=a;
				a=a->right;
			}
		}
	}
	return flg;
}
//delete function
void delNode(BST *t)
{
	int sv;
	NODE *p,*q,*r,*s;
	printf("\nEnter data to delete:");
	scanf("%d",&sv);
	if(search(t,sv)==0)
	{
		printf("\nNo such data");
		return;
	}
	p=t->prnt;
	q=t->curr;
	//leaf node deletion
	if(q->left!=NULL&&q->right!=NULL)
	{
		if(p->left==q)
		{
			p->left=NULL;
		}
		else
		{
			p->right=NULL;
		}
		free(q);
		return;
	}
	if(q->left!=NULL&&q->right!=NULL)
	{
		if(p->left==q)
		{
			r=q->right;
			while(r!=NULL)
			{
				s=r;
				r=r->left;
			}
			s->left=q->left;
			p->left=q->right;
		}
		else
		{
			r=q->left;
			while(r!=NULL)
			{
				s=r;
				r=r->right;
			}
			s->right=q->right;
			p->right=q->left;
		}
		free(q);
		return;
	}
	if(p->left==q)
	{
		if(q->left==NULL)
		{
			p->left=q->right;
		}
		else
		{
			p->left=q->left;
		}
		free(q);
		return;
	}
	if(p->right==q)
	{
		if(q->left==NULL)
		{
			p->right=q->right;
		}
		else
		{
			p->right=q->left;
		}
		free(q);
		return;
	}
	return;
}
iint main()
{
	BST p;
	int opt,sv;
	p.rt=p.curr=p.prnt=NULL;
	while(1)
	{
		printf("\nMenu\n1.Create BST\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Delete\n7.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>6)
			break;
		switch(opt)
		{
			case 1:
				insert(&p);
				break;
			case 2:
				printf("\nPreorder\n");
				preorder(p.rt);
				break;
			case 3:
				printf("\nInorder\n");
				inorder(p.rt);
				break;
			case 4:
				printf("\npostorder\n");
				postorder(p.rt);
				break;
			case 5:
				printf("\nSearch Value:");
				scanf("%d",&sv);
				if(search(&p,sv)==0)
					printf("\nNot Found");
				else
					printf("\nFound");
				break;
			case 6:
				delNode(&p);
				break;
		}
	}
}