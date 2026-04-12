//Infix-Postfix Expression.
#include<ctype.h>
#include"cstk.h"
int preced(char stktop,char opr)
{
	if(stktop!='('&&opr==')')
		return 1;
	else
		return 0;
}
void main()
{
	CSTK p;
	char a[50],b[50],ch;
	int i=0,j=0;
	init(&p);
	printf("\nInfix expre:");
	scanf("%s",a);
	while(a[i]!='\0')
	{
		if(isalpha(a[i]))
			b[j++]=a[i];
		else
		{
			while(!isEmpty(&p)&&preced(p.arr[p.top],a[i]))
			{
				ch=pop(&p);
				b[j++]=ch;
			}
			if(isEmpty(&p)||a[i]!=')')
				push(&p,a[i]);
			else
				ch=pop(&p);
		}
		i++;
	}
	while(!isEmpty(&p))
	{
		ch=pop(&p);
		b[j++]=ch;
	}
	b[j]='\0';
	puts(b);
	return;
}