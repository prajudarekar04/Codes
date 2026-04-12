#include<stdio.h>
#include<ctype.h>
#define M 10
typedef struct stack
{
	int top;
	int arr[M];
}STK;
void init(STK*t)
{
	t->top=-1;
}
void push(STK*t,int d)
{
	t->top++;
	t->arr[t->top]=d;
}
int pop(STK*t)
{
	return t->arr[t->top--];
}
int isEmpty(STK*t)
{
	return(t->top==-1);
}
int comp(int v1,int v2,char opr)
{
	int res=0;
	switch(opr)
	{
		case '+':
			res=v1+v2;
			break;
		case '-':
			res=v1-v2;
			break;
		case '*':
			res=v1*v2;
			break;
		case '/':
			res=v1/v2;
			break;
	}
	return res;
}
void main()
{
	char pstr[50],ch;
	static int val[26];
	int index,i=0,a=0,b=0,res=0;
	STK p;
	init(&p);
	printf("\nInput Postfix Expression:");
	scanf("%s",pstr);
	while(pstr[i]!='\0')
	{
		if(isalpha(pstr[i]))
		{
			index=pstr[i]-65;
			printf("\nValue for %c:",pstr[i]);
			scanf("%d",&val[index]);
		}
		i++;
	}
	i=0;
	while(pstr[i]!='\0')
	{
		if(isalpha(pstr[i]))
		{
			index=pstr[i]-65;
			push(&p,val[index]);
		}
		else
		{
			ch=pstr[i];
			b=pop(&p);
			a=pop(&p);
			res=comp(a,b,ch);
			push(&p,res);
		}
		i++;
	}
	res=pop(&p);
	printf("\nOutput:%d",res);
	return;
}