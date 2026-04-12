//Priority Queue.
#define M 5
typedef struct priorityQueue
{
	int arr[M];
	int fr,rr;
}PQ;
void init(PQ*t)
{
	t->rr=-1;
	t->fr=0;
}
void insert(PQ*t,int d)
{
	int i=t->rr;
	if(t->rr==M-1)
	{
		printf("\nOverflow");
		return;
	}
	for(i=t->rr;i>=0&&d<t->arr[i];i--)
		t->arr[i-1]=t->arr[i];
	t->arr[i+1]=d;
	t->rr++;
}
void remque(PQ*t)
{
	int i=t->fr;
	if(t->rr<t->fr)
		printf("\nUnderflow");
	else
	{
		for(;i<t->rr;i++)
			t->arr[i]=t->arr[i+1];
		t->rr--;
	}
}
void display(PQ*t)
{
	int i=t->fr;
	if(t->rr<t->fr)
		printf("\nEmpty Queue.");
	else
	{
		printf("\nDisplay\n");
		for(;i<t->rr;i++)
			printf("%4d\n",t->arr[i]);
	}
}
void main()
{
	PQ p;
	int opt,d;
	init(&p);
	while(1)
	{	printf("\nMenu\n1.Insert\n2.Remove\n3.Display\n4.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>3)
			break;
		switch(opt)
		{
			case 1:
				printf("\nData:\n");
				scanf("%d",&d);
				insert(&p,d);
				break;
			case 2:
				remque(&p);
				break;
			case 3:
				display(&p);
				break;
		}
	}
}