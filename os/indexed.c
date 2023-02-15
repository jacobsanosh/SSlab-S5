#include<stdio.h>
#include<stdlib.h>
#define size 10
struct linked
{
	int nb,len,start,block[size];
};
typedef struct linked fle;
int main()
{
	fle f[size];
	int n,op;
	printf("\nEnter the no of file to be added\t");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the starting address\t");
		scanf("%d",&f[i].start);
		printf("\nEnter the length\t");
		scanf("%d",&f[i].len);
		printf("\nenter the no of block\t");
		scanf("%d",&f[i].nb);
		printf("\nEnter the blocks\t");
		for(int j=0;j<f[i].nb;j++)
		{
			scanf("%d",&f[i].block[j]);
		}
		printf("\n cal\t");
		for(int j=0;j<f[i].nb;j++)
			printf("%d\t",f[i].block[j]);
	}
	x:printf("\nEnter 1 for view and 0 for exit\t");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("\nEnter the file number\t");
			scanf("%d",&n);
			n=n-1;
			printf("\nstart address\tlength\tno of block\tblocks\n");
			printf("%d\t%d\t%d\t",f[n].start,f[n].len,f[n].nb);
			for(int j=0;j<f[n].nb;j++)
				printf("%d\t",f[n].block[j]);
			break;
		case 2:
			exit(0);
	}
	goto x;
			
}
