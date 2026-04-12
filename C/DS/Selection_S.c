//Selection Sort
#include<stdio.h>
#define M 5
void main()
{
  int x[M],i,j,pos,tmp;
  for(i=0;i<M;i++)
  {
      printf("\nEnter number:");
      scanf("%d",&x[i]);
  }
  printf("\nBefore Sorting\n");
  for(i=0;i<M;i++)
    printf("%4d",x[i]);
  for(i=0;i<M-1;i++)
  {
      pos=i;
      for(j=i+1;j<M;j++)
      {
          if(x[j]<x[pos])
            pos=j;
      }
      if(i!=pos)
      {
          tmp=x[i];
          x[i]=x[pos];
          x[pos]=tmp;
      }
  }
  printf("\nAfter sorting\n");
  for(i=0;i<M;i++)
  {
      printf("%4d",x[i]);
  }
}
