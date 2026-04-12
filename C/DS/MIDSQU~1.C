#include <stdio.h>
void insertion(int list[],int size,int key)
{
    int temp,i,count;
    int no[10];
    temp=key;
    i=0;
    while(temp!=0)
    {
	no[i]=temp%10;
	temp/=10;
	i++;
    }
    i/=2;
    i=no[i]*no[i];
    count=1;
    while(list[i]!=-1&&count<=size)
    {
	i=(i+1)%size;
	count++;
    }
    if(count>size)
	printf("\nList is Full.");
    else
	list[i]=key;
    return;
}
void display(int list[],int size)
{
    int i;
    printf("\nData:");
    for(i=0;i<size;i++)
    {
	if(list[i]==-1)
	    continue;
	printf("\n%2d) %d",i,list[i]);
    }
    return;
}
void search(int list[],int size,int key)
{
    int temp,i,count;
    int no[10];
    temp=key;
    i=0;
    while(temp!=0)
    {
	no[i]=temp%10;
	temp/=10;
	i++;
    }
    i/=2;
    i=no[i]*no[i];
    count=1;
    while(list[i]!=key&&count<=size)
    {
	i=(i+1)%size;
	count++;
    }
    if(count>size)
	printf("\nUnsuccessfull Search.");
    else
	printf("\n%4d is at location %2d.",list[i],i);
    return;
}
int main()
{
    int size=100,i,opt,key;
    int list[100];
    for(i=0;i<size;i++)
	list[i]=-1;
    while(1)
    {
	printf("\nMenu\n1.Insert\t2.Display\n3.search\t4.exit\nOption:");
	scanf("%d",&opt);
	if(opt>3)
	    break;
	switch(opt)
	{
	    case 1:
		printf("\nElement to be insert:");
		scanf("%d",&key);
		insertion(list,size,key);
		break;
	    case 2:
		display(list,size);
		break;
	    case 3:
		printf("\nElement to be search:");
		scanf("%d",&key);
		search(list,size,key);
		break;
	}
    }
    return 0;
}