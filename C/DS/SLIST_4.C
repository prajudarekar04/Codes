#include<stdio.h>
#include"slist.h"
#include<stdlib.h>
void main()
{
	int opt,d,res,sv,rv,pos,i;
	SLIST p;
	init(&p);
	while(1)
	{
		printf("\nSingle Linked List\n1.Add End\n2.Add Beg\n3.Display\n4.Odd Display\n5.Even Display\n6.Odd Nodes\n7.Even Nodes\n8.Data Sum\n9.Delete First\n10.Delete Last\n11.Delete All\n12.Delete i Node\n13.Search Value\n14.Find and Replace\n15.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>14)
			break;
		switch(opt)
		{
			case 1:
				printf("\nData at End:");
				scanf("%d",&d);
				addEnd(&p,d);
				break;
			case 2:
				printf("\nData at Begin:");
				scanf("%d",&d);
				addBeg(&p,d);
				break;
			case 3:
				display(&p);
				break;
			case 4:
				odisplay(&p);
				break;
			case 5:
				edisplay(&p);
				break;
			case 6:
				printf("\nOdd Nodes:%d",ocount(&p));
				break;
			case 7:
				printf("\nEven Nodes:%d",ecount(&p));
				break;
			case 8:
				printf("\nSum:%d",sum(&p));
				break;
			case 9:
			      if(p.st==NULL)
				printf("\nEmpty List");
			      else
				delFirst(&p);
			      break;
			case 10:
			      if(p.st==NULL)
				printf("\nEmpty List");
			      else
				delLast(&p);
			      break;
			case 11:
			      if(p.st==NULL)
				printf("\nEmpty List");
			      else
				delAll(&p);
			      break;
			case 12:
			      if(p.st==NULL)
				printf("\nEmpty List");
			      else
			      {
					printf("\nEnter Position to Delete");
					scanf("%d",&pos);
					if(pos<1||pos>p.cnt)
						printf("\nInvalid Input");
					else
						deliNode(&p,pos);
			      }
			      break;
			case 13:
				if(p.st==NULL)
					printf("\nEmpty List");
				else
				{
					printf("\nEnter Search Value:");
					scanf("%d",&sv);
					if(search(&p,sv)==0)
						printf("\nNot Found");
					else
						printf("\nFound");
				}
				break;
			case 14:
				if(p.st==NULL)
					printf("\nEmpty List");
				else
				{
					printf("\nEnter Search Value:");
					scanf("%d",&sv);
					printf("\nEnter Replace Value:");
					scanf("%d",&rv);
					findRepl(&p,sv,rv);
				}
				break;

		}
	}
}