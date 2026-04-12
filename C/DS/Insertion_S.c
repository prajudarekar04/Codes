//Insertion Sort
#include<stdio.h>
#define M 5
void main()
{
    int x[M],val,i,j;
    for(i=0;i<M;i++)
    {
        printf("\nEnter data");
        scanf("%d",&val);
        for(j=i-1;j>=0;j++)
        {
            if(x[j]>val)
                x[j+1]=x[j];
            else
                break;
        }
        x[j+1]=val;
    }
    printf("\nData\n");
    for(i=0;i<M;i++)
        printf("%4d",x[i]);
    return;
}


/*
#include<stdio.h>
#define M 5
void main()
{
    int x[M],i,j,temp;
    printf("\nEnter data");
    for(i=0;i<M;i++)
        scanf("%d",&x[i]);
    for(i=0;i<M;i++)
    {
	    temp=x[i];
    	i=M-1;
	    while(i>=0&&x[i]>=temp)
    	{
	    	x[i+1]=x[i];
		    i--;
    	}
	    x[i+1]=temp;
    }
    printf("\nData:\n");
    for(i=0;i<M;i++)
        printf("%4d",x[i]);
    return;
}
*/