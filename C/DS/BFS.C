//Breadth First Traversal using adjacency list.
#include<stdio.h>
#include"adj-list.h"
int visited[N];
struct queue
{
	int arr[N];
	int fr,rr;
}q;
void init()
{
	q.rr=-1;
	q.fr=0;
}
void insert(int v)
{
	q.rr++;
	q.arr[q.rr]=v;
}
int isempty()
{
	return(q.rr<q.fr);
}
int remque()
{
	return q.arr[q.fr++];
}
/*

*/
void bfs(int v)
{
	NODE *p;
	visited[v-1]=1;
	printf("%4d",v);
	insert(v);
	while(!isempty())
	{
		v=remque();
		p=arr[v-1];
		while(p!=NULL)
		{
			if(visited[p->data-1]==0)
			{
				insert(p->data);
				visited[p->data-1]=1;
				printf("%4d",p->data);
			}
			p=p->next;
		}
	}
}
void main()
{
	init();
	createList();
	bfs(1);
	return;
}