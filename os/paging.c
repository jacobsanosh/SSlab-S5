#include<stdio.h>
#include<stdlib.h>
#define max 20
int main()
{
	int page[max],np,nf,ps,pno,off;
	printf("\nEnter the no of pages and no of frams and page size\t");
	scanf("%d%d%d",&np,&nf,&ps);
	for(int i=0;i<np;i++)
		page[i]=-1;
	printf("\nEnter the page datails");
	printf("\nEnter the frame -1 if page is not available\n pages \t frame");
	for(int i=0;i<np;i++)
	{
		printf("\n%d--->",i);
		scanf("%d",&page[i]);
	}
	x:printf("\nEnter the logical address and logical address\t");
	scanf("%d%d",&pno,&off);
	if(page[pno]!=-1)
	{
		printf("physical address is %d %d",page[pno],off);
		goto x;
	}
	else
	{
		printf("\ngiven page number is not available");
		goto x;
	}
	
}
