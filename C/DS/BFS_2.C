//BFS
//queue using array
#include<stdio.h>
#include<conio.h>
int adj[10][10],q[10],visited[10],n,f=0,r=-1;
void bfs(int v)
{
	int i;
	visited[v]=1;
	printf("%4d",v);
	q[++r]=v;//insertion
	while(f<=r)
	{
		v=q[f++];//remove
		for(i=1;i<=n;i++)
		{
			if(adj[v][i]&&visited[i]==0)
			{
				q[r++]=i;
				visited[i]=1;
				printf("%4d",i);
			}
		}
	}
}
void main()
{
	int i,j;
	clrscr();
	printf("\nVertices Count:");
	scanf("%d",&n);
	printf("\nEnter Edges:");
	while(1)
	{
		printf("\nSource Destination:");
		scanf("%d %d",&i,&j);
		if(i==0&&j==0)
			break;
		if(i<1||j<1||i>n||j>n)
			continue;
		adj[i][j]=adj[j][i]=1;
	}
	bfs(1);
	getch();
	return;
}