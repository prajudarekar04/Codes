//WAP to check Parenthesis are balanced or not from and inputted string
/*i/p string
a+b=> No parenthesis
(a+b)=>Balanced Parethesis
((a+b)=>Ex at Left
(a+b))=>Ex at Right*/
#include<stdio.h>
#include"cstk.h"
void main()
{
	char s[50],ch;
	int i=0,flg=0;
	CSTK p;
	init(&p);
	printf("\nEnter Expression:");
	scanf("%s",s);
	while(s[i]!='\0')
	{
		if(s[i]=='(')
		{
			push(&p,s[i]);
			flg=1;
		}
		else
		{
			if(s[i]==')')
			{
				if(isEmpty(&p))
					break;
				ch=pop(&p);
			}
		}
		i++;
	}
	if(s[i]=='\0')
	{
		if(isEmpty(&p))
		{
			if(flg==0)
				printf("\nNo Parenthesis");
			else
				printf("\nBalanced Parenthesis.");
		}
		else
			printf("\nEx at Left");
	}
	else
		printf("\nEx at Right");
	return;
}