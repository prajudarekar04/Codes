/*
Dijikshtra

To find out shortest path
There are several paths for going from 1 node to another node,
but the shortest path is that path in which 
the some of weights of the included edges is the minimum.
There are several algorithms to find out shortest path.
Here we will describe the dijikshtra algorithm.
The procedure
We label each node with distance, predecessor and the status.
Distance of node represents the shortest distance of that node from the source node
And predecessor of the node represents the node which... The node in the shortest path from source.
The status of the node can be permanently or temporary.s
1. Initially makes source code permanent and make it the current working node, all other nodes are made temporary.
2. Examine all the temporary neighbourly .... And after checking for the condition for minimum weight relabel the required nodes.
3. From all the temporary nodes, find out the node which has minimum value of distance, make this node permanent and now this is our current working node.
4. Repeat steps until destination node is permanent.
*/
#include<stdio.h>
#include<conio.h>
#define INF 999
int adj[10][10]//adj matrix
int n//no.of edges
/*
----
|  |
A--B
W=	A	B	C	D
A	0	2	0	8
B	3	0	4	7
C	0	0	0	5
D	9	0	6	0
*/
void createAdjMatrix()
{
	int i,j,d;
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			adj[i][j]=INF;
	}
	printf("\nWeighted Matrix:\n");
	while(1)
	{
		printf("\nSource Destination:\n");
		scanf("%d %d",&i,&j);
		if(i==0&&j==0)
			break;
		if(i<1||j<1||i>=n||j>n)
			continue;
		printf("\nWeight on Edge:");
		scanf("%d",&d);
		adj[i][j]=d;
	}
}
void dijik()
{
	int s,d;
	int visited[10],dist[10],preced[10];
	int curr,i,nd,sd,flg=1;
	while(flg)
	{
		printf("\nSource:");
		scanf("%d",&s);
		printf("\nDestination:");
		scanf("%d",&d);
		if(s==0&&d==0)
			break;
		for(i=1;i<=n;i++)
		{
			dist[i]=INF;
			visited[i]=0;
		}
		dist[s]=0;
		visited[s]=1;
		preced[s]=s;
		curr=s;
		while(curr!=d)
	}
	for()
	{

	}
	sd=INF;
	for()
	{

	}
}
/*
	0	1	2	3	4	5	6	7	8	9
visited 1	0	0	0	0	0	0	0	0	0
dist    0	2	0	8      INF     INF     INF     INF     INF	INF
preced  1       1		1
*/