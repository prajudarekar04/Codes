//Depth first search using adjacency matrix.
#include<stdio.h>
#include<conio.h>
int adj[10][10],visited[10],n,i=0,j=0;//Global variable
void dfs(int v)
{
	int j;
	printf("%4d",v);
	visited[v]=1;
	for(j=1;j<=n;j++)
	{
		if(visited[j]==0&&adj[v][j]==1)
		{
			dfs(j);
		}
	}
}
void main()
{
	clrscr();
	printf("\nEnter Vertices Count:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&adj[i][j]);
	}
	dfs(1);
	getch();
	return;
}