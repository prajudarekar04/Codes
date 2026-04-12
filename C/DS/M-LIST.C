#include"mlist.h"
#include<stdio.h>
void main()
{
	int opt;
	SLIST p,q,r;
	init(&p);
	init(&q);
	init(&r);
	while(1)
	{
		printf("\nMenu\n1.Create List1\n2.Create List2\n3.Display List1\n4.Disply List2\n5.Disply List3\n6.Delete List1\n7.Delete List2\n8.Delete List3\n9.Intersection\m10.Union\n11.Merge\n12.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>11)
			break;
		switch(opt)
		{
			case 1:
				createList(&p);
				break;
			case 2:
				createList(&q);
				break;
			case 3:
				display(&p);
				break;
			case 4:
				display(&q);
				break;
			case 5:
				display(&r);
				break;
			case 6:
				delAll(&p);
				break;
			case 7:
				delAll(&q);
				break;
			case 8:
				delAll(&r);
				break;
			case 9:
				r=interList(&p,&q);
				break;
			case 10:
				r=unionList(&p,&q);
				break;
			case 11:
				r=mergeList(&p,&q);
				break;
		}
	}
}
