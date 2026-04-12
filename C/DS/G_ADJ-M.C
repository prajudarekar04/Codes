//Graph Representation using Adjacanacy Matrix.
#include<stdio.h>
#include<conio.h>
#define N 10
int adj[N][N];//Global Variable
void main()
{
	int s,d,n;
	char ch;
	clrscr();
	printf("\nEnter Vertices Count:");
	scanf("%d",&n);
	flushall();
	printf("\nType of Graph\nU:Undirected\nD:Directed\nChoice:");
	scanf("%c",&ch);
	if(!(ch=='U'||ch=='D'))
		return;
	printf("\nEnter Edges:\n");
	while(1)
	{
		printf("\nSource:");
		scanf("%d",&s);
		printf("\nDestination:");
		scanf("%d",&d);
		if(s==0&&d==0)
			break;
		adj[s][d]=1;
		if(ch=='U')//Undirected
			adj[d][s]=1;
	}
	printf("\nAdj Matrix\n");
	for(s=1;s<=n;s++)
	{
		for(d=1;d<=n;d++)
			printf("%4d",adj[s][d]);
		printf("\n");
	}
	getch();
	return;
}